#include "trackchanges.h"

TrackChanges::TrackChanges(QObject *parent)
    : QObject{parent}
{
	endOfWordChars = "`~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-=।॥"; // end of word
}

QVector<QPair<int,QString>> TrackChanges::getValidWords(const QString &text)
{
	QVector<QPair<int,QString>> wordList;

	int startIndex = -1;
	int lenOfWord = 0;
	for (int i = 0; i < text.length(); i++) {
		QChar ch = text[i];
		if (endOfWordChars.contains(ch)) {
			// Divide the string if punctuations occur & put them in vector with their indices
			if (lenOfWord == 0) {
				startIndex = i + 1;
				continue;
			}
			wordList.push_back({startIndex, text.mid(startIndex, lenOfWord)});

			lenOfWord = 0;
			startIndex = i + 1;
		} else {
			lenOfWord++;
		}
	}

	return wordList;
}

void TrackChanges::projectChanged(const QString &projectAbsPath)
{
    if (this->currentProjectAbsPath == projectAbsPath)
        return;

    // Set name and path of new project
    currentProjectAbsPath = projectAbsPath;

	// Traverse the project and build the trie

}

void TrackChanges::currentPageChanged(const QString &fileAbsPath, bool isWritable, QTextDocument *doc)
{
	isCurrentFileWritable = isWritable;
    currentPageAbsPath = fileAbsPath;
	currentDocument = doc->clone(this);

	// Code to handle file changes
	trackWords();
}

void TrackChanges::trackWords()
{
	// Clear previous tracked words
	wordsTracked.clear();

	QTextCursor cur(currentDocument);
    cur.movePosition(QTextCursor::Start);
	cur.movePosition(QTextCursor::StartOfWord);

    while (!cur.atEnd()) {
        int startPositionOfWord = cur.position();
        cur.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor); // Selecting the word
        QString selectedWord = cur.selectedText();

		QVector<QPair<int,QString>> words = getValidWords(selectedWord);
		foreach (auto word, words) {
			std::tuple<int,std::string> curWordInfo = std::make_tuple(startPositionOfWord + word.first, word.second.toStdString());
			wordsTracked.push_back(curWordInfo);
		}
		cur.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor); // Moving anchor to the next word
    }

//    for (auto item : wordsTracked) {
//        QString str = QString::number(std::get<0>(item)) + QString::fromStdString(std::get<1>(item));
//        qDebug() << str;
//	}

	// Update the trie

}


void TrackChanges::handleTimeOut(QTextDocument *document)
{
	currentDocument = document->clone(this);
	trackWords();
}


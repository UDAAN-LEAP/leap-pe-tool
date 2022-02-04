#include  "lg2_common.h"
#include <iostream>
#include <qmessagebox.h>

void lg2_common :: PostError(QString errorMessage) {
	QMessageBox messageBox;
	messageBox.critical(0, "Git Error", errorMessage);
}
int lg2_common :: check_lg2(int error, std::string message, std::string extra) {
	const git_error* lg2err;
	const char* lg2msg = "", * lg2spacer = "";
	int klass = 0;
	if (error == 0) return 0;
	if ((lg2err = giterr_last()) != NULL && lg2err->message != NULL) {
		lg2msg = lg2err->message;
		lg2spacer = " - ";
		klass = lg2err->klass;
		std::string errorMsg = message + ".\nError Message: " + lg2msg + "\nError Code: " + std::to_string(klass);
		QString qerrorMsg = QString::fromStdString(errorMsg);
		PostError(qerrorMsg);
	}
	if (!extra.empty()) {
		std::cout << message << extra << "(" << error << ") " << lg2spacer << lg2msg;
	}
	else
	{
		std::cout << message << "(" << error << ") " << lg2spacer << lg2msg;
	}
	return klass;
}

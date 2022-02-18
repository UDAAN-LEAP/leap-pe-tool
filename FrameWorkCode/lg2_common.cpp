#include  "lg2_common.h"
#include <iostream>
#include <qmessagebox.h>


/*!
 * \class lg2_common
 * \brief This is a class to work with git. Whenever the user is done with the project he can push back to the
 * github repository he cloned from. The code in project.h, project.cpp and this class form the libgit module.
 *
 * The function of the module is to ensure that the project(OCR Text files) gets pushed to github.
 */



/*!
 * \fn PostError()
 * This function is used to fetch error message from the Git Client and show it as a message box to the user in
 * our tool.
 *
 * \param QString errorMessage
 */
void lg2_common :: PostError(QString errorMessage) {
	QMessageBox messageBox;
	messageBox.critical(0, "Git Error", errorMessage);
}


/*!
 * \fn check_lg2()
 * This function is used to check any errors from our Git Client and return the error.
 *
 * If there is no error then it returns 0 (i.e. returns false)
 *
 * If there is a git error then it fetches the error-message from libgit and formats it for showing it in the
 * QMessageBox.
 *
 * It then calls PostError() which facilitates showing the message on MessageBox on our tool
 *
 * \param int error, std::string message, std::string extra
 */


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

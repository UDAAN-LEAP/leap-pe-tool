#include  "lg2_common.h"
#include <iostream>

void check_lg2(int error, std::string message, std::string extra ) {
	const git_error *lg2err;
	const char *lg2msg = "", *lg2spacer = "";
	if (!error) return;
	if ((lg2err = git_error_last()) != NULL && lg2err->message != NULL) {
		lg2msg = lg2err->message;
		lg2spacer = " - ";
	}
	if (!extra.empty()) {
		std::cout << message << extra << "(" << error << ") " << lg2spacer << lg2msg;
	}
	else
	{
		std::cout << message << "(" << error << ") " << lg2spacer << lg2msg;
	}
}
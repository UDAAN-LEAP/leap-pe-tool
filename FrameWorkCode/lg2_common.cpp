#include  "lg2_common.h"
#include <iostream>

int check_lg2(int error, std::string message, std::string extra ) {
	const git_error *lg2err;
	const char *lg2msg = "", *lg2spacer = "";
	int klass = 0;
	if (error == 0) return 0;
    if ((lg2err = giterr_last()) != NULL && lg2err->message != NULL) {
		lg2msg = lg2err->message;
		lg2spacer = " - ";
		klass = lg2err->klass;
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

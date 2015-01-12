/*
 * LoggerParams.h
 *
 *  Created on: Nov 27, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#ifndef LOGGERPARAMS_H_
#define LOGGERPARAMS_H_

#include "Poco/Message.h"
#include <string.h>

typedef unsigned int uint;

class LoggerParams {
public:
	LoggerParams();
	LoggerParams(const std::string& logFileName, uint loggerFilePriority, uint loggerConsolePriority);

	std::string getLogFileName() const;
	Poco::Message::Priority getLoggerFilePriority() const;
	Poco::Message::Priority getConsolePriority() const;
private:
	Poco::Message::Priority convertFromInt2Priority(uint priority) const;

	std::string mLogFileName;
	Poco::Message::Priority mLoggerFilePriority;
	Poco::Message::Priority mLoggerConsolePriority;
};

#endif /* LOGGERPARAMS_H_ */

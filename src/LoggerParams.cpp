/*
 * LoggerParams.cpp
 *
 *  Created on: Nov 27, 2013
 *      Author: Naor Farcas & Roei Biton
 */

#include "../include/LoggerParams.h"
#include <iostream>

using namespace std;

LoggerParams::LoggerParams()
	: mLogFileName("app.log"), mLoggerFilePriority(convertFromInt2Priority(3)),
	  mLoggerConsolePriority(convertFromInt2Priority(4))
{}

LoggerParams::LoggerParams(const std::string& logFileName, uint loggerFilePriority, uint LoggerConsolePriority)
: mLogFileName(logFileName), mLoggerFilePriority(convertFromInt2Priority(loggerFilePriority)),
  mLoggerConsolePriority(convertFromInt2Priority(LoggerConsolePriority))
{}

Poco::Message::Priority LoggerParams::getLoggerFilePriority() const
{
	return mLoggerFilePriority;
}


Poco::Message::Priority LoggerParams::getConsolePriority() const
{
	return mLoggerConsolePriority;
}

std::string LoggerParams::getLogFileName() const
{
	return mLogFileName;
}

Poco::Message::Priority	LoggerParams::convertFromInt2Priority(uint priority) const
{
	Poco::Message::Priority result;
	if ((priority <= 8) && (priority >= 1))
	{
		result = static_cast<Poco::Message::Priority>(priority);
	}
	else
	{
		cerr << "Error: Priority should be an integer between 1 and 8. Priority was set to the default one"
				<< endl;
	}
	return result;
}




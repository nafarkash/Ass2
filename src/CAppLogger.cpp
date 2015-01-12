/*
 * CAppLogger.cpp
 *
 *  Created on: Nov 27, 2013
 *      Author: Naor Farcas & Roei Biton
 */


#include "Poco/LoggingFactory.h"
#include "Poco/Logger.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"
#include "../include/CAppLogger.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include <iostream>

using namespace Poco;
using namespace std;

bool CAppLogger::mInitialized = false;
LoggerParams CAppLogger::mLoggerParams;

void CAppLogger::InitializeLoggerParams(const LoggerParams& loggerParams)
{
	mInitialized = true;
	mLoggerParams = loggerParams;
}

CAppLogger::CAppLogger(const LoggerParams& loggerParams)
: mLoggers()
{
	if (!mInitialized)
	{
		cerr << "Initializing the Logger with default parameters. Did you forget to call InitializeLoggerParams ?"
				<< endl;
	}

	// We tell the vector how much elements we it'll have - its more efficient.
	mLoggers.resize(ELoggersCount);

	// Build the loggers
	mLoggers[ELoggerConsole] =
			&Logger::create("Log.Console", LoggingFactory::defaultFactory().createChannel("ConsoleChannel"),
					loggerParams.getConsolePriority());
	mLoggers[ELoggerFile] =
			&Logger::create("Log.File", LoggingFactory::defaultFactory().createChannel("FileChannel"),
					loggerParams.getLoggerFilePriority());

	// Set file channel path property (file & directory).
	mLoggers[ELoggerFile]->getChannel()->setProperty("path", loggerParams.getLogFileName());

	// Open all loggers.
	vector<Logger*>::iterator iterator;
	for(iterator = mLoggers.begin();
			iterator != mLoggers.end();
			iterator++)
	{
		if (*iterator)
		{
			(*iterator)->getChannel()->open();
		}
	}
}

CAppLogger::~CAppLogger(void)
{
	// Close all loggers
	vector<Logger*>::iterator iterator;
	for(iterator = mLoggers.begin();
			iterator != mLoggers.end();
			iterator++)
	{
		if (*iterator != NULL)
		{
			(*iterator)->getChannel()->close();
			(*iterator)->getChannel()->release();
		}
	}
}

void CAppLogger::Log(const std::string& inLogString, Poco::Message::Priority inPriority/* = Poco::Message::PRIO_INFORMATION*/)
{
	Message msg;
	msg.setPriority(inPriority);
	msg.setText(inLogString);

	vector<Logger*>::iterator iterator;
	for(iterator = mLoggers.begin();
			iterator != mLoggers.end();
			iterator++)
	{
		if (*iterator)
		{
			(*iterator)->log(msg);
		}
	}
}

void CAppLogger::Log(const std::ostringstream& inLogString, Poco::Message::Priority inPriority/* = Poco::Message::PRIO_INFORMATION*/)
{
	Log(inLogString.str(), inPriority);
}

void CAppLogger::LogWithTimeStamp(const std::string& inLogString, Poco::Message::Priority inPriority/* = Poco::Message::PRIO_INFORMATION*/)
{
	Poco::DateTime now;
	std::ostringstream strStream;
	strStream << Poco::DateTimeFormatter::format(now,"%w %b %e %H:%M:%S %Y> ") << inLogString;
	Log(strStream, inPriority);
}




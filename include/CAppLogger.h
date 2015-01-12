/*
 * CAppLogger.h
 *
 *  Created on: Nov 27, 2013
 *      Author: roeibit
 */

#ifndef CAPP_LOGGER_H
#define CAPP_LOGGER_H

#include <string>
#include <sstream>
#include <vector>
#include <string>
#include "Poco/Message.h"
#include "LoggerParams.h"

// Forward declarations (instant including h files)
namespace Poco{class Logger;};
class CMyLogger;

// Application logger: class that handles all application logging.
// It is implemented as a singleton
// Singleton is a design pattern that is used to restrict instantiation of a class to one object.
// This is useful when exactly one object is needed to coordinate actions across the system - for example only one logger.
// Sometimes it is generalized to systems that operate more efficiently when only one or a few objects exist.

class CAppLogger
{
private:
        enum ELogger
        {
                ELoggerFile             = 0,
                ELoggerConsole,
                ELoggersCount
        };

        CAppLogger(const LoggerParams& loggerParams);
        CAppLogger(const CAppLogger&);
        CAppLogger& operator=(const CAppLogger&);
public:
        ~CAppLogger(void);

        // The one and only application logger is accessible through this method
        static CAppLogger& Instance()
        {
                // This is the instance.
                static CAppLogger instance(mLoggerParams);
                static bool firstCall = true;
                if (firstCall)
                {
                        firstCall = false;
                        instance.Log("\n",Poco::Message::PRIO_FATAL);
                        instance.LogWithTimeStamp("Starting new log session.",Poco::Message::PRIO_FATAL);
                }

                // Return a reference to the instance.
                return instance;
        }

        // Write to log a STL string.
        void Log(const std::string& inLogString, Poco::Message::Priority inPriority = Poco::Message::PRIO_INFORMATION);
        // Write to log a STL string stream.
        void Log(const std::ostringstream& inLogString, Poco::Message::Priority inPriority = Poco::Message::PRIO_INFORMATION);

        void LogWithTimeStamp(const std::string& inLogString, Poco::Message::Priority inPriority = Poco::Message::PRIO_INFORMATION);

        static void InitializeLoggerParams(const LoggerParams& loggerParams);

private:
        // Holds pointers to all loggers
        std::vector<Poco::Logger*> mLoggers;
        static bool mInitialized;
        static LoggerParams mLoggerParams;
};

#endif // CAPP_LOGGER_H

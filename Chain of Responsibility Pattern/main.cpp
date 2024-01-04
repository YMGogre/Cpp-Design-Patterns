#include "AbstractLogger.h"
#include "ErrorLogger.h"
#include "FileLogger.h"
#include "ConsoleLogger.h"

AbstractLogger* getChainOfLoggers() {
	AbstractLogger* errorLogger = new ErrorLogger(AbstractLogger::ERROR);
	AbstractLogger* fileLogger = new FileLogger(AbstractLogger::DEBUG);
	AbstractLogger* consoleLogger = new ConsoleLogger(AbstractLogger::INFO);

	errorLogger->setNextLogger(fileLogger);
	fileLogger->setNextLogger(consoleLogger);

	return errorLogger;
}

int main() {
	AbstractLogger* loggerChain = getChainOfLoggers();

	loggerChain->logMessage(AbstractLogger::INFO, "This is an information.");

	loggerChain->logMessage(AbstractLogger::DEBUG,
		"This is a debug level information.");

	loggerChain->logMessage(AbstractLogger::ERROR,
		"This is an error information.");
}
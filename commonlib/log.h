/*------------------------------------------------------
 *
 * class       : CLog
 * description : Log file
 * date        : 2011-7-19
 * author      : wanghonggang
 *
 *----------------------------------------------------*/
#ifndef _LOG_H_
#define _LOG_H_

#include <pthread.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "lock.h"
#include "singleton.h"

#define DEBUG    0, __FILE__, __LINE__
#define INFO     1, __FILE__, __LINE__
#define NOTICE   2, __FILE__, __LINE__
#define WARNNING 3, __FILE__, __LINE__
#define ERROR    4, __FILE__, __LINE__
#define FATAL    5, __FILE__, __LINE__
#define NONE     6, __FILE__, __LINE__

#define CLogS CSingleton<CLog>::Instance()

class CLog
{
public:
	enum LogLevel
	{
		LOGDEBUG,
		LOGINFO,
		LOGNOTICE,
		LOGWARNNING,
		LOGERROR,
		LOGFATAL,	
		LOGNONE	
	};

public:
	CLog();
	~CLog();

public:
	void SetLevel(LogLevel level) { level_ = level; }
	void SetPrintConsole(bool bPrint) { bPrintConsole_ = bPrint; }
	bool InitLog(const std::string& strFileName, LogLevel level = LOGDEBUG, int maxBytes = 1024*1024, bool bPrintConsole = true);
	//void WriteLog(int level, const char* file, int line, const char* format, ...) __attribute__((cdecl));
	void WriteLog(int level, const char* file, int line, const char* format, ...);

private:
	void CheckAndRename();
	void TrimFileName(const char* file, std::string& strFileName);

private:
	int index_;
	FILE* file_;
	CLock lock_;
	int maxBytes_;
	LogLevel level_;
	bool bPrintConsole_;
	std::string strFileName_;	
	std::vector<std::string> logLevelVec_;

	const static int TimeBufMaxSize = 64;
};



#endif /* _LOG_H_ */

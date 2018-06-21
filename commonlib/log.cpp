#include "log.h"
#include <iostream>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

CLog::CLog()
{
	file_  = NULL;
	index_ = 1;
	bPrintConsole_ = false;
}

CLog::~CLog()
{
	if(file_ != NULL)
	{
		fclose(file_);
		file_ = NULL;
	}
}

bool CLog::InitLog(const std::string& strFileName, LogLevel level, int maxBytes, bool bPrintConsole)
{
	level_         = level;
	maxBytes_      = maxBytes;
	bPrintConsole_ = bPrintConsole;

	logLevelVec_.push_back("DEBUG");
	logLevelVec_.push_back("INFO");
	logLevelVec_.push_back("NOTICE");
	logLevelVec_.push_back("WARNNING");
	logLevelVec_.push_back("ERROR");
	logLevelVec_.push_back("FATAL");
	
	char pidBuf[32] = {0};
	snprintf(pidBuf, sizeof(pidBuf), ".%d", getpid());
	std::string strPidFileName = strFileName;
	strPidFileName += (char*)pidBuf;
	strFileName_ = strPidFileName;

	/* Init log */
	file_ = fopen(strFileName_.c_str(), "w+");
	if(NULL == file_)
	{
		std::cout<<"Open log file error!"<< std::endl;
		return false;
	}
	
	return true;
}

void CLog::CheckAndRename()
{
	if(NULL == file_)
	{
		return;
	}

	struct stat info;
    stat(strFileName_.c_str(), &info);
	
	if(info.st_size > maxBytes_)
	{
		fclose(file_);
		char tmBuff[TimeBufMaxSize] = {0};
		time_t tm = time(NULL);
		struct tm tmResult; 
		localtime_r(&tm, &tmResult);
		strftime(tmBuff, TimeBufMaxSize, "%Y%m%d%H%M%S", &tmResult);
		std::string strOldFileName = strFileName_ + '.' + tmBuff;
		char buff[32] = {0};
		snprintf(buff, sizeof(buff), "%d", index_);
		strOldFileName = strOldFileName + "-" + buff;
		rename(strFileName_.c_str(), strOldFileName.c_str());
		file_ = fopen(strFileName_.c_str(), "w+");
		
		index_++;
	}
}

void CLog::WriteLog(int level, const char* file, int line, const char* format, ...)
{
	if(NULL == file_)
	{
		return;
	}

	CAutoLock autoLock(lock_);
	if(level >= level_)
	{
		/* Time, File & Line*/
		char tmBuff[TimeBufMaxSize] = {0};
		time_t tm = time(NULL);
		struct tm tmResult; 
		localtime_r(&tm, &tmResult);
		strftime(tmBuff, TimeBufMaxSize, "%Y-%m-%d %H:%M:%S", &tmResult);

		std::string strFileName = "";
		TrimFileName(file, strFileName);

		char szTimeTag[1024] = {0};
		snprintf(szTimeTag, sizeof(szTimeTag), "%s %s [%s:%d] ", tmBuff, logLevelVec_[level].c_str(), strFileName.c_str(), line);
		fprintf(file_, "%s", szTimeTag);
		if (bPrintConsole_)
		{
			fprintf(stdout, "%s", szTimeTag);
		}

		char szContent[8192] = {0};
		va_list ap;
		va_start(ap, format);
		vsnprintf(szContent, sizeof(szContent), format, ap);
		va_end(ap);
		fprintf(file_, "%s\n", szContent);
		if (bPrintConsole_)
		{
			fprintf(stdout, "%s\n", szContent);
		}

/*		fprintf(stdout, "%s %s [%s:%d]\r\n", tmBuff, logLevelVec_[level].c_str(), strFileName.c_str(), line);
		vfprintf(stdout, format, ap);
		fprintf(stdout, "\r\n\r\n");*/
//		va_end(ap);

//		if(bPrintConsole_)
///		{
			
			
//			fprintf(stdout, "%s %s [%s:%d]\r\n", tmBuff, logLevelVec_[level].c_str(), strFileName.c_str(), line);
			//vfprintf(stdout, format, ap);
//			fprintf(stdout, "\r\n\r\n");
			
//		}
		
//		fprintf(file_, "\r\n\r\n");
		fflush(file_);

		/* Max size, create new file */
		CheckAndRename();
	}
}

void CLog::TrimFileName(const char* file, std::string& strFileName)
{
	strFileName = file;
	int iPos = strFileName.rfind('/');
	if(iPos != std::string::npos)
	{
		strFileName = strFileName.substr(iPos + 1, strFileName.size() - 1);	
	}
}

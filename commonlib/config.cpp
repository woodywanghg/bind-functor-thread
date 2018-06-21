#include "config.h"
#include <iostream>
#include <string>
#include <algorithm>

CConfig::CConfig()
{

}


CConfig::~CConfig()
{
	if(file_)
	{
		file_.close();
	}
}

bool CConfig::Load(const std::string& strFileName)
{
	file_.open(strFileName.c_str());
	if(!file_)
	{
		std::cout<<"Open config file "<<strFileName<<" error!"<<std::endl;
		return false;
	}

	return true;
}

bool CConfig::Reload(const std::string &strFileName)
{
	file_.close();
	return Load(strFileName);
}

bool CConfig::GetInt(const std::string& strSection, const std::string& strKey, int& value)
{
	std::string strValue;
	if(!GetString(strSection, strKey, strValue))
	{
		return false;
	}

	value = atoi(strValue.c_str());

	return true;
}

bool CConfig::GetString(const std::string& strSection, const std::string& strKey, std::string& strValue)
{
	bool bStart = false;
	std::string strLine;
	std::string::size_type pos = std::string::npos;
	std::string strTempKey = strKey +  "=";

	while(!file_.eof()) 
    {
		std::getline(file_, strLine);
		TrimSpace(strLine);
		if(strLine.find(strSection) != std::string::npos)
		{
			
			bStart = true;	
			std::getline(file_, strLine);
			TrimSpace(strLine);
			while(strLine.find("[") == std::string::npos && !file_.eof())
			{
				pos = strLine.find(strTempKey);
				if(pos != std::string::npos)
				{
					strValue = strLine.substr(pos + strTempKey.length(), strLine.length() - strTempKey.length());
					file_.clear(); 
					file_.seekg(0);
					return true;
				}
				std::getline(file_, strLine);
				TrimSpace(strLine);
			}	
		}
		else
		{
			continue;	
		}	
		
    }

	file_.clear(); 
	file_.seekg(0);
	
	return false;
}

void CConfig::TrimSpace(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), bind2nd(std::equal_to<char>(), ' ')), str.end());
}

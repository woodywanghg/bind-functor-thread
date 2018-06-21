#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <fstream>

class CConfig
{
public:
	CConfig();
	~CConfig();
	
	bool Load(const std::string& strFileName);
	bool Reload(const std::string& strFileName);
	bool GetInt(const std::string& strSection, const std::string& strKey, int& value);
	bool GetString(const std::string& strSection, const std::string& strKey, std::string& strValue);

private:
	void TrimSpace(std::string& str);
	std::ifstream file_;
};

#endif /* _CONFIG_H_ */

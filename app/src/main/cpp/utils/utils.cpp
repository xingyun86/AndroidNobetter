#include "utils.h"


bool access_network(std::string strDomainName, int nPort)
{
	bool result = false;
	std::string strIpAddr = "";
	struct hostent * hostent = 0;
	hostent = gethostbyname(strDomainName.c_str());
	if(hostent && hostent->h_addr_list)
	{
		int i = 0;
		while(hostent->h_addr_list[i])
		{
			char ip[32] = {0};
			memset(ip, '\0', sizeof(ip));
			memcpy(&ip, inet_ntoa(*((struct in_addr *)hostent->h_addr_list[i])), 20);
			strIpAddr = ip;
			i++;
			break;
		}
		if(i > 0)
		{
			struct sockaddr_in serverAdd;

			memset(&serverAdd, 0, sizeof(serverAdd));
			serverAdd.sin_family = AF_INET;
			serverAdd.sin_addr.s_addr = inet_addr(strIpAddr.c_str());
			serverAdd.sin_port = htons(nPort);

			int s = socket(AF_INET, SOCK_STREAM, 0);
			//3 seconds timeout
			struct timeval timeval = {3, 0};

			setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, &timeval, sizeof(timeval));
			result = connect(s, (struct sockaddr *)&serverAdd, sizeof(serverAdd));
			if (result == 0) {
				result = true;
			}
			else {
				result = false;
			}
			close(s);
		}
	}

	return result;
}

std::string ReadXmlValue(std::string strFileName, std::string strPattern)
{
	std::smatch match;
	std::string words;
	long lFileSize = 0;
	std::string strData;
	std::string result = "";
	std::regex pattern(strPattern.c_str());
	FILE * pf = fopen(strFileName.c_str(), "rb");

	//FILE * pf = fopen("D:\\A\\system_config_prefs.xml", "rb");
	if (pf)
	{
		fseek(pf, 0, SEEK_END);
		lFileSize = ftell(pf);
		//LOGD("PPSHUAI_DEBUG", "filesize=%d", lFileSize);
		if (lFileSize > 0)
		{
			//LOGD("PPSHUAI_DEBUG", "%s", strFileName.c_str());
			fseek(pf, 0, SEEK_SET);
			strData.resize(lFileSize, '\0');
			fread((void *)strData.c_str(), strData.size(), 1, pf);
			//strData = UnicodeToANSI(UTF8ToUnicode(strData));
			words = strData;
			words = std::regex_replace(words, std::regex("\n"), std::string(""));
			words = std::regex_replace(words, std::regex("\r"), std::string(""));
			//LOGD("PPSHUAI_DEBUG", "content:%s", words.c_str());
			while (regex_search(words, match, pattern)) {
				//smatch中结构
				//	0 -- , 匹配原始字符串
				//	1 -- $1, 匹配到的参数一
				//	2 -- $2, 匹配到的参数二
				//for (auto x = match.begin(); x != match.end(); x++)
				//	cout << x->str().c_str() << endl;
				printf("%s\n", match.format("$1").c_str());
				//LOGD("PPSHUAI_DEBUG", "%s", match.format("$1").c_str());
				result = match.format("$1");

				words = match.suffix().str();
			}
		}
		fclose(pf);
	} else
	{
		LOGD("PPSHUAI_DEBUG", "%s文件不存在", strFileName.c_str());
	}
	return result;
}

int util_exec(std::string strCmd)
{
	pid_t pid = (-1);

	/*  Fork off the parent process */
	pid = fork();
	if (pid < 0) {
		goto __LEAVE_CLEAN__;
	}

	if (pid > 0) {
		goto __LEAVE_CLEAN__;
	}

	//execl("/system/bin/sh", "sh", "-c", strCmd.c_str(), NULL);

	execl("/system/bin/sh", "sh", "-c", strCmd.c_str(), NULL);
	pid = 1;

__LEAVE_CLEAN__:

	return pid;
}

int util_execfile(std::string strCmd)
{
	unsigned int premission = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH;
	struct stat st = {0};
	stat(strCmd.c_str(), &st);
	if(st.st_mode&premission == premission)
	{
		return (0);
	}
	return util_exec(std::string(std::string("su root chmod -R 777 ") + strCmd.c_str()).c_str());
}
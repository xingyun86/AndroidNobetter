#include "curl_helper.h"

//////////////////////////////////////////////////////////////////////
//函数功能:传入URL和要保存的文件名称下载文件
//函数参数:
//		strSavePathFileName	要保存的文件路径名
//		strDownloadURL			下载地址URL
//		strPostFields			发送的POST域数据
//		strHeaderData			要发送的头部数据字符串数组(\r\n为分隔符)
//		nDelayTime				超时设置，默认为60秒
//返回值:
//		0, 成功
//		-1,curl访问URL失败
//		-2,curl初始化失败
//		-3,创建或打开文件失败
int curl_http_get_file(string strSavePathFileName, string strDownloadURL, string strPostFields/* = ""*/, string strHeaderData/* = ""*/, int nDelayTime /*= 60*/)
{
	int result = 0;//成功返回0
	CURLcode curlCode = CURLE_OK;
	FILE * pFile = 0;
	CURL * pCurl = nullptr;
	curl_slist *plist = nullptr;

	pFile = fopen(strSavePathFileName.c_str(), "wb");
	if (pFile)
	{
		curlCode = curl_global_init(CURL_GLOBAL_DEFAULT);

		pCurl = curl_easy_init();
		if (pCurl)
		{
			//设置头部数据
			if (strHeaderData.length() > 0)
			{
				plist = curl_slist_append(plist, strHeaderData.c_str());
				curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);
			}

			// write to this file
			curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, pFile);
			curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, nDelayTime);

			// Now specify the POST data
			//设置头部数据
			if (strPostFields.length() > 0)
			{
				//strPostFields = encrypt_ecb(strPostFields);
				//printf("%ws\r\n加密结果:%s\r\n", wstrPostFields.c_str(), strPostFields.c_str());

				curl_easy_setopt(pCurl, CURLOPT_POST, 0L);
				curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strPostFields.c_str());
			}
			curl_easy_setopt(pCurl, CURLOPT_URL, strDownloadURL.c_str());
			curlCode = curl_easy_perform(pCurl);

			if (curlCode != CURLE_OK)
			{
				result = -1;//curl访问网页失败
			}
			curl_easy_cleanup(pCurl);
		}
		else
		{
			result = -2;//curl初始化失败
		}
		curl_global_cleanup();

		fclose(pFile);
		pFile = nullptr;
	}
	else
	{
		result = -3;//创建或打开文件失败
	}

	return result;
}
//curl 回调处理返回数据函数
size_t write_data(void * buffer, size_t size, size_t nmenb, void * lpvoid)
{
	string * str = dynamic_cast<string *>((string*)lpvoid);
	if (nullptr == str || nullptr == buffer) {
		return -1;
	}
	char * pData = (char *)buffer;
	str->append(pData, size*nmenb);
	return nmenb;
}
//////////////////////////////////////////////////////////////////////
//函数功能:传入URL获取JSON字符串
//函数参数:
//		strJsonData		返回的JSON数据字符串
//		strDownloadURL	下载地址URL
//		strPostFields	发送的POST域数据
//		strHeaderData	要发送的头部数据字符串数组(\r\n为分隔符)
//		nDelayTime		超时设置，默认为60秒
//返回值:
//		0, 成功
//		-1,curl初始化失败
//		-2,curl访问URL失败
int curl_http_get_data(string & strJsonData, string strDownloadURL, string strPostFields/* = ""*/, string strHeaderData/* = ""*/, int nDelayTime/* = 60*/)
{
	int result = 0;//成功返回0
	CURLcode curlCode = CURLE_OK;
	CURL * pCurl = nullptr;
	curl_slist *plist = nullptr;

	curlCode = curl_global_init(CURL_GLOBAL_DEFAULT);

	pCurl = curl_easy_init();
	if (pCurl)
	{
		//设置头部数据
		if (strHeaderData.length() > 0)
		{
			plist = curl_slist_append(plist, strHeaderData.c_str());
			curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);
		}

		curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, write_data);//调用处理函数
		curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, (void *)&strJsonData);//返回的数据，这里可以加个函数指针

		curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, nDelayTime);

		// Now specify the POST data
		//设置头部数据
		if (strPostFields.length() > 0)
		{
			//strPostFields = encrypt_ecb(strPostFields);
			//printf("%ws\r\n加密结果:%s\r\n", wstrPostFields.c_str(), strPostFields.c_str());

			curl_easy_setopt(pCurl, CURLOPT_POST, 0L);
			curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strPostFields.c_str());
		}

		curl_easy_setopt(pCurl, CURLOPT_URL, strDownloadURL.c_str());
		curlCode = curl_easy_perform(pCurl);

		if (curlCode != CURLE_OK)
		{
			result = -1;//curl访问网页失败
		}
		curl_easy_cleanup(pCurl);
	}
	else
	{
		result = -2;//curl初始化失败
	}
	curl_global_cleanup();

	return result;
}

//////////////////////////////////////////////////////////////////////
//函数功能:POST方法传入URL及参数获取JSON字符串
//函数参数:
//		strJsonData		返回的JSON数据字符串
//		strDownloadURL	下载地址URL
//		strPostFields	发送的POST域数据
//		strHeaderData	要发送的头部数据字符串数组(\r\n为分隔符)
//		nDelayTime		超时设置，默认为60秒
//返回值:
//		0, 成功
//		-1,curl初始化失败
//		-2,curl访问URL失败
int curl_http_post_data(string & strJsonData, string strDownloadURL, string strPostFields/* = ""*/, string strHeaderData/* = ""*/, int nDelayTime/* = 60*/)
{
	int result = 0;//成功返回0
	CURLcode curlCode = CURLE_OK;
	CURL * pCurl = nullptr;
	curl_slist *plist = nullptr;

	curlCode = curl_global_init(CURL_GLOBAL_DEFAULT);

	pCurl = curl_easy_init();
	if (pCurl)
	{
		//设置头部数据
		if (strHeaderData.length() > 0)
		{
			plist = curl_slist_append(plist, strHeaderData.c_str());
			curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);
		}
		curl_easy_setopt(pCurl, CURLOPT_FORBID_REUSE, 1L);
		curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1L);

		curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, write_data);//调用处理函数
		curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, (void *)&strJsonData);//返回的数据，这里可以加个函数指针

		curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, nDelayTime);

		curl_easy_setopt(pCurl, CURLOPT_POST, 1L);
		// Now specify the POST data
		//设置POST数据
		if (strPostFields.length() > 0)
		{
			strPostFields = encrypt_ecb(strPostFields);
			//printf("%ws\r\n加密结果:%s\r\n", wstrPostFields.c_str(), strPostFields.c_str());
			curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strPostFields.c_str());
		}

		curl_easy_setopt(pCurl, CURLOPT_URL, strDownloadURL.c_str());
		curlCode = curl_easy_perform(pCurl);

		if (curlCode != CURLE_OK)
		{
			result = -1;//curl访问网页失败
		}
		curl_easy_cleanup(pCurl);
	}
	else
	{
		result = -2;//curl初始化失败
	}
	curl_global_cleanup();

	return result;
}

CURL * initCurl()
{
	curl_global_init(CURL_GLOBAL_DEFAULT);
	return curl_easy_init();
}

void exitCurl(CURL * pCurl)
{
	curl_easy_cleanup(pCurl);
	curl_global_cleanup();
}

//////////////////////////////////////////////////////////////////////
//函数功能:POST方法传入URL及参数获取JSON字符串
//函数参数:
//		strJsonData		返回的JSON数据字符串
//		strDownloadURL	下载地址URL
//		strPostFields	发送的POST域数据
//		strHeaderData	要发送的头部数据字符串数组(\r\n为分隔符)
//		nDelayTime		超时设置，默认为60秒
//返回值:
//		0, 成功
//		-1,curl初始化失败
//		-2,curl访问URL失败
int curl_http_post_data(CURL * pCurl, string & strJsonData, string strDownloadURL, string strPostFields/* = ""*/, string strHeaderData/* = ""*/, int nDelayTime/* = 60*/)
{
	int result = 0;//成功返回0
	CURLcode curlCode = CURLE_OK;
	curl_slist *plist = nullptr;

	if (pCurl)
	{
		//设置头部数据
		if (strHeaderData.length() > 0)
		{
			plist = curl_slist_append(plist, strHeaderData.c_str());
			curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);
		}
		//curl_easy_setopt(pCurl, CURLOPT_FORBID_REUSE, 1L);
		//curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1L);

		curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, write_data);//调用处理掉函数
		curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, (void *)&strJsonData);//返回的数据，这里可以加个函数指针

		curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, nDelayTime);

		curl_easy_setopt(pCurl, CURLOPT_POST, 1L);
		// Now specify the POST data
		//设置POST数据
		if (strPostFields.length() > 0)
		{
			strPostFields = encrypt_ecb(strPostFields);
			//printf("%ws\r\n加密结果:%s\r\n", wstrPostFields.c_str(), strPostFields.c_str());
			curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, strPostFields.c_str());
		}

		curl_easy_setopt(pCurl, CURLOPT_URL, strDownloadURL.c_str());
		curlCode = curl_easy_perform(pCurl);

		if (curlCode != CURLE_OK)
		{
			result = -1;//curl访问网页失败
		}
	}
	else
	{
		result = -2;//curl初始化失败
	}

	return result;
}
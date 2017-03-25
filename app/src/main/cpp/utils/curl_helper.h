
#include <iostream>
using namespace std;
#include <curl/curl.h>
#include "crypt_helper.h"

//////////////////////////////////////////////////////////////////////
//函数功能:传入URL和要保存的文件名称下载文件
//函数参数:
//		strDownloadURL			下载地址URL
//		strSavePathFileName	要保存的文件路径名
//		nDelayTime				超时设置，默认为60秒
//返回值:
//		0, 成功
//		-1,curl访问URL失败
//		-2,curl初始化失败
//		-3,创建或打开文件失败
int curl_http_get_file(string strSavePathFileName, string strDownloadURL, string strPostFields = "", string strHeaderData = "", int nDelayTime = 60);

//////////////////////////////////////////////////////////////////////
//函数功能:GET方法传入URL获取JSON字符串
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
int curl_http_get_data(string & strJsonData, string strDownloadURL, string strPostFields = "", string strHeaderData = "", int nDelayTime = 60);

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
int curl_http_post_data(string & strJsonData, string strDownloadURL, string strPostFields = "", string strHeaderData = "", int nDelayTime = 60);

CURL * initCurl();
void exitCurl(CURL *pCurl);
int curl_http_post_data(CURL *pCurl, string & strJsonData, string strDownloadURL, string strPostFields = "", string strHeaderData = "", int nDelayTime = 60);

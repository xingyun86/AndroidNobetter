#ifndef ___UTILS_H___
#define ___UTILS_H___

#include <jni.h>

// 引入log头文件
#include  <android/log.h>
#include <json/json.h>
#include <errno.h>
#include <unistd.h>
#include <string>
#include <regex>
#include <sys/stat.h>

// 定义info信息
#define LOGI(TAG, ...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 定义debug信息
#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
// 定义error信息
#define LOGE(TAG, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
// 定义warning信息
#define LOGW(TAG, ...) __android_log_print(ANDROID_LOG_WARNING,TAG,__VA_ARGS__)
// 定义verbose信息
#define LOGV(TAG, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,__VA_ARGS__)

#include <string>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//获取网络状态
bool access_network(std::string strDomainName, int nPort);
std::string ReadXmlValue(std::string strFileName, std::string strPattern);
int util_exec(std::string strCmd);
int util_execfile(std::string strCmd);

#endif // ___UTILS_H___


#include "utils/utils.h"
#include "utils/curl_helper.h"
#include "utils/img_conv.h"
#include "utils/base64.h"
#include "utils/mobile.h"

extern "C"{
//static CURL  * pCurl = initCurl();
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    CURL  * pCurl = initCurl();
    FILE * pf = fopen("/storage/emulated/0/Tencent/MicroMsg/b89f2e4705d9abe7538e274dcdaa130d/image2/e1/d2/th_e1d27bed8d31cc084f09b07632e31727", "rb");
    if(pf)
    {
        string strImageData;
        fseek(pf, 0, SEEK_END);
        long lFileLength = ftell(pf);
        LOGD("PPSHUAI_DEBUG", "ppshuai read img file size: %d\n", lFileLength);
        if(lFileLength > 0)
        {
            fseek(pf, 0, SEEK_SET);
            strImageData.resize(lFileLength, '\0');
            fread((void *)strImageData.c_str(), lFileLength, 1, pf);
        }
        fclose(pf);
        std::string strBase64 = Base64::base64Encode((unsigned char const *)strImageData.c_str(), (unsigned int)strImageData.length());
        LOGD("PPSHUAI_DEBUG", "ppshuai read img data: %s\n", strBase64.c_str());
    }
    LOGD("DEBUG", "enter jni!!!!!!");
    std::string hello = "Hello from C++";
    string strData = "AAA";
    curl_http_get_data(strData, "http://192.168.1.30/wxmsg");
    LOGD("DEBUG", "ppshuai data: %s\n", strData.c_str());

    string strJsonData;
    string strDownLoadUrl = "http://192.168.1.30/wxmsg";
    string strPostFields = "{\"message\":\"撒旦发\",\"receive_alias\":\"\",\"send\":\"wxid_knot9kldi4qm22\",\"this_wx\":\"wxid_knot9kldi4qm22\",\"alias\":\"\",\"device\":\"867826022413298\",\"msg_id\":\"6247022675505186877\",\"create_at\":\"1487842223000\",\"send_alias\":\"\",\"type\":\"text\",\"receive\":\"wxid_34303t9wzkbm21\",\"isPC\":\"\"}";
    string strHeaderData = MDString((char *)strPostFields.c_str());
    curl_http_post_data(pCurl, strJsonData, strDownLoadUrl, strPostFields, strHeaderData);
    LOGD("DEBUG", "ppshuai data: %s\n", strJsonData.c_str());

    LOGD("DEBUG", "leave jni!!!!!!");
    exitCurl(pCurl);
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_MainActivity_TestSendImageData(
        JNIEnv *env,
        jobject /* this */) {
    FILE * pf = fopen("/sdcard/123.png", "rb");
    if(pf)
    {
        string strImageData;
        fseek(pf, 0, SEEK_END);
        long lFileLength = ftell(pf);
        LOGD("PPSHUAI_DEBUG", "ppshuai read img file size: %d\n", lFileLength);
        if(lFileLength > 0)
        {
            fseek(pf, 0, SEEK_SET);
            strImageData.resize(lFileLength, '\0');
            fread((void *)strImageData.c_str(), lFileLength, 1, pf);
        }
        fclose(pf);
        std::string strBase64 = Base64::base64Encode((unsigned char const *)strImageData.c_str(), (unsigned int)strImageData.length());
        LOGD("PPSHUAI_DEBUG", "ppshuai read img data: %s\n", strBase64.c_str());
    }
    LOGD("DEBUG", "enter jni!!!!!!");
    std::string hello = "Hello from C++";
    string strData = "AAA";
    curl_http_get_data(strData, "http://192.168.1.30/wxmsg");
    LOGD("DEBUG", "ppshuai data: %s\n", strData.c_str());

    string strJsonData;
    string strDownLoadUrl = "http://192.168.1.30/media_img";
    string strPostFields = "";//"{\"message\":\"撒旦发\",\"receive_alias\":\"\",\"send\":\"wxid_knot9kldi4qm22\",\"this_wx\":\"wxid_knot9kldi4qm22\",\"alias\":\"\",\"device\":\"867826022413298\",\"msg_id\":\"6247022675505186877\",\"create_at\":\"1487842223000\",\"send_alias\":\"\",\"type\":\"text\",\"receive\":\"wxid_34303t9wzkbm21\",\"isPC\":\"\",\"block_data\":\"123333333\",\"block_num\":\"1\",\"block_total\":\"2\",\"file_name\":\"123.png\",\"file_path\":\"\"}";
    string strHeaderData = "Content-Type: application/x-www-form-urlencoded;charset=utf-8";//MDString((char *)strPostFields.c_str());
    //curl_http_post_data(pCurl, strJsonData, strDownLoadUrl, strPostFields, strHeaderData);
    //LOGD("DEBUG", "ppshuai data: %s\n", strJsonData.c_str());

    long lFileSize = 0;
    long lBlockNum = 0;
#define UNIT_SIZE 100 * 1024
    long lBlockSize = UNIT_SIZE;
    char szBlockData[UNIT_SIZE] = {0};

    {
        CURL  * pCurl = initCurl();
        FILE * pf  = fopen("/sdcard/123.png", "rb");
        if (pf)
        {
            fseek(pf, 0, SEEK_END);
            lFileSize = ftell(pf);
            fseek(pf, 0, SEEK_SET);
            lBlockSize = fread(szBlockData, 1, UNIT_SIZE, pf);
            string strBase64 = Base64::base64Encode((unsigned char const *)szBlockData, lBlockSize);

            strPostFields = "{\"message\":\"撒旦发\",\"receive_alias\":\"\",\"send\":\"wxid_knot9kldi4qm22\",\"this_wx\":\"wxid_knot9kldi4qm22\",\"alias\":\"\",\"device\":\"867826022413298\",\"msg_id\":\"6247022675505186877\",\"create_at\":\"1487842223000\",\"send_alias\":\"\",\"type\":\"text\",\"receive\":\"wxid_34303t9wzkbm21\",\"isPC\":\"\",\"block_data\":\"" + strBase64 + "\",\"block_num\":\"1\",\"block_total\":\"2\",\"file_name\":\"123.png\",\"file_path\":\"\"}";
            strHeaderData = "Content-Type: application/x-www-form-urlencoded;charset=utf-8";//MDString((char *)strPostFields.c_str());
            curl_http_post_data(pCurl, strJsonData, strDownLoadUrl, strPostFields, strHeaderData);

            LOGD("DEBUG", "ppshuai data: %s\n", strJsonData.c_str());
            Json::Reader reader;
            Json::Value value;
            if(reader.parse(strJsonData.c_str(), value))
            {
                lBlockSize = fread(szBlockData, 1, lFileSize - UNIT_SIZE, pf);
                LOGD("DEBUG", "ppshuai send data size:%d-%d\n", lFileSize, lBlockSize);
                strBase64 = Base64::base64Encode((unsigned char const *)szBlockData, lBlockSize);
                LOGD("DEBUG", "ppshuai send data strBase64: %s\n", strBase64.c_str());
                string strFileName = value["file_name"].asString();
                LOGD("DEBUG", "ppshuai recv data file_name: %s\n", strFileName.c_str());
                string strFilePath = value["file_path"].asString();
                LOGD("DEBUG", "ppshuai recv data file_path: %s\n", strFilePath.c_str());
                strPostFields = "{\"message\":\"撒旦发\",\"receive_alias\":\"\",\"send\":\"wxid_knot9kldi4qm22\",\"this_wx\":\"wxid_knot9kldi4qm22\",\"alias\":\"\",\"device\":\"867826022413298\",\"msg_id\":\"6247022675505186877\",\"create_at\":\"1487842223000\",\"send_alias\":\"\",\"type\":\"text\",\"receive\":\"wxid_34303t9wzkbm21\",\"isPC\":\"\",\"block_data\":\"" + strBase64 + "\",\"block_num\":\"2\",\"block_total\":\"2\",\"file_name\":\""+strFileName+"\",\"file_path\":\""+strFilePath+"\"}";
                LOGD("DEBUG", "ppshuai post data: %s\n", strPostFields.c_str());
                strHeaderData = "Content-Type: application/x-www-form-urlencoded;charset=utf-8";//MDString((char *)strPostFields.c_str());

                LOGD("DEBUG", "ppshuai data: %s,%s,%s\n", strJsonData.c_str(), strDownLoadUrl.c_str(),strHeaderData.c_str());
                string strJsonData11 = "";
                curl_http_post_data(pCurl, strJsonData11, strDownLoadUrl, strPostFields, strHeaderData);
                LOGD("DEBUG", "ppshuai data: %s\n", strJsonData11.c_str());
            }

            fclose(pf);
            exitCurl(pCurl);
        }
    }



    LOGD("DEBUG", "leave jni!!!!!!");

    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_SendImageData(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_request_url,
        jstring jstr_msg_json) {
    LOGD("PPSHUAI_DEBUG", "Enter jni!!!!!!");
    string str_request_url;
    string str_msg_json;
    jboolean bIsCopy = false;
    const char *strRequestUrl = env->GetStringUTFChars(jstr_request_url, &bIsCopy);//注释1
    if(strRequestUrl == NULL)
    {//注释2
        return NULL;
    }
    str_request_url = strRequestUrl;
    env->ReleaseStringUTFChars(jstr_request_url, strRequestUrl);//注释3
    const char *strMsgJson = env->GetStringUTFChars(jstr_msg_json, &bIsCopy);//注释1
    if(strMsgJson == NULL)
    {//注释2
        return NULL;
    }
    str_msg_json = strMsgJson;
    env->ReleaseStringUTFChars(jstr_msg_json, strMsgJson);//注释3

    LOGD("PPSHUAI_DEBUG", "Params(%s,%s)\n", str_request_url.c_str(), str_msg_json.c_str());
    string strJsonData;
    string strPostFields;
    string strHeaderData;

    //解析JSON格式
    Json::Reader reader;
    Json::Value value;

    if (str_msg_json.length() && reader.parse(str_msg_json.c_str(), value))
    {
        long lFileLength = 0;
        string strImgBase64Data = "";
        std::string strImageData = "";
        //判断是否有原始图像
        std::string strOriginImagePath = value["data"].asString();
        //判断是否有缩略图像
        std::string strThumbImagePath = value["message"].asString();
        std::string strImagePath = strOriginImagePath.length() > 0 ? strOriginImagePath : strThumbImagePath;
        //LOGD("PPSHUAI_DEBUG", "Open image path=%s\n", strImagePath.c_str());
        FILE * pf = fopen(strImagePath.c_str(), "rb");
        if(pf)
        {
            fseek(pf, 0, SEEK_END);
            lFileLength = ftell(pf);
            //LOGD("PPSHUAI_DEBUG", "ppshuai read img file size: %d\n", lFileLength);
            if(lFileLength > 0)
            {
                fseek(pf, 0, SEEK_SET);
                strImageData.resize(lFileLength, '\0');
                fread((void *)strImageData.c_str(), lFileLength, 1, pf);
            }
            fclose(pf);

            value["data"] = Base64::base64Encode((unsigned char const *)strImageData.c_str(), (unsigned int)strImageData.length());
            //LOGD("PPSHUAI_DEBUG", "ppshuai read img data: %s\n", strerror(errno));
        }
        //LOGD("PPSHUAI_DEBUG", "ppshuai read img data: %s\n", strerror(errno));
    }
    CURL  * pCurl = initCurl();
    strPostFields = value.toStyledString();
    //LOGD("PPSHUAI_DEBUG", "ppshuai send data: %s\n", strPostFields.c_str());
    curl_http_post_data(pCurl, strJsonData, str_request_url, strPostFields, MDString((char *)strPostFields.c_str()));
    LOGD("PPSHUAI_DEBUG", "ppshuai recv data: %s\n", strJsonData.c_str());
    LOGD("PPSHUAI_DEBUG", "leave jni!!!!!!");
    exitCurl(pCurl);
    return env->NewStringUTF(strJsonData.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_UploadData(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_request_url,
        jstring jstr_msg_json) {
    LOGD("PPSHUAI_DEBUG", "Enter jni!!!!!!");
    string str_request_url = "";
    string str_msg_json = "";
    string strJsonData = "";
    string strPostFields = "";
    string strHeaderData = "";
    long lFileLength = 0;
    string strImgBase64Data = "";
    std::string strImageData = "";
    //判断是否有原始图像
    std::string strOriginImagePath = "";
    //判断是否有缩略图像
    std::string strThumbImagePath = "";
    std::string strImagePath = "";

    //解析JSON格式
    Json::Reader reader;
    Json::Value value;

    FILE * pf = 0;
    CURL  * pCurl = 0;

    jboolean bIsCopy = false;
    const char * strRequestUrl = (char *)env->GetStringUTFChars(jstr_request_url, &bIsCopy);
    const char * strMsgJson = (char *)env->GetStringUTFChars(jstr_msg_json, &bIsCopy);
    if(strRequestUrl == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_request_url = strRequestUrl;
    env->ReleaseStringUTFChars(jstr_request_url, strRequestUrl);

    if(strMsgJson == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_msg_json = strMsgJson;
    env->ReleaseStringUTFChars(jstr_msg_json, strMsgJson);

    LOGD("PPSHUAI_DEBUG", "Params(%s,%s)\n", str_request_url.c_str(), str_msg_json.c_str());

    if (str_msg_json.length() && reader.parse(str_msg_json.c_str(), value))
    {
        //判断是否有原始图像
        strOriginImagePath = value["data"].asString();
        //判断是否有缩略图像
        strThumbImagePath = value["message"].asString();
        strImagePath = strOriginImagePath.length() > 0 ? strOriginImagePath : strThumbImagePath;
        pf = fopen(strImagePath.c_str(), "rb");
        if(pf)
        {
            fseek(pf, 0, SEEK_END);
            lFileLength = ftell(pf);

            if(lFileLength > 0)
            {
                fseek(pf, 0, SEEK_SET);
                strImageData.resize(lFileLength, '\0');
                fread((void *)strImageData.c_str(), lFileLength, 1, pf);
            }
            fclose(pf);

            value["data"] = Base64::base64Encode((unsigned char const *)strImageData.c_str(), (unsigned int)strImageData.length());
        }
    }
    pCurl = initCurl();
    if(!pCurl)
    {
        strJsonData = "{\"message\":\"Curl初始化错误\",\"errCode\":3}";
        goto __LEAVE_CLEAN__;
    }
    strPostFields = value.toStyledString();
    curl_http_post_data(pCurl, strJsonData, str_request_url, strPostFields, MDString((char *)strPostFields.c_str()));
    LOGD("PPSHUAI_DEBUG", "ppshuai recv data: %s\n", strJsonData.c_str());

    __LEAVE_CLEAN__:

    LOGD("PPSHUAI_DEBUG", "leave jni!!!!!!");
    if(pCurl)
    {
        exitCurl(pCurl);
    }
    return env->NewStringUTF(strJsonData.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_UploadMsgData(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_request_url,
        jstring jstr_msg_json) {

    LOGD("PPSHUAI_DEBUG", "Enter jni!!!!!!");
    string str_request_url = "";
    string str_msg_json = "";
    string strJsonData = "";
    string strPostFields = "";
    string strHeaderData = "";

    CURL  * pCurl = 0;

    jboolean bIsCopy = false;
    const char * strRequestUrl = (char *)env->GetStringUTFChars(jstr_request_url, &bIsCopy);
    const char * strMsgJson = (char *)env->GetStringUTFChars(jstr_msg_json, &bIsCopy);
    if(strRequestUrl == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_request_url = strRequestUrl;
    env->ReleaseStringUTFChars(jstr_request_url, strRequestUrl);

    if(strMsgJson == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_msg_json = strMsgJson;
    env->ReleaseStringUTFChars(jstr_msg_json, strMsgJson);

    LOGD("PPSHUAI_DEBUG", "Params(%s,%s)\n", str_request_url.c_str(), str_msg_json.c_str());

    pCurl = initCurl();
    if(!pCurl)
    {
        strJsonData = "{\"message\":\"Curl初始化错误\",\"errCode\":3}";
        goto __LEAVE_CLEAN__;
    }

    strHeaderData = "Content-Type: application/x-www-form-urlencoded;charset=utf-8";
    curl_http_post_data(pCurl, strJsonData, str_request_url, strPostFields, strHeaderData);
    LOGD("PPSHUAI_DEBUG", "ppshuai recv data: %s\n", strJsonData.c_str());

    __LEAVE_CLEAN__:

    LOGD("PPSHUAI_DEBUG", "leave jni!!!!!!");
    if(pCurl)
    {
        exitCurl(pCurl);
    }

    return env->NewStringUTF(strJsonData.c_str());
}
JNIEXPORT jboolean JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_CheckNetworkState(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_host_name,
        jint jint_port)
{
    jboolean result = false;
    jboolean bIsCopy = false;
    int nPort = jint_port;
    const char *strHostName = env->GetStringUTFChars(jstr_host_name, &bIsCopy);//注释1
    if(strHostName != NULL && nPort > 0 && nPort < 65535)
    {
        result = access_network(strHostName, nPort);
    }
    return result;
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_UploadLargeData(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_request_url,
        jstring jstr_msg_json,
        jint jint_unit_size,
        jint jint_delay_time) {

#define DEFS_UNIT_SIZE 512 * 1024
#define DEFS_DELAY_TIME 500 //默认间隔500ms

    LOGD("PPSHUAI_DEBUG", "Enter jni!!!!!!");
    string str_request_url = "";
    string str_msg_json = "";
    string strJsonData = "";
    string strPostFields = "";
    string strHeaderData = "";
    //解析JSON格式
    Json::Reader reader;
    Json::Value value;
    Json::Reader readerResult;
    Json::Value valueResult;
    long lIndex = 0;
    long lReadSize = 0;
    long lFileLength = 0;
    long lBlockCount = 0;
    char cBlockInfos[128] = {0};
    std::string strFileName = "";
    std::string strFilePath = "";
    std::string strBase64Data = "";
    CURL  * pCurl = 0;
    FILE * pf = 0;
    std::string strData = "";
    std::string strImagePath = "";
    std::string strOriginImagePath = "";
    std::string strThumbImagePath = "";

    jboolean bIsCopy = false;
    int n_unit_size = jint_unit_size <= 0 ? DEFS_UNIT_SIZE : jint_unit_size;
    int n_delay_time = jint_delay_time <= 0 ? DEFS_DELAY_TIME : jint_delay_time;
    const char * strRequestUrl = (char *)env->GetStringUTFChars(jstr_request_url, &bIsCopy);
    const char * strMsgJson = (char *)env->GetStringUTFChars(jstr_msg_json, &bIsCopy);
    if(strRequestUrl == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_request_url = strRequestUrl;
    env->ReleaseStringUTFChars(jstr_request_url, strRequestUrl);

    if(strMsgJson == NULL)
    {
        strJsonData = "{\"message\":\"传入参数错误\",\"errCode\":2}";
        goto __LEAVE_CLEAN__;
    }
    str_msg_json = strMsgJson;
    env->ReleaseStringUTFChars(jstr_msg_json, strMsgJson);

    LOGD("PPSHUAI_DEBUG", "Params(%s,%s)\n", str_request_url.c_str(), str_msg_json.c_str());

    if (str_msg_json.length() && reader.parse(str_msg_json.c_str(), value))
    {
        strHeaderData = "Content-Type: application/x-www-form-urlencoded;charset=utf-8";
        strData.resize(n_unit_size, '\0');
        //判断是否有原始图像
        strOriginImagePath = value["data"].asString();
        //判断是否有缩略图像
        strThumbImagePath = value["message"].asString();
        strImagePath = strOriginImagePath.length() > 0 ? strOriginImagePath : strThumbImagePath;

        if(pf = fopen(strImagePath.c_str(), "rb"))
        {
            strFileName = strImagePath.substr(strImagePath.rfind('/') + 1, strImagePath.length() - strImagePath.rfind('/') - 1);

            fseek(pf, 0, SEEK_END);
            lFileLength = ftell(pf);

            pCurl = initCurl();
            if(!pCurl)
            {
                strJsonData = "{\"message\":\"Curl初始化错误\",\"errCode\":3}";
                goto __LEAVE_CLEAN__;
            }
            fseek(pf, 0, SEEK_SET);
            if(lFileLength > n_unit_size)
            {
                lBlockCount = (lFileLength % n_unit_size != 0) ? (lFileLength / n_unit_size + 1) : lFileLength / n_unit_size;
                while((lReadSize = fread((void *)strData.c_str(), 1, n_unit_size, pf)) > 0)
                {
                    lIndex++;
                    strJsonData = "";

                    value["block_data"] = Base64::base64Encode((unsigned char const *)strData.c_str(), lReadSize);
                    memset(cBlockInfos, 0, sizeof(cBlockInfos));
                    sprintf(cBlockInfos, "%d", lIndex);
                    value["block_num"] = cBlockInfos;
                    memset(cBlockInfos, 0, sizeof(cBlockInfos));
                    sprintf(cBlockInfos, "%d", lBlockCount);
                    value["block_total"] = cBlockInfos;
                    value["file_name"] = strFileName;
                    value["file_path"] = strFilePath;

                    strPostFields = value.toStyledString();

                    //Send post request
                    curl_http_post_data(pCurl, strJsonData, str_request_url, strPostFields, strHeaderData);

                    if (strJsonData.length() && readerResult.parse(strJsonData.c_str(), valueResult) && valueResult["errCode"].asInt() == 1)
                    {
                        if(lIndex == 1)
                        {
                            strFileName = valueResult["file_name"].asString();
                            strFilePath = valueResult["file_path"].asString();
                        }

                        //等待n_delay_time * 1000毫秒
                        usleep(n_delay_time * 1000);
                    }
                    else
                    {
                        goto __LEAVE_CLEAN__;
                    }
                }//End while(lReadSize = fread((void *)strData.c_str(), 1, n_unit_size, pf))
            }
            else
            {
                lReadSize = fread((void *)strData.c_str(), 1, n_unit_size, pf);
                lIndex = 1;
                value["block_data"] = Base64::base64Encode((unsigned char const *)strData.c_str(), lReadSize);
                memset(cBlockInfos, 0, sizeof(cBlockInfos));
                sprintf(cBlockInfos, "%d", lIndex);
                value["block_num"] = cBlockInfos;
                memset(cBlockInfos, 0, sizeof(cBlockInfos));
                sprintf(cBlockInfos, "%d", lIndex);
                value["block_total"] = cBlockInfos;
                value["file_name"] = strFileName;
                value["file_path"] = strFilePath;
                strPostFields = value.toStyledString();

                //Send post request
                curl_http_post_data(pCurl, strJsonData, str_request_url, strPostFields, strHeaderData);

                if (strJsonData.length() && readerResult.parse(strJsonData.c_str(), valueResult) && valueResult["errCode"].asInt() == 1)
                {
                    //continue handle
                }
                else
                {
                    goto __LEAVE_CLEAN__;
                }
            }//End if(lFileLength > n_unit_size)
        }
        else
        {
            strJsonData = "{\"message\":\"打开文件失败\",\"errCode\":4}";
        }
    }
    else
    {
        strJsonData = "{\"message\":\"传输参数错误\",\"errCode\":5}";
    }

    __LEAVE_CLEAN__:
    if(pCurl)
    {
        exitCurl(pCurl);
    }
    if(pf)
    {
        fclose(pf);
    }

    LOGD("PPSHUAI_DEBUG", "leave jni!!!!!!");

    return env->NewStringUTF(strJsonData.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_CalculateMD5Value(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_data)
{
    jboolean result = false;
    jboolean bIsCopy = false;
    std:;string strMd5Data = "";
    std::string strMd5Value = "";
    const char *strData = env->GetStringUTFChars(jstr_data, &bIsCopy);//注释1
    if(strData == NULL) {
        return env->NewStringUTF(strMd5Value.c_str());
    }
    strMd5Data = strData;
    env->ReleaseStringUTFChars(jstr_data, strData);//注释3
    strMd5Value = MDString(strMd5Data);

    return env->NewStringUTF(strMd5Value.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_GetAndroidDeviceID(
        JNIEnv *env,
        jobject obj,
        jobject mContext)
{
    return getAndroidDeviceID(env,obj,mContext);
}

JNIEXPORT jstring JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_ReadXmlValue(
        JNIEnv *env,
        jobject /* this */,
        jstring jstr_filename,
        jstring jstr_pattern) {
    jboolean bIsCopy = false;
    std::string strMd5Value = "";
    std::string strFileName = "";
    std::string strPattern = "";
    const char *pFileName = env->GetStringUTFChars(jstr_filename, &bIsCopy);
    const char *pPattern = env->GetStringUTFChars(jstr_pattern, &bIsCopy);
    if(pFileName == NULL)
    {
        return env->NewStringUTF(strFileName.c_str());
    }
    strFileName = pFileName;
    env->ReleaseStringUTFChars(jstr_filename, pFileName);

    if(pPattern == NULL) {
        return env->NewStringUTF(strPattern.c_str());
    }
    strPattern = pPattern;
    env->ReleaseStringUTFChars(jstr_pattern, pPattern);

    __LEAVE_CLEAN__:

    return env->NewStringUTF(ReadXmlValue(strFileName, strPattern).c_str());
}
JNIEXPORT jint JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_Exec(JNIEnv *env, jobject thiz, jstring cmd) {
    const char *cmd_str  = env->GetStringUTFChars(cmd, 0);
    std::string strCmd = "";
    if(cmd_str == NULL)
    {
        return (-1);
    }
    strCmd = cmd_str;
    env->ReleaseStringUTFChars(cmd, cmd_str);

    return util_exec(strCmd);
}

JNIEXPORT jint JNICALL
Java_com_nobetter_ppshuai_androidnobetter_NativeHelper_ExecFile(JNIEnv *env, jobject thiz, jstring cmd) {
    const char *cmd_str  = env->GetStringUTFChars(cmd, 0);
    std::string strCmd = "";
    if(cmd_str == NULL)
    {
        return (-1);
    }
    strCmd = cmd_str;
    env->ReleaseStringUTFChars(cmd, cmd_str);

    return util_execfile(strCmd);
}
}

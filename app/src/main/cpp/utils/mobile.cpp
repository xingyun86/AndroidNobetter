#include <jni.h>

#include <sys/system_properties.h>
#include <stdio.h>

void getAndroidDeviceID_Serial(char *deviceID)//serial number
{
    __system_property_get("ro.serialno",deviceID);
}

//获取AndroidIMEI值
jstring getAndroidDeviceID(JNIEnv *env,
                           jobject /* this */,
                           jobject mContext)
{
    jclass cls_context;
    jmethodID getSystemService;
    jfieldID TELEPHONY_SERVICE;
    jstring strTelephonyService;
    jobject telephonymanager;
    jclass cls_tm;
    jmethodID getDeviceId;
    if(mContext != 0) {

        cls_context = env->FindClass("android/content/Context");
        if (cls_context != 0) {

            getSystemService = env->GetMethodID(cls_context, "getSystemService",
                                                "(Ljava/lang/String;)Ljava/lang/Object;");
            if (getSystemService != 0) {

                TELEPHONY_SERVICE = env->GetStaticFieldID(cls_context, "TELEPHONY_SERVICE",
                                                          "Ljava/lang/String;");
                if (TELEPHONY_SERVICE != 0) {

                    strTelephonyService = (jstring) env->GetStaticObjectField(cls_context,
                                                                              TELEPHONY_SERVICE);
                    telephonymanager = env->CallObjectMethod(mContext, getSystemService,
                                                             strTelephonyService);
                    if (telephonymanager != 0) {

                        cls_tm = env->FindClass("android/telephony/TelephonyManager");
                        if (cls_tm != 0) {

                            getDeviceId = env->GetMethodID(cls_tm, "getDeviceId",
                                                           "()Ljava/lang/String;");
                            if (getDeviceId != 0) {

                                return (jstring) env->CallObjectMethod(telephonymanager,
                                                                       getDeviceId);
                            }
                        }
                    }
                }
            }
        }
    }
    return env->NewStringUTF("");
}

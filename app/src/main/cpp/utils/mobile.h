//
//  Base64.h
//
//  Created by Collin B. Stuart on 2013-10-29.
//
//

#ifndef __MOBILE_H__
#define __MOBILE_H__

#include "utils.h"

#include <stdio.h>
#include <string>

using namespace std;

//serial number
void getAndroidDeviceID_Serial(char *deviceID);

//获取AndroidIMEI值
jstring getAndroidDeviceID(JNIEnv *env,
                           jobject /* this */,
                           jobject mContext);

#endif /* defined(__MOBILE_H__) */

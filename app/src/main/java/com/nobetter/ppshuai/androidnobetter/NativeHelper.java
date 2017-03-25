package com.nobetter.ppshuai.androidnobetter;

import android.content.Context;

/**
 * Created by PPSHUAI on 2017/2/23.
 */

public class NativeHelper {
    // Used to load the 'nativehelper-lib' library on application startup.
    static {
        System.loadLibrary("nativehelper-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    /**
     * A native method that is implemented by the 'nativehelper-lib' native library,
     * which is packaged with this application.
     * nUnitSize ： 分块大小，单位为字节
     * nDelayTime：分块传输间隔，单位为毫秒
     */
    public native String UploadLargeData(String strRequestUrl, String strMsgData, int nUnitSize, int nDelayTime);
    /**
     * A native method that is implemented by the 'nativehelper-lib' native library,
     * which is packaged with this application.
     */
    public native String UploadMsgData(String strRequestUrl, String strMsgData);

    /**
     * A native method that checking network state
     * @param strHostName
     * @param nPort
     * @return
     */
    public native boolean CheckNetworkState(String strHostName, int nPort);

    /**
     * Calculate md5 value
     * @param strData
     * @return
     */
    public native String CalculateMD5Value(String strData);

    /**
     * Get android device id
     * @param context
     * @return
     */
    public native String GetAndroidDeviceID(Context context);

    /**
     * Execute command
     * @param cmd
     * @return
     */
    public native int Exec(String cmd);

    /**
     * Execute command for file permissions
     * @param cmd
     * @return
     */
    public native int ExecFile(String cmd);

    /**
     * Read xml value with pattern
     * @param strFileName
     * @param strPattern
     * @return
     */
    public native String ReadXmlValue(String strFileName, String strPattern);

    /**
     *
     * @return
     */
    public native String TestSendImageData();

    private static NativeHelper ourInstance = new NativeHelper();

    public static NativeHelper getInstance() {
        return ourInstance;
    }

    private NativeHelper() {
    }

}

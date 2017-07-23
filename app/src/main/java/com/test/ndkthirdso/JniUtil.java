package com.test.ndkthirdso;

/**
 * Created by mingfeng on 2017/7/22.
 */

public class JniUtil {
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("third");
    }

    public  static native int add(int x,int y);
}

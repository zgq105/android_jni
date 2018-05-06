package com.guoqiang.androidjni;

/**
 * Created by zgq on 2018/5/6.
 */

public class CCallJavaUtils {

    public static String getTime() {
        return String.valueOf(System.currentTimeMillis());
    }

    public String sayHello(String msg) {
       return  "hello";
    }
}

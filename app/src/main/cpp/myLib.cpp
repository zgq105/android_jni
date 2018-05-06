//
// Created by zgq on 2018/5/5.
//

#include "com_guoqiang_androidjni_JniUtils.h"
#include "ccalljava.h"
#include <string.h>

extern JNIEnv* jniEnv;

//C++中定义映射的类、方法、对象
jclass CCallJavaUtils;
jobject cCallJavaUtils;
jmethodID getTime;
jmethodID sayHello;

//extern "C"{

//jstring getTim(){
//    jstring res= NULL;
//    //获取类引用
//    CCallJavaUtils=jniEnv->FindClass("com/guoqiang/androidjni/CCallJavaUtils");
//    //获取静态方法
//    getTime=jniEnv->GetStaticMethodID(CCallJavaUtils,"getTime","()Ljava/lang/String");
//    //调用静态方法
//    res=(jstring)jniEnv->CallStaticObjectMethod(CCallJavaUtils,getTime);
//    return res;
//}



/*
 * Class:     com_guoqiang_androidjni_JniUtils
 * Method:    doShort
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_guoqiang_androidjni_JniUtils_doShort
        (JNIEnv *, jobject){
    return  2;
}

/*
 * Class:     com_guoqiang_androidjni_JniUtils
 * Method:    doInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_guoqiang_androidjni_JniUtils_doInt__I
        (JNIEnv * jniEnv, jobject jobject1, jint i){
    return  i ;
}


/*
 * Class:     com_guoqiang_androidjni_JniUtils
 * Method:    doString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_guoqiang_androidjni_JniUtils_doString__Ljava_lang_String_2
        (JNIEnv * env, jobject, jstring string){
    const char *strUTF = env->GetStringUTFChars(string, 0);
    char szBuffer[255];
    strcpy(szBuffer, strUTF);
    env->ReleaseStringUTFChars(string, strUTF);
    return env->NewStringUTF(szBuffer);

}

/*
 * Class:     com_guoqiang_androidjni_JniUtils
 * Method:    doInt
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_com_guoqiang_androidjni_JniUtils_doInt___3I
        (JNIEnv * env, jobject, jintArray jintArr){
    int sum=0;
    int count=env->GetArrayLength(jintArr);
    if(count<=0){
        return sum;
    }
    //获取数组指针的引用
    jint *arr=env->GetIntArrayElements(jintArr, 0);
    for (int i=0 ;i<count;i++){
        sum+=arr[i];
    }
    //释放内存
    env->ReleaseIntArrayElements(jintArr,arr,0);
    return sum;
}


//}

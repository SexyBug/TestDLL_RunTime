// TestDLL_RunTime.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "windows.h"
#include <tchar.h>
// 定义一种名为HELLO的函数指针，此函数无参数，返回值为void
typedef void (*HELLO)();

int main()
{
    // DLL句柄
    HINSTANCE hDLL;              
     // 函数指针
    HELLO hello;
    // 加载DLL,注意是以exe所在目录为当前目录，写dll的相对路径,也可写绝对路径,注意路径分隔符格式
    // 必须使用_T进行转换，不能使用LPCWSTR强制转换
    hDLL = LoadLibrary(_T("MyDll.dll"));
    //hDLL = LoadLibrary(_T("C:\\Users\\33658\\Desktop\\TestDLL_RunTime\\Debug\\MyDll.dll"));
    if (hDLL != NULL) {
        // 传入DLL句柄，获得MyAdd函数的地址，然后强转为lpMyAdd类型
        hello = (HELLO)GetProcAddress(hDLL, "hello");
        //或者使用如下写法
        //void (*hello)() = reinterpret_cast<void (*)()>(GetProcAddress(hModule, "hello"));
        if (hello != NULL) {
            hello();
        }
        else {
            std::cout << "cannot find func" << std::endl;
        }
        // 释放
        FreeLibrary(hDLL);
    }
    else {
        std::cout << "cannot load dll" << std::endl;
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

void test1()
{
	qh::string s;
	qh::string s1("uiuiuiui");  //constructor
	assert(s1.size()==8);       // size()
	qh::string s2("uiuiuuii",2);
	assert(s2.size()==2);
	qh::string s3("uiui",10);
	assert(s3.size()==4);
	qh::string s4 = s1;     // = constructor
	assert(s4.size()==8);
	qh::string s5(s1);      //copy constructor
	assert(s5.size()==8);
	const char* c1 = "uiuiuiui";
	const char* c2 = "ui";
	const char* c3 = "uiui";
	char c4 = 'i';
//	cout<<s1.c_str()<<endl;
//	cout<<s2.c_str()<<endl;
//	cout<<s3.c_str()<<endl;
//	cout<<s4.c_str()<<endl;
	assert(strcmp(s1.c_str(),c1)==0);
//	assert(strcmp(s4.c_str(),c1)==0);
	assert(strcmp(s2.c_str(),c2)==0);
	assert(strcmp(s3.c_str(),c3)==0);
	assert(s1[1]==c4);	 // operator []
//	assert(isalpha(s[1]));
//	cout<<s1.size()<<endl;
	assert(s1.size()==8);   
	cout<<"All test1 is OK"<<endl;
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
    test1();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}


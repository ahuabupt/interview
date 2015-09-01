#include <stdlib.h>
#include "qh_vector.h"
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
void test1()       //push_back pop_back size   resize reverse
{
	qh::vector<int> v;
	v.push_back(1);              //push_back
	assert(v[0]==1);
	assert(v.size() == 1);
	v.pop_back();                //pop_back
	assert(v.size() == 0);
	v.push_back(2);
	v.push_back(3);
	assert(v.size() == 2);
	v.resize(1);               //resize
	assert(v.size() == 1);
	v.push_back(5);
	v.push_back(10);
	assert(v.capacity()==4);
	qh::vector<int> v2(10,8);  //constructor
//	cout<<v2.capacity()<<endl;
	assert(v2.capacity()==10);
	assert(v2.size()==10);
	assert(v2[9] == 8);          //operator[]
	v2.push_back(100);           // add size and capacity
	assert(v2.capacity() == 20);  //capacity double
	assert(v2.size()==11);
//	cout<<v2[10]<<endl;
	assert(v2[10] == 100);        
	cout<<"ALL the test1 is OK!"<<endl;
	

}


int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

 //   qh::vector<int> num_vect;
//    num_vect.push_back(1);
      test1();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}


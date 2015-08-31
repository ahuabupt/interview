#include <stdlib.h>
#include "qh_vector.h"
#include <assert.h>
#include <stdio.h>

void test1()       //push_back pop_back size   resize reverse
{
	qh::vector<int> v;
	v.push_back(1);
	printf("%d\n", v.capacity());
	int size1 = v.size();
	assert(size1 == 1);
	int num = 0;
	v.pop_back(num);
	assert(num == 2);
	size1  = v.size();
	assert(size1 == 0);
	v.push_back(2);
	v.push_back(3);
	printf("%d\n", v.capacity());
	num = v[0];
	assert(num == 2);
	v.resize(1);
	assert(size1 == 1);


}

int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

    qh::vector<int> num_vect;
    num_vect.push_back(1);
    test1();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}


//------------------------------------------------------------
// 2023. 4. 6 ��56								(6�� 1��)
//------------------------------------------------------------
// Sequence container - vector
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;
//-------
int main()
//-------
{	
	���� = true;

	vector<String> v;
	v.reserve(10);
	v.emplace_back("123");
	v.emplace_back("abcde");
	v.emplace_back("7890");

	//�޸� �׸����� �׸� �� �ִ�?

	//save("�ҽ�.cpp");
}
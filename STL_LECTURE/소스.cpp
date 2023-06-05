//------------------------------------------------------------
// 2023. 6. 1, ��56                        (14�� 1��)
//------------------------------------------------------------------
// C++20 - 4 major change
// Concept - �Լ��� ���α׷���
// Range - �Լ��� ���α׷���
// Module
// Coroutine
//-----------------------------------------------------------------
#include <iostream>
#include <ranges>
#include <algorithm>
#include <random>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

default_random_engine dre;
uniform_int_distribution uidNum{ 1,100 };
uniform_int_distribution<int> uidC{'A', 'Z'};

struct Dog
{
	int num = uidNum(dre);
	char c = uidC(dre);
};

//-------
int main()
//-------
{
	vector<Dog> dogs(100);
	
	ranges::sort(dogs, {}, &Dog::num);

	for ( auto& [����, ����] : dogs)
	{
		cout << ���� << " - " << ���� << endl;
	}

	save("�ҽ�.cpp");
}

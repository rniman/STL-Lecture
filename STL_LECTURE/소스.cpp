//------------------------------------------------------------
// 2023. 6. 1, 목56                        (14주 1일)
//------------------------------------------------------------------
// C++20 - 4 major change
// Concept - 함수형 프로그램밍
// Range - 함수형 프로그래밍
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
extern bool 관찰;

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

	for ( auto& [숫자, 글자] : dogs)
	{
		cout << 글자 << " - " << 숫자 << endl;
	}

	save("소스.cpp");
}

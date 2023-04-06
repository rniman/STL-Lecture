//------------------------------------------------------------
// 2023. 4. 6 목56								(6주 1일)
//------------------------------------------------------------
// Sequence container - vector
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;
//-------
int main()
//-------
{	
	관찰 = true;

	vector<String> v;
	v.reserve(10);
	v.emplace_back("123");
	v.emplace_back("abcde");
	v.emplace_back("7890");

	//메모리 그림으로 그릴 수 있니?

	//save("소스.cpp");
}
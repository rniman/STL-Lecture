//------------------------------------------------------------
// 2023. 4. 10 월56								(6주 2일)
// 4월 24일 월요일(8주 2일) - 중간시험
//------------------------------------------------------------
// Sequence container - vector
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;
//-------
int main()
//-------
{	
	//noexcept을 선언해 이동생성을 시킨다.

	vector<String> v;
	
	관찰 = true;
	v.push_back("123");
	v.push_back("abc");


	save("소스.cpp");
}
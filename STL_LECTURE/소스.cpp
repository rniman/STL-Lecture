//------------------------------------------------------------
// 2023. 5.22, 월56                        (12주 2일)
// 13주 2일 5. 29 월요일 - 동영상 출석대체
// 15주 2일 6. 12 월요일 - 기말 시험
//------------------------------------------------------------------
// 컨테이너들의 찾기 실력을 검증한다. int 천만개에서 int 만개를 찾는다
// vector
// set
// unordered_set
//-----------------------------------------------------------------
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

array<int, 1000'0000> numbers;
array<int, 10000> toFind;


template<>
struct hash<String>
{
	size_t operator()(const String& str) const
	{
		return hash<string>()(str.getString());
	}
};

//-------
int main()
//-------
{
	unordered_multiset<String, hash<String>> us{ "C++", "STL", "Container", "Iterator", "Algorithm"};

	auto p = us.find("Algorithm");
	cout << *p << endl;
}

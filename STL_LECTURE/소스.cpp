//------------------------------------------------------------
// 2023. 4. 13 목56								(7주 1일)
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
	vector<String> v{ "1", "2", "3", "4", "5" };
	
	// [문제] v에서 "3"을 제거하라
	erase(v, "3");

	for (String& s : v)
	{
		cout << s << ' ';
	}
	cout << endl;

	//save("소스.cpp");
}
//------------------------------------------------------------
// 2023. 5.25, 목56                        (13주 1일)
// 13주 2일 5. 29 월요일 - 동영상 출석대체
// 15주 2일 6. 12 월요일 - 기말 시험
//------------------------------------------------------------------
//
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;
 
template<typename itr, typename pred>
bool my_all_of(itr begin, itr end, pred pr)
{
	itr now = begin;
	while (true)
	{
		if (now == end)
			break;

		if (pr(*now))
			return true;
		now++;
	}

	return false;
}

//-------
int main()
//-------
{
	vector<int> v{1, 3, 5, 7, 9};
	// [문제] v의 원소가 전부 홀수인지 검사한다.
	bool res = my_all_of(v.begin(), v.end(), [](int i) {
		return i & 1;
		});

	cout << boolalpha << "홀수? - " << res << endl;;

	save("소스.cpp");
}

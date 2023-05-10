//------------------------------------------------------------
// 2023. 5. 8 월56								(10주 2일)
//------------------------------------------------------------
// 반복자(iterator) - 포인터를 추상화(=일반화) 한 것이 반복자다
// String을 표준 컨테이너로 -> 반복자를 제공해줘야 
//		begin(), end()
//		rbegin(), rend() -> 반드시 class로 구현해야만 한다
//		반복자 adapter:반복자처럼 행동하는 객체
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

//-------
int main()
//-------
{
	String s{ "The quick brown fox jumps over the lazy dog" };
	string str{ "The quick brown fox jumps over the lazy dog" };

	sort(s.begin(), s.end());
	sort(str.begin(), str.end());

	cout << s << endl;
	cout << str << endl;

	save("소스.cpp");
}

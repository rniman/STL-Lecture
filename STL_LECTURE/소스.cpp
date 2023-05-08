//------------------------------------------------------------
// 2023. 5. 4 목56								(10주 1일)
//------------------------------------------------------------
// 반복자(iterator) - 포인터를 추상화(=일반화) 한 것이 반복자다
// String을 표준 컨테이너로 -> 반복자를 제공해줘야 
//		begin(), end()
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <span>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

//-------
int main()
//-------
{
	String s{ "STL iterators" };

	// [문제] s를 역순으로 출력하라
	// 다음 문장이 그대로 실행되어야 한다.
	// p가 클래스 객체일때만 가능 

	for (auto p = s.rbegin(); p != s.rend(); ++p) // -> p는 반복자 흉내를 내는 반복자 어뎁터
	{
		cout << *p << ' ';
	}
	cout << endl;

	save("소스.cpp");
}

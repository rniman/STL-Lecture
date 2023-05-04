//------------------------------------------------------------
// 2023. 5. 4 목56								(10주 1일)
//------------------------------------------------------------
// 반복자(iterator)
// - 포인터를 추상화(=일반화) 한 것이 반복자다
// - Iterators are a generalization of pointers
// 6가지 종류(category)로 나뉜다.
// - 입력/출력/전진(전방향)/양방향(전후진)/랜덤억세스/컨티구어스 반복자
// 기초동작: *, ++, =
//------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iterator>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

// [문제] 함수 f() 반복자를 인자로 받아 어떤 종류의 반복자인지 화면 출력한다.
// 
// 전달된 인자가 원하는 타입인지 판단하는 - type_traits 
template <class iter>
void f(iter)
{
	cout << typeid(iter).name() << endl;
}

//-------
int main()
//-------
{
	vector<int> v;
	ostream_iterator<char> p{ cout };
	
	f(123);
	f(v.begin());
	f(p);

	save("소스.cpp");
}

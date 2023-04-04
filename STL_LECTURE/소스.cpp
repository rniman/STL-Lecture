//------------------------------------------------------------
// 2023. 4. 3 월56								(5주 2일)
//------------------------------------------------------------
// Sequence container - array
//------------------------------------------------------------
#include <iostream>
#include <array>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;

extern bool 관찰;

//-------
int main()
//-------
{	
	// [문제] 키보드에서 입력한 int를 10개만 array를 사용하여 저장하라.
	// 합계를 화면에 출력하라.
	array<int, 10> a;

	for (int& i : a)
	{
		cin >> i;
	}
	cin.clear();
	
	int sum = *a.begin();
	cout << *a.begin();
	for (auto i = a.begin() + 1; i!= a.end(); ++i)
	{
		cout << " + " << *i;
		sum += *i;
	}
	cout << " = " << sum << endl;

	save("소스.cpp");
}
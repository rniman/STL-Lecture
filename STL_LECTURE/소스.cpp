//------------------------------------------------------------
// 2023. 5.18, 목56                        (12주 1일)
//------------------------------------------------------------------
// Associative 컨테이너 - set/map - 원소의 같음을 equivalence로 평가
// 
// map은 pair<key, value>를 원소로 갖는다
//-----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

//-------
int main()
//-------
{
	// 소설에서 각 문자가 사용된 횟수를 출력하라.

	ifstream in{ "이상한 나라의 앨리스.txt" };

	if (!in)
		return 0;

	map<char, int> cim;


	char c;
	while (in >> c)
	{
		++cim[c];
	}

	//cim['a'] -> 연관배열

	// [문제] 많이 사용된 문자 순으로 출력하라

	for (auto [문자, 개수] : cim)
	{
		cout << 문자 << " - " << 개수 << endl;
	}
	
	//save("소스.cpp");
}

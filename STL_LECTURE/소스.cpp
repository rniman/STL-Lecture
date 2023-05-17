//------------------------------------------------------------
// 2023. 5.15, 월56                        (10주 2일)
//------------------------------------------------------------------
// Associative 컨테이너 - set/map - 원소의 같음을 equivalence로 평가
// 
// set에 정렬기준을 알려주는 방법
// 1. String의 멤버로 operator <를 정의한다. - 길이순
// 2. Struct less를 특수화한다 - 사전식
// 3. 호출가능객체를 직접 전달 - 영문자먼저
//------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <set>   
#include <fstream>
#include <string>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

//-------
int main()
//-------
{

	//"소스.cpp"를 s에 담아보아라.
	ifstream in("이상한 나라의 앨리스.txt");

	set<String> s{ istream_iterator<String>{in}, {} };

	//save("소스.cpp");

	// [문제] 사용자가 입력한 부분단어가 포함된 단어를 모두 출력하라  

	while (true)
	{
		cout << "찾을 단어를 입력:";
		String word;
		cin >> word;

		for (const String& str : s)
		{
			std::boyer
			if (search(str.begin(), str.end(), word.begin(), word.end()))
			{
				cout << str << ' ';
			}
		}
		cout << endl;
	}

}
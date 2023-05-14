//------------------------------------------------------------
// 2023. 5. 11 목56								(11주 1일)
//------------------------------------------------------------
// 
//------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

//-------
int main()
//-------
{
	// "소스.cpp"를 s에 저장

	ifstream in{ "소스.cpp" };

	//set은 길이기준으로 정렬한다고 치면 길이마다 하나를 저장한다
	//set<String> s{ istream_iterator<String>{in},{} };
	multiset<String> s{ istream_iterator<String>{in},{} };

	for (const String& s : s)
		cout << s << endl;

	save("소스.cpp");
}

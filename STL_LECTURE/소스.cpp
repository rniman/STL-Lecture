//------------------------------------------------------------
// 2023 STL 총정리 실습 - 애너그램 찾기
// - "단어들.txt" 파일을 다운 받는다.
// - 단어들이 자료구조에 369882개 저장되있다
// - 정렬이 되어 있는지 확인하자 - 정렬되어 있다
// - 중복된 단어는 없나? - 없다
// - 길이가 가장 긴 단어는 - 31글자 dichlorodiphenyltrichloroethane
// - 길이가 같은 단어 몇개를 화면에 출력
// - 사용자가 입력한 단어가 사전에 있는지 검사
//   사전에 있는 단어라면 anagram을 출력한다
//-----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <ranges>
#include "save.h"

using namespace std;

struct PS : pair<string, string>
{
	PS(string s) :pair(s, s) {
		sort(first.begin(), first.end());
	}
};

//-------
int main()
//-------
{
	save("소스.cpp");

	ifstream in{ "단어들.txt" };

	if (!in)
	{
		cout << "파일 읽기 실패";
		return 0;
	}

	vector<PS> v;
	v.reserve(40'0000);

	string s;
	while (in >> s)
	{
		v.push_back(s);
	}
	cout << "단어 개수 - " << v.size() << endl;

	// v를 first 오름차순으로 정렬한다.
	auto PS기준 = [](const PS& a, const PS& b) {
		return a.first < b.first;
	};
	sort(v.begin(), v.end(), PS기준);

	// [문제] 전체 anagram 쌍을 컨테이너에 저장하라
	vector<list<string>> anagrams;

	auto i = v.begin();
	int cnt{};
	while (true)
	{
		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});

		if (i == v.end())
		{
			break;
		}

		// 그렇다면 i와 i+1의 first는 같다.
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) {
			return i->first == a.first;
			});

		// [i, j)는 애너그램 쌍이다
		list<string> con;
		for (auto k = i; k < j; ++k)
		{
			con.push_back(k->second);
		}
		anagrams.push_back(con);

		i = j;
	}

	cout << "모두 " << anagrams.size() << "개의 애너그램 쌍을 찾았습니다." << endl;


	// 애너그램 개수가 많은 순서대로 정렬
	sort(anagrams.begin(), anagrams.end(), [](const list<string>& a, const list<string>& b) {
		return a.size() > b.size();
		});

	for (int i = 0; i < 10; ++i)
	{
		cout << anagrams[i].size() << " - ";
		for (const string& word : anagrams[i])
		{
			cout << word << " ";
		}
		cout << endl;
	}
}

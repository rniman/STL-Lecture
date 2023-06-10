//------------------------------------------------------------
// 2023 STL ������ �ǽ� - �ֳʱ׷� ã��
// - "�ܾ��.txt" ������ �ٿ� �޴´�.
// - �ܾ���� �ڷᱸ���� 369882�� ������ִ�
// - ������ �Ǿ� �ִ��� Ȯ������ - ���ĵǾ� �ִ�
// - �ߺ��� �ܾ�� ����? - ����
// - ���̰� ���� �� �ܾ�� - 31���� dichlorodiphenyltrichloroethane
// - ���̰� ���� �ܾ� ��� ȭ�鿡 ���
// - ����ڰ� �Է��� �ܾ ������ �ִ��� �˻�
//   ������ �ִ� �ܾ��� anagram�� ����Ѵ�
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
	save("�ҽ�.cpp");

	ifstream in{ "�ܾ��.txt" };

	if (!in)
	{
		cout << "���� �б� ����";
		return 0;
	}

	vector<PS> v;
	v.reserve(40'0000);

	string s;
	while (in >> s)
	{
		v.push_back(s);
	}
	cout << "�ܾ� ���� - " << v.size() << endl;

	// v�� first ������������ �����Ѵ�.
	auto PS���� = [](const PS& a, const PS& b) {
		return a.first < b.first;
	};
	sort(v.begin(), v.end(), PS����);

	// [����] ��ü anagram ���� �����̳ʿ� �����϶�
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

		// �׷��ٸ� i�� i+1�� first�� ����.
		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) {
			return i->first == a.first;
			});

		// [i, j)�� �ֳʱ׷� ���̴�
		list<string> con;
		for (auto k = i; k < j; ++k)
		{
			con.push_back(k->second);
		}
		anagrams.push_back(con);

		i = j;
	}

	cout << "��� " << anagrams.size() << "���� �ֳʱ׷� ���� ã�ҽ��ϴ�." << endl;


	// �ֳʱ׷� ������ ���� ������� ����
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

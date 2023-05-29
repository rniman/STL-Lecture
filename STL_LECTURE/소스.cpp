//------------------------------------------------------------
// 2023. 5.25, ��56                        (13�� 1��)
// 13�� 2�� 5. 29 ������ - ������ �⼮��ü
// 15�� 2�� 6. 12 ������ - �⸻ ����
//------------------------------------------------------------------
//
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;
 
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
	// [����] v�� ���Ұ� ���� Ȧ������ �˻��Ѵ�.
	bool res = my_all_of(v.begin(), v.end(), [](int i) {
		return i & 1;
		});

	cout << boolalpha << "Ȧ��? - " << res << endl;;

	save("�ҽ�.cpp");
}

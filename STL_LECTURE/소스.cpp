//------------------------------------------------------------
// 2023. 5.29, ��56                        (13�� 2��)
//------------------------------------------------------------------
// distance�� �����Ѵ� - itreator operation
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool ����;

template<class Iter>
int my_distance(Iter b, Iter e)
{
	return e - b;
}

//-------
int main()
//-------
{
	save("�ҽ�.cpp");

	vector<int> v{1, 2, 3, 4, 5};

	cout << my_distance(v.begin(), v.end()) << endl;
}

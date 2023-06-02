//------------------------------------------------------------
// 2023. 5.29, 월56                        (13주 2일)
//------------------------------------------------------------------
// distance를 구현한다 - itreator operation
//-----------------------------------------------------------------
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

template<class Iter>
int my_distance(Iter b, Iter e)
{
	return e - b;
}

//-------
int main()
//-------
{
	save("소스.cpp");

	vector<int> v{1, 2, 3, 4, 5};

	cout << my_distance(v.begin(), v.end()) << endl;
}

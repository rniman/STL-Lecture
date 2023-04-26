//------------------------------------------------------------
// 2023. 4. 20 목56								(8주 1일)
// 4월 24일 월요일(8주 2일) - 중간시험
//------------------------------------------------------------
// Sequence container - list
//------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

// [문제] 파일 "리스트설명.txt"의 단어를 list<String>으로 읽어와라.
// 읽은 단어를 화면에 출려하라.

//-------
int main()
//-------
{
	//save("소스.cpp");

	ifstream in{ "리스트설명.txt" };

	if (!in)
	{
		cout << "파일열기 실패" << endl;
	}

	//list<String> cont{시작, 끝}; -> 모든 컨테이너는 다음과 같이 가능
	//istream_iterator: 입력스트림을 돌아다니는 이터레이터, >>이 구현 되어 있어야한다
	list<String> cont{ istream_iterator<String>{in}, {} };
	cout << "모두 " << cont.size() << "개의 단어를 읽었습니다." << endl;

	// [문제] 길이가 7인 String을 "길이7.txt"에 저장하라
	// 한 줄에 String 한개를 저장하라

	ofstream out{ "길이7.txt" };

	//copy_if(cont.begin(), cont.end(), ostream_iterator<String>(out, '\n'), [](const String& s) {
	//	return s.size() == 7;
	//	});

	for (String& s : cont)
		if (s.size() == 7)
			out << s << endl;

	//cout << "길이가 7인 단어의 수 " << len7Num << endl;
}


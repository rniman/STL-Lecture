//------------------------------------------------------------
// 2023. 6. 5, 월56                        (14주 2일)
// 6/6일 업로드할 동영상 - 총정리 실습
//------------------------------------------------------------------
// C++20 - 4 major change
// Concept - 템플릿에 전달되는 인자(자료형)가 원하는 의미(semantic)를 
//			 만족하는지 컴파일 타임에 검사(소스코드 확장 전);
// Range - composable / less error-prone --> lazy evaluation(지연 평가)
// - lightWeight object -> ex) string_view와 같이 가벼운 정보를 담은 경량화한 객체
//  -- [begin, end)
//  -- [start, size)
//  -- [start, predicate)
//  -- [start..)  끝이없는 시퀀스
//-----------------------------------------------------------------
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include "save.h"
#include "String.h"

using namespace std;
extern bool 관찰;

bool isPrime2(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n % i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}

//-------
int main()
//-------
{
	save("소스.cpp");

	// 소수(prime num, 2 3 5 7 9 11 13)를 영원히 출력하라
	// 100만 이상의 수 중에서 100개만 뒤에서부터 출력하라

	for (int n : views::iota(2)
			   | views::drop_while([](int i) {return i < 100'0000; })
			   | views::filter(isPrime2)
			   | views::take(100)
			   | views::reverse
		)
		cout << n << ' ';
	cout << endl;

}

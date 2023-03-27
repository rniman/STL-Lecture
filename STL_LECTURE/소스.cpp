//------------------------------------------------------------
// 2023. 3. 27 월56								(4주 2일)
//------------------------------------------------------------
// 관찰 클래스 작성 
// 1. C++ 복습 
// 2. 앞으로 발전시켜서 STL 컨테이너로 만듦
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <algorithm>
#include "save.h"

using namespace std;

// [문제] 자원을 할당하는 클래스 String (표준 string과 유사한)를 작성하자.
// special 함수의 동작을 관찰하자
// 모든 객체는 생성시 번호를 받는다.

bool 관찰{ false };

class String
{
	size_t len{};
	char* p{ nullptr };
	//unique_ptr<char[]> p{ nullptr };
	size_t id = ++sid;

	static size_t sid;		// 멤버 변수가 아니다

public:
	String()
	{
		print("디폴트 생성");
	}

	String(const char* str)
		: len{strlen(str)}
		//, p = new char[len] 순서 보장 X -> 망할수있다.
	{
		p = new char[len];
		//p = make_unique<char[]>(len);

		memcpy(p, str, len);	//고속 메모리 복사 - DMA
		//memcpy(p.get(), str, len);
		print("생성(char*)");
	}

	//복사 생성 연산자와 복사할당 연산자는 짝이다.
	String(const String& other)
		:len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("복사 생성");
	}

	String& operator=(const String& other)
	{
		if (this == &other)
			return *this;
		
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		print("복사할당 연산자");
	}

	//지역을 벗어날 때
	//객체가 사라지기 전에 부르는 함수
	//소멸 역순
	~String()
	{
		print("소멸");
		delete[] p;
	}

	void print(const string& s)
	{
		if (!관찰)
			return;
		cout << '[' << id << "] - " << s << ", 개수: " << len << ", 번지: " << (void*)p << endl;
		//cout << '[' << id << "] - " << s << ", 개수: " << len << ", 번지: " << (void*)p.get() << endl;
	}

	//인터페이스 함수
	size_t size() const 
	{
		return len;
	}

	String operator+(const String& rhs)
	{
		String res;
		res.len = len + rhs.len;
		res.p = new char[res.len];

		memcpy(res.p, p, len);
		memcpy(res.p + len, rhs.p, rhs.len);
		
		return res;
	}

	//프렌드 함수
	friend ostream& operator<<(ostream& os, const String& s)
	{
		for (int i = 0; i < s.len; ++i)
		{
			os <<  s.p[i];
		}
		return os;
	}

	string getString() const
	{
		return string(p, len);
	}
};

size_t String::sid{ 0 };

//-------
int main()
//-------
{
	//관찰 = true;
	
	string a;
	cout << sizeof a << ' ';

	array<String, 5> news{ "사진", "촬영은", "무조건", "금지", "견본주택과" }; //3개로 하고 쫒아가보기
	// 오름차순 정렬하라.
	sort(news.begin(), news.end(), [](const String& a, const String& b) {
			return a.getString() < b.getString();
		});

	for (const String& s : news)
	{
		cout << s << endl;
	}

	//save("소스.cpp");
}


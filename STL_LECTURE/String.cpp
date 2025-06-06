//-------------------------------------------------------------------------------------------------------------------
// String.cpp - 표준 string과 유사한 클래스
// 
// 2023. 3. 30
//-------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "String.h"

bool 관찰{ false };				// 스페셜 함수의 동작을  관찰하려면 true로 바꿀 것

// 생성자와 소멸자
String::String()
{
	print("디폴트 생성자");
}

String::String(const char* str)
	: len{ strlen(str) }
{
	p = new char[len];

	memcpy(p, str, len);	//고속 메모리 복사 - DMA
	print("생성자(char*)");
}

String::~String()
{
	print("소멸자");
	delete[] p;
}

// 복사생성자 / 복사할당연산자
String::String(const String& other)
	:len{ other.len }
{
	p = new char[len];
	memcpy(p, other.p, len);

	print("복사 생성자");
}

String& String::operator=(const String& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] p;

	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	print("복사할당연산자");
	return *this;
}

// 이동생성자 / 이동할당연산자 - 2023. 3. 30 추가
// 이동이 안점함을 보중한다. - 2023. 4. 10 추가
String::String(String&& other)	noexcept//&&: r-value ref
	: len{ other.len }
	, p{ other.p }
{
	// 이동되는 객체를 정리해준다
	other.len = 0;
	other.p = nullptr;

	print("이동생성자");
}

String& String::operator=(String&& other) noexcept
{
	// 자신을 이동할당하면 안된다.
	if (this == &other)
	{
		return *this;
	}

	// 이미 확보한 자원을 해제한다.
	delete[] p;

	// other를 이동한다.
	len = other.len;
	p = other.p;

	other.len = 0;
	other.p = nullptr;

	print("이동할당연산자");
	return *this;
}

// 연산자 오버로딩 함수
String String::operator+(const String& rhs)
{
	String res;
	res.len = len + rhs.len;
	res.p = new char[res.len];

	memcpy(res.p, p, len);
	memcpy(res.p + len, rhs.p, rhs.len);

	return res;
}

// 2023. 4. 13 == 추가
bool String::operator==(const String& rhs)
{
	//if (len != rhs.len)
	//{
	//	return false;
	//}

	return std::equal(p, p + len, rhs.p, rhs.p + rhs.len);	//사이즈 비교 필요 X
	//return std::equal(p, p + len, rhs.p);					//사이즈 비교 필요 O
	//return getString() == rhs.getString();
}

bool String::operator==(const String& rhs) const
{
	return std::equal(p, p + len, rhs.p, rhs.p + rhs.len);
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0; i < s.len; ++i)
	{
		os << s.p[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	std::string str;
	is >> str;
	s.len = str.size();
	delete[] s.p;
	s.p = new char[s.len];
	memcpy(s.p, str.data(), s.len);

	return is;
}

// 표준 컨테이너가 되기위하여 추가한 함수들
// 2023. 5. 8일 String_iterator를 return 하도록 변경
String_iterator String::begin()
{
	return String_iterator{ p };
}

String_iterator String::end()
{
	return String_iterator{ p + len };
}

// 2023. 5. 15일 추가
String_iterator String::begin() const
{
	return String_iterator{ p };
}

String_iterator String::end() const
{
	return String_iterator{ p + len };
}

// 2023. 5. 4일 추가
String_reverse_iterator String::rbegin()
{
	return String_reverse_iterator{ p + len };
}

String_reverse_iterator String::rend()
{
	return String_reverse_iterator{ p };
}

// 2023. 5. 11 < 추가
// String이 set의 원소가 되려면 < 연산자를 정의해야 한다
// < 연산자는 정렬하기 위해 필요한 기본연산자
bool String::operator<(const String& rhs) const
{
	return getString() < rhs.getString();
}

// 그 외 멤버함수들
void String::print(const std::string& s) const
{
	if (!관찰)
		return;
	std::cout << '[' << id << "] - " << s << ", 개수: " << len << ", 번지: " << (void*)p << std::endl;
}

//인터페이스 함수
size_t String::size() const
{
	return len;
}

std::string String::getString() const
{
	return std::string(p, len);
}

size_t String::sid{ 0 };			// 이 변수는 클래스 밖에서 초기화한다
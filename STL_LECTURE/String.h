//-------------------------------------------------------------------------------------------------------------------
// String.h - 표준 string과 유사한 클래스
// 
// 2023. 3. 30
//-------------------------------------------------------------------------------------------------------------------
#pragma once

// 2023. 5. 8
// String이 제공하는 반복자
class String_iterator
{
public:
	using iterator_concept = std::contiguous_iterator_tag;

	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = long long;
	using pointer = char*;
	using reference = char&;

private:
	char* p;

public:
	String_iterator() = default;
	String_iterator(char* p) :p{ p } {}

	reference operator*() const
	{
		return *p;
	}

	String_iterator& operator++()
	{
		++p;
		return *this;
	}

	// sort 하려면 이 연산자들 코딩해야~
	difference_type operator-(const String_iterator& rhs) const
	{
		return p - rhs.p;
	}

	String_iterator& operator--()
	{
		--p;
		return *this;
	}

	String_iterator& operator+(difference_type diff)
	{
		p += diff;
		return *this;
	}

	String_iterator& operator-(difference_type diff)
	{
		p -= diff;
		return *this;
	}

	//관계연산자(relational operators) -> 6가지 < <= > >= == != -> 한번에 만들 우주선 연산자 사용
	//space-ship(정식명칭:three-way comparaotr) operator로 자동화할 수 있다.
	auto operator<=>(const String_iterator& rhs) const = default;	//멤버가 하나이기 때문에 쉽게 사용가능
};


// 2023. 5. 4
// String이 제공하는 역방향 반복자
class String_reverse_iterator
{
	char* p;
public:
	String_reverse_iterator(char* p) : p{ p } {};

	bool operator!=(const String_reverse_iterator& rhs) const
	{
		return p != rhs.p;
	}

	String_reverse_iterator& operator++()
	{
		--p;
		return *this;
	}

	char operator*() const
	{
		return *(p - 1);
	}
};


// 2023. 3. 27 String 코딩 시작
class String
{
	size_t len{};				// 확보한 자원 수
	char* p{ nullptr };			// 확보한 자원의 주소
	size_t id = ++sid;			// 객체 id

	static size_t sid;			// class의 static 변수?, 멤버 변수가 아니다

public:
	// 생성자와 소멸자
	String();
	String(const char* str);
	~String();

	// 복사생성자 / 복사할당연산자
	String(const String& other);
	String& operator=(const String& other);

	// 이동생성자 / 이동할당연산자 - 2023. 3. 30 추가
	// 이동이 안점함을 보중한다. - 2023. 4. 10 추가
	String(String&& other) noexcept;	//&&: r-value ref
	String& operator=(String&& other) noexcept;

	// 연산자 오버로딩 함수
	String operator+(const String& rhs);
	// 2023. 4. 13 == 추가
	bool operator==(const String& rhs);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	// 2023. 4. 3 입력연산자 오버로딩
	friend std::istream& operator>>(std::istream& os, String& s);

	// 표준 컨테이너가 되기위하여 추가한 함수들
	// 2023. 5. 8일 String_iterator를 return 하도록 변경
	String_iterator begin();
	String_iterator end();

	// 2023. 5. 4일 추가
	String_reverse_iterator rbegin();
	String_reverse_iterator rend();

	// 그 외 멤버함수들
	void print(const std::string& s) const;


	//인터페이스 함수
	size_t size() const;
	std::string getString() const;
};

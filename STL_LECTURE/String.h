//-------------------------------------------------------------------------------------------------------------------
// String.h - ǥ�� string�� ������ Ŭ����
// 
// 2023. 3. 30
//-------------------------------------------------------------------------------------------------------------------
#pragma once

// 2023. 5. 8
// String�� �����ϴ� �ݺ���
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

	// sort �Ϸ��� �� �����ڵ� �ڵ��ؾ�~
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

	//���迬����(relational operators) -> 6���� < <= > >= == != -> �ѹ��� ���� ���ּ� ������ ���
	//space-ship(���ĸ�Ī:three-way comparaotr) operator�� �ڵ�ȭ�� �� �ִ�.
	auto operator<=>(const String_iterator& rhs) const = default;	//����� �ϳ��̱� ������ ���� ��밡��
};


// 2023. 5. 4
// String�� �����ϴ� ������ �ݺ���
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


// 2023. 3. 27 String �ڵ� ����
class String
{
	size_t len{};				// Ȯ���� �ڿ� ��
	char* p{ nullptr };			// Ȯ���� �ڿ��� �ּ�
	size_t id = ++sid;			// ��ü id

	static size_t sid;			// class�� static ����?, ��� ������ �ƴϴ�

public:
	// �����ڿ� �Ҹ���
	String();
	String(const char* str);
	~String();

	// ��������� / �����Ҵ翬����
	String(const String& other);
	String& operator=(const String& other);

	// �̵������� / �̵��Ҵ翬���� - 2023. 3. 30 �߰�
	// �̵��� �������� �����Ѵ�. - 2023. 4. 10 �߰�
	String(String&& other) noexcept;	//&&: r-value ref
	String& operator=(String&& other) noexcept;

	// ������ �����ε� �Լ�
	String operator+(const String& rhs);
	// 2023. 4. 13 == �߰�
	bool operator==(const String& rhs);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	// 2023. 4. 3 �Է¿����� �����ε�
	friend std::istream& operator>>(std::istream& os, String& s);

	// ǥ�� �����̳ʰ� �Ǳ����Ͽ� �߰��� �Լ���
	// 2023. 5. 8�� String_iterator�� return �ϵ��� ����
	String_iterator begin();
	String_iterator end();

	// 2023. 5. 4�� �߰�
	String_reverse_iterator rbegin();
	String_reverse_iterator rend();

	// �� �� ����Լ���
	void print(const std::string& s) const;


	//�������̽� �Լ�
	size_t size() const;
	std::string getString() const;
};

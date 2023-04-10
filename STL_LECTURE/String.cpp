//-------------------------------------------------------------------------------------------------------------------
// String.cpp - ǥ�� string�� ������ Ŭ����
// 
// 2023. 3. 30
//-------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "String.h"

bool ����{ false };				// ����� �Լ��� ������  �����Ϸ��� true�� �ٲ� ��

// �����ڿ� �Ҹ���
String::String()
{
	print("����Ʈ ������");
}

String::String(const char* str)
	: len{ strlen(str) }
{
	p = new char[len];

	memcpy(p, str, len);	//��� �޸� ���� - DMA
	print("������(char*)");
}

String::~String()
{
	print("�Ҹ���");
	delete[] p;
}

// ��������� / �����Ҵ翬����
String::String(const String& other)
	:len{ other.len }
{
	p = new char[len];
	memcpy(p, other.p, len);

	print("���� ������");
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

	print("�����Ҵ翬����");
	return *this;
}

// �̵������� / �̵��Ҵ翬���� - 2023. 3. 30 �߰�
// �̵��� �������� �����Ѵ�. - 2023. 4. 10 �߰�
String::String(String&& other)	noexcept//&&: r-value ref
	: len{ other.len }
	, p{ other.p }
{
	// �̵��Ǵ� ��ü�� �������ش�
	other.len = 0;
	other.p = nullptr;

	print("�̵�������");
}

String& String::operator=(String&& other) noexcept
{
	// �ڽ��� �̵��Ҵ��ϸ� �ȵȴ�.
	if (this == &other)
	{
		return *this;
	}

	// �̹� Ȯ���� �ڿ��� �����Ѵ�.
	delete[] p;

	// other�� �̵��Ѵ�.
	len = other.len;
	p = other.p;

	other.len = 0;
	other.p = nullptr;

	print("�̵��Ҵ翬����");
	return *this;
}

// ������ �����ε� �Լ�
String String::operator+(const String& rhs)
{
	String res;
	res.len = len + rhs.len;
	res.p = new char[res.len];

	memcpy(res.p, p, len);
	memcpy(res.p + len, rhs.p, rhs.len);

	return res;
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

// �� �� ����Լ���
void String::print(const std::string& s) const
{
	if (!����)
		return;
	std::cout << '[' << id << "] - " << s << ", ����: " << len << ", ����: " << (void*)p << std::endl;
}

//�������̽� �Լ�
size_t String::size() const
{
	return len;
}

std::string String::getString() const
{
	return std::string(p, len);
}

size_t String::sid{ 0 };			// �� ������ Ŭ���� �ۿ��� �ʱ�ȭ�Ѵ�
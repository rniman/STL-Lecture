//------------------------------------------------------------
// 2023. 3. 27 ��56								(4�� 2��)
//------------------------------------------------------------
// ���� Ŭ���� �ۼ� 
// 1. C++ ���� 
// 2. ������ �������Ѽ� STL �����̳ʷ� ����
//------------------------------------------------------------
#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <algorithm>
#include "save.h"

using namespace std;

// [����] �ڿ��� �Ҵ��ϴ� Ŭ���� String (ǥ�� string�� ������)�� �ۼ�����.
// special �Լ��� ������ ��������
// ��� ��ü�� ������ ��ȣ�� �޴´�.

bool ����{ false };

class String
{
	size_t len{};
	char* p{ nullptr };
	//unique_ptr<char[]> p{ nullptr };
	size_t id = ++sid;

	static size_t sid;		// ��� ������ �ƴϴ�

public:
	String()
	{
		print("����Ʈ ����");
	}

	String(const char* str)
		: len{strlen(str)}
		//, p = new char[len] ���� ���� X -> ���Ҽ��ִ�.
	{
		p = new char[len];
		//p = make_unique<char[]>(len);

		memcpy(p, str, len);	//��� �޸� ���� - DMA
		//memcpy(p.get(), str, len);
		print("����(char*)");
	}

	//���� ���� �����ڿ� �����Ҵ� �����ڴ� ¦�̴�.
	String(const String& other)
		:len{ other.len }
	{
		p = new char[len];
		memcpy(p, other.p, len);

		print("���� ����");
	}

	String& operator=(const String& other)
	{
		if (this == &other)
			return *this;
		
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		print("�����Ҵ� ������");
	}

	//������ ��� ��
	//��ü�� ������� ���� �θ��� �Լ�
	//�Ҹ� ����
	~String()
	{
		print("�Ҹ�");
		delete[] p;
	}

	void print(const string& s)
	{
		if (!����)
			return;
		cout << '[' << id << "] - " << s << ", ����: " << len << ", ����: " << (void*)p << endl;
		//cout << '[' << id << "] - " << s << ", ����: " << len << ", ����: " << (void*)p.get() << endl;
	}

	//�������̽� �Լ�
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

	//������ �Լ�
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
	//���� = true;
	
	string a;
	cout << sizeof a << ' ';

	array<String, 5> news{ "����", "�Կ���", "������", "����", "�ߺ����ð�" }; //3���� �ϰ� �i�ư�����
	// �������� �����϶�.
	sort(news.begin(), news.end(), [](const String& a, const String& b) {
			return a.getString() < b.getString();
		});

	for (const String& s : news)
	{
		cout << s << endl;
	}

	//save("�ҽ�.cpp");
}


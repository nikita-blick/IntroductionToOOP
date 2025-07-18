#pragma once
#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------------------------\n"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////                 ���������� ������ (Class declaration)                               /////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class String
{
	int size;      // ������ ������ � ������ ( � ������ NULL-Terminator)
	char* str;     // ����� ������ � ������������ ������ 
public:                            // �����������
	int get_size()const;
	const char* get_str()const;
	char* get_str();


	//            Constructors:
	explicit String(int size = 80);

	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;
	~String();
	//     Operators:
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	char operator[](int i)const;
	char& operator[](int i);

	//        Methods:
	void print()const;

};
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
/////////////////                ����� ���������� ������ (Class declaration end)                      /////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

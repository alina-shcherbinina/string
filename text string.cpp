#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include "pch.h"
#include "class string.h"


using namespace std;

MyString::MyString()
{
	Str = 0;
	Length = 0;
}

MyString::MyString(const char* ptr) : Length(strlen(ptr)), Str(new char[Length + 1])
{
	strcpy(Str, ptr);
}

MyString::MyString(const MyString& t) : Length(strlen(t.Str)), Str(new char[Length + 1])
{
	strcpy(Str, t.Str);
}

MyString& MyString::operator += (const MyString& t)
{
	int newLength = Length + t.Length;
	char *newStr = new char[newLength + 1];
	strcpy(newStr, Str);
	strcat(newStr, t.Str);
	delete[] Str;
	Str = newStr;
	Length = newLength;
	return *this;
}

const char* MyString::getStr() const
{
	return Str;
}

int MyString::getLength() const
{
	return Length;
}

int MyString::getSentences() const
{
	int count = 0;
	for (int i = 0; i < Length; i++)
	{
		if ((Str[i] == '.') || (Str[i] == '!') || (Str[i] == '?')) 
			count++;
	}
	return count;
}

int MyString::getArticles() const
{
	//string str(Str);
	//string Sub = " a ";
	//int start = 0;
	//int count = 0;
	//int pos = 0;
	//for (;;) { // i guess it isnt necessary bc we count pos and break the loop 
	//	pos = str.find(Sub.c_str(), start);
	//	if (pos != -1) {
	//		start = pos + Sub.size();
	//		count++;
	//	}
	//	else {
	//		break;
	//	}
	//}
	//return count;
	return 0;
}

int MyString::search(string Sub)
{
	string str(Str);
	int start = 0;
	int count = 0;
	int pos = 0;
	for (;;) { // i guess it isnt necessary bc we count pos and break the loop 
		pos = str.find(Sub.c_str(), start);
		if (pos != -1) {
			start = pos + Sub.size();
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

ostream & MyString::show(ostream & os) const
{
	return os << "\"" << (Str ? Str : "") << "\"";
}

MyString::~MyString()
{
	Length = 0;
	delete[] Str;
	Str = 0;
}
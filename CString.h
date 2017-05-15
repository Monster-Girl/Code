#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
class CComStu
{
public:
	virtual void show()
	{
		cout << "CComStu" << endl;
	}
};

class CEStu :public CComStu
{
public:
	void show()
	{
		cout << "CEStu" << endl;
	}
};

class CMStu :public CComStu
{
public:
	 void show()
	{
		cout << "CMStu" << endl;
	}
};

class CAStu :public CMStu
{
public:
	void show()
	{
		cout << "CAStu" << endl;
	}
};


class CCStu :public CMStu
{
public:
	void show()
	{
		cout << "CCStu" << endl;
	}
};

void Test()
{
	CEStu x1;
	CMStu x2;
	CAStu x3;

	CComStu *p;
	p = &x1;
	p->show();

	CComStu y1;
	y1 = x2;
	y1.show();

	CComStu &y2 = x3;
	y2.show();

}

//class CString
//{
//protected:
//	int len;   //字符串长度
//	char *Str;  //指向字符串内容的指针
//public:
//	CString()
//		:len(0)
//		, Str(NULL)
//	{}
//
//	CString(char* s)
//	{
//		len = strlen(s);
//		Str = new char[len + 1];
//		memcpy(Str, s, len + 1);
//	}
//
//	CString(CString& s)
//	{
//		len = s.len;
//		Str = new char[len + 1];
//		memcpy(Str, s.Str, len+1);
//	}
//
//	~CString()
//	{
//		if(Str)
//			Str = NULL;
//		len = 0;
//	}
//
//	char* GetStr();//返回字符串起始地址
//
//	int GetLen() //返回字符串长度
//	{
//		return len;
//	}
//	void Show()  //在屏幕上打印字符串
//	{
//		cout << Str <<endl;
//	}
//
//	void SetStr(char* s)  //设置字符串内容
//	{
//		len = strlen(s);
//		memcpy(Str, s, len + 1);
//	}
//
//	CString operator+ (const CString& s)
//	{
//		CString NewStr;
//		NewStr.Str = new char[len + s.len + 1];
//		NewStr.len = len + s.len+1;
//		strcpy(NewStr.Str, Str);
//		strcat(NewStr.Str, s.Str);
//		return NewStr;
//	}
//};
//
//void Test()
//{
//	CString s1("abc");
//	CString s2("123");
//	cout << s1.GetLen() << endl;
//	s1.Show();
//	//cout << s1.GetStr() << endl;
//	s1.SetStr("12345");
//	//cout << s1.GetStr() << endl;
//	s1.Show();
//	cout << s1.GetLen() << endl;
//
//	(s1 + s2).Show();
//}
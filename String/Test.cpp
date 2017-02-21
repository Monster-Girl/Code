#include"String.h"

void Test1()
{
	String s1("hell");
	cout << s1.GetStr() << endl;
	s1.PushBack('o');
	cout << s1.GetStr() << endl;
	s1.PopBack();
	cout << s1.GetStr() << endl;
}

void Test2()
{
	String s2("hllo");
	s2.Insert(1, 'e');
	cout << s2.GetStr() << endl;
	s2.Erase(1);
	cout << s2.GetStr() << endl;
}

void Test3()
{
	String s3("hallo");
	String s4("hello");
	//cout << (s4 > s3) << endl;
	//cout << (s3 == s4) << endl;
	//cout << (s4 < s3) << endl;
	cout << (s3 >= s4) << endl;
	cout << (s3 <= s4) << endl;
	String s5 = s3 + 'w';
	cout << s5.GetStr() << endl;
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}
#include"Date.h"

void Test1()    //²âÊÔ³ÉÔ±º¯Êı
{
	Date d1;
	Date d2 = d1;
	cout << d1;
	cout << d2;
}

void Test()  
{
	Date d1(2017, 1, 23);
	Date d2(2017, 1, 23);
	cout << ++d1;
	cout << d1++;
	cout << d1 + 30;
	cout << d1 - 207 ;
	cout << --d1;
	cout << d1--;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 != d2) << endl;
}

int main()
{
	Test();
	system("pause");
}
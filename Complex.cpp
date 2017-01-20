#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)  //构造函数
	{
		_real = real;
		_image = image;

	}

	Complex(const Complex& c)    //拷贝构造函数
	{
		_real = c._real;
		_image = c._image;
	}

	~Complex()   //析构函数
	{
		//cout << "~Complex" << endl;
	}

	Complex operator =(const Complex& c)    //赋值函数
	{
		this->_real = c._real;
		this->_image = c._image;
		cout << "operator =" << endl;
	}

	bool operator==(const Complex& d)    //判断相等
	{
		return((_real == d._real) && (_image == d._image));
	}

	Complex operator+(const Complex &d)  //两个复数相加  
	{
		Complex tmp;
		tmp._real= _real + d._real;
		tmp._image = _image + d._image;
		return tmp;
	}

	Complex operator-(const Complex &d)  //两个复数相减 
	{
		Complex tmp;
		tmp._real = _real - d._real;
		tmp._image = _image - d._image;
		return tmp;
	}

	Complex& operator+=(const Complex &d)  //复数对象+=d 
	{
		_real += d._real;
		_image += d._image;
		return *this;
	}

	Complex& operator-=(const Complex &d)  //复数对象-=d 
	{
		_real -= d._real;
		_image -= d._image;
		return *this;
	}

	Complex operator++()  //前置++ 
	{
		++_real;
		++_image;
		return *this;
	}

	Complex operator++(int)  //后置++  
	{
		Complex tmp = *this;
		_real++;
		_image++;
		return tmp;
	}

	Complex operator--()  //前置-- 
	{
		--_real;
		--_image;
		return *this;
	}

	Complex operator--(int)  //后置--  
	{
		Complex tmp = *this;
		--_real;
		--_image;
		return tmp;
	}


	void Display()  //显示复数的实部和虚部  
	{
		cout << _real << "+" << _image << "i" << endl;
	}

private:
	double _real;  //实部
	double _image; //虚部
};


void Test1()
{
	Complex c1(1.0, 2.0);  //构造出的C1
	c1.Display();
	Complex c2(c1);   //拷贝构造出的C2
	c2.Display();
}

void Test2()    //==、+、-、+=、-=
{
	Complex c1(1.0, 2.0);
	c1.Display();
	Complex c2(2.0, 2.0);
	c2.Display();
	
	int ret=c1==c2;    //operator==
	if (ret == 0) cout << "c1!=c2" << endl;
	else  cout << "c1=c2" << endl;

	Complex c3 = c1+c2;   //operator+
	c3.Display();

	Complex c4 = c1-c2;   //operator-
	c4.Display();

	c1+=c2;   //operator+=
	c1.Display();

	c1.operator-=(c2);   //operator-=
	c1.Display();

}

void Test3()    //前置++、后置++、前置--、后置--
{
	Complex c1(1.0, 2.0);
	c1.Display();
   
	Complex c2 = ++c1;    //前置++ 
	c2.Display();

	Complex c3 = c1++;     //后置++
	c3.Display();
	c1.Display();

	Complex c4 = --c1;    //前置--
	c4.Display();

	Complex c5 = c1--;
	c5.Display();
	c1.Display();
}

int main()
{
	Test1();
	Test2();
	Test3();
	system("pause");
}
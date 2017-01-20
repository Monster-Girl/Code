#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)  //���캯��
	{
		_real = real;
		_image = image;

	}

	Complex(const Complex& c)    //�������캯��
	{
		_real = c._real;
		_image = c._image;
	}

	~Complex()   //��������
	{
		//cout << "~Complex" << endl;
	}

	Complex operator =(const Complex& c)    //��ֵ����
	{
		this->_real = c._real;
		this->_image = c._image;
		cout << "operator =" << endl;
	}

	bool operator==(const Complex& d)    //�ж����
	{
		return((_real == d._real) && (_image == d._image));
	}

	Complex operator+(const Complex &d)  //�����������  
	{
		Complex tmp;
		tmp._real= _real + d._real;
		tmp._image = _image + d._image;
		return tmp;
	}

	Complex operator-(const Complex &d)  //����������� 
	{
		Complex tmp;
		tmp._real = _real - d._real;
		tmp._image = _image - d._image;
		return tmp;
	}

	Complex& operator+=(const Complex &d)  //��������+=d 
	{
		_real += d._real;
		_image += d._image;
		return *this;
	}

	Complex& operator-=(const Complex &d)  //��������-=d 
	{
		_real -= d._real;
		_image -= d._image;
		return *this;
	}

	Complex operator++()  //ǰ��++ 
	{
		++_real;
		++_image;
		return *this;
	}

	Complex operator++(int)  //����++  
	{
		Complex tmp = *this;
		_real++;
		_image++;
		return tmp;
	}

	Complex operator--()  //ǰ��-- 
	{
		--_real;
		--_image;
		return *this;
	}

	Complex operator--(int)  //����--  
	{
		Complex tmp = *this;
		--_real;
		--_image;
		return tmp;
	}


	void Display()  //��ʾ������ʵ�����鲿  
	{
		cout << _real << "+" << _image << "i" << endl;
	}

private:
	double _real;  //ʵ��
	double _image; //�鲿
};


void Test1()
{
	Complex c1(1.0, 2.0);  //�������C1
	c1.Display();
	Complex c2(c1);   //�����������C2
	c2.Display();
}

void Test2()    //==��+��-��+=��-=
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

void Test3()    //ǰ��++������++��ǰ��--������--
{
	Complex c1(1.0, 2.0);
	c1.Display();
   
	Complex c2 = ++c1;    //ǰ��++ 
	c2.Display();

	Complex c3 = c1++;     //����++
	c3.Display();
	c1.Display();

	Complex c4 = --c1;    //ǰ��--
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
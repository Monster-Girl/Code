#include<iostream>
using namespace std;
//17-3-1
//用递归实现数组求和
//int AddAll(int arr[],int begin,int length)   //求数组arr，从begin到结束的和
//{
//	if (begin == length) return 0;
//	int sum = AddAll(arr, begin+1,length);
//	return sum + arr[begin];
//}
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int sum = AddAll(arr, 0, length);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

//#include<string>
//用递归判断字符串内容是否相等
//bool IsEqual(string s1, string s2)
//{
//	int str1 = s1.length();
//	int str2 = s2.length();
//	if (str1 != str2) return false;
//	//if ((str1 == 0) && (str2 == 0)) return true;
//	if (str1 == 0) return true;
//	/*if ((s1.substr(0, 1)) != (s2.substr(0, 1)))
//		return false;*/
//
//	std::string::iterator it1=s1.begin();
//	std::string::iterator it2 = s2.begin();
//	if (*it1 != *it2) return false;
//
//	return IsEqual(s1.substr(1,str1), s2.substr(1,str2));
//}
//
//
//int main()
//{
//	string s1 = "hello world";
//	string s2 = "hello world";
//	bool ret = IsEqual(s1, s2);
//	cout << ret << endl;
//	//cout << s1.compare(s2) << endl;
//	system("pause");
//	return 0;
//}

//17-3-2
//在n个球中，任一取m个（不放回），求有多少种取法
//int f(int n, int m)
//{
//	//a,b,c 
//	//ab,bc,ac
//	if (n < m) return 0;
//	if (n == m) return 1;
//	if (m == 0) return 1;
//
//	//n个里有一个特殊的，取法划分：包不包括这个特殊的
//	//要么在被取的范围里，要么就不在里面,两种情况
//	return (f(n - 1, m - 1) + f(n - 1, m));
//}
//
//int main()
//{
//	int k = f(10, 3);
//	cout << k << endl;
//	system("pause");
//	return 0;
//}

//求n个元素的全排列
//#include<string>
//void f(string arr,int k)   //当前的交换位置
//{
//	int len = arr.length();
//	if (k == (len-1))
//	{
//		for (int i = 0; i < len; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = k; i < len; i++)
//	{
//		swap(arr[k], arr[i]);//试探
//		f(arr,k+1);
//		swap(arr[k], arr[i]);//回溯
//	}
//}
//
//int main()
//{
//	string arr= "abc";
//	f(arr,0);
//	system("pause");
//	return 0;
//}

//求两个串的最大公共子序列的长度
//子序列是指从一个串中可以跳着取，一些取，一些不取。
//#include<string>
//#include <algorithm>  
//int f(string s1, string s2)
//{
//	int str1 = s1.length();
//	int str2 = s2.length();
//	if (str1 == 0 || str2 == 0) return 0;
//	if (s1.substr(0,1) == s2.substr(0,1))
//		return   f((s1.substr(1, str1)), (s2.substr(1, str2))) + 1;
//	else
//	{
//		return max(f(s1.substr(1, str1), s2), f(s1, s2.substr(1, str2)));
//		/*if (f(s1.substr(1, str1), s2) > f(s1, s2.substr(1, str2)))
//			return f(s1.substr(1, str1), s2);
//		else
//			return f(s1, s2.substr(1, str2));*/
//	}
//}
//
//int main()
//{
//	string s1 = "abc";
//	string s2 = "xbacd";
//	int k = f(s1, s2);
//	cout << k << endl;
//	system("pause");
//	return 0;
//}
//总结：当串的长度过长时，递归将会失效。不是最优解，可行性不高。 

//2017-3-4
//实现串的反串
//#include<string>
//string f(string arr)
//{
//	if (arr=="" || arr.length() <= 1) return arr;
//	return f(arr.substr(1))+ arr.substr(0,1);
//}
//
//int main()
//{
//	string ret = f("abc");
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//杨辉三角
//#include<iomanip>
//int f(int m, int n)  //m层n个元素
//{
//	if (m == 0) return 1;
//	if (n == 0 || n == m) return 1;
//	return f(m - 1, n - 1) + f(m - 1, n);
//}
//
//int main()
//{
//	int level = 5;
//	
//	for (int i = 0; i <= level; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			cout << setw(3) << f(i, j) << "  " << setw(3);
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//3个A,2个B,有多少种排列
//int f(int m, int n)  //m个A，n个B
//{
//	if (m == 0 || n == 0) return 1;
//	return f(m - 1, n) + f(m, n - 1);
//}
//
//int main()
//{
//	cout << f(3, 2) << endl;
//	system("pause");
//	return 0;
//}

//整数的划分问题
//#include<malloc.h>
//void f(int n,int arr[],int k)
//{
//	if (n <= 0)
//	{
//		for (int i = 0; i<k; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = n ; i > 0; i--)
//	{
//		if (k > 0 && i > arr[k - 1]) continue;
//		arr[k] = i;
//		f(n - i, arr, k + 1);
//	}
//}
//
//int main()
//{
//	int *arr = new int[100];
//	f(6, arr, 0);
//	system("pause");
//	return 0;
//}

//err_sum：有错的和
//int arr:明细
//k:当前的处理位置
//cur_sum:前边元素的累加和
void f(int err_sum, int arr[], int k,int cur_sum,int length,bool b[])
{
	if (cur_sum > err_sum) return;  //当累加和 > 有错的和，返回
	if (k > length) return;    //当k越界，返回

	if (err_sum == cur_sum)     //当累加和 = 有错的和 ，开始标记打印
	{
		for (int i = 0; i < length; i++)
		{
			if (b[i]==false)
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	//分两种情况，如果当前k要不要加进去。
	b[k] = false;    //1.如果不加，则直接进行下一个递归
	f(err_sum, arr, k + 1, cur_sum,length,b);

	b[k] = true;        //2.如果加了，cur_sum发生改变，也进行下一个递归
	cur_sum += arr[k];
	f(err_sum, arr, k + 1, cur_sum,length,b);

	b[k] = false;    //回溯
}

int main()
{
	int arr[] = { 3, 2, 4, 3, 1 };
	int sum = 6;
	int length = sizeof(arr) / sizeof(arr[0]);
	bool* b = new bool[length];   //用数组b 标记是否选取
	f(6, arr, 0,0,length,b);
	system("pause");
	return 0;
}
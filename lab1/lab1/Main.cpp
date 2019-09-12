#include <iostream>
using namespace std;

void method1()
{
	unsigned int m = 2147483646;
	int c = 5;
	int a = 3;
	int n = 1000;
	int start = 0;
	int x = 0;
	while (start < n)
	{
		double u;
		x = (a*x + c) % m;
		u = double(x) / double(m);
		cout << u << endl;
		start++;
	}

}

void method2()
{
	unsigned int m = 2147483646;
	int c = 5;
	int a = 3;
	int d = 4;
	int n = 1000;
	int start = 0;
	int x = 0;
	while (start < n)
	{
		double u;
		x = (d*x*x + a * x + c) % m;
		u = double(x) / double(m);
		cout << u << endl;
		start++;
	}
}

void method3()
{
	unsigned int m = 2147483646;
	int n = 1000;
	int start = 0;
	int x1 = 1;
	int x0 = 0;
	int a;
	while (start < n)
	{
		double u;
		a = (x1 + x0) % m;
		u = double(a) / double(m);
		cout << u << endl;
		x0 = x1;
		x1 = a;
		start++;
	}

}

int main()
{
	method1();

	system("pause");
	return 0;
}


 
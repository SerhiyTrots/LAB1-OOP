#define _USE_MATH_DEFINES
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

double method1(int x)
{
	unsigned int m = 2147483647;
	int c = 23;
	int a = 37;
	x = (a*x + c) % m;
	return x;
}

double method2(int x)
{
	unsigned int m = 2147483647;
	int c = 57;
	int a = 37;
	int d = 733;
	x = (d*x*x + a * x + c) % m;
	return x;
}

double method3(int x1, int x0)
{
	unsigned int m = 2000001;
	int x = (x1 + x0) % m;
	x0 = x1;
	x1 = x;
	return x;
}

double findReversal(int x)
{
	int p = 10141;
	for (int i = 1; i < p; i++)
	{
		if ((x*i) % p == 1)
			return i;
	}
}

double method4(int x)
{
	int p = 10141;
	int a = 234;
	int c = 1237;
	int xr = findReversal(x);
	x = (a*xr + c) % p;
	return x;
}

double method5(int a, int b)
{
	a = method1(a);
	b = method2(b);
	unsigned int m = 2147483647;
	return (a - b) % m;
}

double method6(int x1)
{
	unsigned int m = 2147483647;
	double sum = 0;
	for (int i = 1; i <= 12; i++)
	{
		x1 = method1(x1);
		sum += double(x1) / double(m);
	}
	return sum - 6;
}

double  method7(int a, int b, double * arr)
{
	unsigned int m = 2147483647;
	double a1, b1, v1, v2, s;
	do
	{
		a = method1(a);
		b = method2(b);
		a1 = a / double(m);
		b1 = b / double(m);
		v1 = 2 * a1 - 1;
		v2 = 2 * b1 - 1;
		s = v1 * v1 + v2 * v2;
	} while (s >= 1);
	double x1 = v1 * sqrt(((-2) * log(s) / log(M_E)) / s);
	double x2 = v2 * sqrt(((-2) * log(s) / log(M_E)) / s);
	arr[0] = x1;
	arr[1] = x2;
	return  arr[2];
}

double method8(int a, int b)
{
	unsigned int m = 2147483647;
	double a1, b1, x;
	do
	{
		a = method1(a);
		b = method2(b);
		a1 = a / double(m);
		b1 = b / double(m);
		x = sqrt(8 / M_E)*(a1 - 0.5) / b1;
	} while (x*x >= (-4)*(log(b1) / log(M_E)));
	return x;
}

double method9(int a)
{
	unsigned int m = 2147483647;
	a = method1(a);
	int fi = 31;
	double a1 = a / double(m);
	double x = (-fi)*(log(a1) / log(M_E));
	return x;
}

double method10(int a, int b)
{
	unsigned int m = 2147483647;
	double a1, b1, x, y;
	int k = 38;
	do
	{
		a = method1(a);
		b = method2(b);
		a1 = a / double(m);
		b1 = b / double(m);
		y = tan(M_PI*a1);
		x = sqrt(2 * k - 1)*y + k - 1;
	} while (x <= 0 || b1 > (1 + y * y)*exp((k - 1)*(log(x / (k - 1)) - sqrt(2 * k - 1)*y)));
	return x;
}


void gist()
{
	const int n = 1000;
	double arr[n];
	srand(time(NULL));
	arr[0] = rand();
	int number;
	cin >> number;
	srand(time(NULL));
	int x = rand();
	srand(time(NULL));
	int y = rand();
	switch (number)
	{
	case 1:
	{
		for (int i = 1; i < n; i++)
		{
			unsigned int m = 2147483647;
			arr[i] = method1(arr[i - 1]);
			arr[i - 1] = arr[i - 1] / double(m);
		}
		break;
	}
	case 2:
	{
		for (int i = 1; i < n; i++)
		{
			unsigned int m = 2147483647;
			arr[i] = method2(arr[i - 1]);
			arr[i - 1] = arr[i - 1] / double(m);
		}
		break;
	}
	case 3:
	{
		for (int i = 2; i < n; i++)
		{
			unsigned int m = 2000001;
			srand(time(NULL));
			arr[1] = rand();
			arr[i] = method3(arr[i - 1], arr[i - 2]);
			arr[i - 2] = arr[i - 2] / double(m);
		}
		break;
	}
	case 4:
	{
		for (int i = 1; i < n; i++)
		{
			unsigned int p = 10141;
			arr[i] = method4(arr[i - 1]);
			arr[i - 1] = arr[i - 1] / double(p);
		}
		break;
	}
	case 5:
	{
		for (int i = 1; i < n; i++)
		{
			unsigned int m = 2147483647;
			arr[i] = method5(method1(arr[i - 1]), method2(arr[i - 1]));
			arr[i - 1] = arr[i - 1] / double(m);
		}
		break;
	}
	case 6:
	{
		for (int i = 1; i < n; i++)
		{
			arr[i] = method6(x);
			x = method1(x);
		}
		break;
	}
	case 7:
	{
		for (int i = 1; i < n; i++)
		{
			double arr1[2];
			method7(x, y, arr1);
			arr[i - 1] = arr1[0];
			arr[i] = arr1[1];
			x = method1(x);
			y = method2(y);
		}
		break;
	}
	case 8:
	{
		for (int i = 1; i < n; i++)
		{
			arr[i] = method8(x, y);
			x = method1(x);
			y = method2(y);
		}
		break;
	}
	case 9:
	{
		for (int i = 1; i < n; i++)
		{
			arr[i] = method9(x);
			x = method1(x);
		}
		break;
	}
	case 10:
		for (int i = 1; i < n; i++)
		{
			arr[i] = method10(x, y);
			x = method1(x);
			y = method2(y);
		}
		break;
	}
	int count = 0;
	double begin, step, final;
	if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5)
	{
		begin = 0.0;
		step = 0.1;
		final = 0.9;
	}
	if (number == 6 || number == 7 || number == 8)
	{
		begin = -3.0;
		step = 0.5;
		final = 3.0;
	}
	if (number == 9 || number == 10)
	{
		begin = 0.0;
		step = 5.0;
		final = 100.0;
	}
	for (double intr = begin; intr < final; intr += step)
	{
		for (int i = 0; i < n; i++)
		{
			if ((arr[i] <= intr + step) && (arr[i] >= intr))
				count++;
		}
		cout << "[" << intr << " ; " << intr + step << "]" << "  " << count << endl;
		count = 0;
	}
}

int main()
{
	gist();

	system("pause");
	return 0;
}

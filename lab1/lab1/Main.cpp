#define _USE_MATH_DEFINES
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

double method1(int x)
{
	unsigned int m = 2147483647;
	int c = 5555555;
	int a = 3333335;
	x = (a*x + c) % m;
	return x;
}

double method2(int x)
{
	unsigned int m = 2147483647;
	int c = 5;
	int a = 3;
	int d = 4;
	x = (d*x*x + a * x + c) % m;
	return x;
}

double method3(int x, int x1, int x0)
{
	unsigned int m = 2147483647;
	x = (x1 + x0) % m;
	x0 = x1;
	x1 = x;
	return x;
}

double findReversal(double x)
{
	int p = 332423;
	for (int i = 1; i < p; i++)
	{
		if ((int(x)*i) % p == 1)
			return i;
	}

}

double method4(int x)
{
	int p = 12421;
	int a = 234;
	int c = 1234;
	unsigned int m = 2147483647;
	double xr = findReversal(x);
	x = int((a*xr + c)) % p;
	return x;
}


double method5(double a, double b)
{
	unsigned int m = 2147483647;
	return int((a - b)) % m;
}

double method6(unsigned int x1)
{
	unsigned int m = 2147483647;
	unsigned int arr[12];
	arr[0] = x1;
	double sum = 0;
	for (int i = 1; i < 12; i++)
	{
		arr[i] = method1(arr[i - 1]);
		sum += double(arr[i]) / double(m);
	}

	return sum - 6;
}
double  method7(double a, double b, double * arr)
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

double method8(double a, double b)
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
double method9(double a)
{
	unsigned int m = 2147483647;
	a = method1(a);
	int fi = 31;
	double a1 = a / double(m);
	double x = (-fi)*(log(a1) / log(M_E));
	return x;
}

void gist()
{
	const int n = 1000;
	double arr[n];
	srand(time(NULL));
	arr[0] = rand();
	double arrS[n];
	int number;
	cin >> number;
	srand(time(NULL));
	int x = rand();
	srand(time(NULL));
	int y = rand();
	for (int i = 1; i < n; i++)
	{
		switch (number)
		{
		case 1:
		{
			unsigned int m = 2147483647;
			arr[i] = method1(arr[i - 1]);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i] / double(m);
			}
			break;
		}
		case 2:
		{
			unsigned int m = 2147483647;
			arr[i] = method2(arr[i - 1]);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i] / double(m);
			}
			break;
		}
		case 3:
		{
			unsigned int m = 2147483647;
			arr[i] = method3(arr[i - 1], arr[i - 2], arr[i - 3]);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i] / double(m);
			}
			break;
		}
		case 4:
		{
			unsigned int m = 2147483647;
			arr[i] = method4(arr[i - 1]);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i] / double(m);
			}

		}
		case 5:
		{
			unsigned int m = 2147483647;
			arr[i] = method5(method1(arr[i - 1]), method2(arr[i - 1]));
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i] / double(m);
			}
			break;
		}
		case 6:
		{

			arr[i] = method6(x);
			x = method1(x);
			//cout << arr[i] << endl;
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i];
			}

			break;
		}
		case 7:
		{	double arr1[2];
		method7(x, y, arr1);
		arr[i - 1] = arr1[0];
		arr[i] = arr1[1];
		x = method1(x);
		y = method2(y);
		for (int i = 0; i < n; i++)
		{
			arrS[i] = arr[i];
		}

		}
		case 8:
		{

			arr[i] = method8(x, y);
			x = method1(x);
			y = method2(y);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i];
			}
			break;
		}
		case 9:
		{
			arr[i] = method9(x);
			x = method1(x);
			for (int i = 0; i < n; i++)
			{
				arrS[i] = arr[i];
			}
			break;
		}

		}
	}
	int count = 0;
	double begin;
	double step;
	double final;
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
		step = 10.0;
		final = 100.0;
	}
	for (double intr = begin; intr < final; intr += step)
	{
		for (int i = 0; i < n; i++)
		{

			if ((arrS[i] <= intr + step) && (arrS[i] >= intr))
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

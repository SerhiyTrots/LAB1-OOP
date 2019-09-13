#include <iostream>
#include <ctime>
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

double method5(double a, double b)
{
	unsigned int m = 2147483647;
	return int((a - b)) % m;
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
		}
	}
	int count = 0;
	for (double intr = 0.0; intr < 0.9; intr += 0.1)
	{
		for (int i = 0; i < n; i++)
		{

			if ((arrS[i] <= intr + 0.1) && (arrS[i] >= intr))
				count++;
		}
		cout << "[" << intr << " ; " << intr + 0.1 << "]" << "  " << count << endl;
		count = 0;
	}
}

int main()
{
	gist();

	system("pause");
	return 0;
}

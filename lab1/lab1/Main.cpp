 #include <iostream>
#include <ctime>
using namespace std;
 
unsigned int m = 2147483646;

double method1(int x)
{
	int c = 5;
	int a = 3;
	x = (a*x + c) % m;
	return x;
}

double method2(int x)
{
	int c = 5;
	int a = 3;
	int d = 4;
	x = (d*x*x + a * x + c) % m;
	return x;
}

double method3(int x, int x1, int x0)
{
	x = (x1 + x0) % m;
	x0 = x1;
	x1 = x;
	return x;
}

void gist()
{
	const int n = 1000;
	double arr[n];
	arr[0] = time(NULL);
	int number;
	cin >> number;
	for (int i = 1; i < n; i++)
	{
		switch (number)
		{
		case 1:
			arr[i] = method1(arr[i - 1]);
			break;
		case 2:
			arr[i] = method2(arr[i - 1]);
			break;
		case 3:
			arr[i] = method3(arr[i - 1], arr[i - 2], arr[i - 3]);
			break;
		}
	}
	int count = 0;
	for (double intr = 0.0; intr < 0.9; intr += 0.1)
	{
		for (int i = 0; i < n; i++)
		{
			double u = double(arr[i]) / double(m);
			if ((u <= intr + 0.1) && (u >= intr))
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

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
using namespace std;

void Create1(int* t, const int size, const int Low, const int High, int i)
{
	t[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create1(t, size, Low, High, i + 1);
}

void Print1(int* t, const int size, int i)
{
	cout << setw(4) << t[i];
	if (i < size - 1)
		Print1(t, size, i + 1);
	else
		cout << endl;
}


int Dob(int* t, int mini, int maxi, int i, int S)
{

		S *= t[i];
	if (i < maxi) 
		return Dob(t, mini, maxi, i + 1, S);

	return S;

}
int Max(int* t, const int size)
{
	int max = t[0];
	for (int i = 1; i < size; i++)
		if (abs(t[i]) > max)
			max = t[i];
	return max;
}
int Max1(int* t, const int size)
{
	int index = 0;
	int max = t[0];
	int i = 1;
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) > abs(max)) {
			max = t[i];
			index = i;
		}
	return index;
}
int FindMax(int* t, const int size, int i, int k, int min)
{
	if ((abs(t[i])) > abs(min)) {
		min = t[i];
		k = i;
	}
	if (i < size - 1)
		return FindMax(t, size, i + 1, k, min);
	else
		return k;
}

int Min(int* t, const int size)
{
	int min = t[0];
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) < abs(min))
			min = t[i];
	return min;
}
int Min1(int* t, const int size)
{
	int index = 0;
	int min = t[0];
	for (int i = 1; i < size; i++)
		if ((abs(t[i])) < abs(min)) {
			min = t[i];
			index = i;
		}
	return index;
}
int FindMin(int* t, const int size, int i, int k, int min)
{
	if ((abs(t[i])) < abs(min)) {
		min = t[i];
		k = i;
	}
	if (i < size - 1)
		return FindMin(t, size, i + 1,k, min);
	else
	return k;	
}

int Sum1(int* t, const int size, int i, int S)
{
	if (t[i] > 0)
		S += t[i];
	if (i < size - 1)
		return Sum1(t, size, i + 1, S);
	else
		return S;
}

void Sort1(int* t, const int size, int i) // i - параметр зовнішнього циклу
{ // ітераційної версії
	int min = t[i];
	int imin = i;
	for (int j = i + 1; j < size; j++)
		if (min < t[j])
		{
			min = t[j];
			imin = j;
		}
	t[imin] = t[i];
	t[i] = min;
	if (i < size - 2)
		Sort1(t, size, i + 1);
}
int main()
{
	srand((unsigned)time(NULL));

	int n;
	cin >> n;
	int* t = new int[n];

	int Low = -5;
	int High = 12;

	Create1(t, n, Low, High, 0);
	Print1(t, n, 0);
	cout << FindMin(t, n, 1, 0, abs(t[0])) << endl;
	cout << "max" << Max(t, n) << endl;
	cout << "min" << Min(t, n) << endl;

	cout << "syma" << Sum1(t, n,0,1) << endl;
	Min1(t, n);
	cout << "i max " << Max1(t, n) << endl;
	cout << "i min " << Min1(t, n) << endl;
	cout << "imax " << FindMax(t, n, 1, 0, abs(t[0])) << endl;
	cout << "imin " << FindMin(t, n, 1, 0, abs(t[0])) << endl;
	int mim = FindMin(t, n, 1, 0, abs(t[0]));
	int mam = FindMax(t, n, 1, 0, abs(t[0]));

	if (mim > mam)
	{
		int g = mam;
		mam = mim;
		mim = mam;
	}
	cout << "dobytok = " << Dob(t, mim, mam, mim, 1) << endl;
	Sort1(t, n, 0);
	Print1(t, n, 0);
	return 0;
}

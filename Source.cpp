#include <iostream>
#include <cstdlib>
using namespace std;

void Merge(double arr[], int l, int m, int r);

void copyArray(double *original, double *copyee, int start, int end,  int copyeestart)
{
	for (int i = start; i <= end; i++)
	{
		copyee[copyeestart] = original[i];
		copyeestart = copyeestart + 1;
	}
}


void MergeSort(double *arr, int arrLeft, int arrRight)
{
	if (arrRight > arrLeft)
	{
		int arrMid = arrLeft + ((-arrLeft + arrRight) / 2); //left side half will be bigger if odd
		MergeSort(arr, arrLeft, arrMid);
		MergeSort(arr, arrMid + 1, arrRight);
		Merge(arr, arrLeft, arrMid, arrRight);
	}
}


void Merge(double arr[], int l, int m, int r)
{
	// [arrLeft ... arrMid] & [arrMid+1 ... arrRight]
	int k, j, startL;
	int ArrayAlength = m - l + 1;
	int ArrayBlength = (r - (m + 1)) + 1;
	double *L = new double[ArrayAlength]; //temporary array will delete soon
	double *R = new double[ArrayBlength]; //ditto above
	copyArray(arr, L, l, m, 0);
	copyArray(arr, R, m + 1, r, 0);
	startL = l;
	k = 0;
	j = 0;
	while (k < ArrayAlength && j < ArrayBlength)
	{
		if (L[k] < R[j])
		{
			arr[startL] = L[k]; //L is smaller
			k++;
		}
		else
		{
			arr[startL] = R[j]; //R is smaller or equal
			j++;
		}
		startL++;
	}
	//append the leftovers
	while (k < ArrayAlength)
	{
		arr[startL] = L[k];
		k++;
		startL++;
	}
	while (j < ArrayBlength)
	{
		arr[startL] = R[j];
		j++;
		startL++;
	}
	delete[] L;
	delete[] R;
}


int main()
{
	//to pause cmd prmpt
	int n = 10;
	double *testArray = new double[n];
	for (int i = 0; i < n; i++)
	{
		testArray[i] = rand() % 1000 + (rand()%100+1.00)/100.00;
	}

	//before merge sort
	cout << "Before Merge Sort\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": -> " << testArray[i] << endl;
	}
	MergeSort(testArray, 0, n-1);
	cout << "After Merge Sort\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": -> " << testArray[i] << endl;
	}
	delete[] testArray;
	int userResponse;
	cout << "Exiting...\n";
	cin >> userResponse;
	return 0;
}
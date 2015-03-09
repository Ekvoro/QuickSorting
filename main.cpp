#include<iostream>

using namespace std;

/** \file: main.cpp
*/

/// The function, realizing quick sort algorithm

/** Takes three arguments, does not return anything
	\param *mas Pointer to an array
	\param left Left (first) element of the array
	\param right Right (last) element of the array
*/

void quicksort(int *mas, int left, int right)
{
	/// int l = left, r = right 
	/** Write the values of the elements in the local variables */
	int l = left, r = right;
	/// int mid = mas[(l + r) / 2] 
	/** Find the middle element */
	int mid = mas[(l + r) / 2];

	///The process of sorting
	/**
	1) Index l shifts with step of one element to the end of the array until mas[l]>mid.
	And index r shifts from the end of array to its beginning until mas[r]<mid;
	*/
	/** 2) Every two found elements are swaped */
	/** 3) Items 1) and 2) are made until l<r */
	do 
	{
		while (mas[l] < mid) l++;
		while (mas[r] > mid) r--;
		if (l <= r)
		{
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
	} while (l < r);

	/**
	If there is more than one element in some part, obtained as a result of the decomposition of the array,
	you should make a recursive ordering this part
	*/

	if (left < r) quicksort(mas, left, r);
	if (l < right) quicksort(mas, l, right);
}

/// The main function

int main()
{
	/// int n 
	/** The number of elements in the array */
	int n;
	/// Enter the number of array elements
	cin >> n; 
	/// int *a 
	/** A pointer to an array of elements */
	int *a = new int[n];
	/// Enter the values of array elements
	for (int i = 0; i < n; i++)
		cin >> a[i];
	/// Call quicksort function
	quicksort(a, 0, n - 1);
	/// Print of the resulting array
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	delete[]a;
	return 0;
}


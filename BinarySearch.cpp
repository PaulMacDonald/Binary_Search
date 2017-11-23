#include<iostream>
#include<vector>
using namespace std;

// PROTOTYPE
template <typename T>
bool bSearch(vector<T> &a, int lo, int hi, T X);

// (JUST FOR TESTING...)
int main()
{
	vector<int> someStupidNumbers = { -1, 3, 5, 10, 12, 21, 42, 89, 101, 879 };

	cout << "Enter the number you'd like to search for: ";
	int numberToFind;
	cin >> numberToFind;

	cout << boolalpha;

	if (bSearch(someStupidNumbers, 0, someStupidNumbers.size(), numberToFind))
		cout << "You've found me!" << endl;

	else
		cout << "Sorry... couldn't find nothin'." << endl;

	return 0;
}

template <typename T>
bool bSearch(vector<T> &a, int lo, int hi, T X)
{
	if (hi - lo < 0) return false; // Return false if the vector is empty...

	int m = (lo + hi) / 2; // Find the middle value and set it as "m"

	if (X == a[m]) return true; // found
	
	if (X < a[m])
		return bSearch(a, lo, m - 1, X); // search the section before "m"

	else
		return bSearch(a, m + 1, hi, X); // search the section after "m"
}
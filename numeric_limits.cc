#include <limits>
#include <iostream>

using namespace std;

int main()
{
	cout << sizeof(int)
		<< " " << numeric_limits<int>::digits
		<< " " << numeric_limits<int>::digits10
		<< " " << numeric_limits<int>::min()
		<< " " << numeric_limits<int>::max()
		<< endl;
	cout << sizeof(long long)
		<< " " << numeric_limits<long long>::digits
		<< " " << numeric_limits<long long>::digits10
		<< " " << numeric_limits<long long>::min()
		<< " " << numeric_limits<long long>::max()
		<< endl;
}

#include <iostream>

using namespace std;

int main()
{
	long long pattern[50];
	int n;

	pattern[0] = 1;
	pattern[1] = 2;
	pattern[2] = 4;

	for (int i = 3; i < 40; ++i)
	{
		pattern[i] = pattern[i-1] + pattern[i-2] + pattern[i-3];
	}

	while (cin >> n && n != 0)
		cout << pattern[n-1]/3650 + 1 << endl;
}

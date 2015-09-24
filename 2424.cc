#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int get_max_delimiter(int n)
{
	int decit = 1;
	while ((n/=10))
		decit*=10;
	return decit;
}

int get_next(int n)
{
	int maximum = 0;
	int max_delimiter = get_max_delimiter(n);
	int val;

	for (int delimiter = 10; delimiter <= max_delimiter; delimiter*=10)
	{
		val = (n / delimiter) * (n % delimiter);
		maximum = maximum < val ? val : maximum;
	}
	return maximum;
}

int check(int n)
{
	set<int> log;
	int cnt = 0;
	while (n >= 10)
	{
		if (log.find(n) != log.end())
			return -1; /* infinite */
		log.insert(n);

		n = get_next(n);
		++cnt;
	}
	return cnt;
}

int main()
{
	int q, n;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> n;
		cout << check(n) << endl;
	}
}

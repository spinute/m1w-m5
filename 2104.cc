#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x[100007], m;

int main()
{
	cin >> m;
	for (int j = 0; j < m; ++j)
	{
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> x[i];

		int dest[100007];
		for (int i = 0; i < n - 1; ++i)
			dest[i] = x[i + 1] - x[i];

		sort(dest, dest + n - 1);

		long long sum = 0;
		for (int i = 0; i < n-k; ++i)
			sum += dest[i];

		cout << sum << endl;
	}
}

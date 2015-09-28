#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int
main()
{
	int n, m;
	while (cin >> n >> m && (n != 0 || m != 0))
	{
		int sum = 0;
		pair <int, int> dp[10000]; /* prob, distance*/

		for (int i = 0; i < n; ++i)
			cin >> dp[i].second >> dp[i].first;

		sort(dp, dp+n, [](pair<int,int> a, pair<int, int>b){return a > b;});

		for (int i = 0; i < n; ++i)
		{
			if (m >= dp[i].second)
				m -= dp[i].second;
			else
			{
				sum += dp[i].first * (dp[i].second - m);
				m = 0;
			}
		}

		cout << sum << endl;
	}

}

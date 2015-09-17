#include <iostream>
#include <map>

using namespace std;

int
main(void)
{
	for (;;)
	{
		int a[1500], b[1500];
		map<int, int> map_a, map_b;
		int N, M;
		int ans = 0;

		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		for (int i = 0; i < M; i++)
			cin >> b[i];

		for (int i = 0; i < N; i++)
		{
			int length = 0;
			for (int j = i; j < N; j++)
			{
				length += a[j];
				map_a[length]++;
			}
		}

		for (int i = 0; i < M; i++)
		{
			int length = 0;
			for (int j = i; j < M; j++)
			{
				length += b[j];
				map_b[length]++;
			}
		}

		for (auto ite = map_a.begin(); ite != map_a.end(); ite++)
			ans += map_b[ite->first] * ite->second;

		cout << ans << endl;
	}
}

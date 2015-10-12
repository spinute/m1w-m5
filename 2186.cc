#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int n;
	cin >> n;

	bool from_l[100][100];
	bool from_u[100][100];
	long long map[100][100];

	for (int i = 0; i < n; ++i)
	{
		int gx, gy, p;
		cin >> gx >> gy >> p;

		for (int j = 0; j < 100; ++j)
			for (int k = 0; k < 100; ++k)
			{
				from_l[j][k] = from_u[j][k] = true;
				map[j][k] = 0;
			}

		int x1, x2, y1, y2;
		for (int j = 0; j < p; ++j)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
			{
				int big = y1 > y2 ? y1 : y2;
				from_u[x1][big] = false;
			}
			else
			{
				int big = x1 > x2 ? x1 : x2;
				assert(y1 == y2);
				from_l[big][y1] = false;
			}
		}

		for (int x = 0; x <= gx; ++x)
		{
			for (int y = 0; y <= gy; ++y)
			{
				int cnt = 0;
				if (x == 0 && y == 0)
					cnt = 1;
				else if (x == 0)
					cnt += from_u[x][y] ? map[x][y-1] : 0;
				else if (y == 0)
					cnt += from_l[x][y] ? map[x-1][y] : 0;
				else
				{
					if (from_l[x][y])
						cnt += map[x-1][y];
					if (from_u[x][y])
						cnt += map[x][y-1];
				}

				map[x][y] = cnt;
			}
		}

		for (int j = 0; j <= gy; ++j)
			for (int k = 0; k <= gx; ++k)
				;//cout << map[k][j] << (gx-1==k?"\n":" ");

		if (map[gx][gy] == 0)
			cout << "Miserable Hokusai!" << endl;
		else
			cout << map[gx][gy] << endl;
	}
}

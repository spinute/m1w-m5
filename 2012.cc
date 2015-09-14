#include <iostream>

using namespace std;

int
main(void)
{
	int e;
	while (cin >> e)
	{
		int x, y, z;
		int ans = 1000000;

		if (e == 0)
			break;

		for (z = 0; z <= 100; z++)
		{
			for (y = 0; y <= 1000; y++)
			{
				x = e - z*z*z - y*y;
				if (x >= 0)
					ans = ans < x+y+z ? ans : x+y+z;
			}
		}

		cout << ans << endl;
	}

	return 0;
}

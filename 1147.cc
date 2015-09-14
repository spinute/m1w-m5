#include <iostream>

using namespace std;

int
main(void)
{
	int n;

	cin >> n;
	while(n != 0)
	{
		int max = -1, min = 1001;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			int m;
			cin >> m;

			if (max < m)
				max = m;

			if (min > m)
				min = m;

			sum += m;
		}



		cin >> n;
	}


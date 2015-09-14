#include <iostream>

using namespace std;

int
main(void)
{
	for (;;)
	{
		int a[1500*1500];
		int b[1500*1500];
		int N, M;
		int total_b, rest_b;
		int length_a, length_b;
		int ans = 0;
		cin >> N >> M;

		/* not implemented: if total_a < total_b then loop shoulde be inversed */

		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++)
			cin >> a[i];

		for (int i = 0; i < M; i++)
		{
			cin >> b[i];
			total_b += b[i];
		}
		rest_b = total_b;

		for (int i = 0; i < N; i++)
		{
			length_a = 0;
			for (int j = i; j < N; j++)
			{
				length_a += a[j];

				rest_b = total_b;
				for (int k = 0; k < M; k++)
				{
					length_b = 0;
					for (int l = k; l < M; l++)
					{
						length_b += b[k];

						if (length_a == length_b)
							ans++;

						if (length_a <= length_b)
							break;
					}

					rest_b -= b[k];
					if (rest_b == length_a)
						ans++;
					if (rest_b < length_a)
						break;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}

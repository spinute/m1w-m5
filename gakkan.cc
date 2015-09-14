#include <iostream>

using namespace std;

int
main(void)
{
	int n;
	int *power;

	cin >> n;

	power = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		cin >> power[i];

	{
		int *max_ary = malloc(sizeof(int) * n);
		int flag;

		/* assuming that n > 2 */
		if (power[0] > 0)
			max_ary[0] = power[0];
		else
			power[0] = 0;

		max_ary[1] = max_ary[0] > power[1] ? max_ary[0] : power[1];

		for (int i = 2; i < n; i++)
		{
			flag = max_ary[i-1] == max_ary[i-2] ? 1 : 0;
			max_ary[i] = max(                power[i] + max_ary[i-2],
							 (1-flag[i-1]) * power[i] + max_ary[i-1];
		}
	}
}

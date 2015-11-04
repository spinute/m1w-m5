#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(;;)
	{
		int price[] = {10, 50, 100, 500, 1000};
		int n_coins[5];
		for (int i = 0; i < 4; ++i)
			cin >> n_coins[i];
		n_coins[4] = 0;

		for (int i = 0; i < 4; ++i)
		{
			int rate = price[i+1] / price[i];
			int base = (n_coins[i] / rate) * rate;
			int res = n_coins[i] - base;
			int req_res = n % price[i+1] / price[i];
			int num;

			if (n < n_coins[i] * price[i])
			{
				int cover = n - n % price[i];
				cover += n % price[i] ? price[i] : 0;

				if (i != 3)
				{
					num = (n_coins[i] - cover) / rate * rate + cover;
					n = 0;
				}
				else
					num = cover;
			}
			else if (req_res > res && base != 0)
			{
				num = req_res + base - rate;
				n -= num * price[i];
			}
			else
			{
				num = req_res + base;
				n -= num * price[i];
			}

			if (num != 0)
				cout << price[i] << " " << num << endl;
		}

		cin >> n;
		if (n == 0)
			break;
		cout << endl;
	}
}

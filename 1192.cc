#include <iostream>
#include <algorithm>

#define tax(x, v) (v * (100 + x) / 100)

using namespace std;

int main()
{
	int sum, p, n;
	while ((cin >> p >> n >> sum && p != 0) || n != 0 || n != 0)
	{
		int sup = 0;

		for (int i = 1; i < sum; ++i)
			for (int j = i; j < sum; ++j)
				if (tax(p, i) + tax(p, j) == sum)
					sup = max(sup, tax(n, i) + tax(n, j));

		cout << sup << endl;
	}
}

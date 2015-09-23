#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void print_vec(vector<int> &vec)
{
	for (auto e:vec)
		cout << e << " ";
	cout << endl;
}

int main()
{
	int n, r;
	while (cin >> n >> r && n > 0 && r > 0)
	{
		vector<int> dec;
		for (int i = 0; i < n; ++i)
			dec.push_back(n - i);

		for (int i = 0; i < r; ++i)
		{
			int p, c;
			cin >> p >> c;
			rotate(dec.begin(), dec.begin() + p - 1, dec.begin() + p - 1 + c);
		}

		cout << dec[0] << endl;
	}
}

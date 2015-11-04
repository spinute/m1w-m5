#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int lcm = 55440;
	int n;

	while (cin >> n && n != 0) {
		int sum[lcm] = {0};
		int maximum = 0;

		for (int i = 0; i < n; ++i) {
			int d, t;
			vector<int> q;
			cin >> d >> t;

			int input;
			for (int j = 0; j < d; ++j) {
				cin >> input;
				q.push_back(input);
			}

			if (d == 13 || d == 17 || d == 19 || d == 23)
				maximum += *max_element(q.begin(), q.end());
			else {
				rotate(q.begin(), q.begin() + t, q.end());

				for (int j = 0; j < lcm; ++j)
					sum[j] += q[j % d];
			}
		}

		/*
		for (int j = 0; j < lcm; ++j)
			cout << sum[j] << " ";
		cout << endl;
		*/

		maximum += *max_element(sum, sum+lcm);

		cout << maximum << endl;
	}
}

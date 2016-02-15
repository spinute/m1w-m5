#include <iostream>
#include <algorithm>

using namespace std;

int BIT[1000007], bit_size;

void init_bit(int n) {
	fill(BIT, BIT+n, 0);
	bit_size = n;
}

int calc_sum(int n) {
	int ans = 0;
	while (n > 0) {
		ans += BIT[n];
		n &= n-1;
	}
	return ans;
}

void add_bit(int n, int v) {
	while (n <= bit_size) {
		BIT[n] += v;
		n += n & (-n);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	init_bit(n);

	for(int i = 0; i < q; ++i) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 0)
			add_bit(x, y);
		else
			cout << calc_sum(y) - calc_sum(x-1) << endl;
	}
}

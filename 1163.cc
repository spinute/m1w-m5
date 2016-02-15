#include <iostream>

using namespace std;

int m, n;
int b[500], r[500];
int pr[500];
bool v[500];
bool D[500][500];

bool match(int i) {
	if (i < 0)
		return true;
	for (int j = 0; j < n; ++j) {
		if (!D[i][j] || v[j])
			continue;
		v[j] = true;
		if (match(pr[j])) {
			pr[j] = i;
			return true;
		}
	}
	return false;
}


int
calc_gcd(int i, int j) {
	int big = i<j ? j : i;
	int small = i<j ? i : j;
	return small == 0 ? big : calc_gcd(small, big%small);
}

void
solve() {
	fill(pr, pr+n, -1);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			D[i][j] = (calc_gcd(b[i], r[j]) > 1);

	int count = 0;
	for (int i = 0; i < m; ++i) {
		fill(v, v+m, false);
		if (match(i))
			++count;
	}

	cout << count << endl;
}

int
main() {
	while (cin >> m >> n && (m != 0 || n != 0)) {
		for (int i = 0; i < m; ++i)
			cin >> b[i];
		for (int i = 0; i < n; ++i)
			cin >> r[i];

		if (m == 0 || n == 0)
			cout << 0 << endl;
		else
			solve();
	}
}

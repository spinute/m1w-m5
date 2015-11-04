#include <iostream>
#include <array>

using namespace std;

int s[10], d[10];
int n, dist, m;

bool
is_valid(int i, int j, int k)
{
	if (s[i] > s[j])
		return true;

}

int
main()
{
	cin >> dist >> n;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	cin >> m;

	for (int i = 0; i < m; ++i)
		cin >> d[i];

	int min = INT_MAX;

	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				is_valid(i, j, k);
			}
		}
	}
}

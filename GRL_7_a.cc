#include <iostream>
#include <algorithm>

using namespace std;

int nx, ny, ne;
bool e[100][100] = {};
bool v[100];
int py[100];

bool
match(int i){
	if (i < 0)
		return true;
	if (v[i])
		return false;
	v[i] = true;
	for (int y = 0; y < ny; ++y) {
		if (!e[i][y])
			continue;
		if (match(py[y])) {
			py[y] = i;
			return true;
		}
	}
	return false;
}

int
main() {
	cin >> nx >> ny >> ne;

	for (int i = 0; i < ne; ++i) {
		int x, y;
		cin >> x >> y;
		e[x][y] = true;
	}

	fill(py, py+ny, -1);
	int count = 0;

	for (int i = 0; i < nx; ++i) {
		fill(v, v+nx, false);
		if (match(i))
			++count;
	}

	cout << count << endl;
}

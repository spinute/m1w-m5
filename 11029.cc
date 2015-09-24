#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	/* for (int i=0; i<n; ++i) cout << (i?" ":"") << v[i];*/
	for (int i = 0; i < n; ++i)
	{
		cout << v[i];
		if (i != n - 1)
			cout << " ";
		else
			cout << endl;
	}
}

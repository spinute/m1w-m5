#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> str[i];
	sort(str, str+n);
	cout << str[0] << endl;
}

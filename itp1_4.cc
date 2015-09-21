#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int max = INT_MIN, min = INT_MAX;
	long long sum = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;

		max = max < val ? val : max;
		min = min > val ? val : min;
		sum += val;
	}

	printf("%d %d %lld\n", min, max, sum);
}

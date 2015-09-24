#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> car;
	int n, k, t, u, v, l;
	int n_car = 0;
	int doping_remain = 0;
	double time = 0;
	cin >> n >> k >> t >> u >> v >> l;

	for (int i = 0; i < n; ++i)
	{
		int in;
		cin >> in;
		car.push(in);
	}

	for (int i = 0; i < l; ++i)
	{
		if (car.front() == i)
		{
			if (n_car == k)
				doping_remain = t*v;
			else
				++n_car;
			car.pop();
		}

		if (doping_remain == 0 && n_car > 0)
		{
			--n_car;
			doping_remain = t * v;
		}

		if (doping_remain > 0)
			time += 1/(double)v;
		else
			time += 1/(double)u;

		if (doping_remain > 0)
			--doping_remain;
	}
	printf("%.8lf\n", time);
}

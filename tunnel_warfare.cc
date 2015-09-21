#include <stack>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

void print_set(set<int> &se)
{
	for (set<int>::iterator ite = se.begin(); ite != se.end(); ite++)
		cout << *ite << " ";

	cout << endl;
}

int main()
{
	stack<int> st;
	set<int> se;
	int n_op, n_vil;

	scanf("%d %d", &n_vil, &n_op);

	se.insert(0);
	se.insert(n_vil+1);

	for (int i = 0; i < n_op; i++)
	{
		char c[2];
		int val;
		scanf("%s", c);

		if (c[0] == 'D')
		{
			scanf("%d", &val);
			st.push(val);
			se.insert(val);
		}
		else if (c[0] == 'Q')
		{
			scanf("%d", &val);
			set<int>::iterator lower = se.lower_bound(val);
			if (val == *lower)
				printf("0\n");
			else
				printf("%d\n", *lower - *(--lower) - 1);
		}
		else // R
		{
			val = st.top();
			st.pop();
			se.erase(val);
		}

		//print_set(se);
	}
}

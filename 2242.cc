#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n, q;

	while (cin >> n >> q && n != 0 && q != 0)
	{
		map<int, string> last_era;
		map<string, int> era_dur;

		for (int i = 0; i < n; ++i)
		{
			string name;
			int jy, wy;
			cin >> name >> jy >> wy;

			last_era[wy] = name;
			era_dur[name] = era_dur[name] < jy ? jy : era_dur[name];
		}

		for (int i = 0; i < q; ++i)
		{
			int que;
			cin >> que;
			auto ite = last_era.lower_bound(que);
			string name = ite->second;

			while (true)
			{
				auto next = ite;
				if (ite != last_era.end())
					next++;
				int dur = era_dur[name];
				int last = ite->first;

				if (last - dur + 1 > que && (next == last_era.end() || ite->second != next->second))
				{
					cout << "unknown\n";
					break;
				}
				else if (last - dur + 1 <= que)
				{
					cout << name << " " << que - (last - dur) << endl;
					break;
				}
				else
					ite = next;
			}
		}
	}
}

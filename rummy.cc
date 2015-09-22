#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

void print_cards(array<int, 9> &card)
{
	for (auto e:card)
		cout << e << " ";

	cout << endl;
}

bool is_same_card(int a, int b, int c)
{
	return a == b && b == c;
}

bool is_seq(int a, int b, int c)
{
	return a + 1 == b && c - 1 == b;
}

bool is_set(int a, int b, int c)
{
	return is_same_card(a, b, c) || is_seq(a, b, c);
}

bool is_win(array<int, 9>card)
{
	sort(card.begin(), card.end());

	do
	{
		//print_cards(card);
		if (is_set(card[0], card[1], card[2]) &&
			is_set(card[3], card[4], card[5]) &&
			is_set(card[6], card[7], card[8]))
			return true;
	} while (next_permutation(card.begin(), card.end()));

	return false;
}

int main()
{
	array<int, 9> card;
	int n;
	cin >> n;

	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < 9; ++i)
			cin >> card[i];

		for (int i = 0; i < 9; ++i)
		{
			string col;
			cin >> col;
			if (col == "R")
				card[i] += 10;
			if (col == "G")
				card[i] += 20;
		}
		//print_cards(card);

		if (is_win(card))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}

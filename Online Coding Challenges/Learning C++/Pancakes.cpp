#include "library.h"

void main()
{
	int pancakes[10];
	int greatest = 0;
	int person;
	for (int x = 0; x < 10; x++)
	{
		cout << "How many pancakes did person " << x + 1 << " eat? ";
		cin >> pancakes[x];
		if (pancakes[x] > greatest)
		{
			greatest = pancakes[x];
			person = x + 1;
		}
	}
	cout << endl << "Person " << person << " ate the most pancakes: " << greatest << endl << endl;
	for (int x = 0; x < 10; x++)
	{
		if (pancakes[x] != 1)
			cout << "Person " << x + 1 << ": ate " << pancakes[x] << " pancakes" << endl;
		else
			cout << "Person " << x + 1 << ": ate " << pancakes[x] << " pancake" << endl;
	}
}
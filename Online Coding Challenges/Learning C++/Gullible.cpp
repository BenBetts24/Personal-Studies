#include "library.h"

void original()
{
	int number = 0;
	int count = 0;
	while (number != 5 && count < 10)
	{
	cout << "Please enter a number other than 5: ";
	cin >> number;
	if (number != 5)
		count++;
	}
	if (number == 5)
		cout << "Hey! You weren't supposed to enter 5!";
	else
		cout << "Wow, you're more patient than I am.";
}
void main()
{
	int number = 0;
	int count = -1;
	while (number != count && count < 9)
	{
		count++;
		cout << "Please enter a number other than " << count << ": ";
		cin >> number;
	}
	if (number == count)
		cout << "Hey! You weren't supposed to enter " << number << "!";
	else
		cout << "Wow, you're more patient than I am.";
}

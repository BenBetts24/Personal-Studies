#include "library.h"
#include <stdlib.h>

void playerGuess()
{
	int number = (1 + (rand() % 100));
	int guess;
	int guesses = 0;
	do {
	cout << "Please guess a number from 1 to 100: ";
	cin >> guess;
	guesses++;
	if (guess > number)
		cout << "Your guess was too high!\n";
	else if (guess < number)
		cout << "Your guess was too low!\n";
	} while (guess != number);
	cout << endl << "Nice job! It took you " << guesses << " guesses to figure out the number " << number << "!";
}
void thinking()
{
	sleep(1);
	cout << "." << endl;
	sleep(1);
	cout << "." << endl;
	sleep(1);
	cout << "." << endl;
}

void main()
{
	int boundaryHigh = 100;
	int boundaryLow = 1;
	int guess = (1 + (rand() % 100));
	int guesses = 1;
	char input = 'a';
	
	cout << "Think of a number from 1 to 100 and I'll try to guess it!" << endl;
	while (input != 'c' && input != 'C')
	{
		thinking();
		cout << "Is your number " << guess << "?" << endl;
		cout << "If my guess was too high, enter H. If it was too low, enter L. If it was correct, enter C." << endl;
		cin >> input;

		switch (input){
			case ('h' | 'H'):
				boundaryHigh = guess;
				guess = (boundaryLow + (rand() % (boundaryHigh-boundaryLow)));
				guesses++;
				break;
			case('l' | 'L'):
				boundaryLow = guess;
				guess = (boundaryLow + (rand() % (boundaryHigh-boundaryLow)));
				guesses++;
				break;
			case('c' | 'C'):
				cout << endl << "Great! Your number was " << guess << "!" << endl;
				cout << "It took me " << guesses << " guesses to figure it out!" << endl;
				break;
			default:
				cout << "That is not a valid input!" << endl;
				break;
			}
	}
}
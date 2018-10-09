#!bin/bash
# Created by Ben on 6/13/18 to test bash scripting

count=1
upper=100
lower=1
rand=$(python -c "import random; print(random.randint($lower,$upper))")

function changeBounds {
	read -p "Was my guess too high or too low? [high/low] " guess
		while [[ ! $guess =~ high|low ]]; do
			read -p "Please pick only high or low " guess
		done

	case $guess in
		high) upper=$(($1 - 1));;
		low) lower=$(($1 + 1));;
	esac

	rand=$(python -c "import random; print(random.randint($lower,$upper))")
}


clear
echo "Welcome to the number guessing game!"
cat <<- EOF
	The instructions are simple:

	You pick a number between 1 and 100,
	and I'll try to guess it in 7 tries or less!
	All you have to do is tell me whether my guess was too high or too low.

	If I can guess it in 7 tries or less, I win!
	If I can't, then you win!

	Make sure to be honest!
	

	EOF
read -p "Press enter to begin!" trash
clear

read -p "Is $rand your number? [y/n] " answer
	while [[ $answer == "n" ]]; do
		((count++))
		changeBounds $rand
		echo
		read -p "Is $rand your number? [y/n] " answer
	done

if [ $count -gt 7 ]; then
	echo "It took me $count tries, you win!"
elif [ $count == 1 ]; then
	echo "I guessed it in 1 try, I win!"
else
	echo "I guessed it in $count tries, I win!"
fi

echo
read -p "Press enter to quit." trash
clear

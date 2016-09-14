/*  Taylor Jenkins
03-29-16*/

/* Rock, Paper, Scissors Game: lets the user play the game of Rock, Paper, Scissors against the
computer.*/

#include <stdio.h>    
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

//Prototypes:
int getUserChoice(int);
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);
bool playAgain();
void displayUserChoice(int);


//*****************************************
// Function main                          *
//*****************************************
int main()
{
	//Variables:
	int userChoice = 0;
	int computerChoice;

	cout << "Let's play a game!\n";

	do
	{
		//Generate random number for computer choice
		computerChoice = getComputerChoice();
		//reinitialize userChoice to 0
		userChoice = 0;
		// Get user choice from user input
		userChoice = getUserChoice(userChoice);
		// Displays the user's choice
		displayUserChoice(userChoice);
		// Displays the computer's choice
		displayChoice(computerChoice);
		// Determines the winner
		determineWinner(computerChoice, userChoice);
	} while (playAgain());

	return 0;
}

//*********************************************
// Definition of function int getUserChoice() * 
// ask the user to choose rock, paper or      *
// scissors with 1 being rock, 2 being paper  *
// and 3 being scissors.                      *
//*********************************************
int getUserChoice(int userChoice)
{
	do
	{
		switch (userChoice)
		{
		case 1:
			cout << "1: Rock\n";
			break;

		case 2:
			cout << "2. Paper\n";
			break;

		case 3:
			cout << "3. Scissors\n";
			break;

		default:
			cout << endl << "Please enter 1 for rock, 2 for paper, or 3 for scissors.\n";
			cin >> userChoice;
		}
	} while (userChoice <= 0 || userChoice > 3);

	return userChoice;
}

//**************************************************
// Definition of function int getComputerChoice(); *
// Generates a random number 1-3 with 1 being rock *
// 2 being paper, and 3 being scissors. This       *
// generated number will be the computer choice    *
//**************************************************
int getComputerChoice()
{
	/* initialize random seed: */
	srand (time(NULL));
	int computerChoice = rand() % 3 + 1;

	return computerChoice;
}

//**********************************************
// Definition of function void determineWinner *
// Determines the winner based off of the      *
// user choice and the computer's choice.      *
//**********************************************
void determineWinner(int computerChoice, int userChoice)
{
	if (computerChoice == 1 && userChoice == 3)
	{

		cout << "The rock smashes the scissors!\n";
		cout << "You lose.\n";
	}
	else if (computerChoice == 3 && userChoice == 1)
	{
		cout << "The rock smashes the scissors!\n";
		cout << "You win!\n";
	}
	else if (computerChoice == 2 && userChoice == 1)
	{

		cout << "Paper covers the rock!\n";
		cout << "You lose.\n";
	}
	else if (computerChoice == 1 && userChoice == 2)
	{
		cout << "Paper covers the rock!\n";
		cout << "You win!\n";
	}
	else if (computerChoice == 3 && userChoice == 2)
	{

		cout << "Scissors cuts paper!\n";
		cout << "You lose.\n";
	}
	else if (computerChoice == 2 && userChoice == 3)
	{
		cout << "Scissors cuts paper!\n";
		cout << "You win!\n";
	}
	else
	{
		cout << "It's a tie! Let's play again!\n";
	}
}

//**************************************************
// Definition of function void  displayUserChoice  *
// Display's the user's choice to make output less *
// confusing for user.                             *
//**************************************************
void displayUserChoice(int userChoice)
{
	if (userChoice == 1)
	{
		cout << "You chose: Rock!\n";
	}
	else if (userChoice == 2)
	{
		cout << "You chose: Paper!\n";
	}
	else if (userChoice == 3)
	{
		cout << "You chose: Scissors!\n";
	}
}

//********************************************
// Definition of function void displayChoice *
// Displays the computer's choice to make    *
// output less confusing for user.           *
//********************************************
void displayChoice(int computerChoice)
{
	if (computerChoice == 1)
	{
		cout << "The computer chose: Rock!\n";
	}
	else if (computerChoice == 2)
	{
		cout << "The computer chose: Paper!\n";
	}
	else if (computerChoice == 3)
	{
		cout << "The computer chose: Scissors!\n";
	}
}

//*****************************************
// Definition of function void continue() *
// Let the user decide if they want to    *
// play the game again.                   *
//*****************************************

bool playAgain()
{
	int play = 0;

	cout << "\n1. Play again.\n";
	cout << "2. Quit.\n";
	cin >> play;

	if (play == 1 || play == 2)
	{
		if (play == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "ERROR: Invaild choice. Choose 1 to replay the game or choose 2 to quit." << endl;
		playAgain();
	}
}

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enGame { stone = 1, paper = 2, scissors = 3 };

int readnumberFromTo(string massage, int from, int to)
{
	int num;
	do
	{
		cout << massage;//"How Many Rounds Do You Wnts To Play?: Enter From [1] To [10]: "  
		cin >> num;
	} while (num<from || num>to);

	return num;
}
string readAnswr(string massage)
{
	string YES;
	cout << massage;//"Do You WantTo Play Again? Type [yes]: "
	cin >> YES;

	return YES;
}
int randomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}
enGame playerChooseWeapon()
{
	int weapon = readnumberFromTo("Enter [1] for Stone , [2] for Paper, [3] for Scissors: ", 1, 4);

	if (weapon == 1)
		return enGame::stone;

	else if (weapon == 2)
		return enGame::paper;

	else if (weapon == 3)
		return enGame::scissors;
}
enGame computerChooseWeapon()
{
	int weapon = randomNumber(1, 3);

	if (weapon == 1)
		return enGame::stone;

	else if (weapon == 2)
		return enGame::paper;

	else if (weapon == 3)
		return enGame::scissors;
}
int checkWinner(enGame player, enGame computer)
{
	if (player == enGame::stone && computer == enGame::scissors)
		return true;
	else if (player == enGame::stone && computer == enGame::paper)
		return false;
	else if (player == enGame::stone && computer == enGame::stone)
		return -1;

	else if (player == enGame::scissors && computer == enGame::scissors)
		return -1;
	else if (player == enGame::scissors && computer == enGame::paper)
		return true;
	else if (player == enGame::scissors && computer == enGame::stone)
		return false;

	else if (player == enGame::paper && computer == enGame::scissors)
		return false;
	else if (player == enGame::paper && computer == enGame::paper)
		return -1;
	else if (player == enGame::paper && computer == enGame::stone)
		return true;

}
void showResult(int winner, int& player, int& computer, int& even, int roundNum)
{


	cout << "\n___Round Number[" << roundNum << "]___\n";
	if (winner == true)
	{
		player += 1;
		system("color 2F");
		cout << "the winner is The Plyer \n";
		cout << "_______________________________\n";
		cout << " player Score: " << player << endl;
		cout << " computer Score: " << computer << endl;
		cout << " Even times : " << even << endl << endl;
	}
	else if (winner == false)
	{
		computer += 1;
		system("color 4F");
		cout << "\athe winner is The Computer \n";
		cout << "_______________________________ \n";
		cout << " player Score: " << player << endl;
		cout << " computer Score: " << computer << endl;
		cout << " Even times : " << even << endl << endl;
	}
	else if (winner == -1)
	{
		even += 1;
		system("color 3F");
		cout << "It's Even No One Win\n";
		cout << "_______________________________\n";
		cout << " player Score: " << player << endl;
		cout << " computer Score: " << computer << endl;
		cout << " Even times : " << even << endl << endl;
	}

}
void gameOver(int player, int computer, int even)
{
	cout << "\n\n\t\t\t+ + + GAME OVER + + +\n\n";
	cout << "\t\t_____________________________________\n\n";
	cout << "\t\t\t   FINAL RESULT\n";
	cout << "\t\t_____________________________________\n";
	cout << "\n\t\tPlayer Wins   :" << player;
	cout << "\n\t\tComputer Wins :" << computer;
	cout << "\n\t\tEven Times    :" << even;
	cout << "\n\t\t_____________________________________\n" << endl;
}
void rounds()
{
	int rounds = readnumberFromTo("How Many Rounds Do You Wnts To Play?: Enter From [1] To [10]: ", 1, 10);

	int player = 0, computer = 0, even = 0;

	for (int i = 1; i <= rounds; i++)
	{
		showResult(checkWinner(playerChooseWeapon(), computerChooseWeapon()), player, computer, even, i);
	}

	gameOver(player, computer, even);
}
int startGame()
{
	rounds();
	string yes = readAnswr(" \nDo You WantTo Play Again? Type [yes]: ");

	if (yes == "yes")
	{
		system("CLS");
		system("color 0F");
		rounds();
	}
	else
		return 0;
}
int main()
{
	srand((unsigned)time(NULL));

	startGame();
}
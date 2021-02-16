#include "Global.h"

#include "Question1.h"
#include "Question2.h"
#include "Question3.h"
#include "Question4.h"


int cakePercentage = 0;
std::string name; // Doesn't do anything

void showQuestions();
void promptToExit();

/// <summary>
/// Ask for 'Y/N' from uset to check if they want to exit.
/// </summary>
void promptToExit()
{
	char _val;
	// Check if cake is ready
	if (cakePercentage < 100)
	{
		// Ask if user really want to claim their cake now
		std::cout << SPACES + "Do you wish to claim your cake now? ('Y/N') ";
		std::cin.clear();
		std::cin >> _val;
		std::cin.ignore();
	}
	else
	{
		// Ask user to INITIATE HUMAN DISPOSAL SEQUENCE
		std::cout << std::endl << SPACES + "Congratulation Human! You have completed the program!\n" << SPACES + "Please press enter to claim your cake. ";
		system("pause");
		_val = 'Y';
	}

	// Switch depending on their input
	switch (_val)
	{
		case 'Y':
			system("cls");
			std::cout << "\n\n\n" << SPACES + "youR cake will be ready shortly, please wait in the hUmaN relocatioN chamber.\n"
				<< SPACES + "thanks for taking the prOgram WiTH us.\n"
				<< SPACES + "remEmber CAKE IS real, have a Fun And K nicE day. : )\n\n"
				<< SPACES + "[INITIATING IGNITION PROGRAM]\n\n\n\n\n";
			exit(0);
			break;

		case 'N':
			showQuestions();
			break;

		default:
			std::cout << SPACES + "That is not a valid option.\n\n";
			promptToExit();
			break;
	}

}


/// <summary>
/// Show the list of question to choose from
/// At the end of each question, ask if user wish to terminate program.
/// </summary>
void showQuestions()
{
	system("cls");

	if (cakePercentage == 0)
	{
		std::cout << SPACES + "Hello Human, Welcome to C++ Algorithm Validation Program.\n"
			<< SPACES + "Please enter your name: ";
		std::cin.clear();
		std::getline(std::cin, name);
		std::cout << SPACES + "Thanks Human, we will have your cake ready when the program is finished.\n";
	}
	else
		std::cout << SPACES + "Welcome back Human, your cake is now " << cakePercentage << "% ready \n";;


	std::cout << SPACES + "Please choose from the following training option to validate the logic of my creator.\n\n";

	int _selection = 0;
	if (cakePercentage < 100)
	{
		std::cout << SPACES + SPACES + "Training 1 - Find the Length of a list\n"
			<< SPACES + SPACES + "Training 2 - Find missing character(s) in two words to compose anagram\n"
			<< SPACES + SPACES + "Training 3 - Find the number of visiable path [NOT AVAILABLE]\n"
			<< SPACES + SPACES + "Training 4 - Find the size of area of given shape\n"
			<< SPACES + SPACES + "Enter '-1' to claim your cake.\n"
			<< std::endl;

		std::cout << SPACES + SPACES + "Please enter your option: ";
		std::cin.clear();
		std::cin >> _selection;
		std::cin.ignore(256, '\n');


		switch (_selection)
		{
			case 1:
				cakePercentage += loadQuestion1();
				break;

			case 2:
				cakePercentage += loadQuestion2();
				break;

			case 3:
				cakePercentage += loadQuestion3();
				break;

			case 4:
				cakePercentage += loadQuestion4();
				break;

			case -1:
				break;

			default:
				std::cout << SPACES + SPACES + "This is not a valid option.\n\n";

				break;
		}
	}

	promptToExit();
}

int main()
{
	showQuestions();

	return 0;
}
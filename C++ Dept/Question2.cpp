#include "Question2.h"

std::string strA = "rather";
std::string strB = "harder";
std::map<char, int> charTable;


void findMissingLetterforAnagram(std::string &_a, std::string &_b)
{
	std::cout << SPACES + SPACES + "The strings receieved are [String A: " + _a + ", String B: " + _b + "]\n";

	// Add char from _a to charTable
	for (char _c : _a)
		if (charTable.find(_c) == charTable.end())
			charTable.insert(std::make_pair(_c, 1));
		else
			charTable[_c]++;

	// remove duplicated char from _b in charTable
	for (char _c : _b)
		if (charTable.find(_c) == charTable.end())
			charTable.insert(std::make_pair(_c, 1));
		else
			charTable[_c]--;
	
	std::cout << SPACES + SPACES + "This is the missing characters to make this two words anagram are:\n"
		<< SPACES + SPACES;

	// abs value in charTable
	for (auto _i = charTable.begin(); _i != charTable.end(); _i++)
		_i->second = abs(_i->second);

	// print the solution
	for (auto _i = charTable.begin(); _i != charTable.end(); _i++)
		if (_i->second > 0)
		{
			std::cout << _i->first << " ";
			_i->second -= 1;
			_i--;
		}

	//for (auto _i = charTable.begin(); _i != charTable.end(); _i++)
	//	if (_i->second != 0)
	//		std::cout << SPACES + SPACES + "[" << _i->first << "]x" << _i->second << ";";

	std::cout << "\n\n";
}

void enterCustomStrings()
{
	// Prompt to enter custom test case
	std::cout << std::endl
		<< SPACES + SPACES + "Please enter at below.\n";
	
	// get user input for string A
	std::cout << SPACES + SPACES + "String A: ";
	std::cin.clear();
	std::getline(std::cin, strA);
		
	// get user input for string B
	std::cout << SPACES + SPACES + "String B: ";
	std::cin.clear();
	std::getline(std::cin, strB);


	// enforce string to lowercase
	std::transform(strA.begin(), strA.end(), strA.begin(), ::tolower);
	std::transform(strB.begin(), strB.end(), strB.begin(), ::tolower);

	// find the missing characters
	findMissingLetterforAnagram(strA, strB);
}

void askForCustomStrings()
{
	char _val;

	std::cout << SPACES + SPACES + "Do you want to enter a custom test case? (Y/N) ";
	std::cin.clear();
	std::cin >> _val;
	std::cin.ignore();

	switch (_val)
	{
		case 'Y':
			enterCustomStrings();
			break;

		case 'N':
			findMissingLetterforAnagram(strA, strB);
			break;


		default:
			std::cout << SPACES + SPACES + "That is not a valid option.\n";
			askForCustomStrings();
			break;
	}
}

int loadQuestion2()
{
	std::cout << "\n\n";

	charTable.clear();

	std::cout << SPACES + SPACES + "[Default Test case:]\n";
	std::cout << SPACES + SPACES + "[String A: \"rather\"]\n";
	std::cout << SPACES + SPACES + "[String B: \"harder\"]\n";

	askForCustomStrings();
	return 10;
}

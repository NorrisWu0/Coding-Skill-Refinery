#include "Question1.h"

std::vector<int> nums = { 1, 4, -1, 2, 3 };

int findLengthOfList(std::vector<int> _arr, int _index)
{
	if (_arr.size() != 1)
	{
		if (_arr[_index] == -1)
			return 2;
		else
			return 1 + findLengthOfList(_arr, _arr[_index]);
	}
	else
		return 1;

}

int loadQuestion1()
{
	std::cout << "\n\n";

	int _num;
	std::string _ctc = "";

	// Ask if user want to use custom test case
	std::cout << SPACES + SPACES + "[Default Test case: { 1, 4, -1, 2, 3 }]\n";
	std::cout << SPACES + SPACES + "Please enter your test case seperated by comma (e.g. 1 2 3 4 5 6), else leave empty.\n";
	std::cout << SPACES + SPACES + "Custom Test Case: ";
	std::cin.clear();
	std::getline(std::cin, _ctc);

	std::stringstream _ss(_ctc);

	if (_ctc != "")
	{
		nums.clear();
		while (_ss >> _num)
			nums.push_back(_num);
	}


	// Show what the target list is
	std::cout << SPACES + SPACES + "The target list is {" << nums[0];

	if (nums.size() > 1)
	{
		for (size_t i = 1; i < nums.size(); i++)
			std::cout << ", " << nums[i];
		std::cout << "}\n";
	}
	else
		std::cout << "}\n";

	// Traverse the list and record the length of list.
	std::cout << SPACES + SPACES + "The length of this list according to the rule is " << findLengthOfList(nums, nums[0]) << "\n\n";

	return 5;
}

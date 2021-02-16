#include "Question4.h"

std::map<int, Vec2> rect1, rect2, rect3;
Vec2 rect1WH, rect2WH, rect3WH;


bool checkForOverlap()
{
	return rect1[0].x < rect2[1].x &&
		rect1[1].x > rect2[0].x &&
		rect1[0].y < rect2[1].y &&
		rect1[1].y > rect2[0].y;
}

Vec2 calDimentionOfRect(std::map<int, Vec2> _rect)
{
	Vec2 _wh;
	_wh.x = abs(_rect[1].x - _rect[0].x);
	_wh.y = abs(_rect[1].y - _rect[0].y);

	return _wh;
}

int calSizeOfShape(Vec2 _rect1, Vec2 _rect2, Vec2 _rect3)
{
	return (_rect1.x * _rect1.y) + (_rect2.x * _rect2.y) - (_rect3.x * _rect3.y);
}

void findTheSizeOfArea()
{
	// Show recorded rects
	std::cout << std::endl << SPACES + SPACES + "The shapes given are";
	std::cout << std::endl << SPACES + SPACES + "Rectangle 1: {" << rect1[0].x << "," << rect1[0].y << "} {" << rect1[1].x << "," << rect1[1].y << "}";

	// Calculate the size of Rect1
	rect1WH = calDimentionOfRect(rect1);
	std::cout << "\tSize: " << rect1WH.x << " x "<< rect1WH.y << " = " << rect1WH.x * rect1WH.y << std::endl;
	
	// Calculate the size of Rect2
	std::cout << SPACES + SPACES + "Rectangle 2: {" << rect2[0].x << "," << rect2[0].y << "} {" << rect2[1].x << "," << rect2[1].y << "}";
	rect2WH = calDimentionOfRect(rect2);
	std::cout << "\tSize: " << rect2WH.x << " x " << rect2WH.y << " = " << rect2WH.x * rect2WH.y << std::endl;

	// Check if overlap exist
	if (checkForOverlap())
	{
		std::cout << SPACES + SPACES + "Overlap Detected, initiating rect battle royale sequence...\n"
			<< SPACES + SPACES + "Overlapped Rects Delivered to the drop zone...\n";

		// Calculate the size of overlapped area.
		rect3.insert(std::make_pair(0, Vec2{ std::max(rect1[0].x, rect2[0].x), std::max(rect1[0].y, rect2[0].y) }));
		rect3.insert(std::make_pair(1, Vec2{ std::min(rect1[1].x, rect2[1].x), std::min(rect1[1].y, rect2[1].y) }));
		rect3WH = calDimentionOfRect(rect3);

		std::cout << SPACES + SPACES + "Combat finished, additional rect space eliminated.\n";
		
		// Print information of Rect Overlap
		std::cout << SPACES + SPACES + "Rectangle Overlapped: {" << rect3[0].x << "," << rect3[0].y << "} {" << rect3[1].x << "," << rect3[1].y << "}";
		std::cout << "\tSize: " << rect3WH.x << " x " << rect3WH.y << " = " << rect3WH.x * rect3WH.y << std::endl;
	}
	else
		std::cout << SPACES + SPACES + "No Overlap Detected.\n";
		

	// Calculate the size of shape.
	std::cout << std::endl << SPACES + SPACES + "The size of shape given is " << calSizeOfShape(rect1WH, rect2WH, rect3WH) << "\n\n";
}

void enterCustomRectCoords()
{
	// Empty current rectangle table
	rect1.clear();
	rect2.clear();

	// Prmopt for user input
	std::cout << SPACES + SPACES + "Please enter coordinates for rectangles in [LowerLeft] [TopRight] order. (e.g. Rect1: -4 1 2 6)\n";

	// Fetch user input - Can do better with below I think
	int _x, _y, _g, _h;
	std::string _coord;
	std::stringstream _ss;
						// Rect1
	std::cout << SPACES + SPACES + "Rectangle 1: ";
	std::cin.clear();
	std::getline(std::cin, _coord);
	_ss << _coord;
	_ss >> _x >> _y >> _g >> _h;
	rect1.insert(std::make_pair(0, Vec2{_x, _y}));
	rect1.insert(std::make_pair(1, Vec2{_g, _h}));
	_ss.str(std::string());
	_ss.clear();
	_coord = std::string();

						// Rect2
	std::cout << SPACES + SPACES + "Rectangle 2: ";
	std::cin.clear();
	std::getline(std::cin, _coord);
	_ss.str(_coord);
	_ss >> _x >> _y >> _g >> _h;
	rect2.insert(std::make_pair(0, Vec2{_x, _y}));
	rect2.insert(std::make_pair(1, Vec2{_g, _h}));
	_ss.str(std::string());
	_coord = std::string();


	// Proceed to calculate the size of area
	findTheSizeOfArea();
}

void askForCustomRectCoords()
{
	char _val;

	std::cout << SPACES + SPACES + "Do you wish to use a custom test case? (Y/N) ";

	std::cin.clear();
	std::cin >> _val;
	std::cin.ignore();

	switch (_val)
	{
		case 'Y':
			enterCustomRectCoords();
			break;

		case 'N':
			findTheSizeOfArea();
			break;

		default:
			std::cout << SPACES + SPACES + "That is not a valid option.\n";
			askForCustomRectCoords();
			break;
	}
}

int loadQuestion4()
{
	std::cout << "\n\n";

	// Empty current rectangle table
	rect1.clear();
	rect2.clear();
	rect3.clear();

	// Init default test case
	rect1.insert(std::make_pair(0, Vec2{-4, 1}));
	rect1.insert(std::make_pair(1, Vec2{2, 6}));

	rect2.insert(std::make_pair(0, Vec2{0, -1}));
	rect2.insert(std::make_pair(1, Vec2{4, 3}));


	// Prompt what default test case is
	std::cout << SPACES + SPACES + "[Default Test case:]\n";
	std::cout << SPACES + SPACES + "[Rectangle 1: {-4,1}, {2,6}]\n";
	std::cout << SPACES + SPACES + "[Rectangle 2: {0,-1}, {4,3}]\n";

	// Ask user for their input
	askForCustomRectCoords();
	return 20;
}

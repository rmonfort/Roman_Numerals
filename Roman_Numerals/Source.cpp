#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::ostringstream;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	int number = 0;
	// Read number from input file and convert to roman numeral
	while (ifs >> number)
	{
		ostringstream roman_numeral; // Holds output till number is fully converted
		while (number > 0)
		{
			// 1000 - M
			if (number >= 1000)
			{
				roman_numeral << "M";
				number -= 1000;
			}
			// 900 - CM
			else if (number >= 900)
			{
				roman_numeral << "CM";
				number -= 900;
			}
			// 500 - D
			else if (number >= 500)
			{
				roman_numeral << "D";
				number -= 500;
			}
			// 400 - CD
			else if (number >= 400)
			{
				roman_numeral << "CD";
				number -= 400;
			}
			// 100 - C
			else if (number >= 100)
			{
				roman_numeral << "C";
				number -= 100;
			}
			// 90 - XC
			else if (number >= 90)
			{
				roman_numeral << "XC";
				number -= 90;
			}
			// 50 - L
			else if (number >= 50)
			{
				roman_numeral << "L";
				number -= 50;
			}
			// 40 - XL
			else if (number >= 40)
			{
				roman_numeral << "XL";
				number -= 40;
			}
			// 10 - X
			else if (number >= 10)
			{
				roman_numeral << "X";
				number -= 10;
			}
			// 9 - IX
			else if (number == 9)
			{
				roman_numeral << "IX";
				number -= 9;
			}
			// 5 - V
			else if (number >= 5)
			{
				roman_numeral << "V";
				number -= 5;
			}
			// 4 - IV
			else if (number == 4)
			{
				roman_numeral << "IV";
				number -= 4;
			}
			// 1 - I
			else if (number >= 1)
			{
				roman_numeral << "I";
				number -= 1;
			}
		}
		// Output completed roman numeral 
		cout << roman_numeral.str() << endl;
	}
	return 0;
}
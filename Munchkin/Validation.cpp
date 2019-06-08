#include "Validation.h"

std::string ValidationInput::getName()
{
	std::string name;
	do
	{
		std::cout << "Enter your name:";
		getline(std::cin, name);
		if (name.empty())
			std::cout << "Enter at least on sign.\n";
	} while (name.empty());

	return name;
}

std::string ValidationInput::getAnswer()	
{
	std::string answer;
	do
	{
		std::cout << ":";
		getline(std::cin, answer);

		if (answer != "yes" && answer != "no")
			std::cout << "Answer isn't correct.\n Try again.\n";

	} while (answer != "yes" && answer != "no");
	return answer;
}

std::string ValidationInput::getAction()
{
	std::string answer;
	do
	{
		std::cout << "Your action (fight/run):";
		getline(std::cin, answer);
	} while (answer != "fight" && answer != "run");
	return answer;
}

int ValidationInput::validateIndex(int maxIndex, bool clrAll)
{
	std::string string;

	while (true)
	{
		std::cout << "Choose artifact:";
		getline(std::cin, string);

		if (string.length() > 2)
		{
			std::cout << "You entered incorrect index!\n";
			continue;
		}

		if (static_cast<int>(atof(string.c_str())) == MunchkinConst::stopNumeral)
			return MunchkinConst::stopNumeral;

		if (static_cast<int>(atof(string.c_str())) == MunchkinConst::clearAllArtifacts)
		{
			if (clrAll)
				return MunchkinConst::clearAllArtifacts;
			else
			{
				std::cout << "You entered incorrect index!\n";
				continue;
			}

		}

		if (string.length() == 1 && (isalpha(string[0]) || ispunct(string[0])))
		{
			std::cout << "You entered incorrect index!\n";
			continue;
		}

		if (string.length() == 2 && (
			(isalpha(string[0]) || ispunct(string[0])) ||
			(isalpha(string[1]) || ispunct(string[1])) ||
			(string[0] == '0')))
		{
			std::cout << "You entered incorrect index!\n";
			continue;
		}

		if (static_cast<int>(atof(string.c_str())) <= 0 || static_cast<int>(atof(string.c_str())) > maxIndex)
		{
			std::cout << "You entered incorrect index!\n";
			continue;
		}

		break;
	}

	int index = static_cast<int>(atof(string.c_str()));

	return index;
}

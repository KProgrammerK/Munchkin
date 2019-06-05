#ifndef VALIDATION_H
#define VALIDATION_H

#include "Constans.h"

#include <iostream>
#include <cctype>
#include <string>


namespace ValidationInput
{
	std::string getName();

	std::string getAnswer();

	std::string getAction();

	// Flag clrAll for a function deleteUselessartifacts
	int validateIndex(int maxIndex, bool clrAll);
}
#endif // !VALIDATION_H

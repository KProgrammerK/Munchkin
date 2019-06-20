#include "RandomNumber.h"

int RandomNumber::getRandomNumber(int min, int max)
{
	using GRNType = boost::mt19937;
	time_t now{ time(0) };
	GRNType  rng{ static_cast<uint32_t>(now) };

	boost::uniform_int<> min_max_Values{ min,max };
	boost::variate_generator<GRNType, boost::uniform_int<>> randomNumber{ rng, min_max_Values };
	return randomNumber();
}
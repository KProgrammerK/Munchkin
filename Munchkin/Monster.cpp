#include "Monster.h"

Monster::Monster(Monster::MonsterType type) :
	Creature{ monstersTable[static_cast<int>(type)] } {}

const Creature Monster::monstersTable[static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPE)]
{
	//  Name     H   A   D   G   
	{"Dragon",   10, 10, 10, 10},
    {"Skeleton", 2,   3,  1,  2},
    {"Troll",    4,   5,  6,  7},

};

Monster::MonsterType Monster::getRandomMonster()
{
	Monster::MonsterType type = static_cast<MonsterType>(RandomNumber::getRandomNumber(0, (static_cast<int>(MonsterType::MAX_MONSTER_TYPE) - 1)));
	return type;
}
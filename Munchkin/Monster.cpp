#include "Monster.h"

Monster::Monster(Monster::MonsterType type) :
	Creature{ monstersTable[static_cast<int>(type)] } {}

const Creature Monster::monstersTable[static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPE)]
{
	//  Name           H     A    D    G   
	{"Murloc",         10,   2,   2,   10   },
    {"Liquid horror",  14,   4,   3,   10   },
    {"Reaper",         25,   0,   3,   20  },
    {"Ogre",           20,   5,   5,   30  },
    {"Scorpion",       5,    30,  15,  100 },
    {"Witch",          5,    0,   13,  60  },
    {"Skeleton",       5,    0,   2,   10   },
    {"Troll",          19,   15,  10,  70  },
    {"Core Mushroom",  0,    0,   9,   0   },
    {"Pyramid Head",   69,   69,  69,  690 },
    {"Dragon God" ,    100,  100, 50,  999 }
};

Monster::MonsterType Monster::getRandomMonster()
{
	Monster::MonsterType type = static_cast<MonsterType>(RandomNumber::getRandomNumber(0, (static_cast<int>(MonsterType::MAX_MONSTER_TYPE) - 1)));
	return type;
}
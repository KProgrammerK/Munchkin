#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "RandomNumber.h"

class Monster : public Creature
{
public:

	enum class MonsterType
	{
		DRAGON,
		SKELETON,
		TROLL,
		MAX_MONSTER_TYPE
	};

	//Pass type to get informations from table of monsters about monster 
	//and pass these informations in constructor Creature for create monster
	Monster(MonsterType);

	//This is table with informations about monsters
	static const Creature monstersTable[];

    //Random type Monster
	static MonsterType getRandomMonster();
};
#endif // !MONSTER_H

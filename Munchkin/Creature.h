#ifndef CREATURE_H
#define CREATURE_H

#include <string>

class Creature
{
public:
	//          Name       H    A    D    G
	Creature(std::string, int, int, int, int);

	//Functions getters informations
	std::string getName  () const;
	int         getHealth() const;
	int         getArmor () const;
	int         getDamage() const;
	int         getGold  () const;

	//                 D
	void reduceHealth(int);
	bool isDead() const;

protected:
	int m_health;
	int m_armor ;
	int m_damage;
	int m_gold  ;
private:
	std::string m_name;
};
#endif // !CREATURE_H

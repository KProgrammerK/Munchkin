#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

class Creature
{
public:
	//          Name            H        A        D        G
	Creature(const std::string& = "", int = 0, int = 0, int = 0, int = 0);

	//Functions getters informations
	std::string getName  () const;
	int         getHealth() const;
	int         getArmor () const;
	int         getDamage() const;
	int         getGold  () const;

	//                 D
	void reduceHealth(int);
	bool isDead() const;

	void printInformations() const;

protected:
	int m_health;
	int m_armor ;
	int m_damage;
	int m_gold  ;
private:
	std::string m_name;
};
#endif // !CREATURE_H

#include "Creature.h"

// Standard constructor
Creature::Creature(std::string name, int health,int armor, int damage, int gold) :
	m_name  { name   },
	m_health{ health },
	m_armor { armor  },
	m_damage{ damage },
	m_gold  { gold   } {}

// Functions getters informations
std::string  Creature::getName  () const { return m_name  ; }
int          Creature::getHealth() const { return m_health; }
int          Creature::getArmor () const { return m_armor ; }
int          Creature::getDamage() const { return m_damage; }
int          Creature::getGold  () const { return m_gold  ; }

// 1 unit armor blocks 0.50 unit damage
void Creature::reduceHealth(int damage)
{
	int lockedDamage = getArmor() * 0.50;
	int cleanDamage  = damage - lockedDamage;
	if (cleanDamage < 0)
	{
		std::cout << "This damage isn't enough to break through this armor!\n";
		return;
	}
	m_health -= cleanDamage;
}

// If health of creature <= 0 return true
bool Creature::isDead() const { return m_health <= 0; }

void Creature::printInformations() const
{
	std::cout << "Name:" << m_name << "  Health:" << m_health << "  Armor:" << m_armor
		<< "  Damage:" << m_damage << "  Gold:" << m_gold;
}
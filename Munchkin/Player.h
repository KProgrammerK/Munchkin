#ifndef PLAYER_H
#define PLAYER_H

#include "BackPack.h"
#include "Equipment.h"
#include "Creature.h"

class Player : public Creature
{
public:
	//         Name
	Player(std::string);
	~Player();

	//There are functions getting informations about palyer
	void printInformations() const;
	int getLevel   () const;
	int getKillings() const;
	bool isWon() const;

	void addEquipment(Artifact);

	void buffArmor(int);
	void buffHealth(int);
	void buffDamage(int);
	void debuffDamage(int);
	void debuffHealth(int);
	void debuffArmor(int);
	void buffPlayer(Artifact&);
	void debuffPlayer(Artifact&);
	char warning(std::string);

	//There are functions getting access to things of player
	BackPack*  openBackPack () const;
	Equipment* openEquipment() const;

private:
	BackPack*  m_backpack;
	Equipment* m_equipment;
	int m_level;
	int m_killings;
};
#endif // !PLAYER_H



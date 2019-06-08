#ifndef PLAYER_H
#define PLAYER_H

#include "BackPack.h"
#include "Equipment.h"
#include "Creature.h"
#include "Validation.h"

#include <fstream>

class Player : public Creature
{
public:
	//         Name
	Player(const std::string&);
	~Player();

	//There are functions getting informations about palyer
	void printInformations() const;
	int getLevel   () const;
	int getKillings() const;
	bool isWon() const;

	/* Player improves when artifact adds
	** When artifacts swap at first player debuff on current artifact
	** and after player improves on new artifact
	** ↓ This is functions for work with improve player ↓
	*/
	void buffArmor(int);
	void buffHealth(int);
	void buffDamage(int);

	void debuffDamage(int);
	void debuffHealth(int);
	void debuffArmor(int);

	void buffPlayer(Artifact&);
	void debuffPlayer(Artifact&);
	//↑ This is were functions for work with improve player ↑

	//This is function uses to get answer player when cell of equipment is busy 
	//(permission to swap artifacts)
	std::string warning(const std::string&);

	// When player kills monster
	void addGold(int);
	void levelUp();

	void reduceGold(int);
	void addEquipment(Artifact);

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



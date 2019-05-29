#include "Player.h"

Player::Player(std::string name) :
	//       Name   H   A  D  G
	Creature{ name, 10, 0, 1, 0 },
	m_level{ 1 },
	m_killings{ 0 }
{
	m_backpack  = new BackPack;
	m_equipment = new Equipment;
}

Player::~Player()
{
	delete m_backpack;
	delete m_equipment;
}

char Player::warning(std::string item)
{
	std::cout << "You already have: " << item << "   ->   ";
	if (item == "helmet")
		openEquipment()->getArtifact(Equipment::EquipmentType::HEAD).printArtifact();
	else if (item == "armor")
		openEquipment()->getArtifact(Equipment::EquipmentType::BODY).printArtifact();
	else if (item == "weapon")
		openEquipment()->getArtifact(Equipment::EquipmentType::WEAPON).printArtifact();

	char answer;
	do
	{
		std::cout << "Do you want to swap them ?(y/n): ";
		std::cin >> answer;

		if (std::cin.fail())
			std::cin.clear();
		std::cin.ignore(32767, '\n');

	} while (answer != 'y' && answer != 'n');

	return answer;
}

void Player::printInformations() const
{
	Creature::printInformations();
	std::cout << ", Level:" << m_level << ", Killings:" << m_killings << '\n';
}

int  Player::getLevel   () const { return m_level;       }
int  Player::getKillings() const { return m_killings;    }
bool Player::isWon      () const { return m_level >= 20; }

void  Player::buffArmor   (int value) { m_armor += value ; }
void  Player::buffHealth  (int value) { m_health += value; }
void  Player::buffDamage  (int value) { m_damage += value; }

void  Player::debuffArmor (int value) { m_armor -= value;  }
void  Player::debuffHealth(int value) { m_health -=value ; }
void  Player::debuffDamage(int value) { m_damage -= value; }

void Player::buffPlayer(Artifact& artifact)
{
	switch (artifact.getSign())
	{
	case 'A': buffArmor(artifact.getBuff()) ; break;
	case 'H': buffHealth(artifact.getBuff()); break;
	case 'D': buffDamage(artifact.getBuff()); break;
	}
}

void Player::debuffPlayer(Artifact& artifact)
{
	switch (artifact.getSign())
	{
	case 'A': debuffArmor(artifact.getBuff()) ; break;
	case 'H': debuffHealth(artifact.getBuff()); break;
	case 'D': debuffDamage(artifact.getBuff()); break;
	}
}
void Player::addEquipment(Artifact artifact)
{
	if (artifact.getSign() == 'D')
	{
		// If cell is free that add artifact else WARNING
		if (openEquipment()->busyCell(Equipment::EquipmentType::WEAPON))
		{
			openEquipment()->addCell();
			openEquipment()->addArtifact(Equipment::EquipmentType::WEAPON, artifact);
			buffPlayer(artifact);
		}
		else
		{
			char answer = warning("weapon");
			if (answer == 'y')
			{
				debuffPlayer(openEquipment()->getArtifact(Equipment::EquipmentType::WEAPON));
				openBackPack()->addArtifact(openEquipment()->getArtifact(Equipment::EquipmentType::WEAPON));
				openEquipment()->addArtifact(Equipment::EquipmentType::WEAPON, artifact);
				buffPlayer(artifact);
			}
			else
				openBackPack()->addArtifact(artifact);
		}
	}

	if (artifact.getSign() == 'A')
	{
		// If cell is free that add artifact else WARNING
		if (openEquipment()->busyCell(Equipment::EquipmentType::HEAD))
		{
			openEquipment()->addCell();
			openEquipment()->addArtifact(Equipment::EquipmentType::HEAD, artifact);
			buffPlayer(artifact);
		}
		else
		{
			char answer = warning("helmet");
			if (answer == 'y')
			{
				debuffPlayer(openEquipment()->getArtifact(Equipment::EquipmentType::HEAD));
				openBackPack()->addArtifact(openEquipment()->getArtifact(Equipment::EquipmentType::HEAD));
				openEquipment()->addArtifact(Equipment::EquipmentType::HEAD, artifact);
				buffPlayer(artifact);
			}
			else
				openBackPack()->addArtifact(artifact);
		}
	}

	if (artifact.getSign() == 'H')
	{
		// If cell is free that add artifact else WARNING
		if (openEquipment()->busyCell(Equipment::EquipmentType::BODY))
		{
			openEquipment()->addCell();
			openEquipment()->addArtifact(Equipment::EquipmentType::BODY, artifact);
			buffPlayer(artifact);
		}
		else
		{
			char answer = warning("armor");
			if (answer == 'y')
			{
				debuffPlayer(openEquipment()->getArtifact(Equipment::EquipmentType::BODY));
				openBackPack()->addArtifact(openEquipment()->getArtifact(Equipment::EquipmentType::BODY));
				openEquipment()->addArtifact(Equipment::EquipmentType::BODY, artifact);
				buffPlayer(artifact);
			}
			else
				openBackPack()->addArtifact(artifact);
		}
	}
}

//There are functions getting access to things of player
BackPack*  Player::openBackPack () const { return m_backpack ; }
Equipment* Player::openEquipment() const { return m_equipment; }


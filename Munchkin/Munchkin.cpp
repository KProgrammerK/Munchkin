#include "Player.h"
#include "Monster.h"
#include "TypeReturn.h"
#include "SecretShop.h"
#include "Validation.h"

#include <conio.h>
#include <cstdlib>
#include <memory>

void equipPlayer(Player* player)
{
	player->openBackPack()->showBackPack();
	std::cout << "Enter " << MunchkinConst::stopNumeral << " to return.\n";
	int index = ValidationInput::validateIndex(player->openBackPack()->getSize(),false);

	if (index == MunchkinConst::stopNumeral)
		return;

	player->addEquipment(player->openBackPack()->getArtifact(index));
	std::cout << '\n';
	player->printInformations();
	_getch();
	system("cls");
}

void deleteUselessArtifacts(Player* player)
{
	std::cout << "Your backpack is overflow!\n";
	std::cout << "You need to delete useless aritfacts.\n";
	std::cout << "Enter " << MunchkinConst::clearAllArtifacts << " to delete all the artifacts.\n";
	std::cout << "Enter " << MunchkinConst::stopNumeral << " to break to return.\n\n";

	player->openBackPack()->showBackPack();
	int artifact{ 0 };
	std::vector<int> uselessArtifacts;
	uselessArtifacts.reserve(MunchkinConst::max_size_backpack);

	for (int cell = 0; cell < MunchkinConst::max_size_backpack; ++cell)
	{
		artifact = ValidationInput::validateIndex(player->openBackPack()->getSize(),true);

		if (artifact == MunchkinConst::stopNumeral)
		{
			if (uselessArtifacts.size() <= 0)
			{
				std::cout << "Please delete at least one artifact\n";
				--cell;
				continue;
			}
			else
				break;
		}
		
		uselessArtifacts.push_back(artifact);

		if (artifact == MunchkinConst::clearAllArtifacts)
			break;
	}

	player->openBackPack()->deleteUselessArtifacts(uselessArtifacts);
	system("cls");
}

void playerAttack(Player* player, Monster* monster)
{
	std::cout << "You attack monster:" << player->getDamage() << '\n';
	monster->reduceHealth(player->getDamage());
	monster->printInformations(); std::cout << "\n\n";
}

void monsterAttack(Player* player, Monster* monster)
{
	std::cout << "Monster attacks you:" << monster->getDamage() << '\n';
	player->reduceHealth(monster->getDamage());
	player->printInformations();
	std::cout << '\n';
}

bool enoughGold(Player* player, const SecretArtifact& artifact) { return (player->getGold() >= artifact.getCost()) ? true : false; }

/*
** In Secret Shop player can buy artifacts which don't drop in the game. **
** Purchase artifacts implemented with cycle of for()                    **
** If purchase artifacts isn't successfully                              **
** (isn't enough money , entered isn't correct index)                    **  
** then iteration isn't counted                                          **
** If player will buy artifact and your backpack will is overflow        **
** then callered a function deleteUselessArtifacts                       **
** and iteration isn't counted                                           **
*/
void shopSecret(Player* player, SecretShop* secretShop)
{
	system("cls");
	secretShop->showShop();
	std::cout << "You have " << player->getGold() << " golds \n\n";
	std::cout << "Choose artifacts which you want to buy.\n";
	std::cout << "Enter " << MunchkinConst::stopNumeral << " to return.\n";

	int artifact{ 0 };

	for (int buy = 0; buy < static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE); ++buy)
	{
		artifact = ValidationInput::validateIndex(secretShop->getCell(), false);

		if (artifact == MunchkinConst::stopNumeral)
			return;

		if (player->openBackPack()->getSize() < MunchkinConst::max_size_backpack)
		{
			if (enoughGold(player, secretShop->getArtifact(artifact, true)))
			{
				player->reduceGold(secretShop->getArtifact(artifact, true).getCost());
				player->openBackPack()->addArtifact(secretShop->getArtifact(artifact));
				std::cout << "Artifact added in your backpack.\n";
				system("cls");
				secretShop->showShop();
				std::cout << "You have " << player->getGold() << " golds \n\n";
				continue;
			}
			else
			{
				std::cout << "You don't have enough money!\n";
				--buy;
				continue;
			}
		}
		else
		{
			deleteUselessArtifacts(player);
			--buy;
			secretShop->showShop();
			std::cout << "You have " << player->getGold() << " golds \n\n";
		}
	}
	system("cls");
}

ResultGame playGame(Player* player)
{
	//-------------------- Game continues while level of player < 20--------
	while (!player->isWon())
	{
        // When player will have 10 level , he will get access to Secret Shop
		if (player->getLevel() == 10)
		{
			auto shop = std::make_unique<SecretShop>();
			shopSecret(player, shop.get());
			equipPlayer(player);
		}

		//------------------Drop artifact and equip Player------------------
		if (player->openBackPack()->getSize() == MunchkinConst::max_size_backpack)
		{
			do
			{
				deleteUselessArtifacts(player);
			} while (player->openBackPack()->getSize() >= MunchkinConst::max_size_backpack);
		}

		std::cout << "Artifact drops in your backpack.\n";
		player->openBackPack()->addArtifact(Artifact::getRandomArtifact());
			
		std::cout << "Do you want to equip?(yes/no)\n";
		std::string answer = ValidationInput::getAnswer();
		system("cls");
		
		if (answer == "yes")
			equipPlayer(player);
		//------------------------------------------------------------------

		auto monster = std::make_unique<Monster>(Monster::getRandomMonster());

		std::cout << "You met a monster!\n";
		monster->printInformations(); std::cout << '\n';
		player->printInformations();  std::cout << '\n';

		if (monster->getName() == "Core Mushroom")
		{
			std::cout << "It's Core Mushroom!\n";
			std::cout << "It hits damage:" << monster->getDamage() << " and deads!\n";
			player->reduceHealth(monster->getDamage());
			_getch();
			system("cls");
			continue;
		}

		do
		{
			std::string action = ValidationInput::getAction();

			if (action == "run")
			{
				if (RandomNumber::getRandomNumber(1, 2) == 1)
				{
					std::cout << "You seccessfully run!\n";
					_getch();
					system("cls");
					break;
				}
				else
					monsterAttack(player, monster.get());
			}
			else
			{
				playerAttack(player, monster.get());
				if (monster->isDead())
					continue;
				monsterAttack(player, monster.get());
			}
			// Fight
		} while (!monster->isDead() && !player->isDead());

		if (monster->isDead())
		{
			std::cout << "You kill this monster!\n";
			std::cout << "You receive levelUp!\n";
			player->levelUp();
			player->addGold(monster->getGold());
			player->printInformations();
			std::cout << "Press anykey";
			_getch();
			system("cls");
		}

		if (player->isDead())
			return ResultGame::LOSE;

	}// Main cycle 
	return ResultGame::WIN;
}//playGame

int main()
{
    //-----This is isn't interesting----------
	std::cout << "Munchkin v1.0.\n";
    srand(static_cast<unsigned int>(time(0)));
	rand();
	std::string name = ValidationInput::getName();
	//----------------------------------------

	auto player = std::make_unique<Player>(name);

	ResultGame resultGame = playGame(player.get());

	if (resultGame == ResultGame::WIN)
		std::cout << "You're Win!\n";
	else
		std::cout << "You're Dead.\n";

	std::cout << "Your result writes in file (MunchkinResult.txt)\n";
	_getch();

	return 0;
}
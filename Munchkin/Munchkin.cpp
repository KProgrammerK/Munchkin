#include "Player.h"
#include "Monster.h"
#include "TypeReturn.h"
#include "SecretShop.h"

#include <conio.h>
#include <cstdlib>
#include <memory>

std::string getName()
{
	std::string name;
	std::cout << "Enter your name:";
	getline(std::cin, name);
	return name;
}

std::string getAnswer()
{
	std::string answer;
	do
	{
		getline(std::cin, answer);
	} while (answer != "y" && answer != "n");
	return answer;
}

std::string getAnswer(bool)
{
	std::string answer;
	do
	{
		std::cout << "Your action:";
		getline(std::cin, answer);
	} while (answer != "run" && answer != "fight");
	return answer;
}
void equipPlayer(Player* player)
{
	player->openBackPack()->showBackPack();
	std::cout << "Enter 69 to return.\n";
	std::cout << "\n Choose artifact: ";

	int index;
	std::cin >> index;
	std::cin.ignore(32767, '\n');
	if (index == 69)
		return;
	player->addEquipment(player->openBackPack()->getArtifact(index));
	std::cout << '\n';
}

void deleteUselessArtifacts(Player* player)
{
	std::cout << "Your backpack is overflow!\n";
	std::cout << "You need to delete useless aritfacts.\n";
	std::cout << "Enter 11 to delete all the artifacts.\n";
	std::cout << "Enter 69 to break to delete.\n\n";
	player->openBackPack()->showBackPack();
	int artifact{ 0 };
	std::vector<int> uselessArtifacts;
	for (int cell = 0; cell < 10; ++cell)
	{
		std::cout << "Choose artifact:";
		std::cin >> artifact;
		std::cin.ignore(32767, '\n');
		if (artifact == 69)
			break;
		uselessArtifacts.push_back(artifact);
		if (artifact == 11)
			break;
	}
	if (uselessArtifacts.size() == 0)
	{
		system("cls");
		std::cout << "You have not entered a single artifact!\n";
		deleteUselessArtifacts(player);
	}
	player->openBackPack()->deleteUselessArtifacts(uselessArtifacts);
	system("cls");
}
void playerAttack(Player* player, Monster* monster)
{
	std::cout << "You attack monster:" << player->getDamage() << '\n';
	monster->reduceHealth(player->getDamage());
}

void monsterAttack(Player* player, Monster* monster)
{
	std::cout << "Monster attacks you:" << monster->getDamage() << '\n';
	player->reduceHealth(monster->getDamage());

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
	std::cout << "Enter 69 to return.\n";

	int artifact{ 0 };

	for (int buy = 0; buy < static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE); ++buy)
	{
		std::cout << "Enter:";
		std::cin >> artifact;
		std::cin.ignore(32767, '\n');

		if (artifact == 69)
			return;

		if (artifact > secretShop->getCell())
		{
			std::cout << "You entered isn't correct artifact!\n";
			--buy;
			continue;
		}

		if (player->openBackPack()->getSize() < 10)
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
			player->printInformations();
			_getch();
			system("cls");
		}

		//------------------Drop artifact and equip Player------------------
		if (player->openBackPack()->getSize() == 10)
		{
			do
			{
				deleteUselessArtifacts(player);
			} while (player->openBackPack()->getSize() >= 10);
		}
		std::cout << "Artifact drops in your backpack.\n";
		player->openBackPack()->addArtifact(Artifact::getRandomArtifact());
		std::cout << "Do you want to equip?(y/n):";
		std::string answer = getAnswer();
		if (answer == "y")
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
			std::string action = getAnswer(true);

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
    srand(static_cast<unsigned int>(time(0)));
	rand();
	std::string name = getName();
	//----------------------------------------
	auto player = std::make_unique<Player>(name);

	ResultGame resultGame = playGame(player.get());

	if (resultGame == ResultGame::WIN)
		std::cout << "You're Win!\n";
	else
		std::cout << "You're Dead.\n";

	std::cout << "Your result writes in file (MunchkinResult.txt)\n";
	system("pause");

 	return 0;
}
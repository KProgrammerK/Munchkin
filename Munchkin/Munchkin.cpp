#include "Player.h"
#include "Monster.h"
#include "TypeReturn.h"

#include <conio.h>

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

ResultGame playGame(Player* player)
{
	while (!player->isWon())
	{
		//------------------Drop artifact and equip Player------------------
		std::cout << "Artifact drops in your backpack.\n";
		if (player->openBackPack()->getSize() == 10)
		{
			do
			{
				deleteUselessArtifacts(player);
			} while (player->openBackPack()->getSize() >= 10);
		}
			player->openBackPack()->addArtifact(Artifact::getRandomArtifact());
		std::cout << "Do you want to equip?(y/n):";
		std::string answer = getAnswer();
		if (answer == "y")
			equipPlayer(player);
		//------------------------------------------------------------------

		Monster* monster = new Monster{ Monster::getRandomMonster() };
		std::cout << "You met a monster!\n";
		monster->printInformations(); std::cout << '\n';
		player->printInformations();  std::cout << '\n';

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
					monsterAttack(player, monster);
			}
			else
			{
				playerAttack(player, monster);
				if (monster->isDead())
					continue;
				monsterAttack(player, monster);
			}
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

		delete monster;

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

	Player* player = new Player{ name };

	ResultGame resultGame = playGame(player);
	if (resultGame == ResultGame::WIN)
		std::cout << "You're WIN!\n";
	else
		std::cout << "You're Lose.\n";

	delete player;

 	return 0;
}
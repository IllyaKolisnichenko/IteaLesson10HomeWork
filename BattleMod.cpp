#include <iostream>
#include <string>
#include <conio.h>
class Persone
{
public:
	enum Items
	{
		Sword,
		Shield,
		Armor,
		Magik,
		Fighter,
		Count
	};
	void getItem() 
	{
	    Items item{ static_cast<Items>(rand() % Items::Count) };
		if (item == Magik)
		{
			life = 100;
			maxSizeOfDamageOfItems = 25;
		}
		if (item == Fighter)
		{
			life = 200;
		}
		const auto sizeOfDamageOfItems{ rand() % maxSizeOfDamageOfItems };
		Item = { item, sizeOfDamageOfItems };
	}
	int getLife()
	{
		return life;
	}
	
	std::pair<Items, int> Item;
	int life = 150;
	static constexpr int maxSizeOfAttack = 5;
	int maxSizeOfDamageOfItems = 15;
};
class Hero : public Persone
{
public:
	int Attac()
	{
		if (Item.first == Items::Sword)
		{
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		if (Item.first == Items::Magik)
		{
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		if (Item.first == Items::Fighter)
		{
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		else
		{
			return (rand() % maxSizeOfAttack);
		}
	}
	int getDamage(int damage)
	{
		if (Item.first == Shield || Item.first == Armor)
		{
			if (Item.second > 5)
			{
				life -= damage - Item.second;
			}
			else
			{
				life -= damage;
			}
				
		}
		else
		{
			life -= damage;
		}
		    return life;
	}
};
class Monster : public Persone
{
public:
	int Attac()
	{
		if (Item.first == Items::Sword)
		{
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		else if (Item.first == Items::Magik)
		{
			
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		else if (Item.first == Items::Fighter)
		{
			int getAttack = Item.second;
			return (rand() % maxSizeOfAttack) + getAttack;
		}
		else
		{
			return (rand() % maxSizeOfAttack);
		}
	}
	int getDamage(int damage)
	{
		if (Item.first == Shield || Item.first == Armor)
		{
			if (Item.second > 5)
			{
				life -= damage - Item.second + 5;
			}

		}
		else
		{
			life -= damage;
		}
		return life;
	}
};

void print(Hero hero, Monster monster)
{
	switch (hero.Item.first)
	{
	case 0:
		std::cout << "item of hero: Sword" << std::endl;
		break;
	case 1:
		std::cout << "item of hero: Shield" << std::endl;
		break;
	case 2:
		std::cout << "item of hero: Armor" << std::endl;
		break;
	case 3:
		std::cout << "item of hero: Magik" << std::endl;
		break;
	case 4:
		std::cout << "item of hero: Fighter" << std::endl;
		break;
	default:
		std::cout << "error" << std::endl;
		break;
	}

	switch (monster.Item.first)
	{
	case 0:
		std::cout << "item of monster: Sword" << std::endl;
		break;
	case 1:
		std::cout << "item of monster: Shield" << std::endl;
		break;
	case 2:
		std::cout << "item of monster: Armor" << std::endl;
		break;
	case 3:
		std::cout << "item of monster: Magik" << std::endl;
		break;
	case 4:
		std::cout << "item of monster: Fighter" << std::endl;
		break;
	default:
		std::cout << "error" << std::endl;
		break;
	}
}
int main()

{
	srand(time(nullptr));
	Hero hero;
	Monster monster;
	print(hero, monster);
	hero.getItem();
	monster.getItem();
	while (true)
	{
		srand(time(nullptr));
		monster.getDamage(hero.Attac());
		if (monster.getLife() <= 0 && hero.getLife() <= 0)
		{
			std::cout << "it's draw" << std::endl;
			return 0;
		}
		if (monster.getLife() <= 0)
		{
			std::cout << "Hero win" << std::endl;
			return 0;
		}
		hero.getDamage(monster.Attac());
		if (hero.getLife() <= 0)
		{
			std::cout << "Monster win" << std::endl;
			return 0;
		}

		std::cout << "hero's life: " << hero.life << std::endl;
		std::cout << "monster's life: " << monster.life << std::endl << std::endl;
		_getch();
	}
	
	return 0;
}

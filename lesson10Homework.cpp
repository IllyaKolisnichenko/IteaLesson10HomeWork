// lesson10Homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <array>



class Person {
public:
	enum Weapon {
		Sword,
		Axe,
		Mace
	};
	enum Protection {
		WoodShield,
		MetalShield,
		ChainArmor

	};
	void getWeapon(int caseWeapon) {
		 Weapon personWeapon{ static_cast<Weapon>(caseWeapon) };

	}

	void getProtection(int caseProtection) {
		Protection personProtect{ static_cast<Protection>(caseProtection) };

	}

protected:
	int life{ 100 };
	Weapon personWeapon{};
	Protection personProtect{};

};


class Hero : public Person {
	
public:

	int heroAtack() {
		if (personWeapon == Sword) {
			return 1+rand() % maxAtackSword;
		}
		if (personWeapon == Axe) {
			return 1+rand() % maxAtackAxe;
		}
		
		if (personWeapon == Mace) {
			return 1+rand() % maxAtackMace;
		}
		
	}

	int heroProtect() {
		if (personProtect == ChainArmor) {
			return  rand() % maxProtectArmor;
		}
		if (personProtect == WoodShield) {
			return  rand() % maxProtectWoodShield;
		}

		if (personProtect == MetalShield) {
			return  rand() % maxProtectMetalShield;
		}
	}
	void takeDamage(int damage) {
		int protect = heroProtect();
		life = life - (damage - protect);
	}
	int getScore() {
		return score+=10;
	}
	int getlife() {
		return life;
	}

public:
	int score{ };

private:
	static constexpr int maxAtackSword{ 10 };
	static constexpr int maxAtackAxe{ 15 };
	static constexpr int maxAtackMace{ 12 };
	int maxProtectWoodShield{ 2};
	int maxProtectMetalShield{5 };
	int maxProtectArmor{1 };
	

};

class Monstr {

public:
	Monstr()
		: maxAtackMonstr_{ 10 }, life_{ 100 }
	{

	}

	int monstrAtack() {
		return 1+rand() % maxAtackMonstr_;
	}
	void damage(int damage) {

		life_ = life_ - damage;
		return;
		
	}
	int getLife() {
		return life_;
	}

private:
	int maxAtackMonstr_{};
	int life_{ };
};

int main()
{
	int damageMonstr{};
	int weapon;
	int protect;
	srand(time(nullptr));
	Hero hero;
	Monstr monstr;
	std::cout << "Please Choose a weapon:\n"<<"\t0. Sword\n"<<"\t1. Axe\n"<<"\t2. Mace\n";
	std::cin >> weapon;
	hero.getWeapon(weapon);
	std::cout << "Please Choose a protect:\n" << "\t0. Wood Shield\n" << "\t1. Metal Shield\n" << "\t2. Chain Armor\n";
	std::cin >> protect;
	hero.getProtection(protect);


	while (1) {
		if (monstr.getLife() <= 0) {
			std::cout <<"Hero won!";
				return 0;
		}
		
		monstr.damage(hero.heroAtack());
		hero.takeDamage(monstr.monstrAtack());
		if (hero.getlife() <= 0) {
			std::cout << "Monstr Won\n";
			return 0;
		}

		
	}

   
}

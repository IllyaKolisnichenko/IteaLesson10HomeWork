#include <iostream>
#include <string>

class Person {
public:
    enum Item {
        Shield,
        Sword,
        Armor,
        Count
    };

    enum Magic {
        FireBall,
        FireShield,
        MagicStick,
        Count1
    };

    void getItem() {
        Item item{ static_cast<Item> (rand() % Item::Count) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };
        itemPair = { item, sizeOfItem };
    }

    void castMagic() {
        Magic magic{ static_cast<Magic> (rand() % Magic::Count1) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };
        magicPair = { magic, sizeOfItem };
    }

    int getLife() {
        return life;
    }

protected:
    std::pair< Item, int > itemPair;
    std::pair< Magic, int> magicPair;
    int life = 100;
    static constexpr int maxAttack = 10;

private:
    static constexpr int maxSizeOfItem = 10;
};

class Hero : public Person {
public:
    int attack() {
        int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
        return (rand() % maxAttack) + addAttack;
    }

    void takeDamage(int damage) {
        if (itemPair.first == Item::Shield || itemPair.first == Item::Armor) {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class Wizard : public Person {
public:
    int attack() {
        int magicAttack{ magicPair.first == Magic::FireBall ? magicPair.second : 0 };
        return (rand() % maxAttack) + magicAttack;
    }

    void takeDamage(int damage) {
        if (magicPair.first == Magic::FireShield || magicPair.first == Magic::MagicStick) {
            life -= damage - magicPair.second;
            return;
        }

        life -= damage;
    }
};

class BattleWizard : public Wizard {
public:
    int attack() {
        int magicAttack{ magicPair.first == Magic::FireBall ? magicPair.second : 0 };
        return (rand() % maxAttack) + magicAttack;

        int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
        return (rand() % maxAttack) + addAttack;
    }

    void takeDamage(int damage) {
        if (magicPair.first == Magic::FireShield || magicPair.first == Magic::MagicStick) {
            life -= damage - magicPair.second;
            return;
        }

        life -= damage;
    }
};

class Orc : public Person {
public:
    int attack() {
        return (rand() % maxAttack);
    }

    void takeDamage(int damage) {
        if (itemPair.first == Item::Shield || itemPair.first == Item::Armor) {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

int main() {
    srand(time(nullptr));

    BattleWizard wizard;
    Orc orc;

    wizard.getItem();
    wizard.castMagic();
    orc.getItem();

    while (true) {
        orc.takeDamage(wizard.attack());
        if (orc.getLife() <= 0) {
            std::cout << "Wizard fights down orc. ";
            return 0;
        }

        wizard.takeDamage(orc.attack());
        if (wizard.getLife() <= 0) {
            std::cout << "Orc fights down wizard. ";
            return 0;
        }
    }

    return 0;
}

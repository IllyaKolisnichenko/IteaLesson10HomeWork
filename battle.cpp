#include <iostream>
#include <string>

class Person {
public:
    enum Item {
        Shield,
        Sword,
        Armor,
        FistFight,
        Count
    };

    enum Magic {
        Fireball,
        MagicShield,
        KineticField,
        Count1
    };

    void getItem() {
        Item item { static_cast< Item > ( rand() % Item::Count ) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };
        itemPair = { item, sizeOfItem };
    }

    void castMagic() {
        Magic magic { static_cast< Magic > ( rand() % Magic::Count1) };
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
        return ( rand() % maxAttack ) + addAttack;
    }

    void takeDamage( int damage ) {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor ) {
            life -=  damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class Wizard : public Person {
public:
    int attack() {
        int magicAttack{ magicPair.first == Magic::Fireball ? magicPair.second : 0 };
        return ( rand() % maxAttack ) + magicAttack;
    }

    void takeDamage( int damage ) {
        if ( magicPair.first == Magic::MagicShield || magicPair.first == Magic::KineticField ) {
            life -=  damage - magicPair.second;
            return;
        }

        life -= damage;
    }
};

class BattleMage : public Wizard {
public:
    int attack() {
        int magicAttack{magicPair.first == Magic::Fireball ? magicPair.second : 0 };
        return ( rand() % maxAttack ) + magicAttack;

        int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
        return ( rand() % maxAttack ) + addAttack;
    }

    void takeDamage( int damage ) {
        if ( magicPair.first == Magic::MagicShield || magicPair.first == Magic::KineticField ) {
            life -=  damage - magicPair.second;
            return;
        }

        life -= damage;
    }
};

class Monster : public Person {
public:
    int attack() {
        return ( rand() % maxAttack );
    }

    void takeDamage( int damage ) {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor ) {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

int main() {
    srand( time(nullptr ) );

    BattleMage battlemage;
    Monster monster;

    battlemage.getItem();
    battlemage.castMagic();
    monster.getItem();

    while (true) {
        monster.takeDamage( battlemage.attack() );
        if( monster.getLife() <= 0 ) {
            std::cout << "Mage won!";
            return 0;
        }

        battlemage.takeDamage( monster.attack() );
        if( battlemage.getLife() <= 0 ) {
            std::cout << "Monster won!";
            return 0;
        }
    }

    return 0;
}

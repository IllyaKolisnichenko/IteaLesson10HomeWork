#include <iostream>
#include <string>

class Person{
public:
    enum Item{
        Shield,
        Sword,
        Armor,
        Magic,
        HandCombat,
        Count
    };

    void getItem(){
        Item item { static_cast< Item > ( rand() % Item::Count ) };
        const auto sizeOfItem{ rand() % maxSizeOfItem };

        itemPair = { item, sizeOfItem };
    }

    int getLife(){
        return life;
    }

protected:
    std::pair< Item, int > itemPair;
    int life = 100;
    static constexpr int maxAttack = 10;

private:
    static constexpr int maxSizeOfItem = 10;
};

class Hero : public Person{
public:
    int attack()
    {
        int addAttack{ itemPair.first == Item::Sword || itemPair.first == Item::HandCombat ? itemPair.second : 0 };
        return ( rand() % maxAttack );
    }

    void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -=  damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class Monster : public Person{
public:
    int attack()
    {
        return ( rand() % maxAttack );
    }

    void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Shield || itemPair.first == Item::Armor )
        {
            life -= damage - itemPair.second;
            return;
        }

        life -= damage;
    }
};

class MagicHero : public Hero {
public:
    void magic()
    {
        if (itemPair.first == Item::Magic)
        {
            life += itemPair.second;
            return;
        }
    }
};


int main()
{
    srand( time(nullptr ) );

    MagicHero magicHero;
    Monster monster;
   
    while (true)
    {
        magicHero.getItem();
        monster.getItem();
        monster.takeDamage( magicHero.attack() );
        if( monster.getLife() <=0 )
        {
            std::cout << "MagicHero is win!!!" << std::endl;
            system("pause");
            return 0;
        }
        magicHero.magic();
        magicHero.takeDamage( monster.attack() );
        if( magicHero.getLife() <=0 )
        {
            std::cout << "Monster is win!!!" << std::endl;
            system("pause");
            return 0;
        }
    }
    
    return 0;
}

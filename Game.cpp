#include <iostream>


class Warrior {
public:

<<<<<<< HEAD
    int getLife() {
        return life_;
    }

    int attack() {
        return rand() % maxAttack_ + minAttack_ + weaponAttackValue_;
    }

    void getDamage(int damage) {
=======
    virtual int getLife() {
        return life_;
    }

    virtual int attack() {
        return rand() % maxAttack_ + minAttack_ + weaponAttackValue;
    }

    virtual void getDamage(int damage) {
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
        if (damage <= shieldDefenceValue)
            damage = 0;
        else
            damage -= shieldDefenceValue;

        life_ -= damage;
    }

    void getWarriorWeapon() {
        int choise{};

        while (true)
        {
            std::cout << "Choose you weapon: 1 - Axe, 2 - Sword. Your choise is ";
            std::cin >> choise;

            switch (choise) {
            case NoWeapon:
<<<<<<< HEAD
                weaponAttackValue_ = fistAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case Axe:
                weaponAttackValue_ = axeAttack_;
                std::cout << "Weapon is Axe with " << axeAttack_ << " attack bonus" << std::endl;
                return;
            case Sword:
                weaponAttackValue_ = swordAttack_;
=======
                weaponAttackValue = fistAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case Axe:
                weaponAttackValue = axeAttack_;
                std::cout << "Weapon is Axe with " << axeAttack_ << " attack bonus" << std::endl;
                return;
            case Sword:
                weaponAttackValue = swordAttack_;
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
                std::cout << "Weapon is Sword with " << swordAttack_ << " attack bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrond symbol! Please, try again!" << std::endl;
                break;
            }
        }
    }

    void getShield() {
        int choise{};

        while (true)
        {
            std::cout << "Choose you shield: 1 - WoodenShield, 2 - MetalShield. Your choise is ";
            std::cin >> choise;

            switch (choise) {
            case NoShield:
                shieldDefenceValue = noShieldProtection_;
                std::cout << "No shield" << std::endl;
                return;
            case WoodenShield:
                shieldDefenceValue = woodenShieldProtection_;
                std::cout << "Wooden Shield with " << woodenShieldProtection_ << " protect bonus" << std::endl;
                return;
            case MetalShield:
                shieldDefenceValue = metalShieldProtection_;
                std::cout << "Metal Shield with " << metalShieldProtection_ << " protect bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrond symbol! Please, try again!" << std::endl;
                break;
            }
        }

    }
protected:
    enum Weapon {
        NoWeapon,
        Axe,
        Sword,
    };

    enum Shield {
        NoShield,
        WoodenShield,
        MetalShield,
    };

<<<<<<< HEAD
    int weaponAttackValue_{};
=======
    int weaponAttackValue{};
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
    int shieldDefenceValue{};

    static constexpr int fistAttack_{ };
    static constexpr int axeAttack_{ 7 };
    static constexpr int swordAttack_{ 10 };

    static constexpr int noShieldProtection_{ };
    static constexpr int woodenShieldProtection_{ 3 };
    static constexpr int metalShieldProtection_{ 7 };

private:
    int life_{ 150 };

    static constexpr int minAttack_{ 1 };
    static constexpr int maxAttack_{ 10 };

};

class Sorcerer {
public:
<<<<<<< HEAD
    int getLife() {
        return life_;
    }

    int attack() {
        return rand() % maxAttack_ + minAttack_ + weaponAttackValue_;
    }

    void getDamage(int damage) {
=======
    virtual int getLife() {
        return life_;
    }

    virtual int attack() {
        return rand() % maxAttack_ + minAttack_ + weaponAttackValue;
    }

    virtual void getDamage(int damage) {
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
        life_ -= damage;
    }

    void getMagicWeapon() {
        int choise{};

        while (true)
        {
            std::cout << "Choose you magic weapon: 1 - Spell, 2 - Magic Stick. Your choise is ";
            std::cin >> choise;

            switch (choise) {
            case NoWeapon:
<<<<<<< HEAD
                weaponAttackValue_ = noWeaponAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case BattleSpell:
                weaponAttackValue_ = spellAttack_;
                std::cout << "Weapon is Spell with " << spellAttack_ << " attack bonus" << std::endl;
                return;
            case MagicStick:
                weaponAttackValue_ = magicStickAttack_;
=======
                weaponAttackValue = noWeaponAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case BattleSpell:
                weaponAttackValue = spellAttack_;
                std::cout << "Weapon is Spell with " << spellAttack_ << " attack bonus" << std::endl;
                return;
            case MagicStick:
                weaponAttackValue = magicStickAttack_;
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
                std::cout << "Weapon is Magic Stick with " << magicStickAttack_ << " attack bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrond symbol! Please, try again!" << std::endl;
                break;
            }
        }
    }

protected:
    enum Weapon {
        NoWeapon,
        BattleSpell,
        MagicStick,
    };

<<<<<<< HEAD
    int weaponAttackValue_{};
=======
    int weaponAttackValue{};
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e

    static constexpr int noWeaponAttack_{ };
    static constexpr int spellAttack_{ 10 };
    static constexpr int magicStickAttack_{ 13 };

private:
    int life_{ 100 };

    static constexpr int minAttack_{ 1 };
    static constexpr int maxAttack_{ 10 };
};

class CombatSorcerer : public Warrior, public Sorcerer {
public:
<<<<<<< HEAD
    int getLife() {
        return life_;
    }

    int attack() {
        return rand() % maxAttack_ + minAttack_ + shieldDefenceValue;
    }

    void getDamage(int damage) {
=======
    virtual int getLife() {
        return life_;
    }

    virtual int attack() {
        return rand() % maxAttack_ + minAttack_ + shieldDefenceValue;
    }

    virtual void getDamage(int damage) {
>>>>>>> f9d25c5598e0232312150791b43f3afdbaeffc2e
        if (damage <= shieldDefenceValue)
            damage = 0;
        else
            damage -= shieldDefenceValue;

        life_ -= damage;
    }

    void getCombatSorcererWeapon() {
        int choise{};

        while (true)
        {
            std::cout << "Do you want Warrior's weapon or Magic weapon? 1 - Warrior's weapon, 2 - Magic weapon. Your choise is ";
            std::cin >> choise;
            switch (choise) {
            case 1:
                getWarriorWeapon();
                return;
            case 2:
                getMagicWeapon();
                return;
            default:
                std::cout << "You ented wrond symbol! Please, try again!" << std::endl;
                break;
            }

        }
    }

private:
    int life_{ 75 };

    static constexpr int minAttack_{ 1 };
    static constexpr int maxAttack_{ 10 };
};



int main()
{
    srand( time( nullptr ) );

    CombatSorcerer hero;
    std::cout << "Choose the equipment for your hero" << std::endl;
    hero.getCombatSorcererWeapon();
    hero.getShield();

    Sorcerer antagonist;
    std::cout << "Choose the equipment for antagonist" << std::endl;
    antagonist.getMagicWeapon();
    std::cout << std::endl;


    while (true)
    {
        int heroAttack{ hero.attack() };
        std::cout << "Hero attacks is " << heroAttack << std::endl;

        antagonist.getDamage(heroAttack);

        if(antagonist.getLife() <=0 )
        {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Antagonist is dead. Hero won!!!" << std::endl;

            return 0;
        }

        std::cout << "Antagonist's health after damage is " << antagonist.getLife() << std::endl;

        std::cout << std::endl;

        int antagonistAttack{ antagonist.attack() };

        std::cout << "Antagonist attack is " << antagonistAttack << std::endl;

        hero.getDamage(antagonistAttack);

        if( hero.getLife() <=0 )
        {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Hero is dead. Antagonist won!!!" << std::endl;

            return 0;
        }

        std::cout << "Hero's health after damage is " << hero.getLife() << std::endl;

        std::cout << std::endl;
        system("pause");
        std::cout << std::endl;
    }

    return 0;
}

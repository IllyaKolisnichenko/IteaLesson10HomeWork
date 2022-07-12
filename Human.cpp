#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <array>


class Bacterium {
public:
    std::string gasForLife{ "Oxigen" };
    std::string substanceForLife{ "Water" };
    std::string structure{ "Unicellular" };
    
    void getInfo() {
        std::cout << "LIVING ORGANISM BACTERIUM:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << std::endl;
    }
};

class Invertebrates : public Bacterium {
public:
    std::string structure{ "Cellular" };
    
    void crawl() {
        std::cout << "This living organism can crawling" << std::endl;
    }
    
    void swim() {
        std::cout << "This living organism can swiming" << std::endl;
    }
    
    void getInfo() {
        std::cout << "LIVING ORGANISM INVERTEBRATES:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        crawl();
        swim();
        std::cout << std::endl;
    }
};

class Fishes : public Invertebrates {   
public:
    std::string supportАpparatus{ "skeleton" };
    
    void swim() {
        std::cout << "This living organism can swiming" << std::endl;
    }
    
    void getInfo() {
        std::cout << "LIVING ORGANISM FISHES:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << "Living organism have: " << supportАpparatus << std::endl;
        crawl();
        swim();
        std::cout << std::endl;
    }
};

class Amphibia : public Fishes {
public:
    std::string lowerLimbs{ "legs" };
    
    void walk() {
        std::cout << "This living organism can walking" << std::endl;
    }
    
    void getInfo() {
        std::cout << "LIVING ORGANISM AMPHIBIA:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << "Living organism have: " << supportАpparatus << ", " << lowerLimbs << std::endl;
        crawl();
        swim();
        walk();
        std::cout << std::endl;
    }
};

class Mammals : public Amphibia {
public:
    std::string mainProduct{ "Milk" };

    void getInfo() {
        std::cout << "LIVING ORGANISM MAMMALS:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << ", " << mainProduct << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << "Living organism have: " << supportАpparatus << ", " << lowerLimbs << std::endl;
        crawl();
        swim();
        walk();
        std::cout << std::endl;
    }
};

class Primates : public Mammals {
public:
    std::string upperLimbs{ "hands" };
   
    void carry() {
        std::cout << "This living organism can carry objects" << std::endl;
    }

    void getInfo() {
        std::cout << "LIVING ORGANISM PRIMATES:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << ", " << mainProduct << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << "Living organism have: " << supportАpparatus << ", " << lowerLimbs << ", " << upperLimbs << std::endl;
        crawl();
        swim();
        walk();
        carry();
        std::cout << std::endl;
    }
};

class Human : public Primates {
public:
    void toThink() {
        std::cout << "This living organism can thinking" << std::endl;
    }

    void getInfo() {
        std::cout << "LIVING ORGANISM HUMAN:" << "\n";
        std::cout << "For living is nessary: " << gasForLife << ", " << substanceForLife << ", " << mainProduct << std::endl;
        std::cout << "Structure of living organism: " << structure << std::endl;
        std::cout << "Living organism have: " << supportАpparatus << ", " << lowerLimbs << ", " << upperLimbs << std::endl;
        crawl();
        swim();
        walk();
        carry();
        toThink();
        std::cout << std::endl;
    }
};


int main()
{
    std::string userQuestion;
    std::string::size_type n;
    const int arraySize{ 7 };
    std::array<std::string, arraySize> keyWords{ "bacterium", "invertebrat", "fish", "amphibia", "mammals", "primate", "human"};
   
    std::cout << "\n" << "Plaese click enter for start" << std::endl;
    if (_getch() == 13)
    {
        std::cout << "Hello, please enter your qustion about living organism" << std::endl;
    }
    while (true)
    {
        std::getline(std::cin, userQuestion);
        for (int i{}; i < arraySize; i++)
        {
            n = userQuestion.find(keyWords[i]);
            if (n != std::string::npos) 
            {
                std::string findWord{ userQuestion.substr(n) };
                if (findWord == "human")
                {
                    Human smartHuman;
                    smartHuman.getInfo();
                }
                if (findWord == "primate")
                {
                    Primates primate;
                    primate.getInfo();
                }
                if (findWord == "mammals")
                {
                    Mammals mammals;
                    mammals.getInfo();
                }
                if (findWord == "amphibia")
                {
                    Amphibia amphibia;
                    amphibia.getInfo();
                }
                if (findWord == "fish")
                {
                    Fishes fish;
                    fish.getInfo();
                }
                if (findWord == "invertebrat")
                {
                    Invertebrates invertebrat;
                    invertebrat.getInfo();
                }
                if (findWord == "bacterium")
                {
                    Bacterium bacterium;
                    bacterium.getInfo();
                }               
            }
        }
        
        std::cout << "Please enter next question, for exit click ESC" << std::endl;
        if (_getch() == 27)
        {
            std::cout << "Bye, I was glad to answer your questions" << std::endl;
            break;
        }
    }
  
    system("pause");
    return 0;
}

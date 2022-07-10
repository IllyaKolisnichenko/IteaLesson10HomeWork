#include <iostream>
#include <string>
#include"biology.h"


    Eyes::Eyes (int lt) : lightX(lt){
        light_ = lightX;
    }

   int Eyes::signal_cascade () {
            std::cout << "Reaction\n" << std::endl;;
            return 0;
    }

    int Eyes::light() {
        std::cout << "if there are rays of light? Put word 10." << std::endl;
        std::cin >> lightX;
        if (lightX == 10)
        {
            std::cout << "activation reaction!" << std::endl;;
        }
        else if (lightX != 10)
        return night();
    }

    int Eyes::night() {
        std::cout << "release glutamat in sinaps." << std::endl;
        std::cin >> lightX;
        return 0;
    }
                          
    retinal::retinal (int ft, int raza, int ret, int reti, int lt) : Eyes(lt){
     foton = ft;
     retinalizomeraza = raza;
     retinoldegidroginaza= ret; 
     retinal_ = reti;
    }                              
    int retinal::light() {          
        Eyes::light();
        std::cout << "reaction under the action of a photon and transformation in transform." << std::endl;
        std::cout <<"Input umber of photons 10 (trillion)." << std::endl;
        std::cin >> foton;
        if (foton == 10)
        {
            return conformation();
        }
        else if (foton != 10)
            std::cout << "reaction is weak or impossible" << std::endl;;
            return 0;
    }

    int retinal::conformation() {
        int cis = 0;
        int trans = 0;
        std::cout << "rhodopsin absorbs light in the visible part of the spectrum with an absorption maximum of 500 nm." << std::endl;
        std::cout << "input 500 (nanometrs)" << std::endl;
        std::cin >> foton;
        if (foton == 500)
        {
            cis = retinalizomeraza + retinal_;
            trans = retinoldegidroginaza + retinal_;
            std::cout << "Formation of trans and cis forms of retinal!" << std::endl;
        }
        else if (foton != 500)
        std::cout << "reaction is weak or impossible" << std::endl;;
        return 0;
    }
                   
    rhodopsin::rhodopsin(int tr, int lt) : Eyes(lt) {
        trans_retinal=tr;
    }

    int rhodopsin::light() {
        Eyes::light();
        std::cout << "Exchange of GDF for GTF!" << std::endl;;
        std::cout << "Phosphate added! If yes enter 94 (94,9714 g/mol.)" << std::endl;
        std::cin >> trans_retinal;
        if (trans_retinal == 94)
        {
            return reaction();
        }
        else if (trans_retinal != 94)
        std::cout << "reaction is weak or impossible" << std::endl;;
        return 0;
    }

    int rhodopsin::reaction() {
        std::cout << "activation of transducin g protein." << std::endl;
        return 0;                                             
    }                                                          
                                                                 
    transducin::transducin(int G_pn, int lt) : Eyes(lt) {
        G_protein=G_pn;
    } 
    
    int transducin::light(){                                      
        Eyes::light();
        std::cout << "alpha-subelement activation of cGMFfosfodiesterase ferment." << std::endl;
        std::cout << "start of reaction put  namber 1." << std::endl;
        std::cin >> G_protein;
        if (G_protein == 1)
        {
            return decrease();
        }
        else if (G_protein != 1)
            std::cout << "reaction is weak or impossible" << std::endl;
        return 0;
    }
    
    int transducin::decrease() {
        int membran = 0;
        int alfa_subelement_ = 0;
        int cGMFfosfodiesteraza_ = 0;
        membran = cGMFfosfodiesteraza_ + alfa_subelement_;
        std::cout << "decrease in cGMP in cells!" << std::endl;
        return 0;
    } 
   
    cGMP::cGMP(int alst, int gza, int GMF, int lt) : Eyes(lt) {
        alfa_subelement=alst;
        guanilatciklaza = gza;
        cGMFfosfodiesteraza = GMF;
    } 
                                 
    int cGMP::light() {                        
        Eyes::light();                             
        std::cout << "Сations are pumped out of the cell." << std::endl;
        std::cout << "The membrane potential drops! Put namder 1 ." << std::endl;
        std::cin >> alfa_subelement;
        if (alfa_subelement == 1)
        {
            std::cout << "Hyperpolarization begins!" << std::endl;
            return hyperpolarization();
        }
        else if (alfa_subelement != 1)
            std::cout << "reaction is weak or impossible" << std::endl;
        return 0;
    }

    int cGMP::hyperpolarization() {
        setlocale(LC_ALL, "");
        std::cout << "Stops the release of glutamate!" << std::endl;
        std::cout << "If the reaction continues, put number 1!" << std::endl;
        std::cin >> alfa_subelement;
        if (alfa_subelement == cGMFfosfodiesteraza)
        {
            std::cout << "Сell neurons perceive such a signal as light!!" << std::endl;;
            std::cout << "Наглядная Биохимия. Я.Кольман, К.-Г. Рём " << std::endl;;
            return regeneration();
        }
        else if (alfa_subelement <= guanilatciklaza)
        std::cout << "cGMP cyclic nucleotide that is synthesized under the action of guanilatciklaza" << std::endl;
        return 0;
    }
    int cGMP::regeneration() {
        std::cout << "Regeneration!" << std::endl;
        return light();
    }
   
   




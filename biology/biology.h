#include <iostream>
#include <string>

  class Eyes {
public:
    Eyes(int lt);

    int signal_cascade();
    int light();
    int night();

private:
    int light_;
    int lightX;
};

class retinal : public Eyes {
private:
    int foton;
     int retinalizomeraza;
     int retinoldegidroginaza;
     int retinal_;
public:
    retinal(int ft, int raza, int ret, int reti, int lt);
    int light();
    int conformation();
};

class rhodopsin : public Eyes {
private:
    int trans_retinal;
public:
    rhodopsin(int tr, int lt);
    int light();
    int reaction();
};

    class transducin : public Eyes {
    private:
        int G_protein;
    public:
        transducin(int G_pn, int lt);
        int light();
        int decrease();
        int copyr();
};
    class cGMP : public Eyes {
    private:
        int alfa_subelement;
        int guanilatciklaza;
        int cGMFfosfodiesteraza;
    public:
        cGMP(int alst, int gza, int GMF, int lt);
        int light();
        int hyperpolarization();
        int regeneration();
};



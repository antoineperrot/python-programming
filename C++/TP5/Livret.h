#include<iostream>

using namespace std;

class Compte{
protected :
    float solde;
public:
    Compte(float solde = 0);
    void afficherSolde();
    void depot(float val);
    void retrait(float val);
    void virer(float val, Compte & dest);
};



class Livret : public Compte{
    float interet;
    float plafond;
public :
    float CalculInteret(int nbannee = 10);
    Livret(const Livret & copie);
    Livret(float solde = 0,float interet = 0.01, float plafond = 20000.0);
    friend ostream& operator<<(ostream & out, const Livret & l);

};


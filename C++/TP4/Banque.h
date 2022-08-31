#define MAX_SIZE 100 

#include<iostream>

using namespace std;

class Date {
    int jour, mois, annee;
public :
    friend Date operator+(const Date &, const Date &);
    void saisir();
    void afficher();
    bool operator<(Date&);
    bool operator==(Date&);

};

class Compte{
    float solde = 0;
public:
    void afficherSolde();
    void depot(float val);
    void retrait(float val);
    void virer(float val, Compte & dest);
    bool operator==(Compte&);
};

class Client{
    Compte compte;
    char nom[MAX_SIZE];
    Date birthdate;

public :
    void saisirInfos();
    void afficherInfos();
    bool operator==(Client&);
    

};

class Banque{
    int MaxClient;
    int nbClients;
    Client * tab;
public :
    Banque(int MaxClient = 10);
    Banque(const Banque&);
    void operator+(Client&);
    bool operator==(Client&);
    Banque operator+(const Banque &);    // codé par une méthode de la classe
    //friend Banque operator+(const Banque &, const Banque &);   //fonction globale
    //void operator=(const & Banque);
    friend ostream& operator<<(ostream& out, const Banque& b);
    Banque & operator=(const Banque & b2);
    ~Banque();
    
    void transfert(int, Banque &);
    

};




/*
Banque operator+(const Banque & b1, const Banque & b2){     //fonction globale
    Banque  res;
    res.MaxClient = b1.MaxClient + b2.MaxClient ;
    res.nbClients = b1.nbClients + b2.nbClients ;
    res.tab = new Client[res.MaxClient];


    for (int i = 0; i < b1.nbClients; i++){
        res.tab[i] = b1.tab[i];
    }
    for (int i = 0; i < b2.nbClients; i++){
        res.tab[i+ b1.nbClients] = b2.tab[i];
    }

    return  res;
}

*/
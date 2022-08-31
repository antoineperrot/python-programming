#include "Livret.h"
#include<iostream>

using namespace std;

#include <iostream>
using namespace std;

Compte::Compte(float solde){
    this->solde = solde;
}

void Compte :: afficherSolde(){
    cout<<"solde : "<<this->solde<<"\n";
}

void Compte :: depot(float val){
    this->solde += val;
}

void Compte :: retrait(float val){
    this->solde -= val;
}

void Compte :: virer(float val, Compte & dest){
    this->solde -= val;
    dest.depot(val);
}

Livret :: Livret(float solde, float interet, float plafond){
    this->solde = solde;
    this->interet = interet;
    this->plafond = plafond;
}

Livret ::Livret(const Livret & copie){
    this->solde = copie.solde;
    this->interet = copie.interet;
    this->plafond = copie.plafond;  
}

float Livret :: CalculInteret(int nbannee ){
    float somme = 0.0;
    float current_solde = this->solde;
    for (int i = 0; i < nbannee; i++) {
        somme += this->interet * current_solde;
        current_solde = (1 + this->interet) * current_solde;
    }
    return somme;
}


ostream& operator<< (ostream & out, const Livret & l){
    out << "Solde : " << l.solde << endl;
    out << "Taux d'interet : " << l.interet << endl;
    out << "Plafond : " << l.plafond << endl;
    return out;
}


#include "Client.h"
#include<iostream>

using namespace std;

void Date :: saisir(){
    cout << "Entrer le jour : ";
    cin >> this->jour ;
    cout << "Entrer le mois : ";
    cin >> this->mois ;
    cout << "Entrer l'annee : ";
    cin >> this->annee ;
}

void Date :: afficher(){
    cout<<this->jour<<"/" << this->mois << "/" << this->annee ;
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

void Client :: saisirInfos(){
    cout << "\nNom du client : ";
    cout << "\nDate de naissance : \n";
    this->birthdate.saisir();
}

void Client :: afficherInfos(){
    cout << "\nDate de naissance : ";
    this->birthdate.afficher();
}

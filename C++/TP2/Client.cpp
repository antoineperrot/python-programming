#include "Client.h"
#include<iostream>

using namespace std;

Date::Date(int jour, int mois, int annee){
    this->jour = jour;
    this->mois = mois ;
    this->annee = annee;
}

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

void Client :: saisirInfos(){
    cout << "\nNom du client : ";
    cin >> this->nom;
    cout << "\nDate de naissance : \n";
    this->birthdate.saisir();
};

void Client :: afficherInfos(){
    cout << "\nINFOS CLIENT :\nNom : " << this->nom;
    cout << "\nDate de naissance : ";
    this->birthdate.afficher();
}

Client :: Client(){
    this->nom = "";
}
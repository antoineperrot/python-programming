#include "Banque.h"
#include<iostream>
#include<string.h>

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
    cout<<this->jour<<"/" << this->mois << "/" << this->annee << endl;
}

bool Date :: operator<(Date & d2){
    if (this->jour < d2.jour){
        return true;
    }
    else {
        return false;
    }
}
bool Date ::operator==(Date & d2){
    if ((this->jour == d2.jour) && (this->mois == d2.mois) && (this->annee == d2.annee)){
        return true;
    }
    else{
        return false;
    }
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

bool Compte :: operator==(Compte & compte2){
    if (this->solde == compte2.solde){
        return true;
    }
    else {
        return false;
    }
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

bool Client :: operator==(Client & client2){
    if ((this->birthdate == client2.birthdate)&&(strcmp(this->nom,client2.nom)==0)){
        return true;
    }
    else {
        return false;
    }
}

Banque :: Banque(int MaxClient ){
    this->MaxClient = MaxClient;
    this->nbClients = 0;
    this->tab = new Client [MaxClient];
}

Banque :: Banque(const Banque & copie){
    this->nbClients = copie.nbClients;
    this->MaxClient = copie.MaxClient;
    this->tab = copie.tab;

}

void Banque :: afficherInfos(){
    cout << "La banque peut accueillir jusqu'a " << this->MaxClient << " clients.\n";
    cout << "Elle en contient actuellement " << this->nbClients <<".\n\n";
}

void Banque :: afficherClients(){
    if (this->nbClients == 0){
        cout <<"La banque n'a encore aucun client a afficher.\n";
    }
    else
    {
        for (int i = 0; i < this->MaxClient; i++){
            this->tab[i].afficherInfos();
            cout <<"CUT";
        }
    }
}

Banque::~Banque(){delete[] tab;}

void Banque :: ajouter(Client c){
    tab[nbClients] = c;
    this->nbClients += 1;
    
}

int Banque :: appartient(Client c){

    int res = 0;
    int i = 0;
    bool done = (i == this->nbClients );
    while (!(done)) {
        if (this->tab[i] == c){
            res = 1;
            done = true;
        }
        else {
            i++;
            done = (i == this->nbClients);
        }
        
    }
    return res;
}

void Banque :: transfert(int i, Banque & dest){
    if ((i>=this->nbClients)   ||   (dest.MaxClient == dest.nbClients)){
        cout << "Transfert impossible" << endl;
    }
    else {
        Client c;
        Client temp;
        c = Client(this->tab[i]);
        dest.ajouter(c);
        this->tab[i] = Client(this->tab[this->nbClients-1]);
        this->tab[this->nbClients-1] = temp;
        this->nbClients -= 1;

    }
}

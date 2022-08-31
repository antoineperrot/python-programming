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

Banque :: Banque(int MaxClient){
    this->MaxClient = MaxClient;
    this->nbClients = 0;
    this->tab = new Client [MaxClient];
}

Banque :: Banque(const Banque & copie){
    this->nbClients = copie.nbClients;
    this->MaxClient = copie.MaxClient;
    this->tab = copie.tab;

}

Banque::~Banque(){delete[] tab;}

void Banque :: operator+(Client & c){
    tab[nbClients] = c;
    this->nbClients += 1;

}
bool Banque :: operator==(Client & c){
    int res = false;
    int i = 0;
    bool done = (i == this->nbClients );
    while (!(done)) {
        if (this->tab[i] == c){
            res = true;
            done = true;
        }
        else {
            i++;
            done = (i == this->nbClients);
        }
        
    }
    return res;
}
/*
void Banque :: operator=(const & Banque b2){
    this->MaxClient = b2.MaxClient;
    this->nbClients = b2.nbClients;
    this->tab = new Client [this->MaxClient];
    for (int i = 0 ; i < b2.nbClients; i++  ){
        this->tab[i] = b2.tab[i];   
    }
}
*/

Banque & Banque :: operator=(const Banque & b2){
    delete[] this->tab;
    this->MaxClient = b2.MaxClient;
    this->nbClients = b2.nbClients;
    this->tab = new Client[this->MaxClient];
    for (int i = 0; i < b2.nbClients; i++){
        this->tab[i] = b2.tab[i];
    }

    return *this;
    }

void Banque :: transfert(int i, Banque & dest){
    if ((i>=this->nbClients)   ||   (dest.MaxClient == dest.nbClients)){
        cout << "Transfert impossible" << endl;
    }
    else {
        Client c;
        Client temp;
        c = Client(this->tab[i]);
        dest + c ;
        this->tab[i] = Client(this->tab[this->nbClients-1]);
        this->tab[this->nbClients-1] = temp;
        this->nbClients -= 1;

    }
}

Banque Banque :: operator+(const Banque &b2){
    Banque res;
    res.MaxClient = this->MaxClient + b2.MaxClient ;
    res.nbClients = this->nbClients + b2.nbClients;
    res.tab = new Client[MaxClient];
    for (int i = 0; i < this->nbClients; i++){
        res.tab[i] = this->tab[i];
    }
    for (int i = 0; i < b2.nbClients; i++){
        res.tab[i+ this->nbClients] = b2.tab[i];
    }
    return res;
}




ostream& operator<<(ostream& out, const Banque& b){
    out << "La banque peut contenir au maximum " << b.MaxClient << " clients." << endl ;
    out << "Elle en contient actuellement "<< b.nbClients <<"."<< endl;
    if (b.nbClients > 0){ cout <<"En voici la liste :\n";}
    for (int i = 0; i < b.nbClients; i++){
        b.tab[i].afficherInfos();
    }
    return out;
}
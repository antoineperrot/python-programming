#include "Banque.h"
#include<iostream>


#define MAXLOL 6
using namespace std;

int main(){
    Banque b(10);
    Client c1;
    c1.saisirInfos();
    b.ajouter(c1);
    b.afficherClients();

}
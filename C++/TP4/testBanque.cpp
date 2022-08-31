#include "Banque.h"

#define MAXLOL 6

int main(){
    Banque b1(12), b2(9), b3;
    Client c1,c2 ;
    c1.saisirInfos();
    c2.saisirInfos();
    b1 + c1 ;
    b2 + c2 ;
    b3 = b1 + b2;
    cout << b3;
}
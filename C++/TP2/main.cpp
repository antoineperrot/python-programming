#include "Client.h"
#include<iostream>
#define MAX 3


int main(){
    Client banque[MAX];
    
    for(int i = 0; i < MAX; i+=1){
        
        banque[i].saisirInfos();
    
    }
    
    for(int i = 0; i < MAX; i+=1){
        banque[i].afficherInfos();
    
    }
}





#define MAX_SIZE 100 
class Date {
    int jour = 0; 
    int mois = 0;
    int annee = 0;
public :
    void saisir();
    void afficher();
};



class Compte{
    float solde = 0;
public:
    void afficherSolde();
    void depot(float val);
    void retrait(float val);
    void virer(float val, Compte & dest);
};


class Client{
    Compte compte;
    char nom[MAX_SIZE];
    Date birthdate;

public :
    void saisirInfos();
    void afficherInfos();
    

};
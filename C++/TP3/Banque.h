#define MAX_SIZE 100 
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
    void afficherInfos();
    void afficherClients();
    ~Banque();
    void ajouter(Client c);
    int appartient(Client c);
    void transfert(int, Banque &);

};
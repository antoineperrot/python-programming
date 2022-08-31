class Compte{
    float solde;
public:
    Compte(float solde = 0);
    void afficherSolde();
    void depot(float val);
    void retrait(float val);
    void virer(float val, Compte & dest);
};
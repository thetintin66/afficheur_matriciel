#ifndef _AFFICHEUR_
#define  _AFFICHEUR_

class Affichage_Matrice{

  private:
    int minute;
    int seconde;
    int TempMax;
    int RepetitionMax;
    int Repetition;

  public:
    void Affiche_chronometre(String minute,String seconde);
    void Affiche_compteur(String Repetition);
    void Configuration(int luminositer);
    void Affiche_decompte();
    Affichage_Matrice();

};

#endif

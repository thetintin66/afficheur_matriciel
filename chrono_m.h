#ifndef CHRONO_H_
#define CHRONO_H_
#include "afficheur.h"


class Chrono_M{
  private :
    
    bool started = false;  // Si le chronomètre a commencé
    unsigned long int startTime = 0;  // Temps de début du chronomètre
    unsigned long int elapsedTime = 0;  // Temps écoulé depuis le début du chronomètre
    

  public :
    Affichage_Matrice a;
    void get_start_time();
    void chronometre(String qui, int etat);
    void configuration(); 
    void affichage();
    Chrono_M();
};
  
#endif

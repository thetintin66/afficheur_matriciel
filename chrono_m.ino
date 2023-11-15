
#include "chrono_m.h"
#include "afficheur.h"

#define _DEBUG 1  // 0 pour desactiver le debuggage


bool decompte = false;
int startTime = 0;

Chrono_M::Chrono_M(){
    a.Configuration(20);
}


void Chrono_M::configuration(){
  
  Serial.begin(115200);
}

void Chrono_M::chronometre(String qui, int etat){
  //Serial.println(startTime);
  //Serial.println(etat);
  int previousMinute = -1 ;
  //Serial.println(etat);
  
  if(etat == 1) {  // Si le chronomètre est en cours d'exécution
    if(qui == "1"){
      if(decompte == false){
        a.Affiche_decompte();
        decompte = true;
      }
    }

    
    if(sarted == false){
        startTime = clock()/1000;
        sarted = true;
    }
    
    if (startTime != previousMinute) {
     
      elapsedTime = (clock()/1000) - startTime;   // Calcule le temps écoulé
      
      unsigned int minutes = elapsedTime / 60;
      unsigned int seconds = elapsedTime - 60*minutes;


    
      String sec = "";
      String minu = "";
      minu = String(minutes);
      sec = String(seconds);
      
   
      
      a.Affiche_chronometre(minu,sec);
    }
    delay(1000);
  }

  if(etat == 0){
      sarted = false;
      decompte = false;
  }

}

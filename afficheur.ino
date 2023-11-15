#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <string>
#include <cstdio>
#include "afficheur.h"

#define PANEL_RES_X 64    // Nombre de pixels de longeur pour un panneau INDIVIDUEL. 
#define PANEL_RES_Y 32   // Nombre de pixels de largeur pour un panneau INDIVIDUEL. 
#define PANEL_CHAIN 1   // Nonbre total de panneau 

MatrixPanel_I2S_DMA *dma_display = nullptr;   // MatrixPanel_I2S_DMA dma_display;

/**
 * Constructeur de la classe afficheur 
 */
Affichage_Matrice::Affichage_Matrice(){
}

/**
 * Configuration de l'affichage matriciel
 */ 
void Affichage_Matrice::Configuration(int luminositer) {

  // Module configuration de la classe 
  HUB75_I2S_CFG mxconfig(
    PANEL_RES_X,    // module largeur
    PANEL_RES_Y,   // module hauteur
    PANEL_CHAIN   // taile de la chain
  );
  
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);                // Initialise la matrice avec la configuration predefini
  dma_display->begin();                                          // Configuration de la matrice LED
  dma_display->setBrightness8(luminositer);                     // Definit la luminositer des led
  dma_display->setTextWrap(false);                             // Pas de retour a la ligne
  dma_display->setTextColor(dma_display->color444(15,15,15)); // Couleur du texte (blanc)// Permet de definir la luminositer (0-255)
  dma_display->clearScreen();                                // Permet de supprimer tout les données affichers sur l'ecran   
  
}

/**
 * Permet d'afficher le chronometre 
 */
void Affichage_Matrice::Affiche_chronometre(String minute,String sec) {

//Configuration
/********************************************************************************************************************/  
  dma_display->setTextSize(2);                                    // Taille de se qui est afficher
  dma_display->setTextWrap(false);                               // Pas de retour a la ligne
  dma_display->setCursor(3, 9);                                 // Pixel de demarrage (longeur, largeur)
  dma_display->setTextColor(dma_display->color444(15,15,15));  // Declare la couleur de se qui est afficher (ici blanc)
  dma_display->clearScreen();                                 // Supprime tout les données afficher sur l'ecran
/*********************************************************************************************************************/ 

int secs = sec.toInt();    // Convertie les secondes string en int  
int minutes = minute.toInt();     // Convertie les secondes string en int  

 
//Permet de gerer les minute si elles sont inferieur a 10 on ajout un 0 le chronometre affichera donc 01,02 ect sinon aucun changement 10, 11 ect
/***********************************************************************************************************************************************/
  if(minutes < 10 ){
    dma_display->print("0");          //permet dafficher un 0 avant le nombre 
    dma_display->print(minute);     //affiche les minute 
  }
  else{
    dma_display->print(minute);     // Affiche les minute
  }
/***********************************************************************************************************************************************/

  dma_display->print(":"); // Affiche : entre le minute et le seconde
  
//permet de gerer les seconde si elles sont inferieur a 10 on ajout un 0 le chronometre affichera donc 01,02 ect sinon aucun changement 10, 11 ect
/************************************************************************************************************************************************/
  if(secs < 10 ){
    dma_display->print("0");      // Permet dafficher un 0 avant le nombre 
    dma_display->println(sec);  // Affiche les seconde 
  }
  else{
    dma_display->println(sec);  // Affiche les seconde 
  }
/***********************************************************************************************************************************************/
 
}


void Affichage_Matrice::Affiche_compteur(String Repetition) {
  
  //configuration
  dma_display->clearScreen();                                  // Permet de supprimer tout les données affichers sur l'ecran  
  dma_display->setTextSize(3);                                // Definition de la taille 

  int Repetitions = Repetition.toInt();     // Convertie les secondes string en int   

 Serial.println(Repetition);
  //Permet de centrer le nombre si le nombre de repetition est compris en 0 et 9
  /****************************************************************************/
  if(Repetitions < 10){
    dma_display->setCursor(24, 5);   // Centre la valeur de répètition
    dma_display->print(Repetition);       // Affiche la valeur de répètition

    delay(1000);
  }     
  /****************************************************************************/

  
  //Permet de centrer le nombre si le nombre de repetition est compris en 10 et 99
  /******************************************************************************/
  if(Repetitions > 9 && Repetitions <99 ){
    dma_display->setCursor(16, 5);
    dma_display->print(Repetition);

    delay(1000);
  }
  /******************************************************************************/

  
  //Permet de centrer le nombre si le nombre de repetition est compris en 100 et 999
  /********************************************************************************/
  if(Repetitions > 99){
    dma_display->setCursor(6, 5);
    dma_display->println(Repetition);

    delay(1000);
  }
  /********************************************************************************/   
}

/**
 * permet de lancer un decmpte de 10 seconde
 */
void Affichage_Matrice::Affiche_decompte(){
  
  int sec = 10;   //definition du temp décompter

  //configuration
  dma_display->clearScreen(); 
  dma_display->setTextSize(1);     // Definition de la taille 
  dma_display->setCursor(0, 8); 

  //Affichage du texte
  dma_display->println(" Demarrage"); 
  dma_display->println("   dans : ");
  
  delay(2000);
  dma_display->clearScreen();

  /**********************************************************************************/ 
  dma_display->setTextSize(4);     // Definition de la taille 
  dma_display->setCursor(8, 2);   // Definition de la taille pour le 10
  
  dma_display->print("10");  // affichage separer de 10 car il contient deux digit
  
  delay(1000);
  sec --;
  
 
  dma_display->clearScreen();  //supprimmer toute les données de l'ecran
  /**********************************************************************************/ 

  //decompte de 9 jusqu'a 1
  /**********************************************************************************/ 
  while(sec > 0){
    
    dma_display->setCursor(22, 2);// definition de la taille pour le reste de nombre
  
    String secs = String(sec);  // Convertie les secondes int en string 
    dma_display->print(secs);  // Affiche les seconde 
    
    delay(1000);
    sec --;
    
    dma_display->clearScreen();
  }
  /**********************************************************************************/ 
}

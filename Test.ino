#include "chrono_m.h"
#include "afficheur.h"
#include <string>
#include <cstdio>
Chrono_M c;
Affichage_Matrice a;
#include <WiFi.h>

// Configurer la connexion Wi-Fi
const char* ssid = "default";
const char* password = "";
const uint16_t port = 8080;
bool sarted = false;



// Créer un objet serveur Wi-Fi
WiFiServer server(port);

void setup(){
  
  Serial.begin(115200);
  c.configuration();
  
  

  // Se connecter au Wi-Fi
  WiFi.begin(ssid, password);
 
  // Attendre que la connexion soit établie
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  // Démarrer le serveur
  server.begin();
  Serial.println("Server started");
 
}

void loop(){
  String data = "";
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");
    // Lire les données envoyées par le client
    while (client.connected()) {
      
      if (client.available()) {
        data = client.readStringUntil('\n');
        Serial.println("Received: " + data);

        //int val = data.toInt();
      }
      
      //data = "221250";
      String qui = data.substring(0,1);
      String quoi = data.substring(1,2);
      String etat = data.substring(2,3);

      int taille = data.length();
      String rep = data.substring(3,taille);
      /*
     Serial.println("first");
    Serial.println(qui);
    Serial.println("seconde");
    Serial.println(quoi);
    Serial.println("third");
    Serial.println(etat);
    Serial.println("four");
    Serial.println(rep);
    Serial.print("");
*/
    
      if(qui == "1"){
        if(etat == "1"){
          c.chronometre(qui,1);
        }
        if(etat == "0"){
          c.chronometre(qui,0);
        } 
      }

      if(qui == "2"){
        
        if(quoi == "1"){
          
          if(etat == "1"){
            c.chronometre(qui,1);
          }
          if(etat == "0"){
            c.chronometre(qui,0);
          } 
        }

        
        if(quoi == "2"){
          if(etat == "1"){
            a.Affiche_compteur(rep);
            delay(1000);
          }
          if(etat == "0"){
            a.Affiche_compteur("0");
          } 
        }
      }
      
    }   
    // Fermer la connexion avec le client
    client.stop();
    Serial.println("Client disconnected");
  }
  /*    
  server.stop();
  Serial.println("Serveur arreter");
  */
}


//trame (qui,quoi(chrono ou compteur),etat,rep(pour compteur)
/* qui
 * 1 = portable
 * 2 =  ecran oled
 */

/* quoi
 * 1 = chrono
 * 2 = compteur
 */

/* etat
 * 0 = eteint
 * 1 = allumer
 */
 
/* rep
 * nb de rep
 * ou -1 si pas besions
 */

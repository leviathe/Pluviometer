#include "rgb_lcd.h" //Déclaration de la librairie

unsigned long time = millis(); //Initialisation de la variable contenant l'horloge
static unsigned long t = 864000; //Initialisation de la variable de comparaison fixé à 1 jour
int broche_interrupteur = 2; //Initialisation de la broche de l'interrupteur
float q = 0; //Initialisation de la variable de la quantité d'eau de pluie
rgb_lcd lcd; //Appelle de la librairie

void setup() {
  pinMode(broche_interrupteur,INPUT); //Déclaration du mode de la broche de l'interrupteur
  boolean etat_interrupteur = digitalRead(broche_interrupteur); //Déclaration d'une variable booléenne par lecture de la broche de l'interrupteur
  lcd.begin(16, 2); //Utilisation d'un écran 16 colonnes et 2 lignes
  }

void loop() {
  float compteur = 0; //Initialisation de la variable du compteur
  while (time < t) { //Répétition des ordres suivants tant que time < 1 jour
    if (etat_interrupteur == HIGH){ //Condition remplie lorsque la broche reçois un signal électrique
      compteur = compteur++; //Ajout de 1 au compteur
      }
    static unsigned long x = time; //Initialisation de x et assignement de sa valeur
    t = t + x; //Ajout de x à t pour décalage de 1 jour environ
    }
  lcd.clear(); //Effacement du message précédent
  float q_pluie = 0.2794*compteur; //Calcul de la quantité de pluie
  lcd.print(q_pluie); //Affichage de la quantité de pluie
  }
  

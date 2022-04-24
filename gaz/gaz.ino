

// Definition des broches pour les
// LEDs et le Buzzer
int pin_led_rouge = 11;
int pin_led_verte = 12;
int pin_buzzer = 10;

// Definition des broches du senseur
int pin_d = 13;   // Senseur DOUT (digitale)
int pin_a = A2;  // Senseur AOUT (analogique)

int niveau_senseur = 250;
char data;
void setup()
{
  // Definir les broche du senseur comme entree
  pinMode(pin_d, INPUT);
  pinMode(pin_a, INPUT);

  // Definir le buzzer et LEDs comme sortie
  pinMode(pin_led_rouge, OUTPUT);
  pinMode(pin_led_verte, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);

  // Initialiser le port serie
  Serial.begin(9600);
}

void loop()
{
  
  // Lecture de DOUT du senseur sur l'entree digital
  int valeur_digital = digitalRead(pin_d);
  // Lecture de AOUT du senseur sur l'entree analogique
  int valeur_analogique = analogRead(pin_a);

//  Afficher les donnees sur le moniteur serie
  Serial.print("DOut : ");
  Serial.print(valeur_digital);
  Serial.print(" Aout : ");
  Serial.println(valeur_analogique);
  

  if (valeur_analogique > niveau_senseur)
  {
    // Passer en mode alarme (led rouge et buzzer)
    digitalWrite(pin_led_rouge, HIGH);
    digitalWrite(pin_led_verte, LOW);
    digitalWrite(pin_buzzer, HIGH);
    Serial.write('1');
  }
   
       data=Serial.read();
       if(data=='1')
        {
       digitalWrite(pin_led_rouge, LOW);
    digitalWrite(pin_led_verte, HIGH);
    digitalWrite(pin_buzzer, LOW);
      delay(1000);// alumer la lampe 
      Serial.write('1'); //envoyer le nouvel état de la lampe  
     }  
  

  delay(100); // petite pause
  }


const int motionPin = 9;
const int Buzzer = 10; 
int pin_led_rouge = 11;
int State = 0;
 char data;
void setup() 
{
   pinMode(pin_led_rouge, OUTPUT);
 pinMode(Buzzer, OUTPUT); 
 pinMode(motionPin, INPUT); 
 Serial.begin(9600);
}
 
void loop()
{      
 State = digitalRead(motionPin);
 if (State == HIGH) 
 { 
  Serial.write('5');
 digitalWrite(pin_led_rouge, HIGH);
 
 }
    data=Serial.read();
       if(data=='1')
        {
          
       digitalWrite(pin_led_rouge, LOW);
    digitalWrite(Buzzer, HIGH);
      delay(1000);// alumer la lampe 
      digitalWrite(Buzzer, LOW);
     }
 delay(500);
}

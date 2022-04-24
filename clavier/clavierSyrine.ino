
#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
int pin_buzzer = 10;
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'},
  };
byte rowPins[ROWS] = {8,7,6,5};
byte colPins[COLS] = {4,3,2};


Keypad kp = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
char data;
char key = ' ';
  
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  key = kp.getKey();

  if(key)
  {
    if(key == '1')
    {
     Serial.write('2');
    }
    if(key == '2')
    {
      Serial.write('3');
    }
    if(key == '3')
    {
     Serial.write('4');
    }
  }

    data = Serial.read();
     if(data =='1')
      {
     
        digitalWrite(pin_buzzer, HIGH);
        delay(1000);
        digitalWrite(pin_buzzer, LOW);
      
    }
      

  
  delay(100); // petite pause
  }

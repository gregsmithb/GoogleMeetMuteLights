#include "Keyboard.h"

//green button input
#define tripButton   3
//red button input
#define closeButton      6
//green led output
#define tripLight   5
//red led output
#define closeLight      4
char ctrlKey = KEY_LEFT_CTRL;
char shiftKey = KEY_LEFT_SHIFT;

//checking if button is held down
bool holdingButton = false;

void setup()
{
  pinMode(tripButton, INPUT_PULLUP);
  pinMode(closeButton, INPUT_PULLUP);
  pinMode(tripLight, OUTPUT);
  pinMode(closeLight, OUTPUT);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(tripButton) == HIGH && digitalRead(closeButton) == HIGH ){
    holdingButton = false;
  }
  if (digitalRead(tripButton) == LOW) {   
    delay(100);
    if (holdingButton == false)
    {
    Serial.println("Trip");
    Keyboard.press(ctrlKey);
    Keyboard.press('d');
    delay(100);
    Keyboard.releaseAll();
    digitalWrite(closeLight, LOW);
    digitalWrite(tripLight, HIGH);
    holdingButton = true;
    }
    
    delay(100);       
  }
  if (digitalRead(closeButton) == LOW) {
    delay(100);
    if (holdingButton==false)
    {
    Serial.println("Close");
    Keyboard.press(ctrlKey);
    Keyboard.press('d');
    delay(100);
    Keyboard.releaseAll();
    digitalWrite(tripLight, LOW);
    digitalWrite(closeLight, HIGH);
    holdingButton = true;
    }
    
    delay(100);   
  }
}

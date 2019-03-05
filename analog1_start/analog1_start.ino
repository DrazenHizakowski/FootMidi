#include <MIDI.h>

const int a1 = A0;
const int a2 = A1;
const int a3 = A2;
const int a4 = A3;

MIDI_CREATE_DEFAULT_INSTANCE();


unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long t3 = 0;
unsigned long t4 = 0;

boolean last1 = false;
boolean last2 = false;
boolean last3 = false;
boolean last4 = false;

unsigned long threshold = 1000;
unsigned long gate = 500;

void setup() {

  MIDI.begin(4);                      // Launch MIDI and listen to channel 4
}

void loop() {
  // read the analog in value:
  int r1 = analogRead(a1);
  int r2 = analogRead(a2);
  int r3 = analogRead(a3);
  int r4 = analogRead(a4);
  //outputValue = map(sensorValue, 0, 1023, 0, 255);

  if(r1>gate && (t1+threshold)<millis() && last1 == false){
   // MIDI.sendNoteOn(42, 127, 1);
    t1 = millis();
    last1 = true;
  }

  
  if(r2>gate && (t2+threshold)<millis() && last2 == false){
   //MIDI.sendNoteOn(50, 127, 3);
    t2 = millis();
    last2= true;
  }
  if(r3>gate && (t2+threshold)<millis() && last3 == false){
   // MIDI.sendNoteOn(60, 127, 2);
    t3 = millis();
    last3 = true;
  }
  if(r4>gate && (t2+threshold)<millis() && last4 == false){
  //  MIDI.sendNoteOn(70, 127, 4);
    t4 = millis();
    last4 = true;
  }
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:

  
  Serial.print(r1);
  Serial.print("    ");
  Serial.print(r2);
  Serial.print("    ");
  Serial.print(r3);
  Serial.print("    ");
  Serial.print(r4);
  Serial.print("\n");
  
  if(r1<700){
    last1 = false;
    }
    
  if(r2<700){
    last2 = false;
    }
    
  if(r3<700){
    last3 = false;
  }
    
  if(r4<700){
    last4 = false;
  }
  delay(300);
}

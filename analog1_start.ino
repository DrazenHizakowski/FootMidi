#include <MIDI.h>

/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int a1 = A0;
const int a2 = A1;
const int a3 = A2;
const int a4 = A3;

MIDI_CREATE_DEFAULT_INSTANCE();


unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long t3 = 0;
unsigned long t4 = 0;
unsigned long threshold = 1000;
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

  if(r1>700 && (t1+threshold)<millis()){
    MIDI.sendNoteOn(42, 127, 1);
    t1 = millis();
  }
  if(r2>700 && (t2+threshold)<millis()){
    MIDI.sendNoteOn(50, 127, 1);
    t2 = millis();
  }
  if(r3>700 && (t2+threshold)<millis()){
    MIDI.sendNoteOn(60, 127, 1);
    t3 = millis();
  }
  if(r4>700 && (t2+threshold)<millis()){
    t4 = millis();
    MIDI.sendNoteOn(70, 127, 1);
  }
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(100);
}

#include <SPI.h>
#include "RF24.h"
#include <Servo.h>

Servo myservo;
RF24 radio(9,10);
const uint64_t pipe=0xE8E8F0F0E1LL;
int msg[2];

void setup() {
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();

}

void loop() {
  if(radio.available()){
    myservo.attach(A3);
    bool done = false;
    while(!done)
    {
      done = radio.read(msg,1);
      myservo.write(msg[0]);
    }
  }
  myservo.detach();
}

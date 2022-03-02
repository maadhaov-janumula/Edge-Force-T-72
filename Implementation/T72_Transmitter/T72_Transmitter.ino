#include <SPI.h>
#include "RF24.h"
#include <nRF24L01.h>
#define POTPIN A3

int msg[2];
RF24 radio(9,10);
const uint64_t pipe=0xE8E8F0F0E1LL;
int val;

void setup() {
radio.begin();
radio.openWritingPipe(pipe);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();

pinMode(POTPIN, INPUT);
}

void loop() {
val=analogRead(POTPIN);
val=map(val,0,1023,0,360);
msg[0]=val;
radio.write(msg,sizeof(msg));
}

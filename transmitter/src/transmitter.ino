#include <VirtualWire.h>

#define BUTTONS     8

int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
    delay(1000);
    Serial.begin(9600);

    for(unsigned int i = 0; i < BUTTONS; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    vw_set_ptt_inverted(true);
    vw_setup(2000);
    Serial.println("setup");
}

void loop() {
    
    int message = 0;

    for(unsigned int i = 0; i < BUTTONS; i++) {
        if(digitalRead(buttonPins[i]) == LOW) {
            message |= (int)1 << i;
        }
    }

    digitalWrite(13, true);
    vw_send((uint8_t *) &message, 2);
    vw_wait_tx();
    digitalWrite(13, false);

    Serial.println(message, BIN);
    
    delay(50);
}
           
   
   
     
 

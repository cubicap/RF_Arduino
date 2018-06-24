#include <VirtualWire.h>

#define RELAYS     8

int relayPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
    delay(1000);
    Serial.begin(9600);

    for(unsigned int i = 0; i < RELAYS; i++) {
        pinMode(relayPins[i], OUTPUT);
    }

    vw_set_ptt_inverted(true);
    vw_setup(2000);

    vw_rx_start();
    Serial.println("setup");
}

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;


    if (vw_get_message(buf, &buflen)) {
	    int i;

        digitalWrite(13, true);
	    Serial.print("Got: ");
	
	    for (i = 0; i < buflen; i++) {
	        Serial.print(buf[i], BIN);
	        Serial.print(" ");
	    }
	    Serial.println("");

        digitalWrite(13, false);

        int message = (int)buf[0] | ((int)buf[1] << 8);

        Serial.println(message, BIN);

        for(unsigned int i = 0; i < RELAYS; i++) {
            if((message & ((int)1 << i))) {
                digitalWrite(relayPins[i], HIGH);
            }
            else {
                digitalWrite(relayPins[i], LOW);

            }
        }
    }
}

/*
 * Android to Arduino
 * by moty22.co.uk
 * 26/4/20
 *  
*/

unsigned char inByte=0, outByte;         //

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    // initialize outputs 8-11 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  //for switches pullup inputs
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  
        delay(500);
        Serial.write(127);             
        Serial.write((unsigned char)digitalRead(2));
        Serial.write((unsigned char)digitalRead(3));
        Serial.write((unsigned char)digitalRead(4));
        Serial.write((unsigned char)digitalRead(5));
        
        Serial.write(lowByte(analogRead(A0)));  //send low byte of 10 bits analogue read
        Serial.write(highByte(analogRead(A0))); //send high byte of 10 bits analogue read
        Serial.write(lowByte(analogRead(A1)));
        Serial.write(highByte(analogRead(A1)));

        delay(500);
           
        if (Serial.available() > 0) {
            // read the incoming byte:
          inByte = Serial.read();
          PORTB = inByte; //update digital outputs 8-11

       }
     
      
}



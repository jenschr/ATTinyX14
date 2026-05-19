/*
 * Basic test-sketch for button and LED on x14 devboard
 */


#define PA4 0  // SS/A4/Button
#define PA5 1  // A5/LED
#define PA6 2  // A6/DAC
#define PA7 3  // A7
#define PB3 4  // RX
#define PB2 5  // TX
#define PB1 6  // SDA/A10
#define PB0 7  // SCL/A11
#define PA1 8  // MOSI/TX1/A1
#define PA2 9  // MISO/RX1/A2
#define PA3 10 // SCK/A3
#define PA0 11 // UPDI programming

int count = 0;
bool wasButtonPressed = false;

void setup() {
  Serial.begin(9600);
  delay(4000);
  Serial.println("test");
  pinMode(PA5, OUTPUT);       // LED
  pinMode(PA4, INPUT_PULLUP); // Button
}

void loop() {
  // If button is pressed, keep LED turned on
  bool isButtonPressed = !digitalRead(PA4);
  if( isButtonPressed != wasButtonPressed ){
    Serial.println( isButtonPressed );
    digitalWrite( PA5, isButtonPressed );
    delay(100);// simple debounce
  }
  wasButtonPressed = isButtonPressed;

  // Toggle LED every 10000 loops
  if( !isButtonPressed && count % 10000 == 0 ){
    digitalWrite( PA5, !digitalRead(PA5) );
  } else if( isButtonPressed ){
    analogWrite( PA5, (count % 255) );
    delay(3);
  }
  count++;
}

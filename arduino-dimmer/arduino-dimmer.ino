// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 0;     // the number of the pushbutton pin
const int ledPin = 1;      // the number of the LED pin
// variables will change:
int brightness = 0;
bool increasing = false;
void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  analogWrite(ledPin, brightness);
}
void loop() {
  // Button pressed is LOW - Digispark connected to PC via USB
  // Button pressed is LOW - Digispark connected with 5V 
  if (digitalRead(buttonPin) ==  LOW) {
    if(increasing){
      brightness += 51;
      if(brightness == 255){
        increasing = false;
      }
    }
    else{
      if(brightness == 0){
        brightness = 255;
      }
      else{
        brightness -= 51;
        if(brightness == 0) increasing = true;
      }
      
    }
    analogWrite(ledPin, brightness);
  }

  // Added the delay so that we can see the output of button
  delay(200);
}

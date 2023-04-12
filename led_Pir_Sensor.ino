const int pirPin = D1;    // PIR motion sensor pin
const int ledPin = D2;    // LED pin
int motionDetected = 0;   // variable to store motion status

void setup() {
  pinMode(pirPin, INPUT);  // set PIR pin as input
  pinMode(ledPin, OUTPUT); // set LED pin as output
  Serial.begin(9600);      // initialize serial communication
}

void loop() {
  motionDetected = digitalRead(pirPin);  // read PIR sensor
  
  // get current time
  time_t now = time(nullptr);
  struct tm * timeinfo = localtime(&now);
  
  // check if it's between midnight and 6am
  if (timeinfo->tm_hour >= 0 && timeinfo->tm_hour < 6) {
    if (motionDetected == HIGH) {          // if motion detected
      Serial.println("Motion detected!"); // print message to serial monitor
      digitalWrite(ledPin, HIGH);          // turn on LED
      delay(1000);                         // wait for 1 second
    }
    else {
      digitalWrite(ledPin, LOW);           // turn off LED
    }
  }
  else {
    digitalWrite(ledPin, LOW);  // turn off LED
  }
}

String incomingMessage = "";

const long interval = 1000;
unsigned long previousMillis = 0;

// Temp sensor pin
// NOTE: board im using is labeld wrong + & - are swapped.
int tempPin = A1;
int soundPin = A5;
int volt;
int boardResistor = 10000;
float logR2, r2, t;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; //steinhart-hart coeficients for thermistor

int ledPin = 13;
int vibPin = 3;
int vibCount = 0;
int vibVal;

float threshold = 2.57;

void setup(void) {
  // start serial port
  Serial.begin(115200);
  Serial.println("Running");

  pinMode(ledPin, OUTPUT);
  pinMode(vibPin, INPUT);

}

void loop(void) {
  unsigned long currentMillis = millis();

  while (Serial.available() > 0) {
    handleIncomingMessage();
  }

  if(currentMillis - previousMillis >= interval ){
    previousMillis = currentMillis;
    volt = analogRead(tempPin);
    r2 = boardResistor * (1023.0 / (float)volt - 1.0);
    logR2 = log(r2);
    t = (1.0 / (c1 + c2*logR2 + c3 *logR2*logR2*logR2));
    t = t - 273.15;
    Serial.println("temp:" + String(t));
    Serial.println("vibrations:" + String(vibCount));
    vibCount = 0;
  }
 
  if(checkSound()) {
    vibCount ++;
  }

}

void handleIncomingMessage(){
  incomingMessage = Serial.readString();
  Serial.println("Unknown input" + String(incomingMessage));
}

boolean checkSound(){
    int aValue = 0;                             // raw analog value
    float volts;                                // analog voltage value                    
    aValue = analogRead(soundPin);             // analog values from 0-1023, 5V max
    volts = (aValue*5.0)/1024.0;
    
    if (volts > threshold){
      //Serial.print(" volts = ");Serial.println(volts);
      return true;
    }
    return false;

  }




int relayPinRed = 9;
int relayPinBlue= 10;
int relayPinGreen = 11;
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8 
int red = 0;
int green = 0;
int blue = 0; 

void setup() 
{  
  pinMode(relayPinRed, OUTPUT);
  pinMode(relayPinGreen, OUTPUT);
  pinMode(relayPinBlue, OUTPUT);
//pins for TCS3200
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);  
//setting relays to off
  digitalWrite(relayPinRed, HIGH);
  digitalWrite(relayPinGreen, HIGH);
  digitalWrite(relayPinBlue, HIGH);

//setting frequency scaling to 20%
  digitalWrite(S0, HIGH);  
  digitalWrite(S1, LOW);
}

void loop(){
   color();

   if (red < blue && blue < green && red < green && red <= 39){ //for red
      digitalWrite(relayPinRed, LOW);
        delay(5000);
      digitalWrite(relayPinRed, HIGH);
   }
   else if (green < red && blue < green && blue < red) { //for BLUE
      digitalWrite(relayPinBlue, LOW);
        delay(5000);
      digitalWrite(relayPinBlue, HIGH);
   }
   else if (blue < red && green < blue && green < red) { //for green
      digitalWrite(relayPinGreen, LOW);
        delay(5000);
      digitalWrite(relayPinGreen, HIGH);
   }
}

void color() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  delay(100);
}


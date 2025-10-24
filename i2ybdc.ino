//Arduino Nano
//icom band decoder
//Marios Nicolaou 5B4WN (c) 2009 7 24
//Gil Lianni 4Z1KD 2025 10 24
//Use the code at your OWN risk
//GPL licence

int icomBandPin = A5;    // select the input pin for the potentiometer
int realVoltage = 8;  // variable to store the value coming from the sensor Volts
int sensedVoltage=0;
int A=9;
int B=10;
int C=11;
int D=12;
float calculatedVoltage=0;
int band=0;
int counter =0;
int previousValue=0;
 void setup() {
   Serial.begin(9600);
   pinMode(icomBandPin, INPUT);
   pinMode(A, OUTPUT);
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
 }
 void loop() {
   // read the value from the sensor:
   float sensedVoltage = analogRead(icomBandPin);   
   float calculatedVoltage = float(sensedVoltage)*5/1024;
   
   Serial.print (sensedVoltage);
   Serial.print (" - ");
   Serial.print (calculatedVoltage);
   Serial.print (" - ");
   band=getBand(calculatedVoltage);
   
   Serial.println(band, DEC);
   delay (20);
}
 
int  getBand(float voltage) {
   int band=0;

/* Logic Letter (Amplifier Pin#)
/*       A(2)   B(1)    C(9)   D(8)
160      0       0       0      1
80       0       0       1      0
40       0       0       1      1
30       0       1       0      0
20       0       1       0      1
17       0       1       1      1
15       0       1       1      1
12       1       0       0      1
10       1       0       0      1
6        1       0       1      0
*/
 

if (voltage>4.20 && voltage<4.9) {
 band=160;
 digitalWrite(A, LOW);
 digitalWrite(B, LOW);
 digitalWrite(C, LOW);
 digitalWrite(D, HIGH);
 
} else if (voltage>3.50 && voltage<4.20) {
 band=80;
 digitalWrite(A, LOW);
 digitalWrite(B, LOW);
 digitalWrite(C, HIGH);
 digitalWrite(D, LOW);
} else if (voltage>=2.95 && voltage<3.50) {
  band=40;
 digitalWrite(A, LOW);
 digitalWrite(B, LOW);
 digitalWrite(C, HIGH);
 digitalWrite(D, HIGH);
} else if(voltage>=2.30 && voltage<2.95) {
  band=20;
 digitalWrite(A, LOW);
 digitalWrite(B, HIGH);
 digitalWrite(C, LOW);
 digitalWrite(D, HIGH);
 
} else if (voltage>=1.70 && voltage<2.30) {
  band=15;
 digitalWrite(A, LOW);
 digitalWrite(B, HIGH);
 digitalWrite(C, HIGH);
 digitalWrite(D, HIGH);
 
} else if (voltage>=1.3 && voltage<1.7) {
  band=10;
 digitalWrite(A, HIGH);
 digitalWrite(B, LOW);
 digitalWrite(C, LOW);
 digitalWrite(D, HIGH);
 
} else if (voltage>=0.75 && voltage<1.3) {
  band=6;
 digitalWrite(A, HIGH);
 digitalWrite(B, LOW);
 digitalWrite(C, HIGH);
 digitalWrite(D, LOW);
} else if (voltage  <0.75) {
  band=30;
   digitalWrite(A, LOW);
 digitalWrite(B, HIGH);
 digitalWrite(C, LOW);
 digitalWrite(D, LOW);
}

 return band;
 
}

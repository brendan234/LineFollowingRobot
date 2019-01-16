/////////////////////////Right motor
const int RFpin = 5; //A-A forward  
const int RRpin = 6; //A-B reverse
int rightBrake;
///////////////////////////////////

/////////////////////////Left motor
const int LFpin = 9; //B-A forward
const int LRpin = 3; //B-B reverse
int leftBrake;
////////////////////////  ifrared sensors
const int LiPin = 12;//left
const int RiPin = 11;right
///////////////////// sensor values
int Li;
int Ri;
/////////////////////
int throttle = 150;



void setup() {
  //////////////////////////////////
  pinMode(RFpin, OUTPUT);
  pinMode(RRpin, OUTPUT);
  pinMode(LFpin, OUTPUT);
  pinMode(LRpin, OUTPUT);
  ////////////////////////////////////////////
  pinMode(LiPin, INPUT);
  pinMode(RiPin, INPUT);
  Serial.begin(115200);

}

void loop() {
  stop();
  delay(120);
  IR();
  if (Li == 0 && Ri == 0) {

    straight();
  }
  if (Li == 0 && Ri == 1)
  {
    right();

  }
  if (Ri == 0 && Li == 1)
  {

    left();
  }
  if (Ri == 1 && Li == 1)
  {
    stop();

  }
}
//////////////////////functions
void IR() {

  Li = digitalRead(LiPin);
  Ri = digitalRead(RiPin);
  Serial.print("Li: ");
  Serial.println(Li);
  Serial.print("Ri: ");
  Serial.print(Ri);


}
void straight() {
  Serial.println("straight");
  analogWrite(LRpin, 0);
  analogWrite(RRpin, 0);
  analogWrite(RFpin, throttle);
  analogWrite(LFpin, throttle);
  delay(40);
}

void right() {
  Serial.println("right");
  analogWrite(LRpin, 0);
  analogWrite(RRpin, throttle);
  analogWrite(RFpin, 0);
  analogWrite(LFpin, throttle);
  delay(40);
}
void left() {
  Serial.println("left");
  analogWrite(LRpin, throttle);
  analogWrite(RRpin, 0);
  analogWrite(RFpin, throttle);
  analogWrite(LFpin, 0);
  delay(40);
}
void stop() {
  Serial.println("stop");
  analogWrite(LRpin, 0);
  analogWrite(RRpin, 0);
  analogWrite(RFpin, 0);
  analogWrite(LFpin, 0);
}

#include "pitches.h" 
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

  //Defining which ports to be used
  const int speakerPin = 11;  // PWM PORT FOR SPEAKER
  const int ledPin1 = 7;    //Normal I/O PORT
  const int ledPin2 = 8;    //Normal I/O Port
  const int motor1Pin = 4;    // H-bridge leg 1 (pin 2, 1A)
  const int motor2Pin = 3;    // H-bridge leg 2 (pin 7, 2A)
  const int motor3Pin = 5;    // H-bridge leg 3 (pin 10, 3A)
  const int motor4Pin = 6;    // H-bridge leg 4 (pin 15, 4A)
  const int enablePin1 = 9;    // H-bridge enable pin1
  const int buttonpin = 10;   // H-bridge enable pin2
  const int analogsensor = A0;
  
char incomingByte;  //reads the bytes that are accosiated with specific keyboard keys
int speedvalue=255; //INITIAL SPEED VALUE
int *speedpointer=&speedvalue; // Pointer pointing to speedvalue's address
int musicvalue;// intializing random music track
int buttonState =0;
float volts=0;
float distance=0;
void setup() {
  digitalWrite(ledPin1,HIGH);
digitalWrite(ledPin2,HIGH);
  
    // Setting up pins for perpherials
    pinMode(speakerPin, OUTPUT); 
    pinMode(ledPin1, OUTPUT); 
    pinMode(ledPin2, OUTPUT); 
 Serial.begin(9600);
    attachInterrupt(0,brake,RISING);  
    // setting pins for H bridge DC motor Control
    pinMode(motor1Pin, OUTPUT); 
    pinMode(motor2Pin, OUTPUT);  
    pinMode(motor3Pin, OUTPUT); 
    pinMode(motor4Pin, OUTPUT); 
    pinMode(enablePin1, OUTPUT);
    pinMode(buttonpin, INPUT);
    
    
   myservo.attach(10);  // attaches the servo on pin 10 to the servo object 
    // Starting serial communications at the set bit rat
    
    //start the H bridge by writing it in high mode.
    digitalWrite(enablePin1, HIGH); 
    randommusic();
  }

  
void loop() {

servo2();

}


  
void music_win(){ // PLAYS MARIO VICTORY SONG
int melody[] = {NOTE_D3,NOTE_C4,NOTE_E4,
NOTE_G4,NOTE_C5,NOTE_E5,NOTE_G5,
NOTE_E5,NOTE_GS3,NOTE_CS4,NOTE_F4,NOTE_GS4,NOTE_CS5,
NOTE_F5,NOTE_GS5,NOTE_F5,NOTE_AS3,
NOTE_DS4,NOTE_G4,NOTE_AS4,NOTE_DS5,NOTE_G5,NOTE_AS5,
NOTE_AS5,NOTE_AS5,NOTE_AS5,NOTE_C6};


int noteDurations[]={118,118,118,118,118,118,325,
325,118,118,118,118,118,118,325,325,118,
118,118,118,118,118,325,118,118,118,1300};


 for (int thisNote = 0; thisNote < 27; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
}
}

void music_looney(){ // PLAYS looney tunes song

int melody[] = { 1047,1397,1319,1175,1047,880,1047,1397,1319,1175,1245,1319,
1319,1319,1047,1175,1047,1319,1047,1175,880,1047,784,932,880,698};




int noteDurations[]={428,214,214,214,214,642,214,214,214,214,
214,642,214,214,214,214,
214,214,214,214,214,214,214,214,214,214};


 for (int thisNote = 0; thisNote < 26; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.1;
    delay(pauseBetweenNotes);
}
}
void music_doom(){ // PLAYS doom level 1

int melody[] = {330,330,659,330,330,587,330,330,523,330,
330,466,330,330,494,523,330,330,659,330,330,587,
330,330,523,330,330,466,330,330,659,330,330,587,
330,330,523,330,330,466,330,330,494,523,330,330,
659,330,330,587,330,330,523,330,330,466,440,440,
880,440,440,784,440,440,698,440,440,622,440,440,
659,698,440,440,880,440,440,784,440,440,698,440,440,622
};




int noteDurations[]={133,133,133,133,133,133,133,133,133,
133,133,133,133,133,133,133,133,133,133,133,133,133,
133,133,133,133,133,802,133,133,133,133,133,133,133,
133,133,133,133,133,133,133,133,133,133,133,133,133,
133,133,133,133,133,133,133,802,133,133,133,133,133,
133,133,133,133,133,133,133,133,133,133,133,133,133,
133,133,133,133,133,133,133,133,133,535};


 for (int thisNote = 0; thisNote < 84; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.15;
    delay(pauseBetweenNotes);
}
}

void music_lotr(){ // PLAYS lotr song

int melody[] = {880,784,784,784,880,1175,1319,1397,1319,1175,1047,1175,
1319,1175,1047,988,880,784,784,784,880,1175,1319,1397,1319,1175,1047,1175,1319,
1319,1319};

int noteDurations[]={750,750,187,187,1500,187,187,750,187,187,750,
187,187,1125,750,375,750,750,187,187,1500,187,187,750,
187,187,750,375,1125,1125,375};


 for (int thisNote = 0; thisNote < 31; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
}
}
void music_dk(){ // PLAYS donkey kong country theme

int noteDurations[] = {240,240,720,240,240,
240,720,240,240,720,240,240,240,720,
240,240,720,240,240,240,720,240,240,
480,480,240,240,240,720};

int melody[]={523,523,880,698,784,698,587,587,
587,932,784,880,784,659,659,659,1047,880,932,1047,
1175,698,784,880,698,659,698,784,587};

 for (int thisNote = 0; thisNote < 29; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    if(thisNote==3)
    delay(428);
    if(thisNote==7)
    delay(428);
    if(thisNote==10)
    delay(428);
    if(thisNote==14)
    delay(428);
     if(thisNote==17)
    delay(428);
    if(thisNote==21)
    delay(428);
   
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
}
}
void music_xmen(){ // PLAYS xmen show them

int noteDurations[] = {107,107,107,107,428,214,214,107,107,107,107,428,214,214,107,107,107,107,428,214,214,214,
214,107,107,107,107,428,214,214,107,107,107,107,428,214,214,107,107,107,107,428,214,214,214,214};

int melody[]={740,  784,  988,  1175,  1109,  988,  740,  740, 
784,  988,  1175,  1109,  988,  784,  740,  784,  988, 
1175,  1109,  988,  1175,  1109,  988,  988,  1319,  1480,  1568,  1480,  1319,  988, 
988,  1319,  1480,  1568,  1480,  1319,  1047,  740,  784,  988 , 1175 , 1109 , 988 , 1175,  1109, 988};




 for (int thisNote = 0; thisNote < 46; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    if(thisNote==7)
    delay(428);
    if(thisNote==14)
    delay(428);
    if(thisNote==21)
    delay(856);
    if(thisNote==23)
    delay(856);
     if(thisNote==30)
    delay(428);
    if(thisNote==37)
    delay(428);
    if(thisNote==44)
    delay(428);

    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration;
    delay(pauseBetweenNotes);
}
}
void music_ateam(){ // PLAYS the a team theme

int melody[] = {1245,932,1245,831,932,622,784,932,1245,
932,1397,1245,1109,1047,932,831,932};


int noteDurations[]={480,240,960,240,480,720,120,120,240,240,240,960,360,120,120,360,960};


 for (int thisNote = 0; thisNote < 17; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.1;
    delay(pauseBetweenNotes);
}
}

void music_gadget(){ // PLAYS inspector gadget theme

int melody[] = {622,698,740,831,932,740,880,698,831,740,622,698,740,831,932,1245,1175,622,698,
740,831,932,740,880,698,831,740,622};


int noteDurations[]={150,150,150,150,300,300,300,300,300,300,150,150,150,150,
300,300,1200,150,150,150,150,300,300,300,300,300,300,600};


 for (int thisNote = 0; thisNote < 28; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration*1.1;
    delay(pauseBetweenNotes);
}
}

void music_mario(){ // PLAYS MARIO WORLD THEME
int melody[] = {NOTE_A4,NOTE_F4,NOTE_C4,NOTE_D4,NOTE_F4,NOTE_F4,
NOTE_D4,NOTE_C4,NOTE_F4,NOTE_F4,NOTE_C5,NOTE_A4,
NOTE_G4,NOTE_C4,NOTE_A4,NOTE_F4,NOTE_C4,NOTE_D4,NOTE_F4,NOTE_F4,
NOTE_D4,NOTE_C4,NOTE_D4,NOTE_AS4,NOTE_A4,NOTE_G4,NOTE_F4};   

int noteDurations[]={325,243,81,81,162,325,81,162,162,162,162,243,
325,81,
325,243,81,81,162,325,81,162,162,81,81,81,730};


 for (int thisNote = 0; thisNote < 27; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
}
}


void music_lose(){ // PLAYS MARIO LOST SONG
int melody[] = {NOTE_C5,NOTE_G4,NOTE_E4,
NOTE_A4,NOTE_B4,NOTE_A4,NOTE_GS4,
NOTE_AS4,NOTE_GS4,NOTE_G4};


int noteDurations[]={250,250,500,182,182,182,182,182,182,1000};
  

 for (int thisNote = 0; thisNote < 10; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
}
}
    
  
  void movefrontright(){ // moves right
    
      digitalWrite(motor1Pin, LOW);   
      digitalWrite(motor2Pin, HIGH);
      digitalWrite(motor3Pin, HIGH);   
      digitalWrite(motor4Pin, LOW);    
     
  }
  
  void movefrontleft(){  // moves left
      digitalWrite(motor1Pin, HIGH);   
      digitalWrite(motor2Pin, LOW);
      digitalWrite(motor3Pin, LOW);   
      digitalWrite(motor4Pin, HIGH);  

    
  }
  
  void moveforward(){ // moves straight
     digitalWrite(motor1Pin, HIGH);   
      digitalWrite(motor2Pin, LOW);
      digitalWrite(motor3Pin, HIGH);   
      digitalWrite(motor4Pin, LOW);  

       
    
  }
  
  void movebackward(){  // moves reverse
     digitalWrite(motor1Pin, LOW);   
      digitalWrite(motor2Pin, HIGH);
      digitalWrite(motor3Pin, LOW);   
      digitalWrite(motor4Pin, HIGH);  

  }
  
    
  void movebackright(){ // goes in reverse right
    
      digitalWrite(motor1Pin, HIGH);   
      digitalWrite(motor2Pin, LOW);
      digitalWrite(motor3Pin, LOW);   
      digitalWrite(motor4Pin, HIGH); 
   
  }
  
  void movebackleft(){ // goes in reverse left
      digitalWrite(motor1Pin, LOW);   
      digitalWrite(motor2Pin, HIGH);
      digitalWrite(motor3Pin, HIGH);   
      digitalWrite(motor4Pin, LOW);  

  }
  
  void brake(){ // stops the motors
     digitalWrite(motor1Pin, LOW);   
      digitalWrite(motor2Pin, LOW);
      digitalWrite(motor3Pin, LOW);   
      digitalWrite(motor4Pin, LOW);  
  }

void radio_communication(){  // START COMMUNICATIONS

//Default: no buttons pressed robot doesn't move
brake();
if (Serial.available() >= 0) {  // If any data is comming in read it.

incomingByte = Serial.read();  //Incomming data is recieved as characters from a keyboard
randomSeed(analogRead(enablePin1));// setup a random seed so it randomizes music better

// w - go forward
if (incomingByte == 'w'){
moveforward();
delay(1000);
}
// a - go left
else if (incomingByte == 'a'){
movefrontleft();
delay(1000);
}
//d - go right
else if (incomingByte == 'd'){
movefrontright();
delay(1000);
}
// go reverse s
else if (incomingByte == 's'){
movebackward();
delay(1000);
}
//press q to play a random track via pwm and functions
else if (incomingByte == 'q')
{
 musicvalue=random(11);
  if(musicvalue==0)
  {
  music_win();
  }
  
  else if(musicvalue==1)
  {
  music_mario();
 
  }
  else if(musicvalue==2){
  music_lose();

  }
   else if(musicvalue==3){
  music_looney();
  
   }
  else if(musicvalue==4){
  music_gadget();
 
  }
  else if(musicvalue==5){
  music_ateam();

  }
  else if(musicvalue==6){
  music_doom();
  
  }
  else if(musicvalue==7){
  music_lotr();
 
  }
  else if(musicvalue==8){
  music_xmen();
  
  }
  else if(musicvalue==9){
  music_dk();
 
  }
  
}
//press e  to blink the led
else if (incomingByte == 'e')
{

}
else if (incomingByte == 't')// t button to increase speed
{
speed(increase_speed(speedpointer));
}
else if (incomingByte == 'r')// r button to decrease speed
{
speed(decrease_speed(speedpointer));
}
// if no buttons are pressed stop both motors,  THis else will never be invoked

}
}



void speed(int control_speed)// control_speed is a value from 0-255
{
  //write the value to the enable line on the Half Bridge
  analogWrite(enablePin1,control_speed);
}

int increase_speed(int *increasepointer)
{
  speedvalue+=5;  //Increase the speed
  if(*(increasepointer)>250){  // check the pointer value what its pointing too
  speedvalue=250;
  }
  return *increasepointer;
}
int decrease_speed(int *decreasepointer)
{
  speedvalue-=5;//deincrement the speed
  if(*(decreasepointer)<0){
  speedvalue=0;
  }
  return *decreasepointer;
}

void randommusic()
{
  randomSeed(analogRead(A0));
 musicvalue=random(11);
  if(musicvalue==0)
  {
  music_win();
  }
  
  else if(musicvalue==1)
  {
  music_mario();
 
  }
  else if(musicvalue==2){
  music_lose();

  }
   else if(musicvalue==3){
  music_looney();
  
   }
  else if(musicvalue==4){
  music_gadget();
 
  }
  else if(musicvalue==5){
  music_ateam();

  }
  else if(musicvalue==6){
  music_doom();
  
  }
  else if(musicvalue==7){
  music_lotr();
 
  }
  else if(musicvalue==8){
  music_xmen();
  
  }
  else if(musicvalue==9){
  music_dk();
 
  }
}


    // waits 15ms for the servo to reach the position 

void servo2()
{ 
  speed(255);
  moveforward();
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  { 
    speed(255);
volts = analogRead(analogsensor)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
distance = 65*pow(volts, -1.10); 
Serial.println(distance);// in                                  // in steps of 1 degree 
myservo.write(pos);
delay(25);// tell servo to go to position in variable 'pos'     delay(50);  
if(distance<=30){
movebackward();
delay(1500);
movefrontleft();
delay(2000);
moveforward();
}



  }

  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {      
      speed(255);
 volts = analogRead(analogsensor)*0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3
distance = 65*pow(volts, -1.10); 
 myservo.write(pos);              // tell servo to go to position in variable 'pos' 
delay(25);
if(distance<30){
movebackward();
delay(1500);
movebackright();
delay(2000);
moveforward();
 // waits 15ms for the servo to reach the position 
  }

} 

// waits 15ms for the servo to reach the position 
  } 

  
  



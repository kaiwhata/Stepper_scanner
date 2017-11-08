
//Version: 0.3
//Code Author: Arthur Roberts and Elf Eldridge
//Email: arthur.roberts@ecs.vuw.ac.nz, kaiwhata@gmail.com
//Licence: TBC
 
//Motor control variables
//PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_a = 3; 
//PWM control for motor outputs 3 and 4 is on digital pin 11
int pwm_b = 11; 
//direction control for motor outputs 1 and 2 is on digital pin 12
int dir_a = 12; 
//direction control for motor outputs 3 and 4 is on digital pin 13
int dir_b = 13; 
 
//time step, this is the value for the size of the step, if I increase V the steps will become bigger!
int dt = 400; //default 380
int v = 220;
 
//Control methods
 
//steps 4 times for each n
void step_forward(int n, int dt)
{
  int i = 0;
  while (i < n){
    analogWrite(pwm_a, 0); 
    analogWrite(pwm_b, 0);
    digitalWrite(dir_a,HIGH);
    digitalWrite(dir_b,LOW);
    analogWrite(pwm_a, v); 
    analogWrite(pwm_b, v);
    delay(dt);
    i++;
    if (i>n-1){break;}
 
    analogWrite(pwm_a, 0); 
    analogWrite(pwm_b, 0);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    analogWrite(pwm_a, v); 
    analogWrite(pwm_b, v);
    delay(dt);
    i++;
    if (i>n-1){break;}
 
    analogWrite(pwm_a, 0); 
    analogWrite(pwm_b, 0);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,HIGH);
    analogWrite(pwm_a, v); 
    analogWrite(pwm_b, v);
    delay(dt);
    i++;
    if (i>n-1){break;}
 
    analogWrite(pwm_a, 0); 
    analogWrite(pwm_b, 0);
    digitalWrite(dir_a,HIGH);
    digitalWrite(dir_b,HIGH);
    analogWrite(pwm_a, v); 
    analogWrite(pwm_b, v);
    delay(dt);
    i++;}
}
 
void step_backward(int n, int dt)
{
  int i = 0;
  while (i < n){
  analogWrite(pwm_a, 0); 
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v); 
  analogWrite(pwm_b, v);
  delay(dt);
  i++;
  if (i>n){break;}
 
  analogWrite(pwm_a, 0); 
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v); 
  analogWrite(pwm_b, v);
  delay(dt);
  i++;
  if (i>n){break;}
 
  analogWrite(pwm_a, 0); 
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v); 
  analogWrite(pwm_b, v);
  delay(dt);
  i++;
  if (i>n){break;}
  analogWrite(pwm_a, 0); 
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v); 
  analogWrite(pwm_b, v);
  delay(dt);
  i++;
  }
}
 
 
//main code
void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v); 
  analogWrite(pwm_b, v);
  Serial.begin(9600);
}
 
void loop()
{
  //First value is the number of steps, second value is the time spent at each steps
   delay(1000); //wait time before rotation
   int j = 0;
   while(true){
    if (j<1){ //ensures only turns once - could put serial commands in for repeat.
      step_forward(193, 10);   //full circle countercloickwize
      delay(1000);
      //turns off stepper after move to get rid of irritating noise
      analogWrite(pwm_a, 0); 
      analogWrite(pwm_b, 0);
      digitalWrite(dir_a,LOW);
      digitalWrite(dir_b,LOW);
      j++;
    }
   }
   
   //old code for going clockwize
   //step_backward(6, 400); 
   //delay(500);
}

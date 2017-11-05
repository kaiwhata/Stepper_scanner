
//Version: 0.2
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

//time step
int dt = 400; //default 380
int v = 220;

//Control methods

//steps 4 times for each n
void step_forward(int n)
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

void step_backward(int n)
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
   step_forward(11);   
   delay(500);
   step_backward(6);  
   delay(500); 
}

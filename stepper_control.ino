
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
int dt = 380;
int v = 220;

//Control methods
void forward()
{
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
  
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
  
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
  
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
 
}

void backward()
{
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);

  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,HIGH);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);

  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
 
 
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  digitalWrite(dir_a,HIGH);
  digitalWrite(dir_b,LOW);
  analogWrite(pwm_a, v);  
  analogWrite(pwm_b, v);
  delay(dt);
  
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
   forward();   
   forward();   
   forward();   
   forward();   
   forward();   
   forward();   
   backward();   
}
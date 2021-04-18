int ENA = A5;
int ENB = A4
int MOTOR_A1 = 7; // MOTOR_A1 connected to digital pin 7
int MOTOR_A2 = 6; // MOTOR_A2 connected to digital pin 6
int MOTOR_B1 = 5; // MOTOR_B1 connected to digital pin 5
int MOTOR_B2 = 4; // MOTOR_B2 connected to digital pin 4

int a[8];
int last_proportional=0;
intintegral=0;
char select_turn(unsigned char found_left,unsigned char found_right,unsigned char found_st);
int mod(int v);
int set_motors(int a,int b);
void turn(char dir);
void PID();
int right=0;
int left=0;

void setup() {
  pinMode(MOTOR_A1,OUTPUT);
  pinMode(MOTOR_A2,OUTPUT);
  pinMode(MOTOR_B1,OUTPUT);
  pinMode(MOTOR_B2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  PID();
  set_motors(150,150);
  delay(20);
  unsigned char found_left=0;
  unsigned char found_right=0;  //turn parameter
  unsigned char found_st=0;

  readline();
  if(a[0]==LOW)
    found_left=1;
  if(a[7]==LOW)
    found_right=1;
  if(a[3]==LOW || a[4]==LOW)
    found_st=1;

  unsigned char dir;
  dir=select_turn(found_left,found_rigt,found_st);
  turn(dir);
} //main body ends


int set_motors(int l,int r)  ///motor setup
{
  Serial.println(r);
  Serial.println(l);

  if(l>0 && r>0)
  {
    analogWrite(ENA,mod(l));
    analogWrite(ENB,mod(r));

    digitalWrite(MOTOR_A1,LOW);
    digitalWrite(MOTOR_A1,HIGH);
    digitalWrite(MOTOR_A1,LOW);
    digitalWrite(MOTOR_A1,HIGH);
  }
  else if(l<0 && r>0)
  {
    analogWrite(ENA,mod(l));
    analogWrite(ENB,mod(r));

    digitalWrite(MOTOR_A1,HIGH);
    digitalWrite(MOTOR_A1,LOW);
    digitalWrite(MOTOR_A1,LOW);
    digitalWrite(MOTOR_A1,HIGH);
  } 
  else if(l>0 && r<0)
  {
    analogWrite(ENA,mod(l));
    analogWrite(ENB,mod(r));

    digitalWrite(MOTOR_A1,LOW);
    digitalWrite(MOTOR_A1,HIGH);
    digitalWrite(MOTOR_A1,HIGH);
    digitalWrite(MOTOR_A1,LOW);
  } 
  

}

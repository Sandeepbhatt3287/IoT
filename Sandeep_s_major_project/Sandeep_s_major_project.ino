#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include<I2Cdev.h>
//#include<wire.h>
// You should get Auth Token in the Blynk App. .
char auth[] = "2206d1ccc8de4b7aa4926ee006d7a2d0";
// Your WiFi credentials.
char ssid[] = "Sandeep";
char pass[] = "12345678";
int Q1=D1;
int Q2=D0;
int Q3=D2;
int Q4=D3;
void setup()
{
// Debug console
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D0,OUTPUT);
//pinMode(D4,OUTPUT);
}
void loop(){
Blynk.run();

} 
// Handling Joystick data
BLYNK_WRITE(V0){
int x = param[0].asInt();
int y = param[1].asInt();
/*Serial.print("x");
Serial.println(x);
Serial.print("\t\ty");
Serial.println(y);
*/
 
if(x>1)
{
 Serial.println(" Left"); //Left Turn
 digitalWrite(Q1, LOW);
 digitalWrite(Q2, LOW);
 digitalWrite(Q3, HIGH);
 digitalWrite(Q4, HIGH);
 //digitalWrite(D4, HIGH);
}
/*else if(x==-1 && y==1){
 Serial.println("forward and left");//Forward and Left
 digitalWrite(Q1, LOW);
 digitalWrite(Q2, LOW);
 digitalWrite(Q3, LOW);
 digitalWrite(Q4, HIGH);
}*/

else if(y>1)
{
 Serial.println("BackWard"); //BackWard
 digitalWrite(Q1, HIGH);
 digitalWrite(Q2, LOW);
 digitalWrite(Q3, HIGH);
 digitalWrite(Q4, LOW);
}

else if(x==0 && y==0)
{
 Serial.println("stop"); //Stay
 digitalWrite(Q1, LOW);
 digitalWrite(Q2, LOW);
 digitalWrite(Q3, LOW);
// digitalWrite(Q0, LOW);
}
else if(y<0)

{
 Serial.println("forward"); //Forward
digitalWrite(Q1, LOW);
digitalWrite(Q2, HIGH);
digitalWrite(Q3, LOW);
digitalWrite(Q4, HIGH);
//digitalWrite(Q0, HIGH);
}
/*else if(x==1 && y==-1){
 Serial.println("BackWard and right");//Backward and Right
 digitalWrite(Q1, HIGH);

 digitalWrite(Q2, LOW);
 digitalWrite(Q3, LOW);
 digitalWrite(Q4, LOW);
}*/
else if(x<1)
{
Serial.println("right"); //Right turn
digitalWrite(Q1, HIGH);
//digitalWrite(Q0, HIGH);
digitalWrite(Q2, HIGH);
digitalWrite(Q3, LOW);
digitalWrite(Q4, LOW);
}
}
/*else if(x==1 && y==1){
Serial.println("forward and right");//Forward and Right
digitalWrite(Q1, LOW);
 digitalWrite(Q2,HIGH);
 digitalWrite(Q3, LOW);
 digitalWrite(Q4, LOW);*/

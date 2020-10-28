int ledPinRed = 12;
int inPin = 7;    
int ledPinGreen = 13;
int ledPinYellow = 11 ;
int ledPinBlue = 10;
#include <IRremote.h>  //including infrared remote header file
int incomingByte;
int mode = 0;
int last_mode = 0;     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;     




 void setup(){
  Serial.begin(9600);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  irrecv.enableIRIn();
  }
 void turn_All_off(){
  digitalWrite(ledPinGreen, LOW);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinYellow, LOW);
  digitalWrite(ledPinBlue, LOW); 
}
 void mode_BlinkingRed () { 
  if (last_mode != 1){
    Serial.print("Step 1");
    turn_All_off();
    Serial.print("Step 2");
    digitalWrite(ledPinRed, HIGH);
    Serial.print("Step 3");  
    last_mode = 1;
    Serial.print("Step 4");
  }else{
    delay(100); 
    Serial.print("Step 5");
}
 }

void mode_TurnOnGreen() {
  if (last_mode != 2){
    turn_All_off();
    digitalWrite(ledPinGreen, HIGH);  
    last_mode = 2;
  }else{
    delay(100);  
  }  
  
 } 

 void send_0 (){
 Serial.println("step10");   
    turn_All_off();
 Serial.println("step20");
 }
 void mode_TurnOnAll (){ 
 
 if (last_mode != 3){
    turn_All_off();
    digitalWrite(ledPinBlue, HIGH);  
    digitalWrite(ledPinYellow, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinRed, HIGH);
    last_mode = 3;
  }else{
    delay(100);
  }
 }

 void mode_TurnOnYellow ()  {
  if (last_mode != 4){
    turn_All_off();
    digitalWrite(ledPinYellow, HIGH);  
    last_mode = 4;
  }else{
    delay(100);
 }
 }

 void mode_TurnOnBlue () {
 if (last_mode != 5){
    turn_All_off();
    digitalWrite(ledPinBlue, HIGH);  
    last_mode = 5;
  }else{
    delay(100);
 }
 }


      
 
 
 int getMode(int incomingByte){
   if (incomingByte == '1'){
     return 1; 
   }else if (incomingByte == '2'){
     return 2; 
   }else if (incomingByte == '3'){
     return 3; 
   }else if (incomingByte == '4'){
     return 4; 
   }else if (incomingByte == '0'){
     return 0; 
   }else if (incomingByte == '5') {
    return 5;
   }
 }
 int getModeRemote(int incomingByte){
  if (incomingByte == 2895838440){
     return 1; 
   }else if (incomingByte == '2'){
     return 2; 
   }else if (incomingByte == '3'){
     return 3; 
   }else if (incomingByte == '4'){
     return 4; 
   }else if (incomingByte == '0'){
     return 0; 
   }else if (incomingByte == '5') {
    return 5;
   }
 }

 void loop() {  
   if (Serial.available() > 0){     
     incomingByte = Serial.read();
     Serial.print("received: ");
     Serial.println(incomingByte, DEC);   
     mode = getMode(incomingByte);
   }else if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
  {     
   // int results.value = results;// Results of decoding are stored in result.value     
//    Serial.println(" ");     
//    Serial.print("Code: ");     
//    Serial.println(results.value); //prints the value a a button press     
//    Serial.println(" ");     
      mode=getModeRemote(results.value);
    irrecv.resume(); // Restart the ISR state machine and Receive the next value     
  }
   
   if (mode == 1){ //2895838440
     mode_BlinkingRed();
   }else if (mode == 2){
     mode_TurnOnGreen();
   }else if(mode == 3){
     mode_TurnOnAll();               
   }else if(mode == 4){
     mode_TurnOnYellow();
   }else if(mode == 5){
     mode_TurnOnBlue();
   }else if(mode == 0){
     turn_All_off();
   
   }
   
 }


 

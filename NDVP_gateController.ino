void setup(){
  Serial.begin(9600);
pinMode(14,INPUT_PULLUP); //l1
pinMode(12,INPUT_PULLUP); //l2
pinMode(22,OUTPUT);//led 2
pinMode(21,OUTPUT); //led 1
pinMode(13,INPUT_PULLUP); //s
}
void loop()
{
  //reading values for all inputs
  int l1=digitalRead(14);  
  int l2=digitalRead(12);  
  int s=digitalRead(13);  
  //Printing the vlaues of all inputs i.e. limit-1, limit-2, switch 
  Serial.print("Switch:");
  Serial.println(s);
  Serial.print("Limit-1:");
  Serial.println(l1);
  Serial.print("Limit-2:");
  Serial.println(l2);
  delay(500);
  if (s == 0&& l1==0)  //check switch input and limit-1 for moving forword
  {
   while(l2==1){         //moving till gate reaches to limit-2 
   l2=digitalRead(12);
   digitalWrite(21,HIGH);
   digitalWrite(22,LOW);
   }
   digitalWrite(21,LOW); //gate reached to limit-2 i.e it is closed so stop the motor
   digitalWrite(22,LOW);
   }

   
  if (s == 0&& l2==0)   //check the switch input and limit-2
  {
   while(l1==1){    //check for opening the gate 
   l1=digitalRead(14); 
   digitalWrite(21,LOW);
   digitalWrite(22,HIGH);
   }    
   digitalWrite(21,LOW);  //gate reached to limit-1 i.e it is open so stop the motor
   digitalWrite(22,LOW);
   }
} 


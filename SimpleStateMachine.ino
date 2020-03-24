/*
SimpleStateMachine.ino
Demonstrate a state machine with button pushes
*/
  const int InternalLED=13;
  const int ExternalLED=12;
  int Bpush=0;

  //A0 has the pushbutton attached to it. Give it a name:
  int pushButton=A0;

  //the setup routine runs once when you press reset:
  void setup() {
  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(ExternalLED, OUTPUT);
  pinMode(InternalLED, OUTPUT);
  }

  //the loop routine runs over and over again forever:
  void loop() {
  int pushCount=0;//Counts the times button is pressed 
  
  while(pushCount<=3)//Setting to 3 allows pushCount to break out of loop
  {
    int buttonState=digitalRead(pushButton);//Tracks the state of the button
    delay(200);//Delay to allow for stability
    
    if(buttonState==1)//Increments if button is pushed
    {
      pushCount+=1;
      Serial.println(pushCount);
    }
  }  
    
  if(pushCount==4)//Runs after 4 button pushes
   {
    for(int i=0; i<=10; i++)
    {
      digitalWrite(ExternalLED, HIGH);    
      digitalWrite(InternalLED, LOW);   
      delay(500);
      digitalWrite(ExternalLED, LOW);    
      digitalWrite(InternalLED, HIGH); 
      delay(500);  
    }    
   }
   else
   {
    digitalWrite(ExternalLED, LOW);
    digitalWrite(InternalLED, LOW);   
    Bpush++; 
   }

  //Original draft
  /*Serial.println("Entering For Loop");

  for(int i=0; i<=4; i++)
  {
    Serial.println("Inside For Loop");  
    int buttonState=digitalRead(pushButton);//Tracks the state of the button  
    //Serial.println(buttonState);//print out the state of the button:  
    Serial.println("After Input");  
    if(buttonState==1)
    {
      pushCount+=1;  
      Serial.println("Push Count: "+pushCount);//print out the number of button presses:  
    }
  }
  Serial.println("Exiting For Loop");
  
  if(pushCount==4)//Triggers once button is pushed 4 times
  {
    for(int j=0; j<=10; j++)
    {
      digitalWrite(ExternalLED, HIGH);
      digitalWrite(InternalLED, LOW);   
      delay(500);
      digitalWrite(ExternalLED, LOW);    
      digitalWrite(InternalLED, HIGH); 
      delay(500);
      pushCount=0;
     }
  }*/
 }

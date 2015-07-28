
/*  Pulse Sensor Amped 1.4 fork by Dehyrf

----------------------  Notes ----------------------  ---------------------- 
This code:
1) Blinks an LED to User's Live Heartbeat   PIN 13
2) Determines BPM
3) Cuts off power to a keyboard when the BPM is too low  PIN 7
4) Prints to serial
---------  ----------------------
*/

//  Variables
int temp = 0;
int temp1 = 0;
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;  
int powerPin = 7;

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = false;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 


void setup(){
  pinMode(blinkPin,OUTPUT); 
//pinMode(8,INPUT_PULLUP); 
  pinMode(fadePin,OUTPUT); 
 pinMode(powerPin,OUTPUT);    
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
   // UN-COMMENT THE NEXT LINE IF YOU ARE POWERING The Pulse Sensor AT LOW VOLTAGE, 
   // AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);   
}


//  Where the Magic Happens
void loop(){
  
    serialOutput() ;       
    
  if (QS == true){ temp=0;    
  // BPM and IBI have been Determined
             if(BPM >= 80){
     digitalWrite(powerPin,HIGH);
   temp1=0;}
if(BPM <  80 && temp1 >= 10){ digitalWrite(powerPin,LOW);
temp1 = 0;}  
   ledFadeToBeat();             
        digitalWrite(blinkPin,HIGH);     
        fadeRate = 255;        
                                
        serialOutputWhenBeatHappens();       
        QS = false;                      
       temp1++;} 
      else { 
      
      digitalWrite(blinkPin,LOW);            
      }
      if(temp < 50){
      temp++;
    }
     if(temp >= 50){ 
      digitalWrite(powerPin,LOW); 
     temp = 0;} 
   ledFadeToBeat();                       
  delay(20);                             
}

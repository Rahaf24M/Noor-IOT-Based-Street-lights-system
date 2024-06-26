const int sensor6Pin = 40; // Connect sensor 1 signal pin to digital pin 23  التقاطع
const int sensor8Pin = 42; // Connect sensor 2 signal pin to digital pin 25  التقاطع
const int sensor9Pin = 44; // Connect sensor 3 signal pin to digital pin 27  التقاطع

const int sensor1Pin = 29; // Connect sensor 1 signal pin to digital pin 29  الشارع الايسر 
const int sensor2Pin = 31; // Connect sensor 2 signal pin to digital pin 31  الشارع الايسر 

const int sensor3Pin = 33; // Connect sensor 3 signal pin to digital pin 33  الشارع الاوسط 
const int sensor5Pin = 37; // Connect sensor 5 signal pin to digital pin 37  الشارع الاوسط  

const int sensor4Pin = 35; // Connect sensor 4 signal pin to digital pin 35  الشارع الايمن  
const int sensor7Pin = 39; // Connect sensor 7 signal pin to digital pin 39  الشارع الايمن 

#define LED_PIN_1 5  
#define LED_PIN_2 4   
#define LED_PIN_3 3 
#define LED_PIN_4 2 
#define LED_PIN_5 8 
#define LED_PIN_6 9 

#define LED_PIN_7 6   // الشارع الايسر 
#define LED_PIN_9 7   // الشارع الايسر 

#define LED_PIN_10 12 //الشارع الاوسط 
#define LED_PIN_12 13 // الشارع الاوسط 

#define LED_PIN_11 10 // الشارع الايمن 
#define LED_PIN_13 11 // الشارع الايمن 

//unsigned long lastTriggerTime = 0; //الوقت حاليا كم ؟ Variable to store the last time sensors went to zero
//const unsigned long delayTime = 2000;  //وقت الثبات الحركى للانارة  Time in milliseconds to wait before turning off LEDs

int ldr = A0; 
int lightval =0; 

const int Manualcase = 24; // المسئول عن تحويل النظام لمانيوال للصيانة   
const int reciverpin1 = 26; // مستقبل اشارة افتح او اقفل الميدان   
const int reciverpin2 = 28; // مستقبل اشارة افتح او اقفل الشارع الايسر  
const int reciverpin3 = 32; // مستقبل اشارة افتح او اقفل الشارع الاوسط    
const int reciverpin4 = 30; // مستقبل اشارة افتح او اقفل الشارع الايمن 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(sensor6Pin, INPUT);  //التقاطع Set sensor pins as inputs 
  pinMode(sensor8Pin, INPUT);  //التقاطع
  pinMode(sensor9Pin, INPUT);  //التقاطع

  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);
  pinMode(sensor5Pin, INPUT);
  pinMode(sensor7Pin, INPUT);

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT); 
  pinMode(LED_PIN_7, OUTPUT);
  pinMode(LED_PIN_9, OUTPUT);
  pinMode(LED_PIN_10, OUTPUT);
  pinMode(LED_PIN_11, OUTPUT);
  pinMode(LED_PIN_12, OUTPUT);
  pinMode(LED_PIN_13, OUTPUT);

  // تحكمات الEsp 
  pinMode(Manualcase, INPUT);
  pinMode(reciverpin1, INPUT);
  pinMode(reciverpin2, INPUT);
  pinMode(reciverpin3, INPUT);
  pinMode(reciverpin4, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  lightval = analogRead(ldr);
  int sensor6Value = digitalRead(sensor6Pin); //التقاطع Read sensor 1 value
  int sensor8Value = digitalRead(sensor8Pin); //التقاطع Read sensor 2 value
  int sensor9Value = digitalRead(sensor9Pin); //التقاطع Read sensor 3 value
  int sensor1Value = digitalRead(sensor1Pin); 
  int sensor2Value = digitalRead(sensor2Pin);
  int sensor3Value = digitalRead(sensor3Pin); 
  int sensor4Value = digitalRead(sensor4Pin);
  int sensor5Value = digitalRead(sensor5Pin); 
  int sensor7Value = digitalRead(sensor7Pin); 
  int ManualStatus = digitalRead(Manualcase); 
  int SquareControl = digitalRead(reciverpin1); 
  int LeftControl = digitalRead(reciverpin2); 
  int MidControl = digitalRead(reciverpin3); 
  int RightControl = digitalRead(reciverpin4); 


  Serial.println("ldr sensor:");
  Serial.println(lightval); 
  Serial.println(" ");

  Serial.println("sensor 6 التقاطع:");
  Serial.println(sensor6Value); 
  Serial.println(" ");

  Serial.println("sensor 8 التقاطع:");
  Serial.println(sensor8Value);
  Serial.println(" ");

  Serial.println("sensor 9 التقاطع:");
  Serial.println(sensor9Value);
  Serial.println(" ");

  Serial.println("sensor 1:");
  Serial.println(sensor1Value);
  Serial.println(" ");

  Serial.println("sensor 2:");
  Serial.println(sensor2Value);
  Serial.println(" ");

  Serial.println("sensor 3:");
  Serial.println(sensor3Value);
  Serial.println(" ");

  Serial.println("sensor 4:");
  Serial.println(sensor4Value);
  Serial.println(" ");

  Serial.println("sensor 5:");
  Serial.println(sensor5Value);
  Serial.println(" ");

  Serial.println("sensor 7:");
  Serial.println(sensor7Value);
  Serial.println(" ");

  Serial.println("ManualStatus if 1 is on, 0 is off: ");
  Serial.println(ManualStatus);
  Serial.println(" ");

  Serial.println("SquareControl if 1 is on, 0 is off: ");
  Serial.println(SquareControl);
  Serial.println(" ");

  Serial.println("LeftstreetControl if 1 is on, 0 is off: ");
  Serial.println(LeftControl);
  Serial.println(" ");

  Serial.println("Mid street Control if 1 is on, 0 is off: ");
  Serial.println(MidControl);
  Serial.println(" ");

  Serial.println("Right street Control if 1 is on, 0 is off: ");
  Serial.println(RightControl);
  Serial.println(" ");
  Serial.println("--------------------------------------------------------");

  //if(ManualStatus == LOW){
  if (lightval <= 300){
  if (sensor6Value == LOW || sensor8Value == LOW || sensor9Value == LOW) 
  {
    // If any sensor reads a value greater than zero
    analogWrite(LED_PIN_1, map(100, 0, 100, 0, 255));
    analogWrite(LED_PIN_2, map(100, 0, 100, 0, 255));
    analogWrite(LED_PIN_3, map(100, 0, 100, 0, 255));
    analogWrite(LED_PIN_4, map(100, 0, 100, 0, 255));
    analogWrite(LED_PIN_5, map(100, 0, 100, 0, 255));
    analogWrite(LED_PIN_6, map(100, 0, 100, 0, 255));
    //lastTriggerTime =  millis(); //الوقت حاليا كم ؟ Variable to store the last time sensors went to zero
  }
  else if(sensor6Value == HIGH && sensor8Value == HIGH && sensor9Value == HIGH){
        analogWrite(LED_PIN_1, map(10, 0, 100, 0, 255));
        analogWrite(LED_PIN_2, map(10, 0, 100, 0, 255));
        analogWrite(LED_PIN_3, map(10, 0, 100, 0, 255));
        analogWrite(LED_PIN_4, map(10, 0, 100, 0, 255));
        analogWrite(LED_PIN_5, map(10, 0, 100, 0, 255));
        analogWrite(LED_PIN_6, map(10, 0, 100, 0, 255));
  }
  if (sensor3Value == LOW) {
      analogWrite(LED_PIN_10, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_10, map(10, 0, 100, 0, 255));
    } 
  if (sensor5Value == LOW) {
      analogWrite(LED_PIN_12, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_12, map(10, 0, 100, 0, 255));
    } 
  if (sensor1Value == LOW) {
      analogWrite(LED_PIN_7, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_7, map(10, 0, 100, 0, 255));
    } 
    
  if (sensor2Value == LOW) {
     analogWrite(LED_PIN_9, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_9, map(10, 0, 100, 0, 255));
    }
  if (sensor5Value == LOW) {
      analogWrite(LED_PIN_11, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_11, map(10, 0, 100, 0, 255));
    } 
  if (sensor7Value == LOW) {
      analogWrite(LED_PIN_13, map(100, 0, 100, 0, 255));
    } 
    else{
      analogWrite(LED_PIN_13, map(10, 0, 100, 0, 255));
    } 
  }
  else{// فى حالة اننا صباحا فى الظهيرة والقيمة اكبرمن الحد النهارى 
    analogWrite(LED_PIN_1, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_2, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_3, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_4, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_5, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_6, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_7, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_9, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_10, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_11, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_12, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_13, map(0, 0, 100, 0, 255));
   }

 //}
 /*else*/ if(ManualStatus == HIGH){ //لازم نقفل كل الانارة على المدينة كى نختبر المناطق
    analogWrite(LED_PIN_1, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_2, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_3, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_4, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_5, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_6, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_7, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_9, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_10, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_11, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_12, map(0, 0, 100, 0, 255));
    analogWrite(LED_PIN_13, map(0, 0, 100, 0, 255));
    if(SquareControl == HIGH){
      analogWrite(LED_PIN_1, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_2, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_3, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_4, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_5, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_6, map(100, 0, 100, 0, 255));
    }
    /*else*/ if(SquareControl == LOW){
      analogWrite(LED_PIN_1, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_2, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_3, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_4, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_5, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_6, map(0, 0, 100, 0, 255));
    }
    /*else*/ if(LeftControl == HIGH){//الشارع الايسر Turn on 
      analogWrite(LED_PIN_7, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_9, map(100, 0, 100, 0, 255));    
    }
    /*else*/ if(LeftControl == LOW){//الشارع الايسر Turn off
      analogWrite(LED_PIN_7, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_9, map(0, 0, 100, 0, 255));      
    }
    /*else*/ if(MidControl == HIGH){//الشارع الاوسك Turn on 
      analogWrite(LED_PIN_12, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_10, map(100, 0, 100, 0, 255));    
    }
    /*else*/ if(MidControl == LOW){//الشارع الاوسك Turn off
      analogWrite(LED_PIN_12, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_10, map(0, 0, 100, 0, 255));      
    }
    /*else*/ if(RightControl == HIGH){//الشارع الايمن Turn on 
      analogWrite(LED_PIN_13, map(100, 0, 100, 0, 255));
      analogWrite(LED_PIN_11, map(100, 0, 100, 0, 255));    
    }
    /*else*/ if(RightControl == LOW){//الشارع الايمن Turn off
      analogWrite(LED_PIN_13, map(0, 0, 100, 0, 255));
      analogWrite(LED_PIN_11, map(0, 0, 100, 0, 255));      
    }
 }
  delay(1000);
}
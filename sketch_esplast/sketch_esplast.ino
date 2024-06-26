#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <ThingSpeak.h>
WiFiClient client;

unsigned long myChannelNumber = 2507252; 
//https://thingspeak.com/channels/2507252
const char * myWriteAPIKey = "54B6HONPCUZYQ4CU"; 

const char * myReadAPIKey = "9EECIXOZNYO5MO6K"; 

//SSID &PASSWORD
const char *ssid = "HW-4G-SW";
const char *password = "120012001200";

ESP8266WebServer server(80);


uint8_t manual_control = D6;
uint8_t Square = D5;
uint8_t right_street = D0;
uint8_t left_street = D4;
uint8_t middile_street = D3;

bool manual_control_status=false, Square_status=false, right_street_status=false, left_street_status=false, middile_street_status=false;

void setup() {

  //Starting the serial communication channel
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
 
 //Output mode for the LED Pins
  pinMode(manual_control,OUTPUT);
  pinMode(Square,OUTPUT);
  pinMode(right_street,OUTPUT);
  pinMode(left_street,OUTPUT);
  pinMode(middile_street,OUTPUT);

  //Connecting to the local WiFi network
  WiFi.begin(ssid,password);
  ThingSpeak.begin(client); 


  //Keep checking the WiFi status until it is connected to the wifi network
 
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi Connected with IP Address: ");
  Serial.println(WiFi.localIP());
 
  //Specifying the functions which will be executed upon corresponding GET request from the client
  server.on("/",handle_OnConnect);
  server.on("/manual_on",handle_manual_on);
  server.on("/manual_off",handle_manual_off);
  server.on("/Square_on",handle_Square_on);
  server.on("/Square_off",handle_Square_off);
  server.on("/right_street_on",handle_right_street_on);
  server.on("/right_street_off",handle_right_street_off);
  server.on("/left_street_on",handle_left_street_on);
  server.on("/left_street_off",handle_left_street_off);
  server.on("/middile_street_on",handle_middile_street_on);
  server.on("/middile_street_off",handle_middile_street_off);
  server.onNotFound(handle_NotFound);
   
  //Starting the Server
  server.begin();
  Serial.println("HTTP Server Started");
}

void loop() {
 
  if(WiFi.status()==WL_CONNECTED)
  //Check if ESP8266 is still connected to the internet
  {
    //Assign the server to handle the clients
    server.handleClient();
 
    //Turn the LEDs ON/OFF as per their status set by the connected client
   
    //LED1
    if(manual_control_status==false)
    {
      digitalWrite(manual_control,LOW);
    }
    else
    {
      digitalWrite(manual_control,HIGH);
    }
   
    //LED2
    if(Square_status==false)
    {
      digitalWrite(Square,LOW);
    }
    else
    {
      digitalWrite(Square,HIGH);
    }
   
    //LED3
    if(right_street_status==false)
    {
      digitalWrite(right_street,LOW);
    }
    else
    {
      digitalWrite(right_street,HIGH);
    }
   
    //LED4
    if(left_street_status==false)
    {
      digitalWrite(left_street,LOW);
    }
    else
    {
      digitalWrite(left_street,HIGH);
    }
    if(middile_street_status==false)
    {
      digitalWrite(middile_street,LOW);
    }
    else
    {
      digitalWrite(middile_street,HIGH);
    }
    ThingSpeak.writeField(myChannelNumber, 1,manual_control, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 2,right_street, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 3,middile_street, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 4,left_street, myWriteAPIKey);
    ThingSpeak.writeField(myChannelNumber, 5,Square, myWriteAPIKey);
  }
  else
  {
    Serial.println("WiFi Disconnected!!!");
    Serial.print("Trying to establish the connection...");
     
    //Keep checking the WiFi status until it is connected to the wifi network
    while(WiFi.status()!=WL_CONNECTED)
    {
      delay(1000);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi Connected with IP Address: ");
    Serial.println(WiFi.localIP());
  }
}


void handle_OnConnect()
{
  Serial.println("Client Connected");
  server.send(200, "text/html", HTML()); 
}
 
void handle_manual_on()
{
  Serial.println("manual_on");
  Serial.println("GPIO6 Status: ON");
  Serial.println("");  
  manual_control_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_manual_off()
{
  Serial.println("manual_off");
  Serial.println("GPIO6 Status: OFF");
  Serial.println("");
  manual_control_status=false;
  server.send(200, "text/html", HTML());
}
 
void handle_Square_on()
{
  Serial.println("Square_on");
  Serial.println("GPIO5 Status: ON");
  Serial.println("");
  Square_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_Square_off()
{
  Serial.println("Square_OFF");
  Serial.println("GPIO5 Status: OFF");
  Serial.println("");
  Square_status=false;
  server.send(200, "text/html", HTML());
}
 
void handle_right_street_on()
{
  Serial.println("right_street_on");
  Serial.println("GPIO0 Status: OFF");
  Serial.println("");
  right_street_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_right_street_off()
{
  Serial.println("right_street_OFF");
  Serial.println("GPIO0 Status: OFF");
  Serial.println("");
  right_street_status=false;
  server.send(200, "text/html", HTML());
}
 
void handle_left_street_on()
{
  Serial.println("left_street_on");
  Serial.println("GPIO4 Status: ON");
  Serial.println("");
  left_street_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_left_street_off()
{
  Serial.println("left_street_off");
  Serial.println("GPIO4 Status: Off");
  Serial.println("");
  left_street_status=false;
  server.send(200, "text/html", HTML());
}

void handle_middile_street_on()
{
  Serial.println("middile_street_on");
  Serial.println("GPIO3 Status: ON");
  Serial.println("");
  middile_street_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_middile_street_off()
{
  Serial.println("middile_street_off");
  Serial.println("GPIO3 Status: Off");
  Serial.println("");
  middile_street_status=false;
  server.send(200, "text/html", HTML());
}
 
void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}

String HTML()
{
  String msg="<!DOCTYPE html> <html>\n";
  msg+="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  msg+="<title>Smart System control</title>\n";
  msg+="<img src=\"https://i.ibb.co/mybNHVD/Whats-App-Image-2024-05-11-at-9-16-59-PM.jpg\">";
  msg+="<style>html{font-family:Helvetica; display:inline-block; margin:0px auto; text-align:center;}\n";
  msg+="body{margin-top: 50px;} h1{color: #444444; margin: 50px auto 30px;} h3{color:#444444; margin-bottom: 50px;}\n";
  msg+=".button {display: block;width: 160px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  msg+=".button-on{background-color:#f48100;}\n";
  msg+=".button-on:active{background-color:#f48100;}\n";
  msg+=".button-off{background-color:#26282d;}\n";
  msg+=".button-off:active{background-color:#26282d;}\n";
  msg+="</style>\n";
  msg+="</head>\n";
  msg+="<body>\n";
  //msg+="<h1>ESP8266 Web Server</h1>\n";
  //msg+="<h3>Using Station (STA) Mode</h3>\n";

  msg +="<p>Send Email to consult company:</p><a class=\"button button-on\" href=\"https://mail.google.com/mail/u/0/#inbox?compose=DmwnWrRttWXnschZLJGxbsqdcwwsdzbJhpDcrbsQjFSHnpSKkrDrwhlmDMkZHmjGwGLNPkXcbBHb\">Send complaint</a>\n";
  msg +="<p>open thingspeak</p><a class=\"button button-on\" href=\"https://thingspeak.com/channels/2507252\">openthingspeak</a>\n";


  if(manual_control_status==false)
  {
    msg+="<p>manual_control_status: OFF</p><a class=\"button button-on\" href=\"/manual_on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>manual_control_status: ON</p><a class=\"button button-off\" href=\"/manual_off\">OFF</a>\n";
  }

  if(Square_status==false)
  {
    msg+="<p>Square_status: OFF</p><a class=\"button button-on\" href=\"/Square_on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>Square_status: ON</p><a class=\"button button-off\" href=\"/Square_off\">OFF</a>\n";
  }

  if(right_street_status==false)
  {
    msg+="<p>right_street_status: OFF</p><a class=\"button button-on\" href=\"/right_street_on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>right_street_status: ON</p><a class=\"button button-off\" href=\"/right_street_off\">OFF</a>\n";
  }

  if(left_street_status==false)
  {
    msg+="<p>left_street_status: OFF</p><a class=\"button button-on\" href=\"/left_street_on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>left_street_status: ON</p><a class=\"button button-off\" href=\"/left_street_off\">OFF</a>\n";
  }

  if(middile_street_status==false)
  {
    msg+="<p>middile_street_status: OFF</p><a class=\"button button-on\" href=\"/middile_street_on\">ON</a>\n";    
  }
  else
  {
    msg+="<p>middile_street_status: ON</p><a class=\"button button-off\" href=\"/middile_street_off\">OFF</a>\n";
  }
  msg+="</body>\n";
  msg+="</html>\n";
  return msg;
}
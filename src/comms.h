#define TINY_GSM_MODEM_SIM800     
#define GSM_BAUD 9600   
#include <TinyGsmClient.h>

#define Serial Serial            
#define SerialAT Serial3            

const char* apn = "safaricom";     
const char* gprsUser = "";         
const char* gprsPass = "";         

TinyGsm modem(SerialAT);           
TinyGsmClient client(modem);

const char* server = "http://cklogistics.cloud.shiftr.io"; 
const int httpPort = 80;                                 



String sendHttpRequest(String message) {
  
  if (!client.connect(server, httpPort)) {
    Serial.println("Connection to server failed!");
    return "Fail";
  }

  
  String httpRequest = "POST /endpoint HTTP/1.1\r\n"; 
  httpRequest += "Host: cklogistics.cloud.shiftr.io\r\n";
  httpRequest += "Content-Type: application/json\r\n";
  httpRequest += "Content-Length: " + String(message.length()) + "\r\n";
  httpRequest += "\r\n";
  httpRequest += message;

  
  client.print(httpRequest);
  Serial.println("HTTP request sent:");
  Serial.println(httpRequest);

  
  String response = "";
  while (client.available()) {
    response += (char)client.read();
  }

  client.stop();
  Serial.println("HTTP response received:");
  Serial.println(response);

  return response;
}



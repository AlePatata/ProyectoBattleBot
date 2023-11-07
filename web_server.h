#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//Librerias propias
#include "index.h" //Nuestra página web en HTML 

ESP8266WebServer server(80); //Crea el objeto server en el puerto 80

//Nombre y password del punto WIFI
const char *ssid = "BattleBotsMontaña";
// const char *password = "123456"; //no usamos password


/** Handle Root
 * @brief Envía el contenido de index.h
 */
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}


/** Handle Button Request
 * @brief Esta función toma los valores enviados desde la página web y según su valor, llama a distintas funciones de motores.
  * Los botones de la página web ejecutan esta funcion -> sendRequest('http://192.168.4.1/B?val=1') 
 * La función sendRequest() crea una instancia de XMLHttpRequest() y la envía a través de WiFi a nuestra ESP8266.
 */
void handleButtonRequest(void) {

  int AdltAtrs = server.arg("AdltAtrs").toInt();
  int  DerIzq = server.arg("DerIzq").toInt();
  int Arma = server.arg("Arma").toInt();

  if (Arma) {
    
  }

  //ADELANTE DERECHA
  if (AdltAtrs == 1 && DerIzq == -1) {
    motor_FR();
    Serial.println("ADELANTE DERECHA");
    server.send(200, "text/plain", "OK");
  }
  //ADELANTE IZQUIERDA
  if (AdltAtrs == 1 && DerIzq == 1) {
    motor_FL();
    Serial.println("ADELANTE IZQUIERDA");
    server.send(200, "text/plain", "OK");
  }
  // ATRAS DERECHA
  if (AdltAtrs == -1 && DerIzq == -1) {
    motor_BR();
    server.send(200, "text/plain", "OK");
  }
  //ATRAS IZQUIERDA
  if (AdltAtrs == -1 && DerIzq == 1) {
    motor_BL();
    server.send(200, "text/plain", "OK");
  }
  
  //Avanzar
  if (AdltAtrs == 1 && DerIzq == 0) {
    motor_FWBW(true); //llamamos a la función del motor que lo mueve hacia adelante y atrás
                      //Le entregamos el valor true para que avance.
    Serial.print("ADELANTE (Adlt,DerIzq) = ");
    Serial.println(AdltAtrs,DerIzq);
    server.send(200, "text/plain", "OK"); //enviamos una confirmación al servidor
  }
  //Girar Izquierda
  if (AdltAtrs == 0 && DerIzq == 1) {
    motor_LR(true);  //llamamos a la función del motor que lo gira 
                      //Le entregamos el valor true para que gire a la izquierda
    Serial.println("IZQUIERDA");
    server.send(200, "text/plain", "OK"); //enviamos una confirmación al servidor
  }
  
  //Girar Derecha
  if (AdltAtrs == 0 && DerIzq == -1) {
    motor_LR(false);  //llamamos a la función del motor que lo gira 
                      //Le entregamos el valor false para que gire a la derecha
    Serial.println("DERECHA");
    server.send(200, "text/plain", "OK"); //enviamos una confirmación al servidor
  }
  //Atras
  if (AdltAtrs == -1 && DerIzq == 0) {
    motor_FWBW(false); //llamamos a la función del motor que lo mueve hacia adelante y atrás
                      //Le entregamos el valor false para que retroceda.
    server.send(200, "text/plain", "OK"); //enviamos una confirmación al servidor
  }
  //Stop 
  if (AdltAtrs == 0 && DerIzq == 0) { 
    motor_stop();
    server.send(200, "text/plain", "OK"); //enviamos una confirmación al servidor
  }
  //---------------------------------------------------------------------------------
}




/** Run Web Server
 * @brief Función principal que configura la conección wifi, crea el servidor y conecta las funciones.
 */

void run_web_server(void) {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Create a new SoftAP network
  WiFi.softAP(ssid);


  // Print the IP address of the SoftAP network
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Copien esta IP y péguenla en su navegador");




  server.on("/Button", HTTP_GET, handleButtonRequest); //Cuando estemos en la página Button, llamamos a la función handleButtonRequest y le 
  server.on("/", handleRoot);      //Which routine to handle at root location
  
  // Set up web server
  server.onNotFound([]() {
    handleRoot();
  });

  server.begin();
  Serial.println("Web server started");
}

void handle_client(void) {
  server.handleClient();
}
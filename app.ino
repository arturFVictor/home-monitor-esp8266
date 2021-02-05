//diagrama UML : https://cdn.discordapp.com/attachments/766307816016838656/804046263267229746/unknown.png
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//template < class Type, class Alloc = allocator<T> > class list;

using std::string;
using std::list; 

ESP8266WebServer server(80);

class Componente{
  public:
    //Construtor
    Componente(std::string nome, std::string descricao, int pino){
      setNome(nome);
      setDescricao(descricao);
      setPino(pino);
}

    //Pino
    void setPino(int pino);
    int getPino();

    //Nome
    void setNome(std::string nome);
    std::string getNome();
    
    //Descricao
    void setDescricao(std::string descricao);
    std::string getDescricao();

  private:
    int _pino;
    bool _estado;
    std::string _nome;
    std::string _descricao;
};

void Componente::setPino(int pino){
  _pino = pino;
}

int Componente::getPino(){
  return _pino;
}

void Componente::setNome(std::string nome){
  _nome = nome;
}

void Componente::setDescricao(std::string descricao){
  _descricao = descricao;
}

std::string Componente::getDescricao(){
  return _descricao;
}

class ComponenteLED: public Componente {
  public:   
    ComponenteLED(std::string nome, std::string descricao, int pino)
    :Componente(nome, descricao, pino){
    };
    void setEstado(bool estadoLED);
    bool getEstado();

  private:
    bool _estadoLED = false;
};

void ComponenteLED::setEstado(bool estadoLED){
  _estadoLED = estadoLED;
}

bool ComponenteLED::getEstado(){
  return _estadoLED;
}

class ComponenteSensorTemperatura: public Componente{
  public:
    ComponenteSensorTemperatura(std::string nome, std::string descricao, int pino)
    :Componente(nome, descricao, pino){};
    float getTemperatura(); 
    
  private:
    float _temperatura;
};

float ComponenteSensorTemperatura::getTemperatura(){
  return _temperatura;
}

void setup(){
  Serial.begin(9600);

  WiFi.enableInsecureWEP(true);

  char* ssid = "";
  char* pw = "";
  
  WiFi.begin(ssid, pw);
  
  delay(5000);
  
  Serial.println("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(WiFi.status());
    delay(2000);
  }

  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  
  server.begin();

  std::list<Componente> componentes = {};

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);
}

void loop(){
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/plain", "servidor ta vivo");
}

void handleNotFound(){
  server.send(404, "text/html", "404: <a href='https://www.youtube.com/watch?v=2ZIpFytCSVc&ab_channel=JameBenedict'>bruh</a>"); 
}


/*
Rotas

LED

Cadastrar LED
Remover LED
Acender/Apagar LED
Editar LED

SENSOR

Cadastrar SENSOR
Remover SENSOR
Pegar Dados SENSOR
Editar SENSOR

BD

Retorna a lista completa
*/

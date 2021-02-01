//diagrama UML : https://cdn.discordapp.com/attachments/766307816016838656/804046263267229746/unknown.png
#include <algorithm>
#include <iostream>
#include <string>
#include <list>

//template < class Type, class Alloc = allocator<T> > class list;

using std::string;
using std::list; 

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
  std::list<Componente> componentes = {};

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  digitalWrite(LED_BUILTIN, LOW);

  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
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

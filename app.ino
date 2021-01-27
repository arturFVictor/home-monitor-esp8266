//diagrama UML : https://cdn.discordapp.com/attachments/766307816016838656/804046263267229746/unknown.png
//implementar lista no codigo
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using std::string;

class Componente{
  public:
    //Construtor
    Componente(std::string nome, std::string descricao, int pino);

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

Componente::Componente(std::string nome, std::string descricao, int pino){
  setNome(nome);
  setDescricao(descricao);
  setPino(pino);
}

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
    ComponenteLED(std::string nome, std::string descricao, int pino);
    void setEstado(bool estadoLED);
    bool getEstado();

  private:
    bool _estadoLED = false;
};

ComponenteLED::ComponenteLED(std::string nome, std::string descricao, int pino)
{
    setNome(nome);
    setDescricao(descricao);
    setPino(pino);
}
void ComponenteLED::setEstado(bool estadoLED){
  _estadoLED = estadoLED;
}

bool ComponenteLED::getEstado(){
  return _estadoLED;
}

class SensorTemperatura: public Componente{
  public:
    float getTemperatura(); 
    
  private:
    float _temperatura;
};

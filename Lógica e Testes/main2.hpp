
#include<string>
using namespace std;

struct comando{

  string operacao;
  string opcode;
  string operador1;
  string operador2;
  string resultado;
  string pula_para;
  int dependencia;
  bool executa;
  int ciclo_inicia;
  int ciclo_termina;
};

int n_instrucoes;

comando *linha;

void leitura();

void dependencias();
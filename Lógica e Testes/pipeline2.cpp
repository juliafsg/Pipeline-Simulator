
#include<iostream>
#include<string>

using namespace std;

struct comando{

//TO DO zerar os valores das strings
	string operacao;
	string opcode;
	string operador1;
	string operador2;
	string resultado;
	comando *pula_para;
	int *dependencia;
	bool executa;
	int ciclo_inicia;
	int ciclo_termina;
}

struct ciclo {

	string IF;
	string ID;
	string EX;
	string MEM;
	string WB;
}

int main() {

	ciclo *num_ciclo;//aponta para o ciclo
	
	string codigo; // guarda todo o codigo

//ler  o codigo

	cin << codigo;





//determinar a ordem que são executadas

	//percorre as instrucoes

		//verifica se tem um bne , beq ou jump

			//da linha onde tem o pulo, ate a linha que o pula_para do pulo aponta , nada sera executado. exclui essas linhas trazendo as da frente para o lugar dela 










//percorrer os ciclos

//montar o pipeline sem considerar as dependencias

	// ciclo[j].IF tera instrucao[j].operacao
	// ciclo[j+1].ID tera instrucao[j].operacao
	// ciclo[j+2].EX tera instrucao[j].operacao
	// ciclo[j+3].MEM tera instrucao[j].operacao
	// ciclo[j+4].WB tera instrucao[j].operacao
	
//percorre as instrucoes

 //diz as posicoes sem considerar as dependencias

  //instrucao[i].Ciclo_inicia tera como inicio o ciclo i 
  //instrucao[i].ciclo_termina tera como fim o ciclo i+4 	


//percorrer instrucoes

//verificar a partir da linha[2] se tem alguma dependencia de dados

	//pega o maior valor do label.

		//o fim do label  passa ser o inicio da linha que depende do label
					j=linha[i].fim
					

					// ciclo[linha[i].].IF tera instrucao[j].operacao
					// ciclo[j+1].ID tera instrucao[j].operacao
					// ciclo[j+2].EX tera instrucao[j].operacao
					// ciclo[j+3].MEM tera instrucao[j].operacao
					// ciclo[j+4].WB tera instrucao[j].operacao

		//percorre todas as instrucoes

			//inicio e o fim de cada uma das proximas instrucoes (de i+1 até o fim)	aumenta em inicio da label - i	




 	





	return 0;

}
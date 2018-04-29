
#include<iostream>
#include<string>
#include<cstring>
#include"main.hpp"
using namespace std;


void leitura(){
	
  int n_instrucoes; //número de instruções
 

	cout <<"Quantas instruções tem seu código?"<< endl;
	cin >> n_instrucoes;

	n_instrucoes++;
	comando linha[n_instrucoes]; //incializa as instruções
	
  	//ler  o codigo
  	cout <<"Digite seu código:"<< endl;
  	for (int i=0; i<n_instrucoes; i++){
  		getline(cin, linha[i].operacao);
	}

	//separa opcode
	for(int i = 0; i <n_instrucoes; i++){
		int p1;
		p1 = linha[i].operacao.find(" ", 0);
		linha[i].opcode = linha[i].operacao.substr(0, p1);
	}

	//Separando os operandos
	for(int i = 1; i <= n_instrucoes; i++){
		if(linha[i].opcode == "sub" || linha[i].opcode =="add"){ //Caso seja sub ou add
			int p1,p2,p3,p4;
			p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].resultado = linha[i].operacao.substr(p1+1, p2-p1);
   			p3 = linha[i].operacao.find(" ", p2+1);
   			linha[i].operador1 = linha[i].operacao.substr(p2+1, p3-p2);
   			p4 = linha[i].operacao.find(" ", p3+1);
   			linha[i].operador2 = linha[i].operacao.substr(p3+1, p4-p3);

   		} 	

   		else if(linha[i].opcode == "lw"){ //caso seja lw
   			int p1,p2,p3;
   			p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].resultado = linha[i].operacao.substr(p1+1, p2-p1);
   			p3 = linha[i].operacao.find(" ", p2+1);
   			linha[i].operador1 = linha[i].operacao.substr(p2+1, p3-p2);
   		}


   		else if(linha[i].opcode == "bne" || linha[i].opcode =="beq"){//caso seja bne ou beq
   			int p1,p2,p3,p4;
   			p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].operador1 = linha[i].operacao.substr(p1+1, p2-p1);
   			p3 = linha[i].operacao.find(" ", p2+1);
   			linha[i].operador2 = linha[i].operacao.substr(p2+1, p3-p2);
   			p4 = linha[i].operacao.find(" ", p3+1);
   			linha[i].pula_para = linha[i].operacao.substr(p3+1, p4-p3);
   		}

		else if(linha[i].opcode == "sw"){ //caso seja sw
   		   	int p1,p2,p3;
   		   	p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].operador1 = linha[i].operacao.substr(p1+1, p2-p1);
   			p3 = linha[i].operacao.find(" ", p2+1);
   			linha[i].resultado = linha[i].operacao.substr(p2+1, p3-p2);
   		}

   		else if(linha[i].opcode == "j"){ //caso seja jump
   		   	int p1,p2;
   		   	p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].pula_para = linha[i].operacao.substr(p1+1, p2-p1);
   		}	

   	}	
					
}
	
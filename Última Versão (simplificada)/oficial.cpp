#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

struct comando{

  string operacao;
  string opcode;
  string operador1;
  string operador2;
  string resultado;
  string pula_para;
  int dependencia=0;
  bool executa = true;
  int ciclo_inicia =0;
  int ciclo_termina=0;
};

struct ciclo{

	string IF;
	string ID;
	string EX;
	string MEM;
	string WB;
};

int main(){
//LEITURA
	int n_instrucoes;

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
	for(int i = 1; i <n_instrucoes; i++){
		int p1;
		p1 = linha[i].operacao.find(" ", 0);
		linha[i].opcode = linha[i].operacao.substr(0, p1);
	}

	//Separando os operandos
	for(int i = 1; i < n_instrucoes; i++){
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
   			int p1,p2,p3,p4;
   			p1 = linha[i].operacao.find("(", 0);
			p2 = linha[i].operacao.find(")", p1+1);
			p3 = linha[i].operacao.find(" ", p2+1);
   			linha[i].resultado = linha[i].operacao.substr(p1+1, p2-p1-1);
   			p4 = linha[i].operacao.find(" ", p3+1);
   			linha[i].operador1 = linha[i].operacao.substr(p3+1, p4-p3);
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
   		   	int p1,p2,p3,p4;
   		   	p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].operador1 = linha[i].operacao.substr(p1+1, p2-p1);
   			p3 = linha[i].operacao.find("(", p2+1);
   			p4 = linha[i].operacao.find(")", p3+1);
   			linha[i].resultado = linha[i].operacao.substr(p3+1, p4-p3-1);
   		}

   		else if(linha[i].opcode == "j"){ //caso seja jump
   		   	int p1,p2;
   		   	p1 = linha[i].operacao.find(" ", 0);
			p2 = linha[i].operacao.find(" ", p1+1);
   			linha[i].pula_para = linha[i].operacao.substr(p1+1, p2-p1);
   		}	

   	}	


//EXCLUIR APOS O JUMP

	for(int i = 1; i <n_instrucoes; i++){
		
		if(linha[i].opcode == "bne" || linha[i].opcode == "j" || linha[i].opcode == "beq"){

			int v;	
			char u[1];
			u[0] = linha[i].pula_para[0];		
			v = atoi(u);
	
			for(int j = i+1 ; j<v; j++){

				linha[j].executa = false;
				

			}
		}
	}
	

	
	for(int i = 1; i <n_instrucoes; i++){
		
		if(linha[i].executa == false){

			for(int j = i; j<n_instrucoes-1;j++){

				linha[j].operacao = linha[j+1].operacao;
  				linha[j].opcode= linha[j+1].opcode;
  				linha[j].operador1 = linha[j+1].operador1;
  				linha[j].operador2 = linha[j+1].operador2;
  				linha[j].resultado = linha[j+1].resultado;
  				linha[j].pula_para = linha[j+1].pula_para;
  				linha[j].dependencia = linha[j+1].dependencia;
				linha[j].executa = linha[j+1].executa;
				linha[j].ciclo_inicia = linha[j+1].ciclo_inicia;
				linha[j].ciclo_termina = linha[j+1].ciclo_termina;

			}
		n_instrucoes --;
		}
	}

	
	

//DEPENDENCIAS

   	for(int i = 1; i < n_instrucoes; i++){

		for(int j = 1; j<i ; j++){

			//BEQ E BNE
			if (linha[j].opcode!= "sw"){

				if (linha[i].opcode== "beq" || linha[i].opcode == "bne"){//se for do tipo beq ou bne

					if(linha[i].operador1 == linha[j].resultado || linha[i].operador2 == linha[j].resultado) {

						linha[i].dependencia = i;
					}
				}

				else if (linha[i].opcode == "add" || linha[i].opcode == "sub"){ //se for add ou sub

					if (linha[i].operador1 == linha[j].resultado || (linha[i].operador2 == linha[j].resultado) ){ 

						linha[i].dependencia = j; // Adiciona a linha como dependencia
				    }	
				}	

				else if (linha[i].opcode == "sw"){ //se for add ou sub

					if (linha[i].operador1 == linha[j].resultado || (linha[i].resultado == linha[j].resultado) ){ 

						linha[i].dependencia = j; // Adiciona a linha como dependencia	
					}	
				}	

				else if (linha[i].opcode == "lw"){ //se for add ou sub

					if (linha[i].operador1 == linha[j].resultado || (linha[i].resultado == linha[j].resultado) ){ 

						linha[i].dependencia = j; // Adiciona a linha como dependencia	
					}	
				}	
			}

			else if (linha[j].opcode == "sw"){

				if (linha[i].opcode == "lw"){
					string x,y;
					int p1,p2;
					p1 = linha[i].operacao.find(" ", 4);
					p2 = linha[i].operacao.find(" ",p2+1);
					x = linha[i].operacao.substr(p1, p2-p1);

					int p3,p4;
					p3 = linha[j].operacao.find(" ", 4);
					p4 = linha[j].operacao.find(" ", p3+1);
					y = linha[j].operacao.substr(p3, p4-p3);


					if (x==y){

						linha[i].dependencia = j;
					}
				}
			}
		}
	}



//MONTAR O PIPELINE

	//Sem dependencias

	for(int i=0; i<n_instrucoes;i++){

		linha[i].ciclo_inicia = i;
		linha[i].ciclo_termina = i+4;

	}
	
	//Ajustar dependencias

	for(int i=0; i<n_instrucoes;i++){

		if(linha[i].dependencia != 0){

			int z;
			z = linha[i].dependencia;

			if(linha[i].ciclo_inicia < linha[z].ciclo_termina){

				linha[i].ciclo_inicia = linha[z].ciclo_termina;
				linha[i].ciclo_termina=linha[i].ciclo_inicia+4;  

				for(int j=i; j<n_instrucoes;j++){
				
					linha[j+1].ciclo_inicia = linha[j].ciclo_inicia+1;
					linha[j+1].ciclo_termina = linha[j+1].ciclo_inicia+4; 
				}	
			}

		}
	}
	int x = n_instrucoes-1;
	int apoio = linha[x].ciclo_termina;
	apoio++;
	ciclo c[apoio];
	int n_ciclos;
	n_ciclos = apoio;

	for(int i=1;i< n_ciclos;i++){

		for (int j =1; j< n_instrucoes; j++){

			if(linha[j].ciclo_inicia == i){

				c[i].IF = linha[j].operacao;
				c[i+1].ID = linha[j].operacao;
			 	c[i+2].EX = linha[j].operacao;
				c[i+3].MEM = linha[j].operacao;
				c[i+4].WB = linha[j].operacao;
			}
		}
	}

	
	cout<<endl<<"PIPELINE "<<endl; 
	cout<<endl<<"Total de Ciclos: "<< n_ciclos-1<<endl; 	
	
	for(int i =1; i< n_ciclos; i++){
		cout << "\n----------------\nCiclo " << i;
		cout << "\nIF: "<<c[i].IF;
		cout << "\nID: "<<c[i].ID;
		cout << "\nEX: "<<c[i].EX;
		cout << "\nMEM: "<<c[i].MEM;
		cout << "\nWB: "<<c[i].WB;
		cout<<endl;

	}	

	//cout<<endl<< linha[2].ciclo_inicia;
	//cout<<endl<<linha[2].dependencia;
	//cout<<endl<< linha[2].ciclo_termina;

	//cout<<endl<< linha[3].ciclo_inicia;
	//cout<<endl<< linha[3].ciclo_termina;

	//cout<<endl<< apoio;


		
	return 0;
}

#include<iostream>
#include<string>
//#include <vector>



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
  int n_instrucoes;
  string codigo; // guarda todo o codigo

//ler  o codigo

  std::cout<<"Digite seu código:"<<std::endl;
  std::cin.get(codigo);


  std::cout<<"Quantas instruções tem seu código?"<<std::endl;
  std::cin << n_instrucoes;
  
  
  comando linha[n_instrucoes];
	
  int p = 0;// guarda a posicao no codigo
	int z = 0; //guarda a label da instrução
	int f = 0; //guarda o fim do conjunto de carqacteres e inicio do proximo
	int ii = 0; //guarda inicio da instrucao


for(int i = 0; i <= sizeof(codigo); i++){



//Quando estivermos na 1a parte p=0 que vai se referir instrucao
//Apos o primeiro espaco p =1
//apos o terceiro p =2
//apos o quarto p =3


	if (p == 0){//quando estivermos nos primeiros caracteres

		//quando tivermos um espaço, descobrimos o opcode

  		if (codigo[i] == ' '){

  			for(int h =0; h<i ;h++){

   				linha[z].opcode += codigo[h]; //guardar o opcode  de 0 a i-1
   			}	
  			p = 1; // muda para apos os caracteres	
  			f = i; //guarda o fim
  			z++;//ja foi uma instrucao
  		}

  	}

 	

  	if(p == 1){//quando estivermos nos segundos caracteres

  		if (codigo[i] == ' '){

   			//caso a opcode seja sub ou add ou lw

  					//adicionar os  caracteres do fim da primeira parte (f+1) ate o fim da segunda(i-1) como resultado

  					p = 2; // muda para apos os segundo conjunto de caracteres
  					f = i;//guarda o fim	

			//caso a opcode seja bne ou beq ou sw

  					//adicionar os  caracteres do fim da primeira parte (f+1) ate o fim da segunda(i-1) como operador1

  					p = 2; // muda para apos os segundo conjunto de caracteres	
  					f = i; //guarda o fim

			//caso a opcode seja jump

				//adiciona os proximos caracteres como pula_para

  		}	

 
    }

	if(p == 2){//quando estivermos no terceiro conjunto de caracteres 

  		if (codigo[i] == ' '){

  			//caso a opcode seja sub ou add ou lw

 			//adicionar os  caracteres do fim da segunda parte (f+1) ate o fim da terceira (i-1) como operador 1 

 				p=3;	
 				f=i;


			//caso a instrucao seja bne ou beq ou sw

  			//adicionar os  caracteres do fim da segunda parte (f+1) ate o fim da terceira (i-1) como operador 2	
				
				p=3;	
				f=i;	

    	}

  		else if(codigo[i]=='\n'){

  			for(int h = ii ; h < f ;h++){

   				linha[z].operacao += codigo[h]; //guardar o opcode  de 0 ao fim f
   			}	

   			ii=i+1;
  			p = 0;
  			f=i;
  		} 	

	}


	if(p == 3){//quando estivermos no quarto conjunto de caracteres 

  		if (codigo[i] == ' '){

  			//caso a instrucao seja sub ou add

  				//adicionar os  caracteres do fim da terceira parte (f+1) ate o fim da quarta (i-1) como operador 2

  			p = 4;
  			f=i;


			//caso a instrucao seja bne ou beq
				
				//adicionar os  caracteres do fim da terceira parte (f+1) ate o fim da quarta (i-1) como pula_para	

  			p = 4;
  			f=i;

    	}

  		else if(codigo[i]=='\n'){


  			for(int h = ii; h<f ;h++){

   				linha[z].operacao += codigo[h]; //guardar o opcode  de 0 ao fim f
   			}

   			ii=i+1;
  			p = 4;
  			f = i;
  		} 	

  	if (p==4){ // Guarda as instrucoes anteriores completas como linha.operacao

  		for(int h = ii; h<f ;h++){

   			linha[z].operacao += codigo[h]; //guardar o opcode  de 0 ao fim f
   			
   			}	

  			p = 0;

  	}	

	}

}
}
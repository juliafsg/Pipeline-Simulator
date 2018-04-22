
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
	comando *linha; //TO DO : alocação com new // aponta para a linha do comando
	string codigo; // guarda todo o codigo

//ler  o codigo

	cin << codigo;


	int p = 0;// guarda a posicao no codigo
	int z = 0; //guarda a label da instrução
	int f = 0; //guarda o fim do conjunto de carqacteres e inicio do proximo
	int ii = 0; //guarda inicio da instrucao
for(int i = 0; i < strlen(codigo); i++){


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




//determinar a ordem que são executadas

	//percorre as instrucoes

		//verifica se tem um bne , beq ou jump

			//da linha onde tem o pulo, ate a linha que o pula_para do pulo aponta , nada sera executado. exclui essas linhas trazendo as da frente para o lugar dela 





//verificar as dependencias


	int k = 0; //contador das dependencias

	for (int i = total_Linhas; i>0; i--){ //percorre do ultimo elemento

		for (int j = total_linhas-1; j<0; j--){ //verifica com todos acima



				//BEQ E BNE

				if (linha[i].opcode== 'beq' || linha[i].opcode == 'bne'){//se for do tipo beq ou bne

					//verifica se os operandos sao alterados acima

					//adiciona a linha como dependencia


				}		

				//ADD E SUB
					
				if (linha[i].opcode == 'add' || linha[i].opcode == 'sub'){ //caso a instrucao seja do tipo add ou do tipo sub 

					if (linha[i].operador1 == linha[j].resultado || (linha[i].operador2 == linha[j].resultado) ){ // verifica se os operandos recebem algum valor anteriormente pelo resultado

						linha[i].dependencia[k] = j; // Adiciona a linha como dependencia

						k++;

					}
	  				
	     		}

			}

			if (linha[i].opcode == 'jump'){ // se for do tipo jump


				//dependencia = nao existe

			}	

			if (linha[i].opcode == 'sw'){

				//dependencia do operador 1
			}
		
			if (linha[i].opcode == 'lw'){}

				//nao tem dependencia

		
	}



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

				//o inicio da label - i onde ela estava ante é o deslocamente feito

		//percorre todas as instrucoes

			//inicio e o fim de cada uma das proximas instrucoes (de i+1 até o fim)	aumenta em inicio da label - i	




 	





	return 0;

}
#include<iostream>
#include<string>
#include"main.hpp"
using namespace std;


void dependencias(){

	for(int i =1; i <= n_instrucoes; i++){

		for(int j = 1; j<i ; j++){

			//BEQ E BNE

			if (linha[i].opcode== 'beq' || linha[i].opcode == 'bne'){//se for do tipo beq ou bne

				if(linha[i].operador1 == linha[j].resultado || linha[i].operador2 == linha[j].resultado) {

					linha[i].dependencia = i;
				}

			}	

		}


	}





}


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
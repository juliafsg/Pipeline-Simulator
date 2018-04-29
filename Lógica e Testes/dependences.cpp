#include<iostream>
#include<string>
#include"main.hpp"
using namespace std;


void dependencias(){

	for(int i =1; i <= n_instrucoes; i++){

		for(int j = 1; j<i ; j++){

			//BEQ E BNE

			if (linha[i].opcode== "beq" || linha[i].opcode == "bne"){//se for do tipo beq ou bne

				if(linha[i].operador1 == linha[j].resultado || linha[i].operador2 == linha[j].resultado) {

					linha[i].dependencia = i;
				}
			}	
		}
	}
}	
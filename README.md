# Simulador de Pipeline
Repositório dedicado a criação de um simulador de pipeline em 5 etapas: IF, ID, EX, MEM, WB. 

-> O programa recebe um código em Assembly e retorna para cada ciclo as instruções que estão sendo executadas e em que etapa ela se encontra.

-> É considerada uma arquitetura do tipo Harvard, logo não existe dpendência estrutural do acesso a memória.

-> Os saltos promovidos pelas funções BEQ, BNE ou JUMP serão sempre tomados.

-> As dependências de dados são levadas em consideração. 

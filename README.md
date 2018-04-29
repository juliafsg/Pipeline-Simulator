# Simulador de Pipeline
Repositório dedicado a criação de um simulador de pipeline em 5 etapas: IF, ID, EX, MEM, WB. 

-> O programa recebe um código em Assembly e retorna para cada ciclo as instruções que estão sendo executadas e em que etapa ela se encontra.

-> É considerada uma arquitetura do tipo Harvard, logo não existe dpendência estrutural do acesso a memória.

-> Os saltos promovidos pelas funções BEQ, BNE ou JUMP serão sempre tomados.

-> As dependências de dados são levadas em consideração. 

-> Para compilar o código basta digitar o comando : g++ -o pipeline-simulator oficial.cpp

-> Ao escrever o codigo em Assembly você deve:
    a) Digitar uma instrução, depois dê  enter e então digitar a próxima instrução;
    b) O opcode e operandos são separados apenas por um espaço exemplo:
          add $s1 $s3 $s2
    c) e as funçoes que acessam a memória devem ser escritas sem espaçoes após o parenteses seguindo o exemplo:
          lw 10($s1) $s2
    d) o mesmo serve para as funçoes de salto, que além de seguir o modelo de espaçamento, terão como label o número da instrução que deseja saltar;
          
          

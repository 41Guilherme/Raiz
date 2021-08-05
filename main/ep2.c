/* 
PROFESSOR: FLAVIO LUIZ COUTINHO
MATÉRIA: Introdução a Programação (IP)
CURSO: SI - 1º SEMESTRE 
ALUNO: GUILHERME JOSÉ DA SILVA NASCIMENTO 
NºUSP: 12543252
EP: 2
*/

#include <stdio.h>

void verefica(double* x, double* epsilon);
int raizQuadrada(double* x, double* epsilon);
double mod(double a);

int main(){ //Função principal que resgata as outras funções para mostrar os resultados na tela 
    double x, epsilon_r;
    printf("\n\n\tCalcular Raiz Quadrada de \"n\" com precisao \"epsilon\"\n");
    printf("\nNumero de Interacoes: %d",raizQuadrada(&x,&epsilon_r));
    printf("\nDiferenca absoluta: %lf",epsilon_r);
    printf("\nRaiz quadrada: %lf\n\n",x);

    return 0;
}

int raizQuadrada(double* x, double* epsilon_r){
    int i = 0;                  //Contador de interacoes
    double n , epsilon;
    double a = 0.0 , b;         //O "a" sera o chao e o "b" será o teto do intervalo
    verefica(&n , &epsilon);     //Valores de precisao e o resultado da raiz serao fornecidos pelo usuario ao entrar nesta funcao
    *x = n / 2;                 //e dado o primeiro valor a "x" antes do while 
    *epsilon_r = mod(*x * *x - n);      //Calcula a diferenca |x*x - n| = epsilon_r  (r para no final indica que este sera o resultado imprimido no main)
    while(*epsilon_r >= epsilon){   // Aplica o método da bissecção durante a repetição 
        if (*x * *x < n)
            a = *x;
        else    
            b = *x;
        *x = (a + b) / 2;  // valor da raiz quadrada ao fim da ultima repetição
        i = i + 1;
        *epsilon_r = mod(*x * *x - n); // valor da diferença absoluta ao fim da ultima repetição 
    }
    return i + 1; // retorna o número de interações 
}

void verefica(double* x , double* epsilon){  //Função que verefica os sinais e realiza o scanf 
    printf("\nInsira um Valor para n: ");
    while(1){ 
        scanf("%lf",x);
        if(*x < 0.0){

            printf("\nValor Incorreto informe novamente:  ");
            continue;

            }
        break;
    }
    printf("Insira um Valor para epsilon: ");
    while (1){
        scanf("%lf",epsilon);
        if(*epsilon <= 0.0){ 

            printf("\nValor Incorreto informe novamente:  ");
            continue;

            }
        break;
    }
}

double mod(double a){   //Função para aplicar módulo de um número  
    if(a >= 0.0) return a;
    else        return -a;
}

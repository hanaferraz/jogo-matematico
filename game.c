#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta,Calcular calc);
int diminuir(int resposta,Calcular calc);
int multiplicar(int resposta,Calcular calc);

int pontos = 0;

int main(){
	jogar();
	return 0;
}
void jogar(){
	Calcular calc;
	int dificuldade;

	printf("Informe o nivel de dificuldade desejado [1 ,2 ,3 ou 4]:\n");
	scanf("%d",&dificuldade);
	calc.dificuldade = dificuldade;

	calc.operacao = rand() % 3;

	if(calc.dificuldade ==1){
		//fácil
		calc.valor1 = rand() % 11;
		calc.valor2 = rand() % 11;
	}else if(calc.dificuldade == 2){
		//média
		calc.valor1 = rand() % 101;
		calc.valor2 = rand() % 101;
	}else if(calc.dificuldade == 3){
		//difícil
		calc.valor1 = rand() %1001;
		calc.valor2 = rand() %1001;
	}else if(calc.dificuldade == 4){
		//insano
		calc.valor1 = rand() %10001;
		calc.valor2 = rand() %10001;
	}else{
		calc.valor1 = rand() %1000001;
		calc.valor2 = rand() %1000001;
	}
	int resposta;
	printf("Informe o resultado para a seguinte operação\n");

	if(calc.operacao ==0){
		printf("%d + %d",calc.valor1,calc.valor2);
		scanf("%d",&resposta);

		if(somar(resposta,calc)){
			pontos += 1;
			printf("Você tem %d pontos!\n",pontos);
		}
	}//diminuir
	else if(calc.operacao ==1){
		printf("%d - %d",calc.valor1,calc.valor2);
		scanf("%d",&resposta);

		if(diminuir(resposta,calc)){
		pontos += 1;
		printf("Você tem %d pontos!\n",pontos);
	 }
   }//multiplicar
	else if(calc.operacao ==2){
		printf("%d * %d",calc.valor1,calc.valor2);
		scanf("%d",&resposta);

		if(multiplicar(resposta,calc)){
		pontos += 1;
		printf("Você tem %d pontos!\n",pontos);
		}
	}else {
		printf("A opereação não é reconhecida");
	}
	//recomeçar o jogo
	printf("Deseja continuar jogando ?[1 - sim , 0 - não]\n");
	int continuar;
	scanf("%d",&continuar);

	if(continuar ==1){
		jogar();
	}else{
		printf("Você finalizou com %d pontos\n",pontos);
	    printf("Até a próxima :)");
	    exit(0);
	}
}

void mostrarInfo(Calcular calc){
	char op[25];

	if(calc.operacao == 0){
		sprintf(op, "Somar");
	}else if(calc.operacao == 1){
		sprintf(op, "Diminuir");
	}else if(calc.operacao == 2){
		sprintf(op, "Multiplicar");
	}else{
		sprintf(op, "Operaçao desconhecida");
	}
	printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s",calc.valor1,calc.valor2,
			calc.dificuldade,op);
}

int somar(int resposta,Calcular calc){
	int resultado = calc.valor1 + calc.valor2;
	calc.resultado = resultado;
	int certo = 0;
	if(resposta == calc.resultado){
		printf("Resposta correta!!\n");
		certo = 1;
	}else{
		printf("Resposta errada!\n");
	}
	printf("%d + %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
}

int diminuir(int resposta,Calcular calc){
	int resultado = calc.valor1 - calc.valor2;
		calc.resultado = resultado;
	int certo = 0;
	if(resposta == calc.resultado){
		printf("Resposta correta!!\n");
			certo = 1;
	}else{
		printf("Resposta errada!\n");
	}
	printf("%d - %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
}

int multiplicar(int resposta,Calcular calc){
	int resultado = calc.valor1 * calc.valor2;
	calc.resultado = resultado;
	int certo = 0;
	if(resposta == calc.resultado){
		printf("Resposta correta!!\n");
		certo = 1;
	}else{
		printf("Resposta errada!\n");
	}
		printf("%d * %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
}

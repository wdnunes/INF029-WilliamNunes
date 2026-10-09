// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {

    int i = 0, j = 0;
    int datavalida = 1;
    //char data[11];
    DataQuebrada d = {0,0,0};
    char temp[5];

    while(data[i] != '/' && data[i] != '\0' && j < 4) { 
        temp[j] = data[i];
        j++;
        i++;
    }
    temp[j] = '\0';
    d.iDia = atoi(temp);

    if(data[i] == '/') {
        i++;
    }

    j = 0;
    while(data[i] != '/' && data[i] != '\0' && j < 4) { 
        temp[j] = data[i];
        j++;
        i++;
    }
    temp[j] = '\0';
    d.iMes = atoi(temp);

    if(data[i] == '/') {
        i++;
    }

    j= 0;
    while(data[i] != '\0' && j < 4) { 
        temp[j] = data[i];
        j++;
        i++;
    }
    
    temp[j] = '\0';
    d.iAno = atoi(temp);
    
    if (d.iAno >= 0 && d.iAno <= 99) {
        d.iAno += 2000;
    }
    
    if(d.iAno < 1 || d.iAno > 9999) { 
        datavalida = 0;
    }
    
    int diaMes;
    if(d.iMes < 1 || d.iMes > 12) { 
        datavalida = 0;
    } else {  
        switch(d.iMes) {
            case 2:
                if((d.iAno % 4 == 0 && d.iAno % 100 != 0) || (d.iAno % 400 == 0)) {
                    diaMes = 29;
                } else {
                    diaMes = 28;
                }
            break;
            case 4:
            case 6:
            case 9:
            case 11:
                diaMes = 30;
            break;
            default:
                diaMes = 31;
            break;
        }
        if(d.iDia > diaMes || d.iDia < 1) {
            datavalida = 0;   
        }
    }

    if (datavalida)
        return 1;
    else
        return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      int idataInicial = 0, idataFinal = 0;
      int i = 0, j = 0;
      char temp[11];

      DataQuebrada dpInicial = quebraData(datainicial);
      DataQuebrada dpFinal = quebraData(datafinal);

      idataInicial =  (dpInicial.iAno * 1000000) + (dpInicial.iMes * 10000) + (dpInicial.iDia);
      idataFinal =  (dpFinal.iAno * 1000000) + (dpFinal.iMes * 10000) + (dpFinal.iDia);
      
      if(idataInicial > idataFinal) {
        dma.retorno = 4;
        return dma;
      }
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{   
    int qtdOcorrencias = -1, tam = 0, i = 0, j = 0;
    char textoTemp[250];
    while(texto[tam] != '\0') {
        tam++;
    }

    while(i < tam) {
        textoTemp[i] = texto[i];
        i++;
    }
    textoTemp[i] = '\0';
    //printf("Frase Antes: %s\n", texto);
    if(isCaseSensitive != 1) {
        i = 0;
        if(c >= 'A' && c <= 'Z') {
            c += 32;
        }

        while(i < tam) {
            if(textoTemp[i] >= 'A' && textoTemp[i] <= 'Z') {
                textoTemp[i] += 32;
            }
            i++;
        }
    }

    qtdOcorrencias = 0;
    for(i = 0; i < tam; i++) {
        if(textoTemp[i] == c) {
            qtdOcorrencias++;
        }  
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;
    int tamBusca = 0, tamTexto = 0, i = 0, j = 0, k = 0;
    int inicial, final, pos = 0;
    while(strBusca[tamBusca] != '\0'){
        tamBusca++;
    }

    while(strTexto[tamTexto] != '\0'){
        tamTexto++;
    }

    if (tamBusca == 0 || tamBusca > tamTexto) {
        return 0;
    }

    qtdOcorrencias = 0;
    int limite = tamTexto - tamBusca + 1;
    int charCount = 1;

    while(strTexto[i] != '\0' && i < limite) {
        
        if ((unsigned char)strTexto[i] < 0x80 || (unsigned char)strTexto[i] >= 0xC0) {
            
            j = i;
            k = 0;
            int invalido = 0;

            while(k < tamBusca) { 
                if(strTexto[j] != strBusca[k]) {
                    invalido = 1;
                }
                if(k == 0) {
                    inicial = charCount; 
                }
                if(k == (tamBusca - 1)) {
                    final = charCount + tamBusca - 1; 
                }
                k++;
                j++;
            }

            if(invalido == 0) {
                posicoes[pos] = inicial;
                pos++;
                posicoes[pos] = final;
                pos++;
                qtdOcorrencias++;
            }
            
            charCount++;
        }
        i++;
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int i = 0;
    int resto, inverso = 0;

    while(num != 0) {
        resto = num % 10;
        inverso = inverso * 10 + resto;
        num /= 10;
    }

    num = inverso;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;


    
    /*
    
    int i = 0;
    int num, resto;

    num = numerobase;

    while(numerobase != 0) {
        resto = num % 10;
        num /= 10;
        if(resto == numerobusca) {
            qtdOcorrencias++;
        }
    }
    */
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
    int achou, falhou = 1;
    int i = 0, j = 0, tam = 0;

    while(palalvra[tam] != '\0') {
        tam++;
    }
    
    //horizontal de frente para trás
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 10; j++) {
            falhou = 1;
            for(k = j; k < tam + j; k++) {
                if(matriz[i][j] != palavra[k]) { 
                    falhou = 0;
                }
            }
            if(!falhou) {
                achou = 1;
            }
        }    
    }

    //horizontal de trás para frente
    for(i = 0; i < 8; i--) {
        for(j = 0; j < 10; j--) {
            falhou = 1;
            for(k = j; k < tam + j; k++) {
                if(matriz[i][j] != palavra[k]) { 
                    falhou = 0;
                }
            }
            if(!falhou) {
                achou = 1;
            }
        }    
    }

    //vertical de cima para baixo
    if(!achou) {
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 8; j++) {
                falhou = 1;
                for(k = j; k < tam + j; k++) {
                    if(matriz[j][i] != palavra[k]) { 
                        falhou = 0;
                    }
                }
                if(!falhou) {
                    achou = 1;
                }
            }    
        }
    }

    //vertical de baixo para cima
    if(!achou) {
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 8; j++) {
                falhou = 1;
                for(k = j; k < tam + j; k++) {
                    if(matriz[j][i] != palavra[k]) { 
                        falhou = 0;
                    }
                }
                if(!falhou) {
                    achou = 1;
                }
            }    
        }
    }

    //diagonal para cima
    if(!achou) {
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 8; j++) {
                falhou = 1;
                for(k = j; k < tam + j; k++) {
                    if(matriz[j][i] != palavra[k]) { 
                        falhou = 0;
                    }
                }
                if(!falhou) {
                    achou = 1;
                }
            }    
        }
    }

    //diagonal para cima
    if(!achou) {
        for(i = 0; i < 10; i++) {
            for(j = 0; j < 8; j++) {
                falhou = 1;
                for(k = j; k < tam + j; k++) {
                    if(matriz[j][i] != palavra[k]) { 
                        falhou = 0;
                    }
                }
                if(!falhou) {
                    achou = 1;
                }
            }    
        }
    }
    
    return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}


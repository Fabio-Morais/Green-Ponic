#ifndef matrix_lib
#define matrix_lib
#define MatrixSize 30
#include "Message.h"
typedef struct
{
    char str[15];
} linha;

typedef struct
{
    linha l[MatrixSize];	//Numero de linhas que a matrix vair ter
} coluna;

typedef struct
{
    coluna col[MatrixSize];	//Numero de colunas que a matrix vair ter

} Matrix;

typedef struct
{
    char corDeFundo[15];
    char corMoldura[15];
    char corEstufa[15];
    char corSemMote[15];
    char verde[15];
    char vermelho[15];
    char corSala1[15];
    char corSala2[15];
    char corSala3[15];
    char corSala4[15];
    char corMot[15];
    char corExisteAtuador[15];
    char corHeater[15];
    char corValve[15];
    char corLight[15];
    char corSemSala[15];
    char corSensLight[15];
    char corSensTemp[15];
    char corSensHum[15];
    char corSensPh[15];
    char corSensTempLOW[15];
    char corSensTempOK[15];
    char corSensTempHIGH[15];
    char corSensHumLOW[15];
    char corSensHumOK[15];
    char corSensHumHIGH[15];
    char corSensPhLOW[15];
    char corSensPhOK[15];
    char corSensPhHIGH[15];
    char corSensLightLOW[15];
    char corSensLightOK[15];
    char corSensLightHIGH[15];


} cores;

cores cor;

void inicializaCores();
void desenhaMoldura(Matrix *matrix);
void desenhaLimites(Matrix *matrix);
void desenhaFundo(Matrix *matrix);


void imprime(Matrix matrix);


void inicializaTela(Room *room, Matrix *ma);
void adicionaMotsAtuadores(Room *room, Matrix *ma);

#endif

#ifndef Message_lib
#define Message_lib

#define MaxSensors 4
#include "vetor.h"

/*Coloca nas variaveis os bits que interessam*/
typedef struct
{
    char MessageStart[5];
    char MoteId[5];
    int motNumber;
    int motIndice;
    int indiceDiv;
    char PayloadLength[3];
    char RawVoltage[5];
    char RawVisibleLight[5];   /**LUZ**/
    char RawCurrent[5];        /**PH**/
    char RawTemperature[5];    /**TEMPERATURA**/
    char RawHumidity[5];       /**HUMIDADE**/
    char EndMenssage[3];
} Mensagem;
typedef struct{
    char divisao[30];
    int indiceDivisao;
    char sensor[30];
    char atuador[30];
    char operacao[10];
    int valor;
    int num_mot;
    char acao[4];
}Regra;
typedef struct{
    float allMeasurements[2][MaxSensors+1];
    /*FORMATO DA MATRIX allMeasurements*/

    /*  |    0       |     1    | 2  |  3   | -> INDICE
        |temperature | humidity | ph | light| -> VALORES DE MEDI�OES DE CADA SENSOR
        |  1/0       |    1/0   | 1/0|  1/0 | -> 1 ON, 0 OFF   ,  indica se � para incluir o sensor ou nao7
    */
    unsigned int motNumber;

} Medicoes;

typedef struct{
    Medicoes *medi;
    unsigned int numeroMots;//comprimento de mots diferentes, nao repete
    int mots[25];//MOTS existentes na room
    int compMots;//omprimento do vetor MOTS, pode ter mots iguais
    int *motsVec;//vetor de mots igual ao vec
    char **SensorName;
    int compSensor;//comprimento do anterior

    char **ActuadorName;
    unsigned int countActuador;
    unsigned int *ActuadorOnOff;// 1 se tiver on, 0 se tiver off. Segue o mesmo indice que actuadorName
    char *placeName;
} Sensores;

typedef struct{
    Sensores *roomName;
    unsigned int countRoom;
    unsigned int maxMots;
    Regra regra[50];
    int compRegra;
} Room;

/*return do BIT1*/
int organizaSensores(Room *room, char *str, char *condition,  int *posRoom);
int rulesSensores(Room *room, char *str, int *bit0,  int *posRoom);

int rulesAtuadores(Room *room, char *str, int *bit0, int *posRoom);
int operation(int selection, int valor, int sensor, int mot, int posRoom, Room *room);

int mudaRoomNovosValores(Room *room, vetor *vec);
int indiceRoomMotx(Room *room,int mot);
/*
Return -1 se ocorrer erro
return 1 se correr tudo bem
    *vec-> para colocar na struct
*/
int leFicheiroRules(vetor *vec, Room *room);

/*
Toma as decis�es para qual Room vai colocar (RoomName, Sensores, Atuadores)
    Token-> frase que foi usado o strtok
    Count-> serve para sabermos onde enviar a string
    retorna -1 se ocorrer erro
*/
int ToStructMessage(vetor *vec, Room *room, char *token, short *count, int *posRoom);


/*Recebe os tokens e coloca na respetiva variavel
Retorna 1 se tudo correr bem
-1 se falhar o primeiro elemento (45)
-2 se falhar o ultimo
*/
int Control(short count, Mensagem *StructMensagem, char *token);

/*
Confirma a respetiva mensagem
retorna 1 caso corra tudo bem
retorna -1 caso a mensagem lida esteja errada
*/
int ConfirmationMessage(char *str, Mensagem *StructMensagem);

/*Recebe string e converte para decimal*/
float convertToDecimal(char *str);

/*
Aloca memoria e preenche a struct room
allMeasurements[0][n] contem os valores das medi�oes recebeidas no fgets
allMeasurements[1][n] contem os sensores ativos, que foram colocados no sensorconfiguration.txt
*/
void toMedicoes(Room *room, vetor *vec);

/*coloca os atuadores de VEC em ROOM*/
void toActuador(Room *room, vetor *vec);


int pesquisaMot(Room *room, int posRoom, int mot);
int pesquisaSensor(char *sensor);
int pesquisaAtuador(Room *room, int posRoom, char *atuadorName);
/*  Coloca as medi�oes na struct Medicoes
    Coloca 0/1 para saber se o sensor DAQUELA MOT � para usar ou nao
*/
void organizaDados(Room *room, Mensagem *StructMensagem);
float realTemperatureMeasurements(Mensagem *StructMensagem);
float realHumidityMeasurements(Mensagem *StructMensagem);
float realLightMeasurements(Mensagem *StructMensagem);
float realPhMeasurements(Mensagem *StructMensagem);

#endif // Message_lib

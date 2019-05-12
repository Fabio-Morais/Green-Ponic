#include "vetor.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#define debug

/*Retira os espaços que foi colocado acidentalmente*/
void limpaEspacos(char *string)
{

    char* i = string;
    char* j = string;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

int leFicheiroConfiguration(vetor *vec)
{
    const char *filename="SensorConfigurations.txt";
    char buff[MaxBuffer];
    FILE *SensorConviguration;
    SensorConviguration=fopen(filename, "r");
    if(SensorConviguration==NULL)
    {
        printf("Could not open file %s",filename );
        return -1;
    }
    short count=0;
    vec->tamanho=0;

    while(fgets(buff, MaxBuffer, SensorConviguration)!= NULL)
    {
        char* token;
        char* rest = buff;
        char *str=NULL;
        /* walk through tokens */
        while ((token = strtok_r(rest, ":", &rest)))
        {
            str=realloc(str, (strlen(token)+1) * sizeof(char));
            strcpy(str, token);
            upperCase(str);
            ToStruct(vec, str, &count);

        }
        free(str);

    }

    fclose(SensorConviguration);
    return 1;
}


void upperCase(char *str){
    int i=0;
   while(str[i]) {
      str[i]=toupper(str[i]);
      i++;
   }

}

char* strtok_r(char *str, const char *delim, char **nextp)
{
    char *ret;
    if (str == NULL)
        str = *nextp;

    str += strspn(str, delim);

    if (*str == '\0')
        return NULL;

    ret = str;
    str += strcspn(str, delim);

    if (*str)
        *str++ = '\0';

    *nextp = str;
    return ret;
}


void ToStruct(vetor *room, char *token, short *count)
{

    //printf( "\nToken Completo: %s\n", token );
    //printf("\n\tValor do count ToStruct: %d  \n", *count);
    int posRoom=-1;
    limpaEspacos(token);


    switch(*count)
    {
    case 0:
#ifdef debug
        printf("\nRoom Verdadeiro: %s", token);
#endif // debug
        if(Room_tamanho(room)==0)
            vetor_insere_Room(room, token, -1);
        else
        {
            posRoom=vetor_pesquisa(room, token);
            if(posRoom==-1)//nao encontra
                vetor_insere_Room(room, token, -1);
        }

#ifdef debug
        printf("\nRoom: %s", room->elementos[Room_tamanho(room)-1].RoomName);
#endif // debug
        break;
    case 1:
        // ToSensorName(room, token);
        vetor_insere_Sensor(room, token, -1);
#ifdef debug
        printf("\nSensores:\n");
        printf("\n\tNumero de sensores: %d", Sensor_tamanho(room, -1));
        printf("\n\tNumero de Mots: %d\n\n", room->elementos[Room_tamanho(room)-1].CountMots);
        for(int i=0; i<room->elementos[Room_tamanho(room)-1].SensorCount; i++)
            printf("\n %d : %s\tMot:%d",i, room->elementos[Room_tamanho(room)-1].SensorName[i], room->elementos[Room_tamanho(room)-1].IdentMots[i]);
#endif // debug
        break;
    case 2:
        vetor_insere_Actuador(room, token, -1);
#ifdef debug
        printf("\nActuadores:\n");
        for(int i=0; i<room->elementos[Room_tamanho(room)-1].ActuadorCount; i++)
            printf("\n%d : %s",i, room->elementos[Room_tamanho(room)-1].ActuadorName[i]);
#endif // debug
        *count= -1;
        break;
    default:
        printf("Error count");
        break;
    }
    (*count)++;
#ifdef debug
    printf("\n---------------------------------------------------\n");
    system("PAUSE");
    printf("---------------------------------------------------\n");
#endif // debug
}
int vetor_pesquisa_atuador(vetor *vec, int posRoom, char *Name)
{

    for (int i=0; i< vec->elementos[posRoom].ActuadorCount; i++)
        if(!strcmp(Name, vec->elementos[posRoom].ActuadorName[i]))
            return i;

    return -1;
}


vetor* vetor_novo()
{
    vetor* vec;

    /* aloca memoria para a estrutura vetor */
    vec = (vetor*)malloc(sizeof(vetor));
    if(vec == NULL)
        return NULL;

    vec->tamanho = 0;
    vec->capacidade = 0;
    vec->elementos = NULL;

    return vec;
}


int Room_tamanho(vetor* vec)
{
    if(vec == NULL)
        return -1;

    return vec->tamanho;
}

int Sensor_tamanho(vetor* vec, int pos)
{
    if(vec == NULL)
        return -1;

    if(pos==-1)
        pos=vec->tamanho-1;

    return vec->elementos[pos].SensorCount;
}
int Actuador_tamanho(vetor* vec, int pos)
{
    if(vec == NULL)
        return -1;

    if(pos==-1)
        pos=vec->tamanho-1;
    return vec->elementos[pos].ActuadorCount;
}
const char* vetor_room(vetor* vec, int indice)
{
    if (vec == NULL || indice < 0 || indice >= vec->tamanho)
        return NULL;

    return vec->elementos[indice].RoomName;
}

int vetor_insere_Room(vetor* vec, char* valor, int pos)
{
    int i;

    if(vec == NULL || pos < -1 || pos > vec->tamanho)
        return -1;

    /* aumenta elementos do vetor se capacidade nao for suficiente */
    if(vec->tamanho == vec->capacidade)
    {
        if(vec->capacidade == 0)
            vec->capacidade = 1;
        else
            vec->capacidade *= 2;

        vec->elementos = (v_elemento*)realloc(vec->elementos, vec->capacidade * sizeof(v_elemento));
        if(vec->elementos == NULL)
            return -1;
    }

    /* se pos=-1 insere no fim do vetor */
    if(pos == -1)
        pos = vec->tamanho;

    /* copia todos os elementos a partir da posicao pos ate' ao fim do vetor para pos+1 */
    for(i=vec->tamanho-1; i>=pos; i--)
    {
        vec->elementos[i+1] = vec->elementos[i];
    }

    /* aloca espaco para a nova string na posicao pos */
    vec->elementos[pos].RoomName = (char*)calloc(strlen(valor)+1, sizeof(char));
    if(vec->elementos[pos].RoomName == NULL)
        return -1;

    /* copia valor */
    strcpy(vec->elementos[pos].RoomName, valor);

    vec->elementos[pos].SensorCount=0;
    vec->elementos[pos].SensorCapacity=0;
    vec->elementos[pos].ActuadorCount=0;
    vec->elementos[pos].ActuadorCapacity=0;
    vec->elementos[pos].CountMots=0;
    vec->elementos[pos].SensorName=NULL;
    vec->elementos[pos].ActuadorName=NULL;
    vec->elementos[pos].IdentMots=NULL;
    vec->elementos[pos].compIdentMots=0;
    vec->tamanho++;

    return pos;
}
int pesquisaMot_vetorDiferente(vetor *vec, int pos_room, int mot){
    for(int i=0; i<vec->elementos[pos_room].CountMots; i++){
        if(mot==vec->elementos[pos_room].motsDiferentes[i])
            return 1;
    }
    return 0;
}
/*Podemos melhorar a pooupança da memoria ao trocar int para short no IdentMots*/
int vetor_insere_Sensor(vetor* vec, char* valor, int pos_room)
{
    if(vec == NULL || pos_room < -1 || pos_room > vec->tamanho)
        return -1;

    /* se pos_room=-1 insere no fim do vetor */
    if(pos_room == -1)
        pos_room = vec->tamanho-1;


    char* token;
    char* rest = valor;

    while ((token = (char*)strtok_r(rest, ",", &rest)))
    {
        /* aumenta elementos do vetor se capacidade nao for suficiente */
        if(vec->elementos[pos_room].SensorCount == vec->elementos[pos_room].SensorCapacity)
        {
            if(vec->elementos[pos_room].SensorCapacity == 0)
                vec->elementos[pos_room].SensorCapacity = 1;
            else
                vec->elementos[pos_room].SensorCapacity *= 2;

            vec->elementos[pos_room].SensorName = realloc(vec->elementos[pos_room].SensorName, vec->elementos[pos_room].SensorCapacity * sizeof(char*));
            vec->elementos[pos_room].IdentMots = realloc(vec->elementos[pos_room].IdentMots, vec->elementos[pos_room].SensorCapacity * sizeof(int));
            if(vec->elementos[pos_room].SensorName == NULL || vec->elementos[pos_room].IdentMots == NULL)
            {
                return -1;
            }
        }
        /* aloca espaco para a nova string na pos_roomicao pos_room */
        vec->elementos[pos_room].SensorName[vec->elementos[pos_room].SensorCount] = (char*)calloc(strlen(token)+1, sizeof(char));
        if(vec->elementos[pos_room].SensorName[vec->elementos[pos_room].SensorCount] == NULL)
            return -1;

        /*GARANTE QUE É COLOCADO UM NUMERO DA MOT*/
        if(token[strlen(token)-1] != '0' && token[strlen(token)-1] != '1' && token[strlen(token)-1] != '2' && token[strlen(token)-1] != '3'
                && token[strlen(token)-1] != '4' && token[strlen(token)-1] != '5' && token[strlen(token)-1] != '6' && token[strlen(token)-1] != '7'
                && token[strlen(token)-1] != '8' && token[strlen(token)-1] != '9')
        {
            printf("\nNao tem o numero da mot correta\n");
            vec->elementos[pos_room].IdentMots[vec->elementos[pos_room].SensorCount]=-1;
        }
        else
        {
            /*Coloca o valor da mot | Nao permite mots > 9
              Cada posiçao do vetor corresponde ao mesmo indice em que está
            */
            vec->elementos[pos_room].IdentMots[vec->elementos[pos_room].SensorCount]=(int)token[strlen(token)-1]-'0';//Faz a conversao para INT
            vec->elementos[pos_room].compIdentMots++;
        }
        /*SO PERMITE 0 A 9*/
        token[strlen(token)-1]='\0';
		
		int flag=0;
        for(int i=0; i<vec->elementos[pos_room].compIdentMots; i++){
            flag=pesquisaMot_vetorDiferente(vec, pos_room, vec->elementos[pos_room].IdentMots[i]);
            if(!flag)
            {
                vec->elementos[pos_room].motsDiferentes[vec->elementos[pos_room].CountMots]=vec->elementos[pos_room].IdentMots[i];
                vec->elementos[pos_room].CountMots++;
            }


        }
		
        /*Conta o numero de mots*/
        /*int count=0;
        for(int i=0; i<vec->elementos[pos_room].SensorCount; i++)
        {
            if(vec->elementos[pos_room].IdentMots[i] == -1) //Houve um erro, nao inseriu um numero depois do sensor
                break;
            else
            {
                if(vec->elementos[pos_room].IdentMots[i] != vec->elementos[pos_room].IdentMots[vec->elementos[pos_room].SensorCount])
                    count++;
            }
        }
        if(count == vec->elementos[pos_room].SensorCount)
            vec->elementos[pos_room].CountMots++;*/


        /* copia valor */
        strcpy(vec->elementos[pos_room].SensorName[vec->elementos[pos_room].SensorCount], token);
        vec->elementos[pos_room].SensorCount++;

    }

    return pos_room;
}

int vetor_insere_Actuador(vetor* vec, char* valor, int pos_room)
{
    if(vec == NULL || pos_room < -1 || pos_room > vec->tamanho)
        return -1;

    /* se pos_room=-1 insere no fim do vetor */
    if(pos_room == -1)
        pos_room = vec->tamanho-1;


    char* token;
    char* rest = valor;

    while ((token = (char*)strtok_r(rest, ",", &rest)))
    {
        if(vetor_pesquisa_atuador(vec, pos_room, token)==-1)
        {
            /* aumenta elementos do vetor se capacidade nao for suficiente */
            if(vec->elementos[pos_room].ActuadorCount == vec->elementos[pos_room].ActuadorCapacity)
            {
                if(vec->elementos[pos_room].ActuadorCapacity == 0)
                    vec->elementos[pos_room].ActuadorCapacity = 1;
                else
                    vec->elementos[pos_room].ActuadorCapacity *= 2;

                vec->elementos[pos_room].ActuadorName = realloc(vec->elementos[pos_room].ActuadorName, vec->elementos[pos_room].ActuadorCapacity * sizeof(char*));
                if(vec->elementos[pos_room].ActuadorName == NULL)
                {
                    return -1;
                }
            }
            /* aloca espaco para a nova string na pos_roomicao pos_room */
            vec->elementos[pos_room].ActuadorName[vec->elementos[pos_room].ActuadorCount] = (char*)calloc(strlen(token)+1, sizeof(char));
            if(vec->elementos[pos_room].ActuadorName[vec->elementos[pos_room].ActuadorCount] == NULL)
                return -1;

            if(token[strlen(token)-2]=='\r' || token[strlen(token)-2]=='\n')
                token[strlen(token)-2]='\0';
            else if(token[strlen(token)-1]=='\r' || token[strlen(token)-1]=='\n')
                token[strlen(token)-1]='\0';

            /* copia valor */
            strcpy(vec->elementos[pos_room].ActuadorName[vec->elementos[pos_room].ActuadorCount], token);
            vec->elementos[pos_room].ActuadorCount++;


        }


    }

    return pos_room;
}

int vetor_pesquisa(vetor* vec, const char* roomName)
{
    int i;

    if(vec == NULL || roomName==NULL)
        return -1;

    /* pesquisa sequencial */
    for (i = 0; i < vec->tamanho; i++)
    {
        if (!strcmp(vec->elementos[i].RoomName, roomName))
            return i;
    }

    return -1;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Message.h"
#include "vetor.h"

/*-1 se ocorrer erro*/
int leFicheiroRules(vetor *vec, Room *room)
{

    const char *filename="SensorRules.txt";
    int error;
    char buff[MaxBuffer];
    FILE *SensorRules;
    SensorRules=fopen(filename, "r");
    if(SensorRules==NULL)
    {
        printf("Could not open file %s",filename );
        return -1;
    }
    short count=0;
    int posRoom=-1;
    char *str=NULL;
    while(fgets(buff, MaxBuffer, SensorRules)!= NULL)
    {
        char* token;
        char* rest = buff;

        /* walk through tokens */
        while ((token = strtok_r(rest, ":", &rest)))
        {
            str=realloc(str, (strlen(token)+1)*sizeof(char));
            strcpy(str, token);
            upperCase(str);
            error=ToStructMessage(vec, room, str, &count, &posRoom);
            if(error==-1)
                return -1;
        }

    }

    fclose(SensorRules);

    return 1;
}
/*variavel global*/
int bit0;

/*-1 se houver erro*/
int ToStructMessage(vetor *vec, Room *room, char *token, short *count,  int *posRoom)
{
    limpaEspacos(token);

    switch(*count)
    {
    case 0:
        (*posRoom)= vetor_pesquisa(vec, token);
        if((*posRoom) == -1)
        {
            printf("A divisao do ficheiro SensorRules.txt nao corresponde a divisao do ficheiro SensorConfigurations.txt\n%s nao existe", token);
            return -1;
        }
        break;
    case 1:
        if(rulesSensores(room, token, &bit0, posRoom)==-1)
            goto error;
        break;
    case 2:

        if(rulesAtuadores(room, token, &bit0, posRoom)==-1)
            goto error;

        (*count)=-1;
        break;
    default:
        printf("Error count");
        break;
    }
    (*count)++;


    return 1;

error: // houve um erro
    return -1;
}


int rulesSensores(Room *room, char *str, int *bit0,  int *posRoom)
{
    int bit1, count=0;
    char* token;
    char* rest = str;
    while ((token = (char*)strtok_r(rest, "AND", &rest)))
    {
        if(strstr(token, "OR")!=NULL)
        {
            char *token2;
            while ((token2 = (char*)strtok_r(token, "OR", &token)))
            {
                if(count==0) //para fazer so 1 vez, bit0=0 permite nao modificar o valor
                {
                    (*bit0)=0;
                    count++;
                }
                if(count==10)
                {
                    bit1=organizaSensores(room, token2, "AND", posRoom);
                    if(bit1==-1)
                        goto error;
                    (*bit0)=(*bit0) && bit1;
                    count++;
                }
                else
                {
                    bit1=organizaSensores(room, token2, "OR", posRoom);
                    if(bit1==-1)
                        goto error;
                    (*bit0)=(*bit0) || bit1;
                }

            }

        }
        else
        {
            if(count==0) //para fazer so 1 vez, bit0=0 permite nao modificar o valor
            {
                (*bit0)=1;
                count=10;
            }
            bit1=organizaSensores(room, token, "AND", posRoom); // se -1 � porque houve erro
            if(bit1==-1)
                goto error;
            (*bit0)=(*bit0) && bit1;
        }
    }


    return 1;

error:
    return -1;

}
/*-1 se ocorrer erro*/
int organizaSensores(Room *room, char *str, char *condition,  int *posRoom)
{
    int selection=-1, count=0;
    char* token;
    char op[5];
    char* rest = str;
    char *pEnd; //para converter para decimal
    if(strstr(str, ">=")!=NULL)
    {
        selection=1;
        strcpy(op,">=");
    }
    else if(strstr(str, "<=")!=NULL)
    {
        selection=2;
        strcpy(op,"<=");
    }
    else if(strstr(str, ">")!=NULL)
    {
        selection=3;
        strcpy(op,">");
    }
    else if(strstr(str, "<")!=NULL)
    {
        selection=4;
        strcpy(op,"<");
    }
    else if(strstr(str, "!=")!=NULL)
    {
        selection=5;
        strcpy(op,"!=");
    }
    else if(strstr(str, "=")!=NULL)
    {
        selection=6;
        strcpy(op,"=");
    }


    int mot, sensor, valor, bit1=-1;

    /*dentro do while � separado a mot do sensor e do valor, para enviar para a respetiva fun�ao*/
    switch(selection)
    {
    case 1:
        while ((token = (char*)strtok_r(rest, ">=", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;

    case 2:
        while ((token = (char*)strtok_r(rest, "<=", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;
    case 3:
        while ((token = (char*)strtok_r(rest, ">", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;
    case 4:
        while ((token = (char*)strtok_r(rest, "<", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;
    case 5:
        while ((token = (char*)strtok_r(rest, "!=", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;
    case 6:
        while ((token = (char*)strtok_r(rest, "=", &rest)))
        {
            if(count==0)
            {
                mot=(int)token[strlen(token)-1]-'0'; //posi�ao da mot
                token[strlen(token)-1]='\0';// retira numero
                sensor= pesquisaSensor(token); //posi�ao do sensor
            }
            else if(count==1)
            {
                valor= strtol (token,&pEnd,10);
            }
            count++;
        }
        break;
    default:
        printf("Ocorreu um erro no valor de selection no switch da funcao organizaSensores");
        return -1;
        break;
    }
    mot=pesquisaMot(room, *posRoom, mot);
    if(mot<0 || sensor<0)
    {
        printf("A mot nao existe no SensorSonfiguration.txt ou sensor tem indice <0");
        return -1;
    }
    char sensores[5][25]= {"temp","hum","ph","light" };
    bit1=operation(selection, valor, sensor, mot, *posRoom, room);

    strcpy(room->regra[room->compRegra].divisao,room->roomName[*posRoom].placeName);
    room->regra[room->compRegra].indiceDivisao=(*posRoom);
    room->regra[room->compRegra].valor=valor;
    strcpy(room->regra[room->compRegra].sensor,sensores[sensor]);
    room->regra[room->compRegra].num_mot=room->roomName[*posRoom].medi[mot].motNumber ;
    strcpy(room->regra[room->compRegra].operacao,op);


    if(bit1==-1)
    {
        printf("\n\nErro no bit1 organizaSensores");
        return -1;

    }
    return bit1;
}

/*
retorna 1 ou 0
*/
int operation(int selection, int valor, int sensor, int mot, int posRoom, Room *room)
{
    switch(selection)
    {
    case 1:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] >= valor)
            return 1;
        else
            return 0;
        break;
    case 2:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] <= valor)
            return 1;
        else
            return 0;
        break;
    case 3:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] > valor)
            return 1;
        else
            return 0;
        break;
    case 4:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] < valor)
            return 1;
        else
            return 0;
        break;
    case 5:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] != valor)
            return 1;
        else
            return 0;
        break;
    case 6:
        if(room->roomName[posRoom].medi[mot].allMeasurements[0][sensor] == valor)
            return 1;
        else
            return 0;
        break;
    default:
        printf("Erro ao enviar operador");
        return -1;
        break;
    }
    return -1;
}


int rulesAtuadores(Room *room, char *str, int *bit0, int *posRoom)
{
    char* token;
    char* rest = str;
    int count;
    while ((token = (char*)strtok_r(rest, ",", &rest)))
    {
        char* token2;
        char* rest2 = token;
        int indice;
        count=0;//reset a variavel
        while ((token2 = (char*)strtok_r(rest2, "=", &rest2)))
        {
            if(token2[strlen(token2)-1]=='\n')
                token2[strlen(token2)-1]='\0';
            if(count==0)
            {
                indice = pesquisaAtuador(room, *posRoom, token2);

                if(indice==-1)
                {
                    printf("O atuador inserido no SensorRules.txt nao corresponde ao sensor definido no SensorConfiguration.txt");
                    return -1;
                }
                strcpy(room->regra[room->compRegra].atuador,token2);

                //pesquisa atuador e retorna indice
            }
            else if(count==1)
            {

                strcpy(room->regra[room->compRegra].acao,token2);
                room->compRegra++;
                if(!strcmp(token2,"OFF") && (*bit0))
                {
                    room->roomName[*posRoom].ActuadorOnOff[indice] = 0;
                }
                if(!strcmp(token2,"ON") && (*bit0))
                {
                    room->roomName[*posRoom].ActuadorOnOff[indice] = 1;
                }

            }
            count++;
        }
    }
    return 1;
}


int pesquisaMot(Room *room, int posRoom, int mot)
{

    for(int i=0; i<room->roomName[posRoom].numeroMots; i++)
    {
        if(room->roomName[posRoom].medi[i].motNumber == mot)
            return i;
    }
    return -1;
}

int pesquisaSensor (char *sensor)
{

    if(!strcmp("TEMP", sensor))
        return 0;
    else if(!strcmp("HUM", sensor))
        return 1;
    else if(!strcmp("PH", sensor))
        return 2;
    else if(!strcmp("LIGHT", sensor))
        return 3;

    return -1;
}

int pesquisaAtuador(Room *room, int posRoom, char *atuadorName)
{

    for(int i=0; i<room->roomName[posRoom].countActuador; i++)
    {
        if(!strcmp(room->roomName[posRoom].ActuadorName[i],atuadorName))
            return i;
    }
    return -1;
}

int Control(short count, Mensagem *StructMensagem, char *token)
{
    if(count==1)
    {
        if(strcmp(token, "45"))
            return -1;
        strcpy(StructMensagem->MessageStart+2, token);
    }
    else if(count==5)
    {
        strcpy(StructMensagem->MoteId, token);
    }
    else if(count==6)
    {
        strcpy(StructMensagem->MoteId+2, token);
        StructMensagem->motNumber= (int)atoi(StructMensagem->MoteId);

    }
    else if(count==7)
    {
        strcpy(StructMensagem->PayloadLength, token);
    }
    else if(count==10)
    {
        strcpy(StructMensagem->RawVoltage, token);
    }
    else if(count==11)
    {
        strcpy(StructMensagem->RawVoltage+2, token);
    }
    else if(count==12)
    {
        strcpy(StructMensagem->RawVisibleLight, token);
    }
    else if(count==13)
    {
        strcpy(StructMensagem->RawVisibleLight+2, token);
    }
    else if(count==14)
    {
        strcpy(StructMensagem->RawCurrent, token);
    }
    else if(count==15)
    {
        strcpy(StructMensagem->RawCurrent+2, token);
    }
    else if(count==16)
    {
        strcpy(StructMensagem->RawTemperature, token);
    }
    else if(count==17)
    {
        strcpy(StructMensagem->RawTemperature+2, token);
    }
    else if(count==18)
    {
        strcpy(StructMensagem->RawHumidity, token);
    }
    else if(count==19)
    {
        strcpy(StructMensagem->RawHumidity+2, token);
    }
    else if(count==22)
    {
        if(token[0]!='7' || token[1]!='E')
            return -2;
        strcpy(StructMensagem->EndMenssage, token);

    }
    return 1;
}

int ConfirmationMessage(char *str, Mensagem *StructMensagem)
{

    int error=-10;//inicializa��o para n�o entrar em nenhum "if"

    if(strlen(str)!=69)// 69 � o tamanho correto
    {
        error=0;
        goto error;
    }
    short count=1;
    char *token;

    /* get the first token */
    token = strtok(str, " ");
    if(strcmp(token, "7E"))
    {
        error=-3;
        goto error;

    }
    strcpy(StructMensagem->MessageStart, token);
    /* walk through other tokens */
    while( token != NULL )
    {
        token = strtok(NULL, " ");
        error=Control(count, StructMensagem, token);
        if(error==-1 || error==-2)
            goto error;
        count++;
    }
    goto ok;
error:
    /* if(error==-3)
         printf("7E do inicio com defeito");
     else if(error==0)
         printf("Comprimento menor que 69");
     else if(error== -1)
         printf("45 com defeito");
     else if(error== -2)
         printf("7E do fim com defeito");*/
    return -1;

ok:
    return 1;
}
/*retorna o indice da divisao que se encontra a mot X*/
int indiceRoomMotx(Room *room,int mot)
{
    for(int i=0; i< room->countRoom; i++)
    {
        for(int j=0; j<room->roomName[i].numeroMots; j++)
        {
            if(room->roomName[i].mots[j]==mot)
                return i;
        }

    }
    return -1;
}

float convertToDecimal(char *str)
{
    /*Para converter para decimal*/
    char *pEnd;
    return strtol (str,&pEnd,16);
}

int mudaRoomNovosValores(Room *room, vetor *vec)
{
    int roomChange=0;
    int sensorChange=0;
    int actuadorChange=0;
    if(vec->tamanho == room->countRoom)//Tem o mesmo tamanho de divisoes
    {
        for(int i=0; i<room->countRoom; i++)
        {
            if(strcmp(room->roomName[i].placeName, vec->elementos[i].RoomName))
            {
                roomChange=1;
                break;
            }
            if(room->roomName[i].compSensor == vec->elementos[i].SensorCount)
            {
                for(int j=0; j<vec->elementos[i].SensorCount; j++)
                {
                    if(strcmp(room->roomName[i].SensorName[j], vec->elementos[i].SensorName[j]) ||
                            room->roomName[i].motsVec[j] != vec->elementos[i].IdentMots[j])
                    {
                        sensorChange=1;
                        break;
                    }
                }
            }
            else if(room->roomName[i].compSensor != vec->elementos[i].SensorCount)
                sensorChange=1;
            if(room->roomName[i].countActuador == vec->elementos[i].ActuadorCount)
            {
                for(int j=0; j<vec->elementos[i].ActuadorCount; j++)
                {
                    if(strcmp(room->roomName[i].ActuadorName[j], vec->elementos[i].ActuadorName[j]))
                    {
                        actuadorChange=1;
                        break;
                    }
                }
            }
            else if(room->roomName[i].countActuador != vec->elementos[i].ActuadorCount)
                sensorChange=1;

        }
    }
    else if(vec->tamanho != room->countRoom)//testar para maior ou menor
    {
        roomChange=1;
    }

    if(roomChange==1 || sensorChange==1)
    {
        toMedicoes(room, vec);
        toActuador(room, vec);
        return 1;
    }
    else if(actuadorChange==1)
    {
        toActuador(room, vec);
        return 1;
    }
    return 0;
}

/*Coloca tudo de sensores na respetiva struct*/
void toMedicoes(Room *room, vetor *vec)
{
    room->roomName=NULL;
    room->roomName= malloc(vec->tamanho * sizeof( Sensores)); //Quantidade de divisoes
    room->countRoom= vec->tamanho;
    room->compRegra=0;
    for(int i=0; i < vec->tamanho; i++)
    {
        room->roomName[i].medi=NULL;
        room->roomName[i].medi= realloc(room->roomName[i].medi,vec->elementos[i].CountMots * sizeof(Medicoes));//na divisao I, Quantidade de mots
        int mot= 0; //Primeira mot encontrada
        room->roomName[i].compMots=0;
        room->roomName[i].compSensor=0;
        room->roomName[i].placeName = malloc((strlen(vec->elementos[i].RoomName)+1)*sizeof(char));
        strcpy(room->roomName[i].placeName, vec->elementos[i].RoomName);
        room->roomName[i].SensorName=malloc(vec->elementos[i].SensorCount * sizeof(char*));
        room->roomName[i].motsVec=malloc(vec->elementos[i].compIdentMots * sizeof(int));

        for(int z=0; z<vec->elementos[i].SensorCount; z++)
        {
            room->roomName[i].SensorName[z]=malloc((strlen(vec->elementos[i].SensorName[z])+1) * sizeof(char));
            strcpy(room->roomName[i].SensorName[z], vec->elementos[i].SensorName[z]);
            room->roomName[i].compSensor++;
            room->roomName[i].motsVec[z]= vec->elementos[i].IdentMots[z];
        }

        for(int j=0; j<vec->elementos[i].CountMots; j++)
        {
            room->roomName[i].medi[j].allMeasurements[1][0]=0;
            room->roomName[i].medi[j].allMeasurements[1][1]=0;
            room->roomName[i].medi[j].allMeasurements[1][2]=0;
            room->roomName[i].medi[j].allMeasurements[1][3]=0;
            room->roomName[i].medi[j].allMeasurements[0][0]=0;
            room->roomName[i].medi[j].allMeasurements[0][1]=0;
            room->roomName[i].medi[j].allMeasurements[0][2]=0;
            room->roomName[i].medi[j].allMeasurements[0][3]=0;

            room->roomName[i].numeroMots= vec->elementos[i].CountMots;//mots diferentes

            for(int z=0; z<vec->elementos[i].SensorCount; z++)
            {


                if(vec->elementos[i].IdentMots[z] > mot)
                {
                    mot=vec->elementos[i].IdentMots[z];
                    room->roomName[i].medi[j].motNumber=mot;
                    /*coloca as mots no vetor*/
                    room->roomName[i].mots[room->roomName[i].compMots]= vec->elementos[i].IdentMots[z];
                    room->roomName[i].compMots++;

                    break;
                }
            }

            for(int z=0; z<vec->elementos[i].SensorCount; z++)//Pecorre sensores � procura da string e a respetiva mot
            {

                /*temp*/
                if(!strcmp(vec->elementos[i].SensorName[z], "TEMP") && vec->elementos[i].IdentMots[z]==mot)
                {
                    room->roomName[i].medi[j].allMeasurements[1][0]=1;
                }
                else
                {
                    /*humi*/
                    if(!strcmp(vec->elementos[i].SensorName[z], "HUM") && vec->elementos[i].IdentMots[z]==mot)
                    {
                        room->roomName[i].medi[j].allMeasurements[1][1]=1;
                    }

                    else
                    {
                        /*ph*/
                        if(!strcmp(vec->elementos[i].SensorName[z], "PH") && vec->elementos[i].IdentMots[z]==mot)
                        {
                            room->roomName[i].medi[j].allMeasurements[1][2]=1;
                        }

                        else
                        {
                            /*light*/
                            if(!strcmp(vec->elementos[i].SensorName[z], "LIGHT") && vec->elementos[i].IdentMots[z]==mot)
                            {
                                room->roomName[i].medi[j].allMeasurements[1][3]=1;
                            }

                        }
                    }
                }

            }

        }
    }

}


void toActuador(Room *room, vetor *vec)
{

    for(int i=0; i<room->countRoom; i++)
    {
        room->roomName[i].ActuadorName= malloc(vec->elementos[i].ActuadorCount * sizeof(char*));
        room->roomName[i].countActuador=vec->elementos[i].ActuadorCount;
        room->roomName[i].ActuadorOnOff = malloc(room->roomName[i].countActuador *sizeof(int*));
        for(int j=0; j< vec->elementos[i].ActuadorCount; j++)
        {
            room->roomName[i].ActuadorName[j]=malloc((strlen(vec->elementos[i].ActuadorName[j])+1)* sizeof(char));
            strcpy(room->roomName[i].ActuadorName[j], vec->elementos[i].ActuadorName[j]);
            room->roomName[i].ActuadorOnOff[j]=0;
        }
    }
}

/* Colocar ja na mot correta*/
void organizaDados(Room *room, Mensagem *StructMensagem)
{
    int indiceRoom=indiceRoomMotx(room, StructMensagem->motNumber);
    StructMensagem->indiceDiv=indiceRoom;
    if(indiceRoom!=-1)
    {
        int mot= pesquisaMot(room, indiceRoom,StructMensagem->motNumber);
        StructMensagem->motIndice=mot;
        room->roomName[indiceRoom].medi[mot].allMeasurements[0][0]= realTemperatureMeasurements(StructMensagem);
        room->roomName[indiceRoom].medi[mot].allMeasurements[0][1]= realHumidityMeasurements(StructMensagem);
        room->roomName[indiceRoom].medi[mot].allMeasurements[0][2]= realPhMeasurements(StructMensagem);
        room->roomName[indiceRoom].medi[mot].allMeasurements[0][3]= realLightMeasurements(StructMensagem);

    }
    /* FAZER A PARTE DO 0/1.
        2 CICLOS FOR PARA VER SE NO FICHEIRO FOI COLOCADO, SE SIM, ENTAO METE 1.
        ATEN�AO AO NUMERO DA MOT
    */

}


float realTemperatureMeasurements(Mensagem *StructMensagem)
{
    float T=convertToDecimal(StructMensagem->RawTemperature);
    return -39.6+0.01*T;
}

float realHumidityMeasurements(Mensagem *StructMensagem)
{
    float Treal= realTemperatureMeasurements(StructMensagem);
    return (Treal-25)*(0.01+0.00008*551)+17.69;
}
float realLightMeasurements(Mensagem *StructMensagem)
{
    float Light= convertToDecimal(StructMensagem->RawVisibleLight);
    return 0.625*pow(10, 6)*( Light/ 4096)*1.5/100;
}

float realPhMeasurements(Mensagem *StructMensagem)
{
    float ph=convertToDecimal(StructMensagem->RawCurrent);
    return 0.769*pow(10,5)*(ph/4096)*1.5/100;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vetor.h"
#include "Message.h"
#include "Matrix.h"
#include "query.h"
#include <unistd.h>
short numOperacoes;

int maxMots(Room *room){
    int max=0;
    for(int i=0; i< room->countRoom; i++){
        for(int j=0; j<room->roomName[i].compMots; j++){
                if(room->roomName[i].mots[j]>max)
                    max=room->roomName[i].mots[j];

        }
    }
    return max;
}

void debug(Room room)
{

    for(int i=0; i<room.countRoom; i++)
    {
        printf("\nDivisao %s\n", room.roomName[i].placeName);
        for(int z=0; z<room.roomName[i].compSensor; z++){
            printf("\n\t->%s:%d", room.roomName[i].SensorName[z], room.roomName[i].motsVec[z]);
        }            printf("\n");

        for(int j=0; j<room.roomName[i].numeroMots; j++)
        {
            printf("\n\tmot %d\n", room.roomName[i].medi[j].motNumber);
            for(int z=0; z<4; z++)
            {
                printf("\t%f",room.roomName[i].medi[j].allMeasurements[0][z]);
            }
            printf("\n");
            for(int z=0; z<4; z++)
            {
                printf("\t%f",room.roomName[i].medi[j].allMeasurements[1][z]);
            }
            printf("\n\n\n\n\n");
        }
        printf("\n\tATUADORES\n");
        for(int z=0; z<room.roomName[i].countActuador; z++)
        {
            printf("\t%d:%s", room.roomName[i].ActuadorOnOff[z],room.roomName[i].ActuadorName[z] );
        }
        printf("\n\n");
        printf("\n\n\tcount atu: %d", room.roomName[i].countActuador);
        printf("\n\n\n\n\n");

    }
}

int leitura(char str[80], Room *room, vetor *vec, Mensagem *StructMensagem, int *count, int *inicio){
    /*strcpy(str[0],"7E 45 00 FF FF 00 03 0A 3F 0C 00 01 00 E1 00 50 19 8E 7F 0D 48 81 7E\n");
    strcpy(str[1],"7E 45 00 FF FF 00 02 0A 3F 0C 00 05 00 E1 00 02 19 8E 7F 0D 48 81 7E\n");
    strcpy(str[2],"7E 45 00 FF FF 00 04 0A 3F 0C 00 00 02 E1 00 20 19 8E 7F 05 48 81 7E\n");
    strcpy(str[3],"7E 45 00 FF FF 00 04 0A 3F 0C 00 00 00 E1 00 01 19 8E 7F 0D 48 81 7E\n");*/
    int mudanca=0;


sleep(1.5);
    repetir:
       if(*inicio)//busca todas as mots
            {
                *inicio=0;
                for(int i=0; i<maxMots(room); i++)
                    fgets(str, 80, stdin);
    /*ENCHER AS MOTS TODAS PRIMEIRO*/
            }else
                fgets(str, 80, stdin);
    leFicheiroConfiguration(vec);
    if( ConfirmationMessage(str, StructMensagem) == -1)
    {
       // printf("leitura errada");
    }
    mudanca=mudaRoomNovosValores(room, vec);
    if(mudanca==1)
        goto repetir;
    organizaDados(room, StructMensagem);
    return 1;
}

int controlo(vetor *vec,  Room *room, PGconn *conn, Mensagem *mensagem){
    
     if(!numOperacoes){
        room->first=1;
        numOperacoes++;
        insereRegra(conn, room);
        
        /*for(int j=0; j<room->compRegra; j++){
        printf("\n\nsensor %s\natuador %s\noperacao %s\nvalor %d\n num_mot %d\n acao %s\n",
               room->regra[j].sensor, room->regra[j].atuador, room->regra[j].operacao, room->regra[j].valor, room->regra[j].num_mot, room->regra[j].acao);
    
    }*/
    }
    if(leFicheiroRules(vec,room)==-1)
            return -1;
    insereMedicoes(conn,room,mensagem);
    return 1;
}

void ativaAtuadores(Room *room, Matrix *ma){

 adicionaMotsAtuadores(room, ma);

    //imprime(*ma);

}
int main()
{
    Mensagem StructMensagem;
    vetor *vec=vetor_novo();
    Room room;
    Matrix ma;
    int count=0;
    numOperacoes=0;
    int inicio=1;
    char str[80];
    leFicheiroConfiguration(vec);
    toMedicoes(&room, vec);
    toActuador(&room, vec);
    inicializaTela(&room, &ma);
    PGconn *conn= inicializaSql();
    insereConfiguracao(conn, &room);

    while(1){
    if(leitura(str, &room, vec, &StructMensagem, &count, &inicio)==-1)
        return -1;
    if(controlo(vec, &room, conn, &StructMensagem)==-1)
        return -1;
	ativaAtuadores(&room, &ma);

   // debug(room);


    //system("pause");
    
    }
    return 0;
}


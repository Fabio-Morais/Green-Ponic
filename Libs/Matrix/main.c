#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "Message.h"

#include "vetor.h"

#include "matrix.h"



int main(int argc, char **argv)

{

    /*for l=0, l<total

    * 	for col=0; col< tolal*/

    Matrix ma;

    Room room;

    room.roomName= malloc(4*sizeof(Sensores));

    room.roomName[0].numeroMots=3;

    room.roomName[1].numeroMots=3;

    room.roomName[2].numeroMots=3;

    room.roomName[3].numeroMots=3;

    room.roomName[0].medi=malloc(4*sizeof(Medicoes));

    room.roomName[1].medi=malloc(4*sizeof(Medicoes));

    room.roomName[2].medi=malloc(4*sizeof(Medicoes));

    room.roomName[3].medi=malloc(4*sizeof(Medicoes));



    room.roomName[0].placeName=malloc(25*sizeof(char));

    strcpy(room.roomName[0].placeName, "null");





    room.roomName[0].ActuadorName= malloc(sizeof(char*) * 4);//dá para 4 nomes

    room.roomName[1].ActuadorName= malloc(sizeof(char*) * 4);//dá para 4 nomes

    room.roomName[2].ActuadorName= malloc(sizeof(char*) * 4);//dá para 4 nomes

    room.roomName[3].ActuadorName= malloc(sizeof(char*) * 4);//dá para 4 nomes



    room.roomName[0].ActuadorOnOff=malloc(4*sizeof(Sensores));

    room.roomName[0].countActuador=4;



    room.roomName[0].ActuadorOnOff[0]=1;

    room.roomName[0].ActuadorOnOff[1]=0;

    room.roomName[0].ActuadorOnOff[2]=0;

    room.roomName[0].ActuadorOnOff[3]=0;



    room.roomName[1].ActuadorOnOff=malloc(4*sizeof(Sensores));

    room.roomName[1].countActuador=4;



    room.roomName[1].ActuadorOnOff[0]=1;

    room.roomName[1].ActuadorOnOff[1]=0;

    room.roomName[1].ActuadorOnOff[2]=0;

    room.roomName[1].ActuadorOnOff[3]=1;



    room.roomName[2].ActuadorOnOff=malloc(4*sizeof(Sensores));

    room.roomName[2].countActuador=4;



    room.roomName[2].ActuadorOnOff[0]=0;

    room.roomName[2].ActuadorOnOff[1]=1;

    room.roomName[2].ActuadorOnOff[2]=0;

    room.roomName[2].ActuadorOnOff[3]=1;



    room.roomName[3].ActuadorOnOff=malloc(4*sizeof(Sensores));

    room.roomName[3].countActuador=4;



    room.roomName[3].ActuadorOnOff[0]=0;

    room.roomName[3].ActuadorOnOff[1]=1;

    room.roomName[3].ActuadorOnOff[2]=0;

    room.roomName[3].ActuadorOnOff[3]=1;



    room.roomName[0].ActuadorName[0]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[0].ActuadorName[0],"FAN");

    room.roomName[0].ActuadorName[1]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[0].ActuadorName[1],"ELECTROVALVE");

    room.roomName[0].ActuadorName[2]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[0].ActuadorName[2],"LIGHT");

    room.roomName[0].ActuadorName[3]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[0].ActuadorName[3],"HEATER");





    room.roomName[1].ActuadorName[0]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[1].ActuadorName[0],"HEATER");

    room.roomName[1].ActuadorName[1]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[1].ActuadorName[1],"FAN");

    room.roomName[1].ActuadorName[2]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[1].ActuadorName[2],"LIGHT");

    room.roomName[1].ActuadorName[3]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[1].ActuadorName[3],"ELECTROVALVE");



    room.roomName[2].ActuadorName[0]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[2].ActuadorName[0],"FAN");

    room.roomName[2].ActuadorName[1]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[2].ActuadorName[1],"HEATER");

    room.roomName[2].ActuadorName[2]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[2].ActuadorName[2],"LIGHT");

    room.roomName[2].ActuadorName[3]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[2].ActuadorName[3],"ELECTROVALVE");



    room.roomName[3].ActuadorName[0]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[3].ActuadorName[0],"FAN");

    room.roomName[3].ActuadorName[1]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[3].ActuadorName[1],"HEATER");

    room.roomName[3].ActuadorName[2]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[3].ActuadorName[2],"LIGHT");

    room.roomName[3].ActuadorName[3]= malloc(sizeof(char) * 25);

    strcpy(room.roomName[3].ActuadorName[3],"ELECTROVALVE");









    room.roomName[0].medi[0].allMeasurements[1][0]=1;

    room.roomName[0].medi[0].allMeasurements[1][1]=0;

    room.roomName[0].medi[0].allMeasurements[1][2]=1;

    room.roomName[0].medi[0].allMeasurements[1][3]=1;



    room.roomName[0].medi[0].allMeasurements[0][0]=25;

    room.roomName[0].medi[0].allMeasurements[0][1]=15;

    room.roomName[0].medi[0].allMeasurements[0][2]=35;

    room.roomName[0].medi[0].allMeasurements[0][3]=15;



    room.roomName[0].medi[1].allMeasurements[1][0]=1;

    room.roomName[0].medi[1].allMeasurements[1][1]=1;

    room.roomName[0].medi[1].allMeasurements[1][2]=0;

    room.roomName[0].medi[1].allMeasurements[1][3]=1;



    room.roomName[0].medi[1].allMeasurements[0][0]=25;

    room.roomName[0].medi[1].allMeasurements[0][1]=15;

    room.roomName[0].medi[1].allMeasurements[0][2]=15;

    room.roomName[0].medi[1].allMeasurements[0][3]=15;



    room.roomName[0].medi[2].allMeasurements[1][0]=1;

    room.roomName[0].medi[2].allMeasurements[1][1]=1;

    room.roomName[0].medi[2].allMeasurements[1][2]=1;

    room.roomName[0].medi[2].allMeasurements[1][3]=1;



    room.roomName[0].medi[2].allMeasurements[0][0]=25;

    room.roomName[0].medi[2].allMeasurements[0][1]=15;

    room.roomName[0].medi[2].allMeasurements[0][2]=15;

    room.roomName[0].medi[2].allMeasurements[0][3]=15;

    /************************/



    room.roomName[1].medi[0].allMeasurements[1][0]=1;

    room.roomName[1].medi[0].allMeasurements[1][1]=0;

    room.roomName[1].medi[0].allMeasurements[1][2]=1;

    room.roomName[1].medi[0].allMeasurements[1][3]=1;



    room.roomName[1].medi[0].allMeasurements[0][0]=25;

    room.roomName[1].medi[0].allMeasurements[0][1]=15;

    room.roomName[1].medi[0].allMeasurements[0][2]=35;

    room.roomName[1].medi[0].allMeasurements[0][3]=15;



    room.roomName[1].medi[1].allMeasurements[1][0]=1;

    room.roomName[1].medi[1].allMeasurements[1][1]=0;

    room.roomName[1].medi[1].allMeasurements[1][2]=1;

    room.roomName[1].medi[1].allMeasurements[1][3]=1;



    room.roomName[1].medi[1].allMeasurements[0][0]=25;

    room.roomName[1].medi[1].allMeasurements[0][1]=15;

    room.roomName[1].medi[1].allMeasurements[0][2]=35;

    room.roomName[1].medi[1].allMeasurements[0][3]=15;



    room.roomName[1].medi[2].allMeasurements[1][0]=0;

    room.roomName[1].medi[2].allMeasurements[1][1]=1;

    room.roomName[1].medi[2].allMeasurements[1][2]=0;

    room.roomName[1].medi[2].allMeasurements[1][3]=1;



    room.roomName[1].medi[2].allMeasurements[0][0]=25;

    room.roomName[1].medi[2].allMeasurements[0][1]=15;

    room.roomName[1].medi[2].allMeasurements[0][2]=15;

    room.roomName[1].medi[2].allMeasurements[0][3]=5;



    room.roomName[2].medi[0].allMeasurements[1][0]=1;

    room.roomName[2].medi[0].allMeasurements[1][1]=0;

    room.roomName[2].medi[0].allMeasurements[1][2]=1;

    room.roomName[2].medi[0].allMeasurements[1][3]=1;



    room.roomName[2].medi[0].allMeasurements[0][0]=5;

    room.roomName[2].medi[0].allMeasurements[0][1]=15;

    room.roomName[2].medi[0].allMeasurements[0][2]=25;

    room.roomName[2].medi[0].allMeasurements[0][3]=5;



    room.roomName[2].medi[1].allMeasurements[1][0]=1;

    room.roomName[2].medi[1].allMeasurements[1][1]=1;

    room.roomName[2].medi[1].allMeasurements[1][2]=1;

    room.roomName[2].medi[1].allMeasurements[1][3]=1;



    room.roomName[2].medi[1].allMeasurements[0][0]=15;

    room.roomName[2].medi[1].allMeasurements[0][1]=25;

    room.roomName[2].medi[1].allMeasurements[0][2]=5;

    room.roomName[2].medi[1].allMeasurements[0][3]=15;



    room.roomName[2].medi[2].allMeasurements[1][0]=1;

    room.roomName[2].medi[2].allMeasurements[1][1]=1;

    room.roomName[2].medi[2].allMeasurements[1][2]=1;

    room.roomName[2].medi[2].allMeasurements[1][3]=1;



    room.roomName[2].medi[2].allMeasurements[0][0]=15;

    room.roomName[2].medi[2].allMeasurements[0][1]=25;

    room.roomName[2].medi[2].allMeasurements[0][2]=5;

    room.roomName[2].medi[2].allMeasurements[0][3]=15;



    room.roomName[3].medi[3].allMeasurements[1][0]=1;

    room.roomName[3].medi[3].allMeasurements[1][1]=1;

    room.roomName[3].medi[3].allMeasurements[1][2]=1;

    room.roomName[3].medi[3].allMeasurements[1][3]=1;



    room.roomName[3].medi[3].allMeasurements[0][0]=15;

    room.roomName[3].medi[3].allMeasurements[0][1]=25;

    room.roomName[3].medi[3].allMeasurements[0][2]=5;

    room.roomName[3].medi[3].allMeasurements[0][3]=15;



    room.countRoom=4;



    inicializaCores();

    desenhaFundo(&ma);

    desenhaMoldura(&ma);

    desenhaLimites(&ma);

    int indice=0;

    imprimeMots1(&ma, &room, &indice);

    imprimeMots2(&ma, &room, &indice);

    imprimeMots3(&ma, &room, &indice);

    imprimeMots4(&ma, &room, &indice);

    colocaatuadores1(&ma,&room);

    colocaatuadores2(&ma,&room);

    colocaatuadores3(&ma,&room);

    colocaatuadores4(&ma,&room);



    imprime(ma);



    return 0;

}

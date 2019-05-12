#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Message.h"
#include "vetor.h"
#include "Matrix.h"

void inicializaCores()
{
    strcpy(cor.corDeFundo, "[79,78,99]");
    strcpy(cor.corMoldura, "[0,0,0]");
    strcpy(cor.corSemMote, "[119,136,153]");
    strcpy(cor.corEstufa, "[220,240,249]");
    strcpy(cor.corMot,"[228,24,221]");
    strcpy(cor.verde, "[0,255,0]");
    strcpy(cor.vermelho, "[255,0,0]");
    strcpy(cor.corSala1,"[80,166,83]");
    strcpy(cor.corSala2,"[210,91,91]");
    strcpy(cor.corSala3,"[203,177,72]");
    strcpy(cor.corSala4,"[125,197,205]");
    strcpy(cor.corExisteAtuador,"[102,141,171]");
    strcpy(cor.corLight,"[232,241,247]");
    strcpy(cor.corValve,"[35,38,40]");
    strcpy(cor.corHeater,"[228,99,13]");
    strcpy(cor.corSemSala,"[61,58,56]");
    strcpy(cor.corSensLight,"[58,203,213]");
    strcpy(cor.corSensTemp,"[34,86,90]");
    strcpy(cor.corSensHum,"[107,149,172]");
    strcpy(cor.corSensPh,"[94,103,104]");
    strcpy(cor.corSensTempLOW,"[1,220,253]");
    strcpy(cor.corSensTempOK,"[253,236,1]");
    strcpy(cor.corSensTempHIGH,"[255,0,0]");
    strcpy(cor.corSensHumLOW,"[1,220,253]");
    strcpy(cor.corSensHumOK,"[253,236,1]");
    strcpy(cor.corSensHumHIGH,"[255,0,0]");
    strcpy(cor.corSensPhLOW,"[1,220,253]");
    strcpy(cor.corSensPhOK,"[253,236,1]");
    strcpy(cor.corSensPhHIGH,"[255,0,0]");
    strcpy(cor.corSensLightLOW,"[1,220,253]");
    strcpy(cor.corSensLightOK,"[253,236,1]");
    strcpy(cor.corSensLightHIGH,"[255,0,0]");


}

void desenhaMoldura(Matrix *matrix)
{
    for (int i=0; i<MatrixSize; i++)
    {
        strcpy(matrix->col[i].l[0].str,cor.corMoldura );
        strcpy(matrix->col[i].l[MatrixSize-1].str,cor.corMoldura );
        strcpy(matrix->col[0].l[i].str,cor.corMoldura );
        strcpy(matrix->col[MatrixSize-1].l[i].str,cor.corMoldura );
    }
}

void desenhaLimites(Matrix *matrix)
{
    for(int i=5; i<25; i++)
    {
        strcpy(matrix->col[i].l[6].str,cor.corEstufa);
        strcpy(matrix->col[i].l[26].str,cor.corEstufa);
    }
    strcpy(matrix->col[14].l[6].str,cor.corDeFundo);
    strcpy(matrix->col[15].l[6].str,cor.corDeFundo);
    for(int j=6; j<27; j++)
    {
        strcpy(matrix->col[5].l[j].str,cor.corEstufa);
        strcpy(matrix->col[24].l[j].str,cor.corEstufa);
    }
    for(int j=7; j<15; j++)
    {
        strcpy(matrix->col[13].l[j].str, cor.corEstufa);
        strcpy(matrix->col[16].l[j].str, cor.corEstufa);
    }
    for(int i=6; i<11; i++)
    {
        strcpy(matrix->col[i].l[14].str, cor.corEstufa);
        strcpy(matrix->col[i].l[17].str, cor.corEstufa);
    }
    for(int i=19; i<24; i++)
    {
        strcpy(matrix->col[i].l[14].str, cor.corEstufa);
        strcpy(matrix->col[i].l[17].str, cor.corEstufa);
    }
    for(int j=18; j<26; j++)
    {
        strcpy(matrix->col[14].l[j].str, cor.corEstufa);
    }
    for(int i=13; i<17; i++)
    {
        strcpy(matrix->col[i].l[17].str, cor.corEstufa);
    }
}


void desenhaFundo(Matrix *matrix)
{
    for(int i=0; i< MatrixSize; i++)
    {
        for(int j=0; j<MatrixSize; j++)
        {
            strcpy(matrix->col[i].l[j].str, cor.corDeFundo);
        }
    }
}

void mot11(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<10)
            strcpy(matrix->col[17].l[7].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<15)
            strcpy(matrix->col[17].l[7].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[17].l[7].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[17].l[7].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<10)
            strcpy(matrix->col[18].l[7].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<15)
            strcpy(matrix->col[18].l[7].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[18].l[7].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[18].l[7].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<10)
            strcpy(matrix->col[18].l[8].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<15)
            strcpy(matrix->col[18].l[8].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[18].l[8].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[18].l[8].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<10)
            strcpy(matrix->col[17].l[8].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<15)
            strcpy(matrix->col[17].l[8].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[17].l[8].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[17].l[8].str, cor.corSemMote);
}

void mot12(Matrix *matrix, Room *room, int *indice)
{

    /**Temperatura**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<10)
            strcpy(matrix->col[22].l[7].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<15)
            strcpy(matrix->col[22].l[7].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[22].l[7].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[22].l[7].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<10)
            strcpy(matrix->col[23].l[7].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<15)
            strcpy(matrix->col[23].l[7].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[23].l[7].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[23].l[7].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<10)
            strcpy(matrix->col[23].l[8].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<15)
            strcpy(matrix->col[23].l[8].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[23].l[8].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[23].l[8].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<10)
            strcpy(matrix->col[22].l[8].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<15)
            strcpy(matrix->col[22].l[8].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[22].l[8].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[22].l[8].str, cor.corSemMote);

}

void mot13(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<10)
            strcpy(matrix->col[22].l[12].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<15)
            strcpy(matrix->col[22].l[12].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[22].l[12].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[22].l[12].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<10)
            strcpy(matrix->col[23].l[12].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<15)
            strcpy(matrix->col[23].l[12].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[23].l[12].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[23].l[12].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<10)
            strcpy(matrix->col[23].l[13].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<15)
            strcpy(matrix->col[23].l[13].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[23].l[13].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[23].l[13].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<10)
            strcpy(matrix->col[22].l[13].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<15)
            strcpy(matrix->col[22].l[13].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[22].l[13].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[22].l[13].str, cor.corSemMote);
}

void pintaExterior(Room *room, Matrix *matrix)
{
    /**Temperatura**/
    if(room->roomName[0].medi[0].allMeasurements[1][0]==1)
    {
        if(room->roomName[0].medi[0].allMeasurements[0][0]<10)
            strcpy(matrix->col[14].l[2].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[0].medi[0].allMeasurements[0][0]<15)
            strcpy(matrix->col[14].l[2].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[14].l[2].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[14].l[2].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[0].medi[0].allMeasurements[1][1]==1)
    {
        if(room->roomName[0].medi[0].allMeasurements[0][1]<10)
            strcpy(matrix->col[15].l[2].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[0].medi[0].allMeasurements[0][1]<15)
            strcpy(matrix->col[15].l[2].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[15].l[2].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[15].l[2].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[0].medi[0].allMeasurements[1][2]==1)
    {
        if(room->roomName[0].medi[0].allMeasurements[0][2]<10)
            strcpy(matrix->col[15].l[3].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[0].medi[0].allMeasurements[0][2]<15)
            strcpy(matrix->col[15].l[3].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[15].l[3].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[15].l[3].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[0].medi[0].allMeasurements[1][3]==1)
    {
        if(room->roomName[0].medi[0].allMeasurements[0][3]<10)
            strcpy(matrix->col[14].l[3].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[0].medi[0].allMeasurements[0][3]<15)
            strcpy(matrix->col[14].l[3].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[14].l[3].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[14].l[3].str, cor.corSemMote);
}

void imprimeMots1(Matrix *matrix, Room *room, int *indice, int *confirmation)
{
    if(room->countRoom>0)
    {
        if(!strcmp(room->roomName[0].placeName, "EXTERIOR"))
        {
            pintaExterior(room, matrix);
            if(room->countRoom>1)
            {
                (*indice)++;
                *confirmation=1;
            }
            else
                *confirmation=0;
        }
        else
            *confirmation=1;
        for(int i=17; i<24; i++)
        {
            for(int j=7; j<14; j++)
            {
                strcpy(matrix->col[i].l[j].str, cor.corSala1);
            }
        }
        if(room->roomName[(*indice)].numeroMots==0 || room->roomName[(*indice)].numeroMots>3
                || room->roomName[(*indice)].numeroMots<0 || (*confirmation)==0)
        {
            strcpy(matrix->col[17].l[7].str, cor.corSemMote); //mot1
            strcpy(matrix->col[23].l[7].str, cor.corSemMote); //mot2
            strcpy(matrix->col[23].l[13].str, cor.corSemMote); //mot3
        }
        else if(room->roomName[(*indice)].numeroMots==1)
        {
            mot11(matrix, room, indice);

        }
        else if(room->roomName[(*indice)].numeroMots==2)
        {
            mot11(matrix, room, indice);
            mot12(matrix, room, indice);

        }

        else if(room->roomName[(*indice)].numeroMots==3)
        {
            mot11(matrix, room, indice);
            mot12(matrix, room, indice);
            mot13(matrix, room, indice);



        }
    }else
        {
            for(int i=17; i<24; i++)
            {
                for(int j=7; j<14; j++)
                {
                    strcpy(matrix->col[i].l[j].str, cor.corSemSala);
                }
            }
        }
        (*indice)++;
}

void mot21(Matrix *matrix, Room *room, int *indice)
{


    /**Temperatura**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<10)
            strcpy(matrix->col[15].l[18].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<15)
            strcpy(matrix->col[15].l[18].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[15].l[18].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[15].l[18].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<10)
            strcpy(matrix->col[16].l[18].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<15)
            strcpy(matrix->col[16].l[18].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[16].l[18].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[16].l[18].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<10)
            strcpy(matrix->col[16].l[19].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<15)
            strcpy(matrix->col[16].l[19].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[16].l[19].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[16].l[19].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<10)
            strcpy(matrix->col[15].l[19].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<15)
            strcpy(matrix->col[15].l[19].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[15].l[19].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[15].l[19].str, cor.corSemMote);

}

void mot22(Matrix *matrix, Room *room, int *indice)
{


    /**Temperatura**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<10)
            strcpy(matrix->col[22].l[18].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<15)
            strcpy(matrix->col[22].l[18].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[22].l[18].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[22].l[18].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<10)
            strcpy(matrix->col[23].l[18].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<15)
            strcpy(matrix->col[23].l[18].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[23].l[18].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[23].l[18].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<10)
            strcpy(matrix->col[23].l[19].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<15)
            strcpy(matrix->col[23].l[19].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[23].l[19].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[23].l[19].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<10)
            strcpy(matrix->col[22].l[19].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<15)
            strcpy(matrix->col[22].l[19].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[22].l[19].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[22].l[19].str, cor.corSemMote);

}

void mot23(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<10)
            strcpy(matrix->col[22].l[24].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<15)
            strcpy(matrix->col[22].l[24].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[22].l[24].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[22].l[24].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<10)
            strcpy(matrix->col[23].l[24].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<15)
            strcpy(matrix->col[23].l[24].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[23].l[24].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[23].l[24].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<10)
            strcpy(matrix->col[23].l[25].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<15)
            strcpy(matrix->col[23].l[25].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[23].l[25].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[23].l[25].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<10)
            strcpy(matrix->col[22].l[25].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<15)
            strcpy(matrix->col[22].l[25].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[22].l[25].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[22].l[25].str, cor.corSemMote);
}


void imprimeMots2(Matrix *matrix, Room *room, int *indice, int *confirmation)
{
    if((room->countRoom - (*confirmation))>1)
    {
        for(int i=15; i<24; i++)
        {
            for(int j=18; j<26; j++)
            {
                strcpy(matrix->col[i].l[j].str, cor.corSala2);
            }
        }
        if(room->roomName[(*indice)].numeroMots==0 || room->roomName[(*indice)].numeroMots>3
                || room->roomName[(*indice)].numeroMots<0)
        {
            strcpy(matrix->col[15].l[18].str, cor.corSemMote); //mot1
            strcpy(matrix->col[23].l[18].str, cor.corSemMote); //mot2
            strcpy(matrix->col[23].l[25].str, cor.corSemMote); //mot3
        }
        else if(room->roomName[(*indice)].numeroMots==1)
        {
            mot21(matrix, room, indice);

        }
        else if(room->roomName[(*indice)].numeroMots==2)
        {
            mot21(matrix, room, indice);
            mot22(matrix, room, indice);

        }

        else if(room->roomName[(*indice)].numeroMots==3)
        {
            mot21(matrix, room, indice);
            mot22(matrix, room, indice);
            mot23(matrix, room, indice);



        }
    }else
        {
            for(int i=15; i<24; i++)
            {
                for(int j=18; j<26; j++)
                {
                    strcpy(matrix->col[i].l[j].str, cor.corSemSala);
                }
            }
        }
        (*indice)++;
}


void mot31(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<10)
            strcpy(matrix->col[6].l[18].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<15)
            strcpy(matrix->col[6].l[18].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[6].l[18].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[6].l[18].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<10)
            strcpy(matrix->col[7].l[18].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<15)
            strcpy(matrix->col[7].l[18].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[7].l[18].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[7].l[18].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<10)
            strcpy(matrix->col[7].l[19].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<15)
            strcpy(matrix->col[7].l[19].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[7].l[19].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[7].l[19].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[0].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<10)
            strcpy(matrix->col[6].l[19].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<15)
            strcpy(matrix->col[6].l[19].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[6].l[19].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[6].l[19].str, cor.corSemMote);
}

void mot32(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<10)
            strcpy(matrix->col[6].l[24].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<15)
            strcpy(matrix->col[6].l[24].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[6].l[24].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[6].l[24].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<10)
            strcpy(matrix->col[7].l[24].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<15)
            strcpy(matrix->col[7].l[24].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[7].l[24].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[7].l[24].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<10)
            strcpy(matrix->col[7].l[25].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<15)
            strcpy(matrix->col[7].l[25].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[7].l[25].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[7].l[25].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[1].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<10)
            strcpy(matrix->col[6].l[25].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<15)
            strcpy(matrix->col[6].l[25].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[6].l[25].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[6].l[25].str, cor.corSemMote);
}

void mot33(Matrix *matrix, Room *room, int *indice)
{
    /**Temperatura**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][0]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<10)
            strcpy(matrix->col[12].l[24].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<15)
            strcpy(matrix->col[12].l[24].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[12].l[24].str, cor.corSensTempHIGH);
    }
    else
        strcpy(matrix->col[12].l[24].str, cor.corSemMote); //mot1
    /**Humidade**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][1]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<10)
            strcpy(matrix->col[13].l[24].str, cor.corSensHumLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<15)
            strcpy(matrix->col[13].l[24].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[13].l[24].str, cor.corSensHumHIGH); //mot1
    }
    else
        strcpy(matrix->col[13].l[24].str, cor.corSemMote); //mot1
    /**Ph**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<10)
            strcpy(matrix->col[13].l[25].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<15)
            strcpy(matrix->col[13].l[25].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[13].l[25].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[13].l[25].str, cor.corSemMote);
    /**Light**/
    if(room->roomName[(*indice)].medi[2].allMeasurements[1][3]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<10)
            strcpy(matrix->col[12].l[25].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<15)
            strcpy(matrix->col[12].l[25].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[12].l[25].str, cor.corSensLightHIGH); //mot1
    }
    else
        strcpy(matrix->col[12].l[25].str, cor.corSemMote);
}

void imprimeMots3(Matrix *matrix, Room *room, int *indice, int *confirmation)
{

    if((room->countRoom - (*confirmation))>2)
    {
        for(int i=6; i<14; i++)
        {
            for(int j=18; j<26; j++)
            {
                strcpy(matrix->col[i].l[j].str, cor.corSala3);
            }
        }
        if(room->roomName[(*indice)].numeroMots==0 || room->roomName[(*indice)].numeroMots>3
                || room->roomName[(*indice)].numeroMots<0)
        {
            strcpy(matrix->col[6].l[18].str, cor.corSemMote); //mot1
            strcpy(matrix->col[6].l[25].str, cor.corSemMote); //mot2
            strcpy(matrix->col[13].l[25].str, cor.corSemMote); //mot3
        }
        else if(room->roomName[(*indice)].numeroMots==1)
        {
            mot31(matrix, room, indice);

        }
        else if(room->roomName[(*indice)].numeroMots==2)
        {
            mot31(matrix, room, indice);
            mot32(matrix, room, indice);

        }

        else if(room->roomName[(*indice)].numeroMots==3)
        {
            mot31(matrix, room, indice);
            mot32(matrix, room, indice);
            mot33(matrix, room, indice);



        }
    }else
        {
            for(int i=6; i<14; i++)
            {
                for(int j=18; j<26; j++)
                {
                    strcpy(matrix->col[i].l[j].str, cor.corSemSala);
                }
            }
        }
        (*indice)++;
}


void mot41(Matrix *matrix, Room *room, int *indice)
{

    /**Temperatura**/



    if(room->roomName[(*indice)].medi[0].allMeasurements[1][0]==1)



    {

        if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<10)
            strcpy(matrix->col[11].l[7].str, cor.corSensTempLOW); //mot1
        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][0]<20)
            strcpy(matrix->col[11].l[7].str, cor.corSensTempOK);
        else
            strcpy(matrix->col[11].l[7].str, cor.corSensTempHIGH);

    }
    else
        strcpy(matrix->col[11].l[7].str, cor.corSemMote); //mot1



    /**Humidade**/



    if(room->roomName[(*indice)].medi[0].allMeasurements[1][1]==1)



    {



        if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<10)



            strcpy(matrix->col[12].l[7].str, cor.corSensHumLOW); //mot1



        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][1]<20)



            strcpy(matrix->col[12].l[7].str, cor.corSensHumOK); //mot1



        else



            strcpy(matrix->col[12].l[7].str, cor.corSensHumHIGH); //mot1



    }



    else



        strcpy(matrix->col[12].l[7].str, cor.corSemMote); //mot1



    /**Ph**/



    if(room->roomName[(*indice)].medi[0].allMeasurements[1][2]==1)



    {



        if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<10)



            strcpy(matrix->col[12].l[8].str, cor.corSensPhLOW); //mot1



        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][2]<20)



            strcpy(matrix->col[12].l[8].str, cor.corSensPhOK); //mot1



        else



            strcpy(matrix->col[12].l[8].str, cor.corSensPhHIGH);



    }



    else



        strcpy(matrix->col[12].l[8].str, cor.corSemMote);



    /**Light**/



    if(room->roomName[(*indice)].medi[0].allMeasurements[1][3]==1)



    {



        if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<10)



            strcpy(matrix->col[11].l[8].str, cor.corSensLightLOW); //mot1



        else if(room->roomName[(*indice)].medi[0].allMeasurements[0][3]<20)



            strcpy(matrix->col[11].l[8].str, cor.corSensLightOK); //mot1



        else



            strcpy(matrix->col[11].l[8].str, cor.corSensLightHIGH); //mot1



    }


    else

        strcpy(matrix->col[11].l[8].str, cor.corSemMote);


}



void mot42(Matrix *matrix, Room *room, int *indice)

{

    /**Temperatura**/



    if(room->roomName[(*indice)].medi[1].allMeasurements[1][0]==1)



    {



        if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<10)



            strcpy(matrix->col[6].l[7].str, cor.corSensTempLOW); //mot1



        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][0]<20)



            strcpy(matrix->col[6].l[7].str, cor.corSensTempOK);



        else



            strcpy(matrix->col[6].l[7].str, cor.corSensTempHIGH);



    }



    else



        strcpy(matrix->col[6].l[7].str, cor.corSemMote); //mot1



    /**Humidade**/



    if(room->roomName[(*indice)].medi[1].allMeasurements[1][1]==1)



    {



        if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<10)



            strcpy(matrix->col[7].l[7].str, cor.corSensHumLOW); //mot1



        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][1]<20)



            strcpy(matrix->col[7].l[7].str, cor.corSensHumOK); //mot1



        else



            strcpy(matrix->col[7].l[7].str, cor.corSensHumHIGH); //mot1



    }



    else



        strcpy(matrix->col[7].l[7].str, cor.corSemMote); //mot1



    /**Ph**/



    if(room->roomName[(*indice)].medi[1].allMeasurements[1][2]==1)



    {



        if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<10)



            strcpy(matrix->col[7].l[8].str, cor.corSensPhLOW); //mot1



        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][2]<20)



            strcpy(matrix->col[7].l[8].str, cor.corSensPhOK); //mot1



        else



            strcpy(matrix->col[7].l[8].str, cor.corSensPhHIGH);



    }



    else

        strcpy(matrix->col[7].l[8].str, cor.corSemMote);



    /**Light**/

    if(room->roomName[(*indice)].medi[1].allMeasurements[1][3]==1)

    {

        if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<10)

            strcpy(matrix->col[6].l[8].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[1].allMeasurements[0][3]<20)

            strcpy(matrix->col[6].l[8].str, cor.corSensLightOK); //mot1

        else

            strcpy(matrix->col[6].l[8].str, cor.corSensLightHIGH); //mot1

    }

    else

        strcpy(matrix->col[6].l[8].str, cor.corSemMote);

}

void mot43(Matrix *matrix, Room *room, int *indice)
{


    /**Temperatura**/

    if(room->roomName[(*indice)].medi[2].allMeasurements[1][0]==1)

    {

        if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<10)



            strcpy(matrix->col[6].l[12].str, cor.corSensTempLOW); //mot1



        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][0]<20)



            strcpy(matrix->col[6].l[12].str, cor.corSensTempOK);



        else



            strcpy(matrix->col[6].l[12].str, cor.corSensTempHIGH);



    }



    else

        strcpy(matrix->col[6].l[12].str, cor.corSemMote); //mot1

    /**Humidade**/


    if(room->roomName[(*indice)].medi[2].allMeasurements[1][1]==1)

    {

        if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<10)
            strcpy(matrix->col[7].l[12].str, cor.corSensHumLOW); //mot1

        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][1]<20)
            strcpy(matrix->col[7].l[12].str, cor.corSensHumOK); //mot1
        else
            strcpy(matrix->col[7].l[12].str, cor.corSensHumHIGH); //mot

    }
    else
        strcpy(matrix->col[7].l[12].str, cor.corSemMote); //mot1

    /**Ph**/

    if(room->roomName[(*indice)].medi[2].allMeasurements[1][2]==1)
    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<10)
            strcpy(matrix->col[7].l[13].str, cor.corSensPhLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][2]<20)
            strcpy(matrix->col[7].l[13].str, cor.corSensPhOK); //mot1
        else
            strcpy(matrix->col[7].l[13].str, cor.corSensPhHIGH);
    }
    else
        strcpy(matrix->col[7].l[13].str, cor.corSemMote);
    /**Light**/

    if(room->roomName[(*indice)].medi[2].allMeasurements[1][3]==1)

    {
        if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<10)
            strcpy(matrix->col[6].l[13].str, cor.corSensLightLOW); //mot1
        else if(room->roomName[(*indice)].medi[2].allMeasurements[0][3]<20)
            strcpy(matrix->col[6].l[13].str, cor.corSensLightOK); //mot1
        else
            strcpy(matrix->col[6].l[13].str, cor.corSensLightHIGH); //mot1

    }
    else
        strcpy(matrix->col[6].l[13].str, cor.corSemMote);

}




void imprimeMots4(Matrix *matrix, Room *room, int *indice, int *confirmation)

{



    if((room->countRoom - (*confirmation))>3)

    {

        for(int i=6; i<13; i++)

        {

            for(int j=7; j<14; j++)

            {

                strcpy(matrix->col[i].l[j].str, cor.corSala4);

            }

        }

        if(room->roomName[(*indice)].numeroMots==0 || room->roomName[(*indice)].numeroMots>3

                || room->roomName[(*indice)].numeroMots<0)

        {

            strcpy(matrix->col[12].l[7].str, cor.corSemMote); //mot1

            strcpy(matrix->col[6].l[7].str, cor.corSemMote); //mot2

            strcpy(matrix->col[6].l[13].str, cor.corSemMote); //mot3

        }

        else if(room->roomName[(*indice)].numeroMots==1)

        {

            mot41(matrix, room, indice);



        }

        else if(room->roomName[(*indice)].numeroMots==2)

        {

            mot41(matrix, room, indice);

            mot42(matrix, room, indice);



        }



        else if(room->roomName[(*indice)].numeroMots==3)

        {

            mot41(matrix, room, indice);

            mot42(matrix, room, indice);

            mot43(matrix, room, indice);







        }



    }else

        {

            for(int i=6; i<13; i++)

            {

                for(int j=7; j<14; j++)

                {

                    strcpy(matrix->col[i].l[j].str, cor.corSemSala);

                }

            }

        }

        (*indice)++;

}

void imprime(Matrix matrix)
{
    printf("[");
    for(int i=0; i<MatrixSize; i++)
    {
        for(int j=0; j<MatrixSize; j++)
        {
            printf("%s,", matrix.col[i].l[j].str);
        }
    }
    printf("]\n");
}

void colocaatuadores1(Matrix *matrix, Room *room, int *indice)
{
    if((*indice)< room->countRoom)
    {
        if(room->roomName[(*indice)].countActuador == 0)
        {
            /*pinta cor de fundo no sitio dos sensores*/

        }
        else if(room->roomName[(*indice)].countActuador == 1)
        {
            if(!strcmp(room->roomName[(*indice)].ActuadorName[0], "FAN"))
            {
                strcpy(matrix->col[19].l[10].str, cor.corExisteAtuador);
                if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                {
                    strcpy(matrix->col[19].l[10].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[19].l[10].str, cor.vermelho);  //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[1], "HEATER"))
            {
                strcpy(matrix->col[20].l[10].str, cor.corExisteAtuador);
                if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                {
                    strcpy(matrix->col[20].l[10].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[20].l[10].str, cor.vermelho);

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[2], "LIGHT"))
            {
                strcpy(matrix->col[19].l[11].str, cor.corExisteAtuador); //fan
                if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                {
                    strcpy(matrix->col[19].l[11].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[19].l[11].str, cor.vermelho);  //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[3], "ELECTROVALVE"))
            {
                strcpy(matrix->col[20].l[11].str, cor.corExisteAtuador); //fan
                if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                {
                    strcpy(matrix->col[20].l[11].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[20].l[11].str, cor.vermelho);  //fan
            }
        }
        else if(room->roomName[(*indice)].countActuador == 2)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[19].l[10].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[19].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[10].str, cor.vermelho);  //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[20].l[10].str, cor.corExisteAtuador); //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[20].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[10].str, cor.vermelho);  //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[19].l[11].str, cor.corExisteAtuador); //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[19].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[11].str, cor.vermelho);  //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[20].l[11].str, cor.corExisteAtuador); //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[20].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[11].str, cor.vermelho);  //fan
                }

            }
        }
        else if(room->roomName[(*indice)].countActuador == 3)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[19].l[10].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[19].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[10].str, cor.vermelho);  //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[20].l[10].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[20].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[10].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[19].l[11].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[19].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[11].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[20].l[11].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[20].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[11].str, cor.vermelho); //fan
                }

            }

        }
        else if(room->roomName[(*indice)].countActuador == 4)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[19].l[10].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[19].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[10].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[20].l[10].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[20].l[10].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[10].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[19].l[11].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[19].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[11].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[20].l[11].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[20].l[11].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[20].l[11].str, cor.vermelho); //fan
                }

            }
        }
        (*indice)++;
    }
}

void colocaatuadores2(Matrix *matrix, Room *room, int *indice)
{
    if((*indice)< room->countRoom)
    {
        if(room->roomName[(*indice)].countActuador == 0)
        {
            /*pinta cor de fundo no sitio dos sensores*/

        }
        else if(room->roomName[(*indice)].countActuador == 1)
        {
            if(!strcmp(room->roomName[(*indice)].ActuadorName[1], "FAN"))
            {
                strcpy(matrix->col[18].l[21].str, cor.corExisteAtuador);
                if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                {
                    strcpy(matrix->col[18].l[21].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[18].l[21].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[1], "HEATER"))
            {
                strcpy(matrix->col[19].l[21].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                {
                    strcpy(matrix->col[19].l[21].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[19].l[21].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[2], "LIGHT"))
            {
                strcpy(matrix->col[18].l[22].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                {
                    strcpy(matrix->col[18].l[22].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[18].l[22].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[3], "ELECTROVALVE"))
            {
                strcpy(matrix->col[19].l[22].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                {
                    strcpy(matrix->col[19].l[22].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[19].l[22].str, cor.vermelho); //fan
            }
        }
        else if(room->roomName[(*indice)].countActuador == 2)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[18].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[18].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[19].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[19].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[18].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[18].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[19].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[19].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[22].str, cor.vermelho); //fan
                }

            }
        }
        else if(room->roomName[(*indice)].countActuador == 3)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[18].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[18].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[19].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[19].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[18].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[18].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[19].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[19].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[22].str, cor.vermelho); //fan
                }

            }

        }
        else if(room->roomName[(*indice)].countActuador == 4)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[18].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[18].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[19].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[19].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[18].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[18].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[18].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[19].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[19].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[19].l[22].str, cor.vermelho); //fan
                }

            }
        }
        (*indice)++;
    }
}

void colocaatuadores3(Matrix *matrix, Room *room, int *indice)
{
    if((*indice)< room->countRoom)
    {
        if(room->roomName[(*indice)].countActuador == 0)
        {
            /*pinta cor de fundo no sitio dos sensores*/

        }
        else if(room->roomName[(*indice)].countActuador == 1)
        {
            if(!strcmp(room->roomName[(*indice)].ActuadorName[1], "FAN"))
            {
                strcpy(matrix->col[9].l[21].str, cor.corExisteAtuador);
                if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                {
                    strcpy(matrix->col[9].l[21].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[9].l[21].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[1], "HEATER"))
            {
                strcpy(matrix->col[10].l[21].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                {
                    strcpy(matrix->col[10].l[21].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[10].l[21].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[2], "LIGHT"))
            {
                strcpy(matrix->col[9].l[22].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                {
                    strcpy(matrix->col[9].l[22].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[9].l[22].str, cor.vermelho); //fan

            }
            else if(!strcmp(room->roomName[(*indice)].ActuadorName[3], "ELECTROVALVE"))
            {
                strcpy(matrix->col[10].l[22].str, cor.corExisteAtuador);  //fan
                if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                {
                    strcpy(matrix->col[10].l[22].str, cor.verde); //fan
                }
                else
                    strcpy(matrix->col[10].l[22].str, cor.vermelho); //fan
            }
        }
        else if(room->roomName[(*indice)].countActuador == 2)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[9].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[9].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[10].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[10].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[9].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[9].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[10].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[10].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[22].str, cor.vermelho); //fan
                }

            }
        }
        else if(room->roomName[(*indice)].countActuador == 3)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[9].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[9].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[10].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[10].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[9].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[9].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[10].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[10].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[22].str, cor.vermelho); //fan
                }

            }

        }
        else if(room->roomName[(*indice)].countActuador == 4)
        {
            for(int i=0; i<room->roomName[(*indice)].countActuador; i++)
            {
                if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "FAN"))
                {
                    strcpy(matrix->col[9].l[21].str, cor.corExisteAtuador);
                    if(room->roomName[(*indice)].ActuadorOnOff[0]==1)
                    {
                        strcpy(matrix->col[9].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "HEATER"))
                {
                    strcpy(matrix->col[10].l[21].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[1]==1)
                    {
                        strcpy(matrix->col[10].l[21].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[21].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "LIGHT"))
                {
                    strcpy(matrix->col[9].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[2]==1)
                    {
                        strcpy(matrix->col[9].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[9].l[22].str, cor.vermelho); //fan

                }
                else if(!strcmp(room->roomName[(*indice)].ActuadorName[i], "ELECTROVALVE"))
                {
                    strcpy(matrix->col[10].l[22].str, cor.corExisteAtuador);  //fan
                    if(room->roomName[(*indice)].ActuadorOnOff[3]==1)
                    {
                        strcpy(matrix->col[10].l[22].str, cor.verde); //fan
                    }
                    else
                        strcpy(matrix->col[10].l[22].str, cor.vermelho); //fan
                }

            }
        }
        (*indice)++;
    }
}

void inicializaTela(Room *room, Matrix *ma)
{

    inicializaCores();

    desenhaFundo(ma);

    desenhaMoldura(ma);

    desenhaLimites(ma);
}

void adicionaMotsAtuadores(Room *room, Matrix *ma)
{

    int indice=0;
    int confirmation=0;

    imprimeMots1(ma, room, &indice, &confirmation);
    imprimeMots2(ma, room, &indice, &confirmation);
    imprimeMots3(ma, room, &indice, &confirmation);
    imprimeMots4(ma, room, &indice, &confirmation);
    if(room->countRoom>0)
    {
        if(!strcmp(room->roomName[0].placeName, "EXTERIOR") && room->countRoom>1)
            indice=1;
        else
            indice=0;
    }

    colocaatuadores1(ma,room, &indice);

    colocaatuadores2(ma,room, &indice);

    colocaatuadores3(ma,room, &indice);
}

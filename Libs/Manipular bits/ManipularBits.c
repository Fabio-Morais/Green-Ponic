#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Message.h"
#include "vetor.h"

int main()
{
    Mensagem StructMensagem;
    Room room;
    vetor *vec=vetor_novo();
    leFicheiroConfiguration(vec);
    char str[80]= "7E 45 00 FF FF 00 05 0A 3F 0C 00 00 00 E1 00 00 19 8E 7F 0D 48 81 7E\n";
    //fgets(str, 80, stdin);
    int confirmation= ConfirmationMessage(str, &StructMensagem);
    if(confirmation == 1)
    {
        printf("\n\nPrint dos valores nas variaveis da struct\n");
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s -", StructMensagem.MessageStart, StructMensagem.MoteId, StructMensagem.PayloadLength, StructMensagem.RawVoltage,
               StructMensagem.RawVisibleLight,StructMensagem.RawCurrent, StructMensagem.RawTemperature, StructMensagem.RawHumidity, StructMensagem.EndMenssage);
        printf("\n%f", convertToDecimal(StructMensagem.EndMenssage));

    }
    /*teste*/
    /*
        strcpy(StructMensagem.RawTemperature, "1D3F");
        printf("\n->Temperatura: %f", realTemperatureMeasurements(&StructMensagem));

        strcpy(StructMensagem.RawHumidity, "0227");
        printf("\n->humidade: %f", realHumidityMeasurements(&StructMensagem));

        strcpy(StructMensagem.RawVisibleLight, "00BD");
        printf("\n->Luz: %f", realLightMeasurements(&StructMensagem));

        strcpy(StructMensagem.RawCurrent, "001E");
        printf("\n->PH: %f", realPhMeasurements(&StructMensagem));

    */

    toMedicoes(&room, vec);

    /**imprime estrutura da struct room**/
    for(int i=0; i<room.countRoom; i++)
    {
        printf("\n\n\nDIVISAO %d", i+1);
        printf("\nNumero de mots: %d",room.roomName[i].numeroMots );
        for(int j=0; j<room.roomName[i].numeroMots; j++)
        {
            printf("\nMot %d ", room.roomName[i].medi[j].motNumber);
            for(int z=0; z< 4; z++)
                printf("%d: %d   ",z, (int)room.roomName[i].medi[j].allMeasurements[1][z] );
        }


    }
    toActuador(&room, vec);

    for(int i=0; i<room.countRoom; i++)
    {
        printf("\n\nDivisao %d\n", i+1);
        for(int j=0; j< room.roomName[i].countActuador; j++)
        {
            printf("\n->%s", room.roomName[i].ActuadorName[j]);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "query.h"
/*DELETE FROM tablename*/



/*MEDIÇOES SENSORES*/
int enviaMedicoesSensores (PGconn *conn, char *sensor, int mot, float values){
	char query[250];
	sprintf(query ,"INSERT INTO medi_sensor (valor, sensor_id, tempo) VALUES (%f, (SELECT id_sensor FROM sensor WHERE (nome='%s' AND mot_id=%d)), (SELECT LOCALTIME(0)))", values, sensor, mot );
	PGresult *res = PQexec(conn, query);

	printf("\n\nMEDI SENSOR->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}

/*MEDIÇOES ATUADORES*/
int enviaMedicoesAtuadores (PGconn *conn,char *atuador, int indice, char* estado){
	char query[250];
	sprintf(query ,"INSERT INTO medi_atuador (on_off,  atuador_id, tempo) VALUES ('%s', (SELECT id_atua FROM atuador WHERE (nome='%s' AND divisao_id = (SELECT id_div FROM divisao WHERE indice=%d))),(SELECT LOCALTIME(0)))", estado, atuador, indice);
	PGresult *res = PQexec(conn, query);

	printf("\n\nMED.ATU->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}


/**DIVISAO**/
int enviaDivisao(PGconn *conn,char *nomeDivisao, int indice,unsigned int num_mots){
	char query[250];
	sprintf(query ,"INSERT INTO divisao (nome, indice, num_mots) VALUES ('%s', %d, %d)", nomeDivisao, indice, num_mots);
	PGresult *res = PQexec(conn, query);
	printf("\n\nDIVISAO->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}

/**MOTE**/
int enviaMote(PGconn *conn, int num_mot, char *nomeDivisao, int indiceDivisao){
	char query[250];
	sprintf(query ,"INSERT INTO mote (num_mot, divisao_id) VALUES (%d, (SELECT id_div FROM divisao WHERE (nome = '%s' AND indice=%d) LIMIT 1))", num_mot, nomeDivisao, indiceDivisao);
	PGresult *res = PQexec(conn, query);
	printf("\n\n\nMOTE->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}

/**SENSOR**/
int enviaSensor(PGconn *conn, char *nomeSensor, int num_mot){
	char query[250];
	sprintf(query ,"INSERT INTO sensor (nome, mot_id) VALUES ('%s', (SELECT num_mot FROM mote WHERE num_mot=%d LIMIT 1) )", 
		nomeSensor, num_mot);
	PGresult *res = PQexec(conn, query);
	printf("\n\n\nSENSOR->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}

/**ATUADOR**/
int enviaAtuador(PGconn *conn, char *nomeAtuador, char *nomeDivisao, int indiceDivisao){
	char query[250];
	sprintf(query ,"INSERT INTO atuador (nome, divisao_id) VALUES ('%s', (SELECT id_div FROM divisao WHERE (nome = '%s' AND indice=%d) LIMIT 1))", nomeAtuador, nomeDivisao, indiceDivisao);
	PGresult *res = PQexec(conn, query);
	printf("\n\n\nATUADOR->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);
}

int enviaRegra(PGconn *conn,int linha){
	char query[250];
	sprintf(query ,"INSERT INTO regra (linha_regra) VALUES (%d)", linha);
	PGresult *res = PQexec(conn, query);
	printf("\n\n\nREGRA->%d",  PQresultStatus(res) == PGRES_COMMAND_OK);

}

int enviaRegraGeral(PGconn *conn, int linha, char *nomeSensor,int num_mot, char *operador, int valor, char *nomeAtuador, char *nomeDivisao, int indiceDivisao, char *estadoAtuador){
char query[500];
	sprintf(query ,"INSERT INTO regra_geral (regra_id, sensor_id, operador, valor,atuador_id, acao) VALUES ((SELECT id_regra FROM regra WHERE linha_regra=%d),(SELECT id_sensor FROM sensor WHERE (nome='%s' AND mot_id=%d) LIMIT 1),'%s',%d, (SELECT id_atua FROM atuador WHERE (nome ='%s' AND divisao_id=(SELECT id_div FROM divisao WHERE (nome = '%s' AND indice=%d) LIMIT 1)) LIMIT 1),'%s')", 
	linha, nomeSensor,num_mot, operador, valor, nomeAtuador, nomeDivisao, indiceDivisao, estadoAtuador);
	PGresult *res = PQexec(conn, query);
	printf("\n\nREGRA GERAL->%d",  (PQresultStatus(res) == PGRES_COMMAND_OK));

}

/*coloca tudo desligado*/
int insereAtuadoresDefault(PGconn *conn, Room *room){
	for(int j=0; j<room->countRoom; j++)
		for(int i=0; i< room->roomName[j].countActuador; i++)
			enviaMedicoesAtuadores(conn, room->roomName[j].ActuadorName[i], j, "off");		
}

PGconn* inicializaSql(){
    PGconn *conn = PQconnectdb("host='db.fe.up.pt' user='sinf19a38' password='UbwJSLsu'");
	
	if ( PQstatus(conn) != CONNECTION_OK) {
		printf( "Failed to connect to Database\n %s", PQerrorMessage(conn)); 
		exit(-1);
	}
	/* define schema para estufa*/
	PGresult *schema = PQexec(conn, "SET search_path TO estufa");
	/*inicializa o time*/
	PGresult *time = PQexec(conn, "SET TIME ZONE 'UTC-1'");
    return conn;
}


/*INCLUIR FUNÇOES DE CONFIGURAÇAO*/
int insereConfiguracao (PGconn *conn, Room *room){
	char sensores[5][25]={"temp","hum","ph","light" };
    for(int i=0; i<room->countRoom; i++){

                        /*  ROOM NAME    ,    INDICE DIV      ,     NUM_MOTS  */
    	enviaDivisao(conn, room->roomName[i].placeName, i, room->roomName[i].numeroMots);//DIVISAO
		for(int j=0; j<room->roomName[i].countActuador; j++){
			/*so envia atuador se nao estiver escrito NULL*/
			if(strcmp(room->roomName[i].ActuadorName[j], "NULL")){
							/*  NOME ATUADOR		,		NOME DIVISAO		,			INDICE DIV*/
			enviaAtuador(conn, room->roomName[i].ActuadorName[j], room->roomName[i].placeName, i);//ATUADOR
			}

		}

		for(int j=0; j<room->roomName[i].numeroMots; j++){
					/*		NUM MOTE  ,	NOME DIV, INDICE DIV*/
			enviaMote(conn, room->roomName[i].mots[j],room->roomName[i].placeName, i);//MOTE
		}

		for(int j=0; j<room->roomName[i].numeroMots; j++){

			for(int z=0; z<4; z++){
				if(room->roomName[i].medi[j].allMeasurements[1][z]){
								/*		NOME SENSOR  	 ,  	NUM MOTE*/
					enviaSensor(conn,sensores[z], room->roomName[i].medi[j].motNumber);//SENSOR
				}
					
			
			}
		}
	}	
	insereAtuadoresDefault(conn, room);


}

int insereRegra (PGconn *conn, Room *room){
	for(int i=0; i<room->compRegra; i++){
		enviaRegra(conn, i);
		enviaRegraGeral(conn, i, room->regra[i].sensor, room->regra[i].num_mot,room->regra[i].operacao,room->regra[i].valor,
		room->regra[i].atuador,room->regra[i].divisao,room->regra[i].indiceDivisao,room->regra[i].acao );
	}
	

}

int insereMedicoes (PGconn *conn, Room *room, Mensagem *mensagem){
	char sensores[5][25]={"temp","hum","ph","light" };
	char on_off[5];
	int indiceDiv=mensagem->indiceDiv;
	int mot= mensagem->motIndice;
	printf("\nmot: %d\n", mensagem->motNumber);
	if(indiceRoomMotx(room, mensagem->motNumber)!=-1){
		
		for(int i=0; i<4; i++){
			if(room->roomName[indiceDiv].medi[mot].allMeasurements[0][i])
				enviaMedicoesSensores(conn, sensores[i], room->roomName[indiceDiv].medi[mot].motNumber,room->roomName[indiceDiv].medi[mot].allMeasurements[0][i] );
		}
		for(int i=0; i< room->roomName[indiceDiv].countActuador; i++){
			if(room->roomName[indiceDiv].ActuadorOnOff[i])
				strcpy(on_off, "on");
			else if(!room->roomName[indiceDiv].ActuadorOnOff[i])
				strcpy(on_off, "off");
			enviaMedicoesAtuadores(conn, room->roomName[indiceDiv].ActuadorName[i], indiceDiv, on_off);		
		
		}
		printf("\n2");
	}
}

		
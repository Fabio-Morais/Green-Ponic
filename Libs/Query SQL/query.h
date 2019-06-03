
#include <stdio.h>
#include <stdlib.h>
#include "Message.h"
#include <postgresql/libpq-fe.h>

/* FAZ INICIALIZAÇAO
*faz connect, set schema, set localtime
*/
PGconn* inicializaSql();



/*INSERE CONFIGURAÇAO
* Insere: divisao, atuador,mote e sensor
*/
int insereConfiguracao (PGconn *conn, Room *room);

/*INSERE REGRAS
*
*/
int insereRegra (PGconn *conn, Room *room);

/*INSERE MEDICOES SENSORES/ATUADORES
*
*/
int insereMedicoes (PGconn *conn, Room *room, Mensagem *mensagem);
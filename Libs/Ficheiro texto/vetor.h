#ifndef VETOR_H
#define VETOR_H
#define MaxLength 35
#define MaxBuffer 255
/**
* registo para armazenar cada elemento (apenas uma string neste caso)
*/
typedef struct
{
    /*ROOM*/
    char *RoomName;

    /*SENSORES*/
    char **SensorName;
    int *IdentMots;//Valor da mot em cada posiçao do vetor, de acordo com o indice do Sensor correspondente
    int compIdentMots; // comprimento do vetor IdentMots
    int CountMots;//Numero diferentes de mots
    unsigned int SensorCount; //Numero de sensores no vetor de Sensores
    unsigned int SensorCapacity;//capacidade maxima para colocar sensores no vetor

    /*ACTUADORES*/
    char **ActuadorName;
    unsigned int ActuadorCount;//Numero de actuadores no vetor de Actuadores
    unsigned int ActuadorCapacity;//Capacidade maxima para colocar actuadores no vetor

} v_elemento;
/*Utilizar esta estrutura para o SensorRules.txt
Colocar no mesmo indice a condiçao e o valor do respetivo sensor*/

/*
****E SE:****
Nao colocar os sensores/atuadores todos?
Nao inserir uma divisao que ja tenha adicionado
*/


/**
* este registo contem um vetor de elementos, um contador do tamanho e outro para a capacidade
*/
typedef struct
{
  /** numero de elementos do vetor */
  int tamanho;

  /** capacidade do vetor */
  int capacidade;

  /** array de elementos armazenados */
  v_elemento* elementos;

} vetor;

void limpaEspacos(char *string);

/*Funçao igual ao STRTOK, porem conseguimos colocar um strtok dentro de outro strtok*/
char* strtok_r(char *str, const char *delim, char **nextp);


/*
Toma as decisões para qual vetor vai colocar (RoomName, Sensores, Atuadores)
    Token-> frase que foi usado o strtok
    Count-> serve para sabermos onde enviar a string
*/
void ToStruct(vetor *room, char *token, short *count);

/*
Return -1 se ocorrer erro
return 1 se correr tudo bem
    *vec-> para colocar na struct
*/
int leFicheiroConfiguration(vetor *vec);




/**
*  cria um novo vetor com tamanho 0 e capacidade 0
*  retorno: apontador para o vetor criado
*  nota: se vetor nao foi criado retorna NULL
*/
vetor* vetor_novo();


/**
*  indica o o numero de elementos do vetor Room
*  parametro: vec apontador para vetor
*  retorno: -1 se ocorrer algum erro ou numero de elementos do vetor
*/
int Room_tamanho(vetor *vec);


/**
*  indica o o numero de elementos do vetor Sensor
*  parametro: vec apontador para vetor
*  pos: Se -1 então retorna o tamanho do ultimo elemento ROOM
*  retorno: -1 se ocorrer algum erro ou numero de elementos do vetor
*/
int Sensor_tamanho(vetor *vec,  int pos);


/**
*  indica o o numero de elementos do vetor Actuador
*  parametro: vec apontador para vetor
*  pos: Se -1 então retorna o tamanho do ultimo elemento ROOM
*  retorno: -1 se ocorrer algum erro ou numero de elementos do vetor
*/
int Actuador_tamanho(vetor *vec,  int pos);

/**
*  retorna o elemento armazenado na posicao especificada
*  parametro: vec apontador para vetor
*  parametro: pos indice do elemento
*  retorno: apontador para a string na posicao correspondente
*  nota: se ocorrer algum erro retorna NULL (p.ex. se valor pos indicar uma posicao invalida)
*/
const char* vetor_room(vetor *vec, int pos);

/**
*  insere um elemento na posicao especificada
*  parametro: vec apontador para vetor
*  parametro: valor string a inserir
*  parametro: pos indice do elemento onde se pretende inserir a string, se pos=tamanho ou pos=-1 insere no fim do vetor
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou o valor de pos se bem sucedido
*  nota: se a capacidade nao for suficiente para guardar novo elemento, devera ser aumentada para 2x em relacao a capacidade anterior; inicialmente aumenta para capacidade 1
*/
int vetor_insere_Room(vetor *vec, char* valor, int pos);


/**
*  insere um elemento na posicao especificada
*  parametro: vec apontador para vetor
*  parametro: valor string a inserir
*  parametro: pos_room indice do elemento onde se pretende inserir a string, se pos_room=tamanho ou pos_room=-1 insere no fim do vetor
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou o valor de pos se bem sucedido
*  nota: se a capacidade nao for suficiente para guardar novo elemento, devera ser aumentada para 2x em relacao a capacidade anterior; inicialmente aumenta para capacidade 1
*/
int vetor_insere_Sensor(vetor *vec, char* valor, int pos_room);

/**
*  insere um elemento na posicao especificada
*  parametro: vec apontador para vetor
*  parametro: valor string a inserir
*  parametro: pos_room indice do elemento onde se pretende inserir a string, se pos_room=tamanho ou pos_room=-1 insere no fim do vetor
*  retorno: -1 se ocorrer algum erro (p.ex. se valor pos indicar uma posicao invalida) ou o valor de pos se bem sucedido
*  nota: se a capacidade nao for suficiente para guardar novo elemento, devera ser aumentada para 2x em relacao a capacidade anterior; inicialmente aumenta para capacidade 1
*/
int vetor_insere_Actuador(vetor *vec, char* valor, int pos_room);


/**
*  devolve a posicao do elemento especificado
*  parametro: vec apontador para vetor
*  parametro: str string pretendida
*  retorno: posicao do elemento ou -1 se ocorrer algum erro ou nao encontrar elemento
*/
int vetor_pesquisa(vetor *vec, const char* roomName);

#endif

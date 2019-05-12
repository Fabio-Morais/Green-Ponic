## Visão geral

* ### 4 sensores disponiveis:
  * Temperatura
  * Humidade
  * ph
  * luz

* ### 4 atuadores disponiveis:
  * Ventoinha
  * Aquecedor
  * luz (cortinhas/luz artificial)
  * eletrovalvulas 

* ### Divisões disponiveis:
  * Exterior
  * Alface
  * Morango
  * (Permite adicionar mais 2 divisões)

-----

**Nomenclatura para configuração do sistema**

* Sensores
  * TEMP
  * HUM
  * PH
  * LIGHT
 
* Atuadores
  * FAN
  * HEATER
  * LIGHT
  * ELECTROVALVE


* ### Configuração do SensorConfigurations.txt
**Não é sensivel a espaços nem a letras maisculas**

room_name:sensor_name,sensor_name .... :actuator,actuator ....


Ex: 

➢LIVING_ROOM:TEMP3,HUM3,LIGHT3,TEMP4,HUM4,LIGHT4:HEAT_LR,LIGHT_LR



-----

* ### Configuração do SensorConfigurations.txt
**Não é sensivel a espaços nem a letras maisculas**

<room_name>: <sensor_name><condition><value> [AND / OR<sensor_name><condition><value>] <actuator>:<state>[,<actuator>:<state>] 
  
Ex: 

➢ROOM1: TEMP1>25 AND LIGHT1>3000:HEAT_ROOM1=OFF,LIGHT_ROOM1=OFF

----

Organização da representação dos sensores/atuadores  
<img src="https://user-images.githubusercontent.com/47572923/54824756-c2050580-4ca3-11e9-9e30-a4ebefa41bd6.png" data-canonical-src="https://user-images.githubusercontent.com/47572923/54824756-c2050580-4ca3-11e9-9e30-a4ebefa41bd6.png" width="90" height="90" />

* ### Sensores

| TEMP  | HUM |
| ---- | ------ |
| PH  | LIGHT  |


* ### Atuadores

| FAN  | HEATER |
| ---- | ------ |
| LIGHT  | ELECTROVALVE  |

--Nome da Schema --
CREATE SCHEMA IF NOT EXISTS  estufa;

--Limpa tabelas para inserir novos dados--
DROP TABLE IF EXISTS estufa.divisao,estufa.atuador, estufa.mote, estufa.medi_atuador,
estufa.regra, estufa.sensor, estufa.medi_sensor, estufa.regra_geral CASCADE ;


--DIVISÃO--
CREATE TABLE IF NOT EXISTS estufa.divisao(
	id_div SERIAL PRIMARY KEY,
	nome VARCHAR(256),
	indice INTEGER UNIQUE,
);

--ATUADOR--
CREATE TABLE IF NOT EXISTS estufa.atuador(
	nome VARCHAR(256) PRIMARY KEY ,
	divisao_id INTEGER REFERENCES estufa.divisao(id_div) ON DELETE CASCADE  NOT NULL
);


--MOTE--
CREATE TABLE IF NOT EXISTS estufa.mote(
	num_mot INTEGER PRIMARY KEY,
	divisao_id INTEGER REFERENCES estufa.divisao(id_div) ON DELETE CASCADE NOT NULL
);

--MEDI_ATUADOR--
CREATE TABLE IF NOT EXISTS estufa.medi_atuador(
	id_ma SERIAL PRIMARY KEY,
	on_off VARCHAR(5),
	atuador_nome VARCHAR(256) REFERENCES estufa.atuador(nome) ON DELETE CASCADE NOT NULL,
	tempo TIMESTAMP(3)
);

--REGRA--
CREATE TABLE IF NOT EXISTS estufa.regra(
	id_regra SERIAL PRIMARY KEY,
	linha_regra INTEGER UNIQUE
);

--SENSOR--
CREATE TABLE IF NOT EXISTS estufa.sensor(
	nome VARCHAR(256) PRIMARY KEY ,
	mot_id INTEGER REFERENCES estufa.mote(num_mot) ON DELETE CASCADE NOT NULL
);


--MEDI_SENSOR--
CREATE TABLE IF NOT EXISTS estufa.medi_sensor(
	id_ms SERIAL PRIMARY KEY,
	valor NUMERIC(10,2),
	sensor_nome VARCHAR(256) REFERENCES estufa.sensor(nome) ON DELETE CASCADE NOT NULL,
	tempo TIMESTAMP(3)
);

--REGRA_GERAL--
CREATE TABLE IF NOT EXISTS estufa.regra_geral(
	regra_id INTEGER REFERENCES estufa.regra(id_regra) ON DELETE CASCADE NOT NULL,
	sensor_nome VARCHAR(256) REFERENCES estufa.sensor(nome) ON DELETE CASCADE NOT NULL,
	operador VARCHAR(2),
	valor INTEGER,
	atuador_nome VARCHAR(256) REFERENCES estufa.atuador(nome) ON DELETE CASCADE NOT NULL, 
	acao VARCHAR(5),
	PRIMARY KEY (atuador_nome, sensor_nome, regra_id)
);


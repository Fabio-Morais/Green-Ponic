-- schema  to ESTUFA --
SET search_path TO estufa;

/*definir o fuso horario*/
SET TIME ZONE 'UTC-1';


/*
	****inserir valores defaults****
*/

							-- INSERIR DIVISAO--
INSERT INTO divisao (nome, indice, num_mots) VALUES ('exterior', 0, 1), 
													('alfaces', 1, 1),
													('morangos', 2, 1);
													
							-- INSERIR MOTE--
INSERT INTO mote (num_mot, divisao_id) VALUES (1, (SELECT id_div FROM divisao WHERE (nome = 'exterior' AND indice=0) LIMIT 1)),
											  (2, (SELECT id_div FROM divisao WHERE (nome = 'alfaces' AND indice=1) LIMIT 1)),
											  (4, (SELECT id_div FROM divisao WHERE (nome = 'morangos' AND indice=2) LIMIT 1));
											  
							-- INSERIR SENSOR--								  
INSERT INTO sensor (nome, mot_id) VALUES ('temp1', (SELECT num_mot FROM mote WHERE num_mot=1 LIMIT 1) ),
										 ('light1', (SELECT num_mot FROM mote WHERE num_mot=1 LIMIT 1) ),
										 ('hum1', (SELECT num_mot FROM mote WHERE num_mot=1 LIMIT 1) ),
										 
										 ('hum2', (SELECT num_mot FROM mote WHERE num_mot=2 LIMIT 1) ),
										 ('light2', (SELECT num_mot FROM mote WHERE num_mot=2 LIMIT 1) ),
										 ('temp2', (SELECT num_mot FROM mote WHERE num_mot=2 LIMIT 1) ),
										 ('ph2', (SELECT num_mot FROM mote WHERE num_mot=2 LIMIT 1)),
										 
										 ('hum4', (SELECT num_mot FROM mote WHERE num_mot=4 LIMIT 1)),
										 ('light4', (SELECT num_mot FROM mote WHERE num_mot=4 LIMIT 1)),
										 ('temp4', (SELECT num_mot FROM mote WHERE num_mot=4 LIMIT 1)),
										 ('ph4', (SELECT num_mot FROM mote WHERE num_mot=4 LIMIT 1) );
										 
							-- INSERIR ATUADOR--								  
INSERT INTO atuador (nome, divisao_id) VALUES ('FAN_alfaces', (SELECT id_div FROM divisao WHERE (nome = 'alfaces' AND indice=1) LIMIT 1)),
											  ('HEATER_alfaces', (SELECT id_div FROM divisao WHERE (nome = 'alfaces' AND indice=1) LIMIT 1)),
											  ('LIGHT_alfaces', (SELECT id_div FROM divisao WHERE (nome = 'alfaces' AND indice=1) LIMIT 1)),
											  ('ELECTROVALVE_alfaces', (SELECT id_div FROM divisao WHERE (nome = 'alfaces' AND indice=1) LIMIT 1)),
											  ('FAN_morangos', (SELECT id_div FROM divisao WHERE (nome = 'morangos' AND indice=2) LIMIT 1)),
											  ('HEATER_morangos', (SELECT id_div FROM divisao WHERE (nome = 'morangos' AND indice=2) LIMIT 1)),
											  ('LIGHT_morangos', (SELECT id_div FROM divisao WHERE (nome = 'morangos' AND indice=2) LIMIT 1)),
											  ('ELECTROVALVE_morangos', (SELECT id_div FROM divisao WHERE (nome = 'morangos' AND indice=2) LIMIT 1));
										 
							-- INSERIR REGRAS--	
INSERT INTO regra (linha_regra) VALUES (1),
									   (2),
									   (3),
									   (4),
									   (5),
									   (6),
									   (7),
									   (8),
									   (9),
									   (10),
									   (11),
									   (12),
									   (13),
									   (14),
									   (15),
									   (16);

							-- INSERIR REGRA GERAL--
INSERT INTO regra_geral (regra_id, sensor_nome, operador, valor,atuador_nome, acao) VALUES ( (SELECT id_regra FROM regra WHERE linha_regra=1),
																						'hum2' ,'>',10, 'FAN_alfaces' ,'on');
																						


-- MEDI ATUADOR --																		
INSERT INTO estufa.medi_atuador (on_off, atuador_nome, tempo) VALUES ('on', (SELECT nome FROM estufa.atuador WHERE (nome='FAN_alfaces')), (SELECT localtimestamp(0)));
/*SELECT LOCALTIME(0);*/

-- MEDI SENSOR --																		
INSERT INTO estufa.medi_sensor (valor, sensor_nome, tempo) VALUES (12, 'temp1', (SELECT localtimestamp(0)) );

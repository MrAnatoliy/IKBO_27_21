INSERT INTO brawler (name,Trophies,Strength) VALUES ('dynamike',678,10);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('mr p',583,10);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('barley',574,9);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('jessie',599,9);
INSERT INTO brawler (id, name,Trophies,Strength) VALUES (5, 'shelly',560,9);

SELECT nextval('seq_brawlerid');

INSERT INTO brawler (name,Trophies,Strength) VALUES ('edgar',568,9);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('nita',599,8);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('piper',574,8);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('spike',574,8);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('poco',494,7);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('bo',536,7);
INSERT INTO brawler (name,Trophies,Strength) VALUES ('fang',206,6);

INSERT INTO skin (id, name, Cost, BrawlerID) VALUES (1,'robomike',399,1);

SELECT nextval('seq_skinid');

INSERT INTO skin (name, Cost, BrawlerID) VALUES ('classic mike',0,1);
INSERT INTO skin (name, Cost, BrawlerID) VALUES ('golden barley',49,3);
INSERT INTO skin (name, Cost, BrawlerID) VALUES ('wizard barely',49,3);
INSERT INTO skin (name, Cost, BrawlerID) VALUES ('unicorn knight barley',149,3);

INSERT INTO gadget (name, Description, BrawlerID) VALUES ('satchel charge','stun for 1.5s',1);
INSERT INTO gadget (name, Description, BrawlerID) VALUES ('fidget spinner','spin and throw dinamite',1);
INSERT INTO gadget (name, Description, BrawlerID) VALUES ('service bell','buff porter',2);
INSERT INTO gadget (name, Description, BrawlerID) VALUES ('porter reinforcment','next attack spawn porter',2);

INSERT INTO best_gadgets (GadgetID,BrawlerID) VALUES (1,1);
INSERT INTO best_gadgets (GadgetID,BrawlerID) VALUES (3,2);
INSERT INTO best_gadgets (GadgetID,BrawlerID) VALUES (4,2);
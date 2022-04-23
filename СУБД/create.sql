CREATE SEQUENCE seq_brawlerid;
CREATE SEQUENCE seq_skinid
CREATE SEQUENCE seq_gadgetid;

CREATE TABLE brawler
(
id INT PRIMARY KEY DEFAULT nextval('seq_brawlerid'),
name TEXT,
Trophies INT,
Strength INT
);
CREATE TABLE skin
(
id INT PRIMARY KEY DEFAULT nextval('seq_skinid'),
name TEXT,
Cost INT,
BrawlerID INT,
FOREIGN KEY(BrawlerID) REFERENCES brawler(id)
);

CREATE TABLE gadget
(
name TEXT,
Description TEXT,
BrawlerID INT,
FOREIGN KEY(BrawlerID) REFERENCES brawler(id)
);

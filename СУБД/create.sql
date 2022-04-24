CREATE SEQUENCE seq_brawlerid;
CREATE SEQUENCE seq_skinid;
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
BrawlerID INT REFERENCES "brawler" ON DELETE CASCADE,
FOREIGN KEY(BrawlerID) REFERENCES brawler(id)
);

CREATE TABLE gadget
(
id INT PRIMARY KEY DEFAULT nextval('seq_gadgetid'),
name TEXT,
Description TEXT,
BrawlerID INT REFERENCES "brawler",
FOREIGN KEY(BrawlerID) REFERENCES brawler(id)
);

CREATE TABLE best_gadgets
(
GadgetID INT REFERENCES "gadget" ON DELETE RESTRICT,
BrawlerID INT REFERENCES "brawler" ON DELETE CASCADE,
FOREIGN KEY (GadgetID) REFERENCES "gadget"(id),
FOREIGN KEY (BrawlerID) REFERENCES "brawler"(id)
);
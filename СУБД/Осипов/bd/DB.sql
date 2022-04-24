CREATE SEQUENCE seq_songsid;
CREATE SEQUENCE seq_groupsid;
CREATE SEQUENCE seq_coversid;

CREATE TABLE groups
(
id INT PRIMARY KEY DEFAULT nextval('seq_groupsid'),
GroupName TEXT,
Country TEXT
);

CREATE TABLE songs
(
id INT PRIMARY KEY DEFAULT nextval('seq_songsid'),
SongName TEXT,
Genre TEXT,
Groupid INT REFERENCES groups ON DELETE CASCADE,
FOREIGN KEY (groupid) REFERENCES groups(id)
);

CREATE TABLE covers
(
id INT PRIMARY KEY DEFAULT nextval('seq_coversid'),
CoverName TEXT,
Songid INT REFERENCES songs ON DELETE CASCADE,
FOREIGN KEY (Songid) REFERENCES songs(id)
);

CREATE TABLE mlikelysongs
(
groupsid INT REFERENCES groups ON DELETE RESTRICT,
songsid INT REFERENCES songs ON DELETE CASCADE,
FOREIGN KEY (groupsid) REFERENCES groups(id),
FOREIGN KEY (songsid) REFERENCES songs(id)
);



INSERT INTO groups (id, GroupName, Country) VALUES (1, 'Skan and Krale', 'France/Canada');
SELECT nextval('seq_groupsid');
INSERT INTO groups (GroupName, Country) VALUES ('RHCP', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Brian Tyler', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Sabaton', 'Sweden');
INSERT INTO groups (GroupName, Country) VALUES ('JORN', 'Norway');
INSERT INTO groups (GroupName, Country) VALUES ('Fall Out Boy', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Tristam', 'Canada');
INSERT INTO groups (GroupName, Country) VALUES ('NF', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Thousand Foot Krutch', 'Canada');
INSERT INTO groups (GroupName, Country) VALUES ('Alan Walker', 'UK');
INSERT INTO groups (GroupName, Country) VALUES ('Alan Walker', 'UK');
INSERT INTO groups (GroupName, Country) VALUES ('Alan Walker', 'UK');
INSERT INTO groups (GroupName, Country) VALUES ('Celldweller', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Essenger', 'U.S.A.');
INSERT INTO groups (GroupName, Country) VALUES ('Warriyo', 'U.S.A.');

INSERT INTO songs (SongName, Genre, Groupid) VALUES ('No Glory', 'Electro Music', 1);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Californication', 'Alternative Rock', 2);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Transformers Prime OST', 'Epic Music', 3);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Bismarck', 'Power-Metal', 4);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('I Walk Alone', 'Metal', 5);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Centuries', 'Pop-Rock', 6);
INSERT INTO songs (id, SongName, Genre, Groupid) VALUES (7,'Frame of Mind', 'Electro Music', 7);
SELECT nextval('seq_songsid');
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('The Search', 'Rap', 8);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Let The Sparks Fly', 'Alternative', 9);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Faded', 'Electro Music', 10);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Live Fast', 'Hip-Hop', 10);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Paradise', 'Electro Music', 10);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Lost in Time', 'Metal', 11);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Tenebrous', 'Rock', 12);
INSERT INTO songs (SongName, Genre, Groupid) VALUES ('Mortals', 'Electro Music', 13);


INSERT INTO covers (CoverName, Songid) VALUES ('Solence Cover', 2);
INSERT INTO covers (CoverName, Songid) VALUES ('Niall Stenson Cover', 3);
INSERT INTO covers (CoverName, Songid) VALUES ('Radiotapok Cover', 4);
INSERT INTO covers (CoverName, Songid) VALUES ('Tarja Turunen Cover', 5);
INSERT INTO covers (CoverName, Songid) VALUES ('Solence and Jonathan Young Cover', 6);

INSERT INTO mlikelysongs (groupsid, songsid) VALUES (1, 1);
INSERT INTO mlikelysongs (groupsid, songsid) VALUES (2, 2);
INSERT INTO mlikelysongs (groupsid, songsid) VALUES (10, 10);
INSERT INTO mlikelysongs (groupsid, songsid) VALUES (10, 11);
INSERT INTO mlikelysongs (groupsid, songsid) VALUES (10, 12);
ALTER SEQUENCE seq_songsid RESTART WITH 1;
ALTER SEQUENCE seq_groupsid RESTART WITH 1;
ALTER SEQUENCE seq_coversid RESTART WITH 1;

TRUNCATE mlikelysongs, songs, groups, covers;

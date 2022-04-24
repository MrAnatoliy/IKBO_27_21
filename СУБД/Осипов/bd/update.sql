UPDATE songs SET SongName = 'When i grow up' WHERE Groupid = 8;
UPDATE songs SET SongName = 'Shapeshifter' WHERE Groupid = 11;

DELETE FROM groups WHERE id = 2;
DELETE FROM mlikelysongs WHERE groupsid = 2;
DELETE FROM groups WHERE id = 2;
DELETE FROM songs WHERE id = 7;
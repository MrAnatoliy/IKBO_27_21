SELECT * FROM covers;
SELECT (SongName, Genre, Groupid) FROM songs ORDER BY SongName;
SELECT * FROM groups WHERE id BETWEEN 1 AND 3 OR GroupName = 'Alan Walker';
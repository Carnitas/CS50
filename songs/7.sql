SELECT SUM(energy) / COUNT(songs.name) AS "Average Energy" FROM songs JOIN artists on songs.artist_id = artists.id where artists.name = 'Drake';

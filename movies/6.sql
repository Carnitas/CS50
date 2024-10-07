SELECT ROUND(AVG(ratings.rating), 2)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2012;

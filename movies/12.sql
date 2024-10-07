SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
GROUP BY movies.title
HAVING (SUM(people.name == 'Jennifer Lawrence') AND SUM(people.name == 'Bradley Cooper')) > 0;

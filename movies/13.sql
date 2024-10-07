SELECT name
FROM people

JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN
    (SELECT id
    FROM movies
    JOIN stars ON movies.id = stars.movie_id
    WHERE stars.person_id IN
        (SELECT id
        FROM people
        WHERE people.name = 'Kevin Bacon' AND people.birth = 1958))
AND people.name NOT LIKE 'Kevin Bacon';

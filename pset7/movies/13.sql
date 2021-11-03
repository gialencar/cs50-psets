SELECT name FROM people
JOIN stars ON stars.person_id = people.id
WHERE movie_id IN
(SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id
WHERE name = 'Kevin Bacon' AND birth = 1958)
AND NOT person_id IN (SELECT person_id WHERE name = 'Kevin Bacon' AND birth = 1958)
GROUP BY person_id

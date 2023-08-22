SELECT count(DISTINCT pid) AS cnt FROM (
    SELECT credits.peopleid AS pid
        FROM credits
                JOIN (
           SELECT peopleid, gender
           FROM people
        ) p ON credits.peopleid = p.peopleid
                JOIN (
           SELECT title, movieid
           FROM movies
        ) m ON credits.movieid = m.movieid
        WHERE title LIKE '%Avengers%'
         AND gender = 'F'
) AS res;
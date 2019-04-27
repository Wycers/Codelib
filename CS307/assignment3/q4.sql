SELECT first_name, surname
FROM (
    SELECT peopleid, count(peopleid) as cnt FROM credits JOIN movies m ON credits.movieid = m.movieid and year_released > 2000 GROUP BY peopleid
) AS res
JOIN people p ON cnt > 20 and p.peopleid = res.peopleid and gender = 'F';
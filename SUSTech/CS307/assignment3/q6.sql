WITH res AS (
    SELECT first_name, surname, count(*) cnt
    FROM people p
    JOIN credits c ON p.peopleid = c.peopleid
    WHERE 1910 <= p.born AND p.born <= 1932 AND credited_as = 'A'
    GROUP BY p.peopleid
)
SELECT first_name, surname
FROM res
WHERE cnt = (SELECT max(cnt) FROM res);
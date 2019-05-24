CREATE OR REPLACE FUNCTION percentage(qwq varchar, g bigint, b bigint)
    RETURNS varchar
AS
$$
    DECLARE tmp int;
BEGIN
    if qwq = 'BLUE'
        then tmp = g; g = b; b = tmp;
    END IF;
    if b is NULL
        THEN RETURN NULL;
    ELSEIF g is NULL
        THEN RETURN '0%';
    ELSE RETURN round(g / b :: numeric * 100, 0) || '%';
    END IF;
END;
$$
    LANGUAGE plpgsql;

WITH res AS ( SELECT city, year_no, color, count(color) FROM cars WHERE city IN (
    SELECT city FROM cars GROUP BY city ORDER BY count(city) DESC LIMIT 2
    )GROUP BY year_no, city, color
)
SELECT a.year_no, a.city, percentage(a.color, a.count, b.count) FROM res a LEFT OUTER JOIN res b ON a.city = b.city and a.year_no = b.year_no and a.color <> b.color
WHERE (a.color is NULL or b.color is NULL or a.color <> 'GREEN') ORDER BY year_no, city;

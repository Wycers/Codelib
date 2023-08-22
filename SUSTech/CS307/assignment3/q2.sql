WITH res AS (
    SELECT year_released, count(year_released) as cnt FROM movies WHERE country = 'us' and year_released >= 2000 and year_released <= 2015 group by year_released
)
SELECT * FROM res WHERE res.cnt = (SELECT max(cnt) FROM res);
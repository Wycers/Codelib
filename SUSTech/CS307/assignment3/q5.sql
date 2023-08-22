SELECT continent, count(continent)
FROM (
    SELECT *
    FROM countries
    LEFT JOIN movies m
    ON countries.country_code = m.country
    WHERE m.country is null
) AS res GROUP BY continent;
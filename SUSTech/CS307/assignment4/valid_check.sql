CREATE OR REPLACE FUNCTION valid_check()
    RETURNS trigger
AS
$$
DECLARE
    car_num cars.car_num%type;
    ric     cars.car_num%type;
BEGIN
    car_num := trim(new.car_num);
    IF car_num ~ ('^(粤[A-G][A-Z0-9]{5})$')
    THEN
        new.color = 'BLUE';
    ELSEIF car_num ~ ('^(粤[A-G][D,F][A-Z0-9]{5})$')
    THEN
        new.color = 'GREEN';
    ELSE
        RAISE EXCEPTION 'Invalid car_num';
    END IF;
    ric = substring(car_num, 2, 1);
    IF ric = 'A'
    THEN
        new.city = 'GUANG ZHOU';
    ELSEIF ric = 'B'
    THEN
        new.city = 'SHEN ZHEN';
    ELSEIF ric = 'C'
    THEN
        new.city = 'ZHU HAI';
    ELSEIF ric = 'D'
    THEN
        new.city = 'SHAN TOU';
    ELSEIF ric = 'E'
    THEN
        new.city = 'FO SHAN';
    ELSEIF ric = 'F'
    THEN
        new.city = 'SHAO GUAN';
    ELSE
        new.city = 'ZHAN JIANG';
    END IF;
    RETURN new;
END;
$$
    LANGUAGE plpgsql;

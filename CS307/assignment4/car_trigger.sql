CREATE TRIGGER car_trigger
    BEFORE INSERT
    ON cars
    FOR EACH ROW
EXECUTE PROCEDURE valid_check();

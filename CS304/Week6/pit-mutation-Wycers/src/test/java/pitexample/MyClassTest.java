package pitexample;

import org.junit.Test;

import static org.junit.Assert.*;

public class MyClassTest {

    @Test
    public void testMyMethod() {
        MyClass sut = new MyClass();
        assertTrue(sut.myMethod(1, true));
        assertTrue(sut.myMethod(2, true));
        assertTrue(sut.myMethod(1, false));
        assertTrue(sut.myMethod(2, false));
        assertFalse(sut.myMethod(0, false));
        assertTrue(sut.myMethod(0, true));
        assertTrue(sut.myMethod(1, true));
    }


    @Test
    public void testStockService() {
        StockService stockService = new StockService(1);
        assertEquals(6, stockService.add(5));
        assertEquals(0, stockService.deduct(6));

        stockService.add(0);


        try {
            stockService.add(-1);
            fail();
        } catch (IllegalArgumentException e) {

        }
        try {
            stockService.deduct(-1);
            fail();
        } catch (IllegalArgumentException e) {

        }
        try {
            stockService.deduct(1);
            fail();
        } catch (IllegalArgumentException e) {

        }
    }
}
package net.mooctest;

import org.junit.Test;

import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.util.Random;

import static junit.framework.TestCase.fail;
import static org.junit.Assert.*;

public class BinaryHeapTest {

    @Test(timeout = 4000 )
    public void test() throws Overflow, NoSuchFieldException, IllegalAccessException {

        BinaryHeap bh = new BinaryHeap();
        assertTrue(bh.isEmpty());
        assertFalse(bh.isFull());

        assertEquals(-1, bh.findMin());
        bh.insert(5);
        assertEquals(5, bh.findMin());
        bh.insert(4);
        assertTrue(bh.wellFormed());
        bh.insert(3);
        assertTrue(bh.wellFormed());
        bh.insert(2);
        assertTrue(bh.wellFormed());
        bh.insert(1);
        assertTrue(bh.wellFormed());
        assertEquals(1, bh.findMin());
        bh.deleteMin();
        assertEquals(2, bh.findMin());
        assertTrue(bh.wellFormed());
        assertEquals(2, bh.deleteMin());
        assertEquals(3, bh.deleteMin());
        assertEquals(4, bh.deleteMin());
        assertEquals(5, bh.deleteMin());
        assertEquals(-1, bh.deleteMin());
        assertEquals(-1, bh.deleteMin());
        for (int i = 0; i < 100; ++i)
            bh.insert(4);
        assertTrue(bh.wellFormed());
        assertTrue(bh.isFull());
        assertFalse(bh.isEmpty());
        try {
            bh.insert(4);
            fail();
        } catch (Exception e ) {

        }
        assertTrue(bh.wellFormed());

        bh.buildHeap();
        Class mClass = bh.getClass();

        Field array = mClass.getDeclaredField("array");

        if (array != null) {
            array.setAccessible(true);

            System.out.println(array.toString());
            System.out.println("Before Modify：MSG = " + bh);

            array.set(bh, null);
            assertFalse(bh.wellFormed());
            System.out.println("After Modify：MSG = " + bh);
        }


        array.set(bh, new int[]{1, 2, 3});

        Field currentSize = mClass.getDeclaredField("currentSize");

        if (currentSize != null) {
            currentSize.setAccessible(true);

            System.out.println(currentSize.toString());
            currentSize.set(bh, -1);
            assertFalse(bh.wellFormed());

            currentSize.set(bh, 101);
            assertFalse(bh.wellFormed());
        }

        currentSize.set(bh, 2);
        array.set(bh, new int[]{1, 2, 0});
        assertFalse(bh.wellFormed());

        currentSize.set(bh, 3);
        array.set(bh, new int[]{1, 2, 4, 0});
        assertFalse(bh.wellFormed());

        bh.makeEmpty();
        assertTrue(bh.isEmpty());

        Random nmd = new Random(233);
        bh =  new BinaryHeap(100);
        for (int i = 0; i < 100; ++i) {
            bh.insert(nmd.nextInt(100));
        }
        bh.buildHeap();
        Object arrayo = array.get(bh);
        int len = Array.getLength(arrayo);
        String str = "";
        for (int i = 0; i < len; ++i) {
            str += Array.get(arrayo, i);
        }
        assertEquals("000201538104679512152016141527119791296576142272047373518584633326033342116246128823393482691886566899566454594894133935851719938635385755778727659327872806781434643756295759395894183", str);

        bh.makeEmpty();
        for (int i = 0; i < 100; ++i) {
            bh.insert(i);
        }
        str = "";
        for (int i = 0; i < len; ++i) {
            str += Array.get(arrayo, i);
        }
        assertEquals("00123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899", str);

        bh.makeEmpty();
        for (int i = 0; i < 100; ++i) {
            bh.insert(100 -i);
        }
        str = "";
        for (int i = 0; i < len; ++i) {
            str += Array.get(arrayo, i);
        }
        assertEquals("0172248340332517944945413834302622181410655250724644426955373565312927612321195715131153395471957778519675884789737443100849164947079369768853286666728988083569262632093608116825859129976874890", str);

    }
}

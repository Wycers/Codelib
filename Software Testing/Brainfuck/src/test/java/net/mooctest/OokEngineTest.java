package net.mooctest;



import static org.evosuite.runtime.EvoAssertions.verifyException;
import static org.junit.Assert.assertEquals;

import static org.junit.Assert.fail;



import java.io.BufferedInputStream;

import java.io.ByteArrayInputStream;

import java.io.ByteArrayOutputStream;

import java.io.DataInputStream;

import java.io.InputStream;

import java.io.OutputStream;

import java.io.PipedInputStream;

import java.io.PushbackInputStream;

import java.io.SequenceInputStream;



import org.junit.Test;

import org.junit.runner.RunWith;



public class OokEngineTest{


    @org.junit.Test(timeout = 4000)
    public void test0() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[1];
        brainfuckEngine0.data = byteArray0;
        brainfuckEngine0.interpret("dKmLRt");
        try {
            brainfuckEngine0.interpret("i$`\"+\' PFn;Vbg-E<M");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 22:data pointer (0) on postion 16 negative.
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test1() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(35);
        char[] charArray0 = new char[5];
        brainfuckEngine0.dataPointer = 91;
        brainfuckEngine0.interpret('<', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test2() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(79);
        char[] charArray0 = new char[7];
        brainfuckEngine0.interpret('>', charArray0);
        brainfuckEngine0.interpret('>', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test3() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        brainfuckEngine0.interpret("wc0=");
        char[] charArray0 = new char[4];
        brainfuckEngine0.interpret('>', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test4() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        brainfuckEngine0.dataPointer = 1;
        brainfuckEngine0.charPointer = 1;
        char[] charArray0 = new char[4];
        try {
            brainfuckEngine0.interpret('>', charArray0);
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 0:data pointer (1) on postion 1 out of range.
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test5() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        char[] charArray0 = new char[4];
        brainfuckEngine0.interpret('>', charArray0);
        try {
            brainfuckEngine0.interpret('>', charArray0);
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 1:data pointer (1) on postion 0 out of range.
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test6() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(698917);
        brainfuckEngine0.charPointer = 698917;
        brainfuckEngine0.interpret("");
    }
//    @org.junit.Test(timeout = 4000)
//    public void test7() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
//        byte[] byteArray0 = new byte[1];
//        brainfuckEngine0.data = byteArray0;
//        org.evosuite.runtime.testdata.EvoSuiteFile evoSuiteFile0 = new org.evosuite.runtime.testdata.EvoSuiteFile("Error on line ");
//        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(evoSuiteFile0, brainfuckEngine0.data);
//        org.eclipse.core.runtime.Path path0 = new org.eclipse.core.runtime.Path("Error on line ");
//        java.io.File file0 = path0.toFile();
//        brainfuckEngine0.interpret(file0);
//        brainfuckEngine0.interpret(file0);
//    }
//    @org.junit.Test(timeout = 4000)
//    public void test8() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
//        byte[] byteArray0 = new byte[1];
//        brainfuckEngine0.data = byteArray0;
//        org.evosuite.runtime.testdata.EvoSuiteFile evoSuiteFile0 = new org.evosuite.runtime.testdata.EvoSuiteFile("Error on line ");
//        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(evoSuiteFile0, brainfuckEngine0.data);
//        brainfuckEngine0.interpret("dKmLRt");
//        org.eclipse.core.runtime.Path path0 = new org.eclipse.core.runtime.Path("Error on line ");
//        java.io.File file0 = path0.toFile();
//        brainfuckEngine0.interpret(file0);
//    }
    @org.junit.Test(timeout = 4000)
    public void test9() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(35);
        brainfuckEngine0.initate(35);
    }
//    @org.junit.Test(timeout = 4000)
//    public void test10() throws java.lang.Throwable {
//        org.eclipse.core.runtime.Path path0 = org.eclipse.core.runtime.Path.forWindows(".STNei-z?`@");
//        java.io.File file0 = path0.toFile();
//        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(file0);
//        org.eclipse.jdt.internal.core.util.LRUCache<java.io.InputStream, java.io.PipedInputStream> lRUCache0 = new org.eclipse.jdt.internal.core.util.LRUCache<java.io.InputStream, java.io.PipedInputStream>();
//        org.eclipse.jdt.internal.core.util.ICacheEnumeration<java.io.InputStream, java.io.PipedInputStream> iCacheEnumeration0 = lRUCache0.keysAndValues();
//        java.io.SequenceInputStream sequenceInputStream0 = new java.io.SequenceInputStream(iCacheEnumeration0);
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(213, mockPrintStream0, sequenceInputStream0);
//    }
    @org.junit.Test(timeout = 4000)
    public void test11() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        brainfuckEngine0.charPointer = -610;
        try {
            brainfuckEngine0.interpret("W_qa-`(06RNl>|Ve");
            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
        } catch (java.lang.StringIndexOutOfBoundsException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test12() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        java.io.BufferedOutputStream bufferedOutputStream0 = new java.io.BufferedOutputStream(byteArrayOutputStream0, 871);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(871, bufferedOutputStream0);
        try {
            brainfuckEngine0.interpret(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
//    @org.junit.Test(timeout = 4000)
//    public void test13() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
//        try {
//            brainfuckEngine0.interpret(", column ");
//            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
//        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
//            //
//            // 0
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
//    @org.junit.Test(timeout = 4000)
//    public void test14() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
//        org.evosuite.runtime.testdata.EvoSuiteFile evoSuiteFile0 = new org.evosuite.runtime.testdata.EvoSuiteFile("Error on line ");
//        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(evoSuiteFile0, brainfuckEngine0.data);
//        brainfuckEngine0.charPointer = ((int) ((byte) (-93)));
//        org.eclipse.core.runtime.Path path0 = new org.eclipse.core.runtime.Path("Error on line ");
//        java.io.File file0 = path0.toFile();
//        try {
//            brainfuckEngine0.interpret(file0);
//            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
//        } catch (java.lang.StringIndexOutOfBoundsException e) {
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test15() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(44);
        try {
            brainfuckEngine0.interpret(((java.io.File) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("org.evosuite.runtime.mock.java.io.MockFileInputStream", e);
        }
    }
//    @org.junit.Test(timeout = 4000)
//    public void test16() throws java.lang.Throwable {
//        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("\nNo Exports");
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(881, mockPrintStream0);
//        org.evosuite.runtime.testdata.FileSystemHandling.shouldAllThrowIOExceptions();
//        org.evosuite.runtime.mock.java.io.MockFile mockFile0 = new org.evosuite.runtime.mock.java.io.MockFile("\nNo Exports");
//        try {
//            brainfuckEngine0.interpret(((java.io.File) (mockFile0)));
//            org.junit.Assert.fail("Expecting exception: IOException");
//        } catch (java.io.IOException e) {
//            //
//            // Simulated IOException
//            //
//            verifyException("org.evosuite.runtime.vfs.VirtualFileSystem", e);
//        }
//    }
//    @org.junit.Test(timeout = 4000)
//    public void test17() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1828);
//        java.io.File file0 = org.evosuite.runtime.mock.java.io.MockFile.createTempFile(" negative.", " negative.", ((java.io.File) (null)));
//        try {
//            brainfuckEngine0.interpret(file0);
//            org.junit.Assert.fail("Expecting exception: FileNotFoundException");
//        } catch (java.io.FileNotFoundException e) {
//            //
//            // no message in exception (getMessage() returned null)
//            //
//            verifyException("org.evosuite.runtime.mock.java.io.MockFileInputStream", e);
//        }
//    }
//    @org.junit.Test(timeout = 4000)
//    public void test18() throws java.lang.Throwable {
//        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("1M!,7gz,V|wR", false);
//        java.io.ObjectOutputStream objectOutputStream0 = new java.io.ObjectOutputStream(mockFileOutputStream0);
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(985, objectOutputStream0);
//        try {
//            brainfuckEngine0.interpret(']', ((char[]) (null)));
//            org.junit.Assert.fail("Expecting exception: NullPointerException");
//        } catch (java.lang.NullPointerException e) {
//            //
//            // no message in exception (getMessage() returned null)
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
//    @org.junit.Test(timeout = 4000)
//    public void test19() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(10);
//        char[] charArray0 = new char[4];
//        brainfuckEngine0.interpret(',', charArray0);
//        try {
//            brainfuckEngine0.interpret(',', charArray0);
//            org.junit.Assert.fail("Expecting exception: IOException");
//        } catch (java.io.IOException e) {
//            //
//            // Simulated exception in System.in
//            //
//            verifyException("org.evosuite.runtime.util.SystemInUtil", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test20() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("e");
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(60, mockPrintStream0);
        // Undeclared exception!
        try {
            brainfuckEngine0.initate((-1610612219));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test21() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0, byteArrayOutputStream0, ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("java.io.Reader", e);
        }
    }
//    @org.junit.Test(timeout = 4000)
//    public void test22() throws java.lang.Throwable {
//        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("-<D+HR@v4", false);
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
//        try {
//            brainfuckEngine0 = new net.mooctest.BrainfuckEngine((-382), mockFileOutputStream0);
//            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
//        } catch (java.lang.NegativeArraySizeException e) {
//            //
//            // no message in exception (getMessage() returned null)
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test23() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine((-1945));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test24() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        char[] charArray0 = new char[4];
        brainfuckEngine0.interpret('>', charArray0);
        brainfuckEngine0.interpret('<', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test25() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(35);
        char[] charArray0 = new char[5];
        brainfuckEngine0.interpret('3', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test26() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        char[] charArray0 = new char[4];
        try {
            brainfuckEngine0.interpret('<', charArray0);
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 0:data pointer (0) on postion 0 negative.
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test27() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(44);
        brainfuckEngine0.interpret('.', ((char[]) (null)));
    }
    @org.junit.Test(timeout = 4000)
    public void test28() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        brainfuckEngine0.charPointer = 1;
        char[] charArray0 = new char[4];
        charArray0[0] = ']';
        try {
            brainfuckEngine0.interpret(']', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test29() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        char[] charArray0 = new char[21];
        charArray0[0] = '[';
        charArray0[3] = ']';
        brainfuckEngine0.interpret('[', charArray0);
        brainfuckEngine0.interpret(']', charArray0);
        try {
            brainfuckEngine0.interpret('[', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 21
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
//    @org.junit.Test(timeout = 4000)
//    public void test30() throws java.lang.Throwable {
//        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("\nNo Exports");
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(881, mockPrintStream0);
//        org.evosuite.runtime.testdata.EvoSuiteFile evoSuiteFile0 = new org.evosuite.runtime.testdata.EvoSuiteFile("\nNo Exports");
//        byte[] byteArray0 = new byte[8];
//        byteArray0[2] = ((byte) (60));
//        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(evoSuiteFile0, byteArray0);
//        org.evosuite.runtime.mock.java.io.MockFile mockFile0 = new org.evosuite.runtime.mock.java.io.MockFile("\nNo Exports");
//        try {
//            brainfuckEngine0.interpret(((java.io.File) (mockFile0)));
//            org.junit.Assert.fail("Expecting exception: Exception");
//        } catch (java.lang.Exception e) {
//            //
//            // Error on line 1, column 2:data pointer (0) on postion 2 negative.
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test31() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1);
        char[] charArray0 = new char[4];
        brainfuckEngine0.interpret('-', charArray0);
    }
//    @org.junit.Test(timeout = 4000)
//    public void test32() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(10);
//        char[] charArray0 = new char[4];
//        brainfuckEngine0.interpret(',', charArray0);
//        brainfuckEngine0.interpret('[', charArray0);
//    }
    @org.junit.Test(timeout = 4000)
    public void test33() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1094);
        char[] charArray0 = new char[1];
        brainfuckEngine0.interpret('+', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test34() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
    }
//    @org.junit.Test(timeout = 4000)
//    public void test35() throws java.lang.Throwable {
//        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
//        org.evosuite.runtime.testdata.EvoSuiteFile evoSuiteFile0 = new org.evosuite.runtime.testdata.EvoSuiteFile("Error on line ");
//        org.evosuite.runtime.testdata.FileSystemHandling.appendStringToFile(evoSuiteFile0, "u.^}2");
//        org.eclipse.core.runtime.Path path0 = new org.eclipse.core.runtime.Path("Error on line ");
//        java.io.File file0 = path0.toFile();
//        try {
//            brainfuckEngine0.interpret(file0);
//            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
//        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
//            //
//            // 0
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test36() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine((-1201), ((java.io.OutputStream) (null)), ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test37() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(682);
        org.junit.Assert.assertNotNull(ookEngine0);
        ookEngine0.defaultTokenLength = -1835;
        try {
            ookEngine0.interpret("H8r,ED:+xL");
            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
        } catch (java.lang.StringIndexOutOfBoundsException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test38() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(603979776, ((java.io.OutputStream) (null)));
        org.junit.Assert.assertNotNull(ookEngine0);
        ookEngine0.charPointer = 3416;
        // Undeclared exception!
        ookEngine0.interpret("CnEzNrhq12}N!Scj");
    }
    @org.junit.Test(timeout = 4000)
    public void test39() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        org.junit.Assert.assertEquals(0, byteArrayOutputStream0.size());
        org.junit.Assert.assertEquals("", byteArrayOutputStream0.toString());
        org.junit.Assert.assertNotNull(byteArrayOutputStream0);
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine(5272, byteArrayOutputStream0, ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("java.io.Reader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test40() throws java.lang.Throwable {
        byte[] byteArray0 = new byte[0];
        java.io.ByteArrayInputStream byteArrayInputStream0 = new java.io.ByteArrayInputStream(byteArray0);
        org.junit.Assert.assertEquals(0, byteArrayInputStream0.available());
        org.junit.Assert.assertNotNull(byteArrayInputStream0);
        org.junit.Assert.assertEquals(0, byteArray0.length);
        org.junit.Assert.assertArrayEquals(new byte[]{  }, byteArray0);
        java.io.PushbackInputStream pushbackInputStream0 = new java.io.PushbackInputStream(byteArrayInputStream0);
        org.junit.Assert.assertEquals(0, byteArrayInputStream0.available());
        org.junit.Assert.assertNotNull(pushbackInputStream0);
        org.junit.Assert.assertEquals(0, byteArray0.length);
        org.junit.Assert.assertArrayEquals(new byte[]{  }, byteArray0);
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-1030), ((java.io.OutputStream) (null)), pushbackInputStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test41() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream(805306368);
    }
    @org.junit.Test(timeout = 4000)
    public void test42() throws java.lang.Throwable {
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        org.junit.Assert.assertEquals(0, pipedInputStream0.available());
        org.junit.Assert.assertNotNull(pipedInputStream0);
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream(pipedInputStream0);
        org.junit.Assert.assertEquals(0, pipedInputStream0.available());
        org.junit.Assert.assertNotNull(pipedOutputStream0);
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-4131), pipedOutputStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test43() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(1610612959);
    }
    @org.junit.Test(timeout = 4000)
    public void test44() throws java.lang.Throwable {
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.PREVIOUS;
        org.junit.Assert.assertEquals("Ook? Ook.", ookEngine_Token0.getValue());
        java.lang.String string0 = ookEngine_Token0.getValue();
        org.junit.Assert.assertEquals("Ook? Ook.", ookEngine_Token0.getValue());
        org.junit.Assert.assertNotNull(string0);
        org.junit.Assert.assertEquals("Ook? Ook.", string0);
    }
    @org.junit.Test(timeout = 4000)
    public void test45() throws java.lang.Throwable {
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        org.junit.Assert.assertNotNull(pipedOutputStream0);
        java.io.BufferedInputStream bufferedInputStream0 = new java.io.BufferedInputStream(((java.io.InputStream) (null)), 374);
        org.junit.Assert.assertNotNull(bufferedInputStream0);
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(374, pipedOutputStream0, bufferedInputStream0);
        org.junit.Assert.assertNotNull(ookEngine0);
    }
    @org.junit.Test(timeout = 4000)
    public void test46() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(9);
        try {
            ookEngine0.interpret("Ook! Ook?");
            org.junit.Assert.fail("Expecting exception: IndexOutOfBoundsException");
        } catch (java.lang.IndexOutOfBoundsException e) {
            //
            // Index: 1, Size: 1
            //
            verifyException("java.util.ArrayList", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test47() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream(0);
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(0, byteArrayOutputStream0);
        ookEngine0.interpret(".LAD@$im^\"hD9tt");
    }
    @org.junit.Test(timeout = 4000)
    public void test48() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-1));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test49() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.shouldAllThrowIOExceptions();
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(byteArrayOutputStream0);
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1610612996, mockPrintStream0, pipedInputStream0);
    }
    @org.junit.Test(timeout = 4000)
    public void test50() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token1 = new net.mooctest.TrollScriptEngine.Token();
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream(pipedInputStream0);
        pipedOutputStream0.write(578);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(578);
        trollScriptEngine0.interpret("org.eclipse.jdt.core.formatter.insert_space_after_comma_in_annotation");
        trollScriptEngine0.interpret("lll");
        trollScriptEngine0.interpret("totalLoadTime");
        trollScriptEngine0.interpret("oll");
    }
    @org.junit.Test(timeout = 4000)
    public void test51() throws java.lang.Throwable {
        long long0 = 0L;
//        java.lang.System.setCurrentTimeMillis(0L);
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("`");
        mockPrintStream0.print(2354.2131F);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1610613384, mockPrintStream0);
    }
    @org.junit.Test(timeout = 4000)
    public void test52() throws java.lang.Throwable {
        int int0 = 2147483645;
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2147483645);
    }
    @org.junit.Test(timeout = 4000)
    public void test53() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(603979776);
        trollScriptEngine0.initate(0);
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.initate(603979776);
        trollScriptEngine0.isValidToken("");
        byte[] byteArray0 = new byte[2];
        byteArray0[0] = ((byte) (93));
        byteArray0[1] = ((byte) (118));
        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), byteArray0);
        // Undeclared exception!
        trollScriptEngine0.interpret("oll");
    }
    @org.junit.Test(timeout = 4000)
    public void test54() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token1 = new net.mooctest.TrollScriptEngine.Token();
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream(pipedInputStream0);
        pipedOutputStream0.write(0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(578, pipedOutputStream0, pipedInputStream0);
        trollScriptEngine0.interpret("org.eclipse.jdt.core.formatter.insert_space_after_comma_in_annotation");
        trollScriptEngine0.isValidToken("olo");
        trollScriptEngine0.interpret("lll");
        trollScriptEngine0.interpret("");
        trollScriptEngine0.interpret("oll");
    }
    @org.junit.Test(timeout = 4000)
    public void test55() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2795);
        char[] charArray0 = new char[8];
        charArray0[0] = 'k';
        trollScriptEngine0.initate(2795);
        charArray0[1] = '#';
        charArray0[2] = 'k';
        charArray0[3] = 'k';
        charArray0[4] = 'k';
        charArray0[5] = 'k';
        charArray0[6] = 'k';
        charArray0[7] = 'k';
        trollScriptEngine0.interpret('k', charArray0);
        trollScriptEngine0.interpret("net.mooctest.TrollScriptEngine");
    }
    @org.junit.Test(timeout = 4000)
    public void test56() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1335);
        trollScriptEngine0.interpret("ool");
        trollScriptEngine0.interpret("ool");
        trollScriptEngine0.isValidToken("lll");
        org.eclipse.core.runtime.Path path0 = null;
        try {
            path0 = new org.eclipse.core.runtime.Path(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("org.eclipse.core.runtime.Path", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test57() throws java.lang.Throwable {
        int int0 = 1028;
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(pipedOutputStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1028, mockPrintStream0, ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("java.io.Reader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test58() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("Enums.stringConverter(", false);
        java.io.DataOutputStream dataOutputStream0 = new java.io.DataOutputStream(mockFileOutputStream0);
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-3060), dataOutputStream0, pipedInputStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test59() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        int int0 = 0;
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.isValidToken("lol");
        trollScriptEngine0.isValidToken(">UQ(fe}7");
        trollScriptEngine0.interpret("");
        trollScriptEngine0.dataPointer = -887;
        trollScriptEngine0.interpret("ll.");
        java.io.SequenceInputStream sequenceInputStream0 = null;
        try {
            sequenceInputStream0 = new java.io.SequenceInputStream(((java.io.InputStream) (null)), ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("java.io.SequenceInputStream", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test60() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.initate(0);
        trollScriptEngine0.charPointer = 67109282;
        trollScriptEngine0.defaultTokenLength = 3;
        trollScriptEngine0.interpret("P");
        trollScriptEngine0.isValidToken("P");
    }
//    @org.junit.Test(timeout = 4000)
//    public void test61() throws java.lang.Throwable {
//        java.lang.String string0 = "LocalVarReferencePattern: ";
//        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("LocalVarReferencePattern: ", true);
//        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
//        try {
//            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-611), mockFileOutputStream0);
//            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
//        } catch (java.lang.NegativeArraySizeException e) {
//            //
//            // no message in exception (getMessage() returned null)
//            //
//            verifyException("net.mooctest.BrainfuckEngine", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test62() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2336);
        int int0 = 3487;
        trollScriptEngine0.columnCount = 3487;
        java.lang.String string0 = null;
        // Undeclared exception!
        try {
            trollScriptEngine0.isValidToken(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test63() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token1 = new net.mooctest.TrollScriptEngine.Token();
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        java.io.SequenceInputStream sequenceInputStream0 = new java.io.SequenceInputStream(pipedInputStream0, pipedInputStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(484, byteArrayOutputStream0, sequenceInputStream0);
        trollScriptEngine0.isValidToken("ooo");
    }
    @org.junit.Test(timeout = 4000)
    public void test64() throws java.lang.Throwable {
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        java.io.SequenceInputStream sequenceInputStream0 = new java.io.SequenceInputStream(pipedInputStream0, pipedInputStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-75), ((java.io.OutputStream) (null)), sequenceInputStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test65() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(13);
        trollScriptEngine0.initate(0);
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.initate(13);
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.interpret("oll");
        trollScriptEngine0.isValidToken("loo");
        trollScriptEngine0.interpret("EYR*`c!X-");
        trollScriptEngine0.isValidToken("lll");
        trollScriptEngine0.isValidToken("llo");
    }
    @org.junit.Test(timeout = 4000)
    public void test66() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1157);
        trollScriptEngine0.isValidToken(".L()5$J6.+tEKI1");
    }
//    @org.junit.Test(timeout = 4000)
//    public void test67() throws java.lang.Throwable {
//        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("|?81)Gx\"i:");
//        java.lang.Object[] objectArray0 = new java.lang.Object[5];
//        objectArray0[0] = ((java.lang.Object) (mockPrintStream0));
//        mockPrintStream0.format(((java.util.Locale) (null)), "|?81)Gx\"i:", objectArray0);
//        objectArray0[1] = ((java.lang.Object) (mockPrintStream0));
//        mockPrintStream0.checkError();
//        objectArray0[2] = ((java.lang.Object) (mockPrintStream0));
//        objectArray0[3] = ((java.lang.Object) (mockPrintStream0));
//        java.lang.Object object0 = new java.lang.Object();
//        objectArray0[4] = object0;
//        java.io.PrintStream printStream0 = mockPrintStream0.format("|?81)Gx\"i:", objectArray0);
//        mockPrintStream0.println(((java.lang.Object) (null)));
//        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0, printStream0);
//        trollScriptEngine0.interpret("?4ij5");
//        trollScriptEngine0.outWriter = ((java.io.OutputStream) (mockPrintStream0));
//        trollScriptEngine0.interpret("|?81)Gx\"i:");
//        mockPrintStream0.print("");
//        trollScriptEngine0.interpret("");
//        trollScriptEngine0.interpret("|?81)Gx\"i:");
//        try {
//            trollScriptEngine0.interpret(((java.lang.String) (null)));
//            org.junit.Assert.fail("Expecting exception: NullPointerException");
//        } catch (java.lang.NullPointerException e) {
//            //
//            // no message in exception (getMessage() returned null)
//            //
//            verifyException("net.mooctest.TrollScriptEngine", e);
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test68() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("ll.");
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(mockFileOutputStream0, false);
        java.io.PrintStream printStream0 = mockPrintStream0.append(((java.lang.CharSequence) ("ll.")));
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(805, printStream0);
        trollScriptEngine0.interpret("ll.");
    }
    @org.junit.Test(timeout = 4000)
    public void test69() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("O]:avx49iwx");
        java.io.DataOutputStream dataOutputStream0 = new java.io.DataOutputStream(mockPrintStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(708, dataOutputStream0);
        trollScriptEngine0.interpret("O]:avx49iwx");
    }
//    @org.junit.Test(timeout = 4000)
//    public void test70() throws java.lang.Throwable {
//        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2965);
//        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("zH?O,KyB8*R?7|a7f$9", true);
//        trollScriptEngine0.charPointer = -262;
//        trollScriptEngine0.outWriter = ((java.io.OutputStream) (mockFileOutputStream0));
//        try {
//            trollScriptEngine0.interpret("zH?O,KyB8*R?7|a7f$9");
//            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
//        } catch (java.lang.StringIndexOutOfBoundsException e) {
//        }
//    }
    @org.junit.Test(timeout = 4000)
    public void test71() throws java.lang.Throwable {
        int int0 = -65537;
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-65537));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test72() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.interpret("rV,~");
    }
    @org.junit.Test(timeout = 4000)
    public void test73() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("llo");
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2071, mockPrintStream0);
        trollScriptEngine0.isValidToken("llo");
        trollScriptEngine0.interpret("org.eclipse.jdt.internal.compiler.env.IBinaryTypeAnnotation");
    }
    @org.junit.Test(timeout = 4000)
    public void test74() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(67109836);
        trollScriptEngine0.interpret("olo");
        trollScriptEngine0.interpret("com.google.common.collect.DiscreteDomain$BigIntegerDomain");
        trollScriptEngine0.interpret("lol");
        trollScriptEngine0.interpret("'BUz>GNllR");
    }
    @org.junit.Test(timeout = 4000)
    public void test75() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2795);
        trollScriptEngine0.interpret("net.mooctest.TrollScriptEngine");
        trollScriptEngine0.interpret("(D/[lKPyuv&Cgrb#&%<");
    }
    @org.junit.Test(timeout = 4000)
    public void test76() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1335);
        trollScriptEngine0.interpret("ool");
        org.evosuite.runtime.testdata.FileSystemHandling.shouldAllThrowIOExceptions();
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.interpret("lll");
//        java.lang.System.setCurrentTimeMillis(1335);
    }
    @org.junit.Test(timeout = 4000)
    public void test77() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(282);
        trollScriptEngine0.initate(282);
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.interpret("loo");
        trollScriptEngine0.interpret("A47RR=csTrn_AB4I]");
    }
}


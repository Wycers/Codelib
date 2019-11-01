package net.mooctest;



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
import java.util.ArrayList;


import org.junit.Before;
import org.junit.Test;

import org.junit.runner.RunWith;



public class OokEngineTest{
    @Before
    public void handleBefore() {

    }



    @org.junit.Test(timeout = 4000)
    public void test0() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byteArray0[6] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[5] = ((byte) (-26));
        byteArray0[6] = ((byte) (-1));
        brainfuckEngine0.data = byteArray0;
        char[] charArray0 = new char[0];
        brainfuckEngine0.interpret('>', charArray0);
        char[] charArray1 = new char[7];
        charArray1[0] = ']';
        charArray1[1] = ',';
        charArray1[3] = ',';
        charArray1[4] = '<';
        charArray1[5] = ']';
        charArray1[6] = ']';
        brainfuckEngine0.interpret('<', charArray1);
        brainfuckEngine0.interpret('[', charArray1);
    }
    @org.junit.Test(timeout = 4000)
    public void test2() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(7);
        char[] charArray0 = new char[4];
        brainfuckEngine0.data = null;
        charArray0[0] = '[';
        charArray0[0] = '[';
        charArray0[2] = '[';
        brainfuckEngine0.interpret('3', charArray0);
        charArray0[3] = '[';
        try {
            brainfuckEngine0.interpret('[', charArray0);
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @org.junit.Test(timeout = 4000)
    public void test4() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(7);
        char[] charArray0 = new char[4];
        charArray0[0] = '[';
        charArray0[1] = '[';
        charArray0[2] = '[';
        byte[] byteArray0 = new byte[2];
        byteArray0[0] = ((byte) (46));
        byteArray0[1] = ((byte) (42));
        brainfuckEngine0.data = byteArray0;
        charArray0[3] = '[';
        brainfuckEngine0.interpret('[', charArray0);
    }
    @org.junit.Test(timeout = 4000)
    public void test5() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("Unable to get value for ");
        java.io.BufferedOutputStream bufferedOutputStream0 = new java.io.BufferedOutputStream(mockFileOutputStream0);
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream(2001);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(2001);
        byte[] byteArray0 = new byte[1];
        byteArray0[0] = ((byte) (34));
        brainfuckEngine0.data = byteArray0;
        brainfuckEngine0.interpret("t8[;qh?Xq{+7bp_W");
    }
    @org.junit.Test(timeout = 4000)
    public void test6() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(7);
        char[] charArray0 = new char[4];
        charArray0[0] = '[';
        charArray0[1] = '[';
        charArray0[2] = '[';
        charArray0[3] = '[';
        try {
            brainfuckEngine0.interpret('[', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 4
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @org.junit.Test(timeout = 4000)
    public void test10() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine((-3422));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test11() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        java.lang.String string0 = "uTT?OU_= q";
        brainfuckEngine0.data = null;
        brainfuckEngine0.charPointer = 850;
        try {
            brainfuckEngine0.interpret("uTT?OU_= q");
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test12() throws java.lang.Throwable {
        int int0 = 0;
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0, ((java.io.OutputStream) (null)), ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.io.Reader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test13() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        char[] charArray0 = new char[7];
        brainfuckEngine0.initate(3071);
        brainfuckEngine0.lineCount = 3395;
        charArray0[0] = 'K';
        charArray0[1] = 'K';
        charArray0[2] = 'K';
        charArray0[3] = 'K';
        charArray0[4] = 'K';
        brainfuckEngine0.dataPointer = 0;
        brainfuckEngine0.lineCount = -2109;
        charArray0[5] = 'K';
        charArray0[6] = 'K';
        brainfuckEngine0.interpret('K', charArray0);
        try {
            brainfuckEngine0.interpret(((java.io.File) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("org.evosuite.runtime.mock.java.io.MockFileInputStream", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test14() throws java.lang.Throwable {
        int int0 = 106;
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(106);
        char char0 = '+';
        char[] charArray0 = null;
        brainfuckEngine0.interpret('+', ((char[]) (null)));
        brainfuckEngine0.interpret('R', ((char[]) (null)));
        java.io.InputStreamReader inputStreamReader0 = brainfuckEngine0.consoleReader;
        brainfuckEngine0.consoleReader = inputStreamReader0;
        brainfuckEngine0.charPointer = 0;
        // Undeclared exception!
        try {
            inputStreamReader0.read(((char[]) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.io.Reader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test15() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("iqko31!F8:=S");
        mockFileOutputStream0.getChannel();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0, mockFileOutputStream0);
        brainfuckEngine0.interpret("iqko31!F8:=S");
        char[] charArray0 = new char[2];
        charArray0[0] = '^';
        brainfuckEngine0.lineCount = 0;
        charArray0[1] = ']';
        try {
            brainfuckEngine0.interpret(']', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @org.junit.Test(timeout = 4000)
    public void test17() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(16, byteArrayOutputStream0);
        byte[] byteArray0 = new byte[3];
        byteArray0[0] = ((byte) (-14));
        byteArray0[1] = ((byte) (-50));
        byteArray0[2] = ((byte) (56));
        byteArrayOutputStream0.write(byteArray0);
        // Undeclared exception!
        try {
            brainfuckEngine0.initate((-443));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test18() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1265);
        brainfuckEngine0.charPointer = -271;
        java.lang.String string0 = "";
        try {
            brainfuckEngine0.interpret("");
            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
        } catch (java.lang.StringIndexOutOfBoundsException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test19() throws java.lang.Throwable {
        int int0 = -40;
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("Type arguments may not be primitive.");
        net.mooctest.BrainfuckEngine brainfuckEngine0 = null;
        try {
            brainfuckEngine0 = new net.mooctest.BrainfuckEngine((-40), mockPrintStream0, ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test20() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("AUTHOR");
        mockFileOutputStream0.flush();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(88, mockFileOutputStream0);
        brainfuckEngine0.interpret("AUTHOR");
        char[] charArray0 = new char[5];
        charArray0[0] = '0';
        charArray0[1] = '0';
        mockFileOutputStream0.getChannel();
        charArray0[2] = '0';
        charArray0[3] = '0';
        charArray0[4] = '0';
        brainfuckEngine0.interpret('0', charArray0);
        brainfuckEngine0.interpret('0', charArray0);
        brainfuckEngine0.interpret(";+JZru>o| O");
    }
    @org.junit.Test(timeout = 4000)
    public void test23() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byteArray0[0] = ((byte) (-26));
        byteArray0[1] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[3] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[5] = ((byte) (0));
        byteArray0[6] = ((byte) (-1));
        brainfuckEngine0.data = byteArray0;
        brainfuckEngine0.dataPointer = -2113;
        try {
            brainfuckEngine0.interpret("f=3*6(<e+dz");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 6:data pointer (-2113) on postion 6 negative.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test27() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(923);
        brainfuckEngine0.charPointer = 923;
        try {
            brainfuckEngine0.interpret(((java.io.File) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("org.evosuite.runtime.mock.java.io.MockFileInputStream", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test28() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byte byte0 = ((byte) (-26));
        char[] charArray0 = new char[4];
        charArray0[0] = '>';
        charArray0[1] = ',';
        charArray0[2] = 'u';
        charArray0[3] = '[';
        try {
            brainfuckEngine0.interpret('[', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 0
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test29() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byteArray0[1] = ((byte) (0));
        byteArray0[2] = ((byte) (-26));
        byteArray0[3] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[5] = ((byte) (124));
        brainfuckEngine0.dataPointer = 327;
        byteArray0[6] = ((byte) (95));
        brainfuckEngine0.data = byteArray0;
        char[] charArray0 = new char[4];
        charArray0[0] = ']';
        charArray0[1] = '.';
        charArray0[2] = '[';
        charArray0[3] = ']';
        try {
            brainfuckEngine0.interpret('>', charArray0);
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 0:data pointer (327) on postion 0 out of range.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test30() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1598);
        char[] charArray0 = new char[3];
        brainfuckEngine0.interpret("");
        brainfuckEngine0.initate(532);
        brainfuckEngine0.interpret('q', charArray0);
        try {
            brainfuckEngine0.interpret(";`L]OVq&`+T'C@Mm");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test31() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        org.evosuite.runtime.testdata.FileSystemHandling.appendDataToFile(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), byteArray0);
        byteArray0[0] = ((byte) (-26));
        byteArray0[6] = ((byte) (0));
        byteArray0[2] = ((byte) (-26));
        byteArray0[2] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[5] = ((byte) (-26));
        byteArray0[6] = ((byte) (-1));
        brainfuckEngine0.data = byteArray0;
        char[] charArray0 = new char[0];
        brainfuckEngine0.interpret('>', charArray0);
        char[] charArray1 = new char[7];
        charArray1[0] = ']';
        charArray1[1] = ',';
        charArray1[2] = '+';
        charArray1[3] = ',';
        charArray1[4] = '<';
        charArray1[5] = 'a';
        charArray1[6] = ']';
        brainfuckEngine0.interpret('<', charArray1);
        try {
            brainfuckEngine0.interpret("f=3*6(<e+dz");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 8:data pointer (0) on postion 6 negative.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test32() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("Unable to get value for ");
        java.io.BufferedOutputStream bufferedOutputStream0 = new java.io.BufferedOutputStream(mockFileOutputStream0);
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream(2001);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1436, bufferedOutputStream0, pipedInputStream0);
        try {
            brainfuckEngine0.interpret("t8[;qh?Xq{+7bp_W");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 16
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test33() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1598);
        char[] charArray0 = new char[3];
        brainfuckEngine0.interpret("=I?Xhsu(");
        brainfuckEngine0.initate(532);
        brainfuckEngine0.interpret('q', charArray0);
        brainfuckEngine0.interpret("EBaN\u007fn4jV\"V2f.R@");
        brainfuckEngine0.interpret('I', charArray0);
        byte[] byteArray0 = new byte[0];
        brainfuckEngine0.data = byteArray0;
        brainfuckEngine0.interpret('^', charArray0);
        brainfuckEngine0.interpret("");
        try {
            brainfuckEngine0.interpret("IDB_>eLJfS!D|ff@U@$");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 31:data pointer (0) on postion 4 out of range.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test34() throws java.lang.Throwable {
        int int0 = 46;
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(46);
        java.lang.String string0 = "kO`A/]eI";
        brainfuckEngine0.initate(46);
        try {
            brainfuckEngine0.interpret("kO`A/]eI");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test35() throws java.lang.Throwable {
        java.io.BufferedOutputStream bufferedOutputStream0 = new java.io.BufferedOutputStream(((java.io.OutputStream) (null)));
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(bufferedOutputStream0, false);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(609, mockPrintStream0);
        brainfuckEngine0.interpret("com.github.javaparser.ast.stmt.LocalClassDeclarationStmt");
    }
    @org.junit.Test(timeout = 4000)
    public void test36() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byteArray0[0] = ((byte) (-26));
        byteArray0[1] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[3] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[5] = ((byte) (124));
        brainfuckEngine0.dataPointer = 327;
        byteArray0[6] = ((byte) (95));
        brainfuckEngine0.data = byteArray0;
        try {
            brainfuckEngine0.interpret("f=3*6(<e+dz");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 326
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test37() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(282);
        char[] charArray0 = new char[4];
        charArray0[0] = 'C';
        charArray0[1] = 'C';
        charArray0[2] = 'C';
        charArray0[3] = 'C';
        brainfuckEngine0.interpret('C', charArray0);
        brainfuckEngine0.initate(282);
        try {
            brainfuckEngine0.interpret("~uM|hZ_jd<>mW>>");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 10:data pointer (0) on postion 9 negative.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test39() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(202, ((java.io.OutputStream) (null)));
        try {
            brainfuckEngine0.interpret("com.github.javaparser.metamodel.ForStmtMetaModel");
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test40() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(2466);
    }
    @org.junit.Test(timeout = 4000)
    public void test41() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1450);
        brainfuckEngine0.lineCount = 2377;
        brainfuckEngine0.columnCount = 2377;
        brainfuckEngine0.interpret(":gxu\u0002W7\'6kqES\"}DQ+");
        brainfuckEngine0.initate(93);
        brainfuckEngine0.initate(2377);
        brainfuckEngine0.charPointer = 93;
        brainfuckEngine0.interpret(":gxu\u0002W7\'6kqES\"}DQ+");
        brainfuckEngine0.data = null;
        brainfuckEngine0.initate(213);
        brainfuckEngine0.interpret("F`\"YkH");
    }
    @org.junit.Test(timeout = 4000)
    public void test42() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        java.util.Enumeration<java.io.InputStream> enumeration0 = ((java.util.Enumeration<java.io.InputStream>) (org.evosuite.shaded.org.mockito.Mockito.mock(java.util.Enumeration.class, new org.evosuite.runtime.ViolatedAssumptionAnswer())));
        org.evosuite.shaded.org.mockito.Mockito.doReturn(false).when(enumeration0).hasMoreElements();
        java.io.SequenceInputStream sequenceInputStream0 = new java.io.SequenceInputStream(enumeration0);
        java.io.BufferedInputStream bufferedInputStream0 = new java.io.BufferedInputStream(sequenceInputStream0, 748);
        byte[] byteArray0 = new byte[7];
        byteArray0[1] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        char[] charArray0 = new char[1];
        try {
            brainfuckEngine0.interpret('.', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 0
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test43() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(7);
        char[] charArray0 = new char[4];
        charArray0[0] = '[';
        charArray0[2] = '[';
        charArray0[3] = '[';
        try {
            brainfuckEngine0.interpret('[', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 4
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test44() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(65);
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        char[] charArray0 = new char[2];
        charArray0[0] = 'n';
        charArray0[1] = 'n';
        brainfuckEngine0.interpret('n', charArray0);
        brainfuckEngine0.interpret('n', charArray0);
        brainfuckEngine0.initate(78);
        try {
            brainfuckEngine0.interpret(']', charArray0);
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test45() throws java.lang.Throwable {
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream(2001);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(2001);
        try {
            brainfuckEngine0.interpret("t8[;qh?Xq{+7bp_W");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // 16
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test46() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream(4369);
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(4369, byteArrayOutputStream0);
        brainfuckEngine0.interpret("?y%dHav-03");
        byte[] byteArray0 = new byte[0];
        brainfuckEngine0.initate(4369);
        brainfuckEngine0.data = byteArray0;
        byteArrayOutputStream0.write(byteArray0);
        brainfuckEngine0.initate(4369);
        char[] charArray0 = new char[2];
        charArray0[0] = '1';
        charArray0[1] = '1';
        brainfuckEngine0.interpret('1', charArray0);
    }

    @org.junit.Test(timeout = 4000)
    public void test48() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(1598);
        java.lang.String string0 = "J$NCZ;]o";
        try {
            brainfuckEngine0.interpret("J$NCZ;]o");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // -1
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test49() throws java.lang.Throwable {
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token0 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine.Token brainfuckEngine_Token1 = new net.mooctest.BrainfuckEngine.Token();
        net.mooctest.BrainfuckEngine brainfuckEngine0 = new net.mooctest.BrainfuckEngine(0);
        byte[] byteArray0 = new byte[7];
        byteArray0[6] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[4] = ((byte) (56));
        byteArray0[6] = ((byte) (-1));
        brainfuckEngine0.data = byteArray0;
        char[] charArray0 = new char[0];
        brainfuckEngine0.interpret('>', charArray0);
        char[] charArray1 = new char[7];
        charArray1[0] = ']';
        charArray1[1] = ',';
        charArray1[4] = '<';
        charArray1[5] = 'a';
        charArray1[6] = ']';
        brainfuckEngine0.interpret('<', charArray1);
        try {
            brainfuckEngine0.interpret("f=3*6(<e+dz");
            org.junit.Assert.fail("Expecting exception: Exception");
        } catch (java.lang.Exception e) {
            //
            // Error on line 0, column 8:data pointer (0) on postion 6 negative.
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test50() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(125);
        ookEngine0.dataPointer = 125;
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream();
        java.io.InputStreamReader inputStreamReader0 = new java.io.InputStreamReader(pipedInputStream0);
        ookEngine0.consoleReader = inputStreamReader0;
        ookEngine0.interpret(" ");
        net.mooctest.OokEngine.Token.values();
    }
    @org.junit.Test(timeout = 4000)
    public void test51() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(121);
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.BRACKET_RIGHT;
        java.lang.String string0 = "NEXT";
        ookEngine0.defaultTokenLength = 1265;
        ookEngine_Token0.value = "*";
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        java.lang.String string1 = "P+5VO>OxsC/SLyIx";
        byte[] byteArray0 = new byte[8];
        byteArray0[0] = ((byte) (-23));
        byteArray0[1] = ((byte) (-35));
        byteArray0[2] = ((byte) (4));
        byteArray0[3] = ((byte) (1));
        byteArray0[4] = ((byte) (13));
        byteArray0[5] = ((byte) (-100));
        byteArray0[6] = ((byte) (40));
        byteArray0[7] = ((byte) (17));
        ookEngine0.data = byteArray0;
        ookEngine0.defaultTokenLength = 121;
        ookEngine_Token0.getValue();
        try {
            ookEngine0.interpret("*");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test53() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(125);
        ookEngine0.lineCount = 34;
        ookEngine0.dataPointer = 125;
        ookEngine0.interpret(" ");
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("cK2");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.cK2
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test54() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(121);
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.BRACKET_RIGHT;
        java.lang.String string0 = "NEXT";
        ookEngine0.defaultTokenLength = 1265;
        ookEngine_Token0.value = "*";
        java.lang.String string1 = "P+5VO>OxsC/SLyIx";
        ookEngine0.defaultTokenLength = 121;
        ookEngine_Token0.getValue();
        ookEngine0.interpret("*");
        net.mooctest.OokEngine.Token.values();
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("*");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.*
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test56() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(0);
        ookEngine0.defaultTokenLength = 0;
        ookEngine0.initate(0);
        java.io.InputStreamReader inputStreamReader0 = ookEngine0.consoleReader;
        ookEngine0.consoleReader = inputStreamReader0;
        ookEngine0.interpret("");
        char[] charArray0 = new char[1];
        charArray0[0] = 'L';
        ookEngine0.interpret('L', charArray0);
        ookEngine0.outWriter = null;
        ookEngine0.dataPointer = -2664;
        ookEngine0.interpret("e{VF?}t:c}");
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("uXm");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.uXm
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }

    @org.junit.Test(timeout = 4000)
    public void test58() throws java.lang.Throwable {
        net.mooctest.OokEngine.Token.values();
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("-f!1a", true);
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine(306654252, mockFileOutputStream0, ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.io.Reader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test59() throws java.lang.Throwable {
        int int0 = -1473;
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-1473));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test60() throws java.lang.Throwable {
        int int0 = -128;
        java.lang.String string0 = "net.mooctest.OokEngine";
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("net.mooctest.OokEngine");
        java.io.PrintStream printStream0 = mockPrintStream0.append(((java.lang.CharSequence) ("net.mooctest.OokEngine")));
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream1 = new org.evosuite.runtime.mock.java.io.MockPrintStream(printStream0, true);
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-128), mockPrintStream1);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test61() throws java.lang.Throwable {
        int int0 = -262;
        net.mooctest.OokEngine ookEngine0 = null;
        try {
            ookEngine0 = new net.mooctest.OokEngine((-262), ((java.io.OutputStream) (null)), ((java.io.InputStream) (null)));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test62() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(1528);
        ookEngine0.defaultTokenLength = -1;
        byte[] byteArray0 = new byte[5];
        byteArray0[0] = ((byte) (119));
        byteArray0[1] = ((byte) (17));
        byteArray0[2] = ((byte) (25));
        byteArray0[3] = ((byte) (-10));
        byteArray0[4] = ((byte) (94));
        ookEngine0.data = byteArray0;
        try {
            ookEngine0.interpret(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.OokEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test63() throws java.lang.Throwable {
        org.evosuite.runtime.testdata.FileSystemHandling.appendLineToFile(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), "Ook! Ook.");
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(125);
        byte[] byteArray0 = new byte[3];
        ookEngine0.dataPointer = -2205;
        ookEngine0.data = byteArray0;
        ookEngine0.columnCount = 125;
        byteArray0[0] = ((byte) (79));
        byteArray0[1] = ((byte) (-108));
        byteArray0[2] = ((byte) (22));
        ookEngine0.dataPointer = ((int) ((byte) (22)));
        ookEngine0.data = byteArray0;
        ookEngine0.interpret("`[HsI,J8|b{");
        ookEngine0.interpret(" ");
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("T;");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.T;
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test64() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(125);
        byte[] byteArray0 = new byte[3];
        ookEngine0.dataPointer = 125;
        org.evosuite.runtime.testdata.FileSystemHandling.shouldAllThrowIOExceptions();
        ookEngine0.data = byteArray0;
        ookEngine0.columnCount = 125;
        ookEngine0.columnCount = 125;
        byteArray0[0] = ((byte) (79));
        byteArray0[2] = ((byte) (22));
        ookEngine0.interpret("`[HsI,J8|b{");
        ookEngine0.defaultTokenLength = -1632679171;
        try {
            ookEngine0.interpret(" ");
            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
        } catch (java.lang.StringIndexOutOfBoundsException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test65() throws java.lang.Throwable {
        int int0 = 2147483645;
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(2147483645);
    }
    @org.junit.Test(timeout = 4000)
    public void test66() throws java.lang.Throwable {
        net.mooctest.OokEngine.Token.values();
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(0);
        ookEngine0.interpret("D!yghE^h%MH)34");
    }
    @org.junit.Test(timeout = 4000)
    public void test67() throws java.lang.Throwable {
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(4261, pipedOutputStream0);
        ookEngine0.dataPointer = 0;
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("CharMatcher.invisible()");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.CharMatcher.invisible()
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }

    @org.junit.Test(timeout = 4000)
    public void test69() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(125);
        ookEngine0.dataPointer = 125;
        ookEngine0.interpret(" ");
    }
    @org.junit.Test(timeout = 4000)
    public void test70() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(4783);
        ookEngine0.interpret("eK");
    }
    @org.junit.Test(timeout = 4000)
    public void test71() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(4365);
        byte[] byteArray0 = new byte[6];
        byteArray0[0] = ((byte) (-1));
        byteArray0[1] = ((byte) (125));
        byteArray0[2] = ((byte) (-93));
        byteArray0[3] = ((byte) (-80));
        byteArray0[4] = ((byte) (-58));
        byteArray0[5] = ((byte) (-30));
        ookEngine0.data = byteArray0;
        ookEngine0.interpret("COMMENT");
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("COMMENT");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.COMMENT
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test72() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(121);
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.BRACKET_RIGHT;
        java.lang.String string0 = "NEXT";
        ookEngine0.defaultTokenLength = 1265;
        java.lang.String string1 = "P+5VO>OxsC/SLyIx";
        ookEngine0.defaultTokenLength = 121;
        ookEngine_Token0.getValue();
        ookEngine0.interpret("*");
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf("*");
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.*
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test73() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(139);
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.BRACKET_LEFT;
        java.lang.String string0 = "NEXT";
        ookEngine0.defaultTokenLength = 1265;
        java.lang.String string1 = "P+5VO>OxsC/SLyIx";
        ookEngine0.defaultTokenLength = 139;
        ookEngine_Token0.getValue();
        ookEngine0.interpret("com.github.javaparser.metamodel.ExplicitConstructorInvocationStmtMetaModel");
        net.mooctest.OokEngine.Token.values();
        // Undeclared exception!
        try {
            net.mooctest.OokEngine.Token.valueOf(ookEngine_Token0.value);
            org.junit.Assert.fail("Expecting exception: IllegalArgumentException");
        } catch (java.lang.IllegalArgumentException e) {
            //
            // No enum constant net.mooctest.OokEngine.Token.Ook! Ook?
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.lang.Enum", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test74() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(115);
        ookEngine0.initate(9);
        ookEngine0.interpret("&");
        ookEngine0.dataPointer = 115;
        ookEngine0.dataPointer = 115;
        ookEngine0.interpret(" ");
        net.mooctest.OokEngine.Token.values();
    }
    @org.junit.Test(timeout = 4000)
    public void test77() throws java.lang.Throwable {
        net.mooctest.OokEngine ookEngine0 = new net.mooctest.OokEngine(121);
        net.mooctest.OokEngine.Token ookEngine_Token0 = net.mooctest.OokEngine.Token.BRACKET_RIGHT;
        ookEngine0.defaultTokenLength = 1265;
        ookEngine_Token0.value = "*";
        org.evosuite.runtime.testdata.FileSystemHandling.createFolder(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)));
        byte[] byteArray0 = new byte[8];
        byteArray0[0] = ((byte) (-23));
        byteArray0[1] = ((byte) (-35));
        byteArray0[2] = ((byte) (4));
        byteArray0[3] = ((byte) (4));
        byteArray0[4] = ((byte) (13));
        byteArray0[5] = ((byte) (-100));
        byteArray0[6] = ((byte) (40));
        byteArray0[7] = ((byte) (17));
        ookEngine0.data = byteArray0;
        ookEngine0.defaultTokenLength = 121;
        ookEngine_Token0.getValue();
        try {
            ookEngine0.interpret("*");
            org.junit.Assert.fail("Expecting exception: ArrayIndexOutOfBoundsException");
        } catch (java.lang.ArrayIndexOutOfBoundsException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test78() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(56);
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.interpret("oll");
        trollScriptEngine0.isValidToken("llo");
        try {
            trollScriptEngine0.interpret(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.TrollScriptEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test80() throws java.lang.Throwable {
        int int0 = -1279;
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-1279));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test81() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.interpret("LONG");
    }
    @org.junit.Test(timeout = 4000)
    public void test82() throws java.lang.Throwable {
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        byte[] byteArray0 = new byte[6];
        byteArray0[0] = ((byte) (0));
        byteArray0[1] = ((byte) (0));
        byteArray0[2] = ((byte) (0));
        byteArray0[3] = ((byte) (35));
        byteArray0[4] = ((byte) (-1));
        byteArray0[5] = ((byte) (-117));
        java.io.ByteArrayInputStream byteArrayInputStream0 = new java.io.ByteArrayInputStream(byteArray0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-582), pipedOutputStream0, byteArrayInputStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test83() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.dataPointer = 0;
        trollScriptEngine0.initate(0);
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.charPointer = 0;
        trollScriptEngine0.interpret("olo");
        trollScriptEngine0.interpret('?', ((char[]) (null)));
        trollScriptEngine0.charPointer = 3;
        trollScriptEngine0.interpret("net.mooctest.TrollScriptEngine");
        trollScriptEngine0.isValidToken("olo");
        trollScriptEngine0.interpret("");
        try {
            trollScriptEngine0.interpret(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.TrollScriptEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test84() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(4);
        java.io.BufferedReader bufferedReader0 = trollScriptEngine0.fileReader;
        trollScriptEngine0.fileReader = null;
        trollScriptEngine0.charPointer = 62;
        trollScriptEngine0.interpret("`X=l ");
    }

    @org.junit.Test(timeout = 4000)
    public void test86() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token1 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.isValidToken("tro");
        trollScriptEngine0.interpret("%s is not an ArrayType");
        trollScriptEngine0.isValidToken("5&6+8");
        char[] charArray0 = new char[3];
        charArray0[0] = 'U';
        charArray0[1] = 'U';
        charArray0[2] = 'U';
        trollScriptEngine0.interpret('U', charArray0);
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.isValidToken("JSA$~Ag5)(nza");
        trollScriptEngine0.interpret("zmmqHQH");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.interpret("ool");
        trollScriptEngine0.interpret("oll");
        trollScriptEngine0.interpret("");
    }
    @org.junit.Test(timeout = 4000)
    public void test87() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("net.mooctest.TrollScriptEngine$Token");
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(mockFileOutputStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(120, mockPrintStream0);
        java.lang.Integer integer0 = new java.lang.Integer((-1750));
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.isValidToken("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.isValidToken("!yd]9y:I'p_1xZ/sJ");
    }
    @org.junit.Test(timeout = 4000)
    public void test88() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        byte[] byteArray0 = new byte[3];
        byteArray0[0] = ((byte) (57));
        byteArray0[1] = ((byte) (-63));
        byteArray0[2] = ((byte) (85));
        trollScriptEngine0.data = byteArray0;
        // Undeclared exception!
        try {
            trollScriptEngine0.isValidToken(((java.lang.String) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test89() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token1 = new net.mooctest.TrollScriptEngine.Token();
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream("lll");
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-331), mockPrintStream0);
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test90() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        java.io.File file0 = org.evosuite.runtime.mock.java.io.MockFile.createTempFile("ll.", ((java.lang.String) (null)), ((java.io.File) (null)));
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(file0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(114, mockPrintStream0);
        trollScriptEngine0.charPointer = -468;
        mockPrintStream0.format(((java.util.Locale) (null)), "ool", ((java.lang.Object[]) (null)));
        trollScriptEngine0.lineCount = 114;
        try {
            trollScriptEngine0.interpret("ool");
            org.junit.Assert.fail("Expecting exception: StringIndexOutOfBoundsException");
        } catch (java.lang.StringIndexOutOfBoundsException e) {
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test91() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.isValidToken("lll");
        trollScriptEngine0.interpret("tro");
    }
    @org.junit.Test(timeout = 4000)
    public void test92() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(77);
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.isValidToken("llo");
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.isValidToken(":OADV}fxbkmp|fOn");
    }
    @org.junit.Test(timeout = 4000)
    public void test93() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(0);
        trollScriptEngine0.interpret("Try has no finally, no catch, and no resources.");
    }
    @org.junit.Test(timeout = 4000)
    public void test94() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2044);
        trollScriptEngine0.interpret("lol");
    }
    @org.junit.Test(timeout = 4000)
    public void test95() throws java.lang.Throwable {
        java.lang.String string0 = "gW";
        org.evosuite.runtime.testdata.FileSystemHandling.appendStringToFile(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), "gW");
        int int0 = 2147483645;
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(2147483645);
    }
    @org.junit.Test(timeout = 4000)
    public void test96() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new net.mooctest.TrollScriptEngine((-884));
            org.junit.Assert.fail("Expecting exception: NegativeArraySizeException");
        } catch (java.lang.NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            org.evosuite.runtime.EvoAssertions.verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test97() throws java.lang.Throwable {
        java.io.ByteArrayOutputStream byteArrayOutputStream0 = new java.io.ByteArrayOutputStream(1804);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1804, byteArrayOutputStream0);
    }
    @org.junit.Test(timeout = 4000)
    public void test98() throws java.lang.Throwable {
        java.io.PipedOutputStream pipedOutputStream0 = new java.io.PipedOutputStream();
        org.evosuite.runtime.testdata.FileSystemHandling.appendStringToFile(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), "tro");
        org.evosuite.runtime.testdata.FileSystemHandling.shouldAllThrowIOExceptions();
        pipedOutputStream0.flush();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1326, pipedOutputStream0);
        trollScriptEngine0.interpret("6");
        trollScriptEngine0.interpret("6");
        org.evosuite.runtime.testdata.FileSystemHandling.setPermissions(((org.evosuite.runtime.testdata.EvoSuiteFile) (null)), true, true, true);
        trollScriptEngine0.isValidToken("6");
        trollScriptEngine0.isValidToken("TYPE");
        trollScriptEngine0.interpret("tro");
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.interpret("");
        trollScriptEngine0.isValidToken("TYPE");
        trollScriptEngine0.isValidToken("I5@.U*eEG/K29..9M'u");
        trollScriptEngine0.interpret("com.google.common.cache.ForwardingLoadingCache$SimpleForwardingLoadingCache");
    }
    @org.junit.Test(timeout = 4000)
    public void test99() throws java.lang.Throwable {
        org.evosuite.runtime.mock.java.io.MockFileOutputStream mockFileOutputStream0 = new org.evosuite.runtime.mock.java.io.MockFileOutputStream("net.mooctest.TrollScriptEngine$Token");
        org.evosuite.runtime.mock.java.io.MockPrintStream mockPrintStream0 = new org.evosuite.runtime.mock.java.io.MockPrintStream(mockFileOutputStream0);
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(120, mockPrintStream0);
        java.lang.Integer integer0 = new java.lang.Integer((-1750));
        java.lang.String string0 = "net.moontest.TrollScriptEngine$Token";
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        java.io.PipedInputStream pipedInputStream0 = new java.io.PipedInputStream(474);
        java.io.PushbackInputStream pushbackInputStream0 = new java.io.PushbackInputStream(pipedInputStream0, 1445);
        java.io.PushbackInputStream pushbackInputStream1 = new java.io.PushbackInputStream(pushbackInputStream0);
        java.io.InputStreamReader inputStreamReader0 = null;
        try {
            inputStreamReader0 = new java.io.InputStreamReader(pushbackInputStream1, ((java.nio.charset.CharsetDecoder) (null)));
            org.junit.Assert.fail("Expecting exception: NullPointerException");
        } catch (java.lang.NullPointerException e) {
            //
            // charset decoder
            //
            org.evosuite.runtime.EvoAssertions.verifyException("java.io.InputStreamReader", e);
        }
    }
    @org.junit.Test(timeout = 4000)
    public void test100() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(1);
        trollScriptEngine0.isValidToken("olo");
        trollScriptEngine0.isValidToken("ll.");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.interpret("oll");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.interpret("loo");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.isValidToken("loo");
        trollScriptEngine0.isValidToken("ll.");
        trollScriptEngine0.isValidToken("V;#_c");
        trollScriptEngine0.interpret("lol");
        trollScriptEngine0.dataPointer = 1991;
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.interpret("hojJG@;]9tn_");
        trollScriptEngine0.interpret("");
        trollScriptEngine0.interpret("\"b@a]g");
    }
    @org.junit.Test(timeout = 4000)
    public void test101() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(3919);
        trollScriptEngine0.interpret("a)Z7'8eT:Nx}(M=j'@3");
        trollScriptEngine0.charPointer = 191;
        trollScriptEngine0.interpret("Z/:");
    }
    @org.junit.Test(timeout = 4000)
    public void test103() throws java.lang.Throwable {
        net.mooctest.TrollScriptEngine.Token trollScriptEngine_Token0 = new net.mooctest.TrollScriptEngine.Token();
        net.mooctest.TrollScriptEngine trollScriptEngine0 = new net.mooctest.TrollScriptEngine(9);
        trollScriptEngine0.dataPointer = 9;
        trollScriptEngine0.interpret("=]%e*I|Q5G");
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.isValidToken("");
        byte[] byteArray0 = new byte[9];
        byteArray0[0] = ((byte) (1));
        byteArray0[1] = ((byte) (-20));
        byteArray0[2] = ((byte) (114));
        byteArray0[3] = ((byte) (84));
        byteArray0[4] = ((byte) (-122));
        byteArray0[5] = ((byte) (-122));
        byteArray0[6] = ((byte) (21));
        byteArray0[7] = ((byte) (124));
        byteArray0[8] = ((byte) (1));
        trollScriptEngine0.data = byteArray0;
        char[] charArray0 = new char[4];
        charArray0[1] = 'B';
        charArray0[2] = 'B';
        charArray0[3] = 'B';
        trollScriptEngine0.interpret('B', charArray0);
        trollScriptEngine0.interpret("ool");
        trollScriptEngine0.interpret("-x]>l^n(K(2b|J3K$E");
        trollScriptEngine0.isValidToken("QnImvUL");
        trollScriptEngine0.isValidToken("lll");
        trollScriptEngine0.interpret("lol");
        trollScriptEngine0.interpret("llo");
        trollScriptEngine0.interpret("lol");
        trollScriptEngine0.interpret("lol");
        trollScriptEngine0.isValidToken("oll");
        trollScriptEngine0.isValidToken("-x]>l^n(K(2b|J3K$E");
        trollScriptEngine0.isValidToken("lol");
        trollScriptEngine0.interpret("7aDNe(&");
        trollScriptEngine0.interpret("lll");
        trollScriptEngine0.interpret("");
    }


}


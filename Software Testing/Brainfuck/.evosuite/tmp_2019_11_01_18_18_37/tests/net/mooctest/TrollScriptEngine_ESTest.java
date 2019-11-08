/*
 * This file was automatically generated by EvoSuite
 * Fri Nov 01 10:19:34 GMT 2019
 */

package net.mooctest;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.evosuite.runtime.EvoAssertions.*;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.io.PrintStream;
import java.io.PushbackInputStream;
import java.nio.charset.CharsetDecoder;
import java.util.Locale;

import net.mooctest.TrollScriptEngine;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.evosuite.runtime.mock.java.io.MockFile;
import org.evosuite.runtime.mock.java.io.MockFileOutputStream;
import org.evosuite.runtime.mock.java.io.MockPrintStream;
import org.evosuite.runtime.testdata.EvoSuiteFile;
import org.evosuite.runtime.testdata.FileSystemHandling;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class)
@EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true)
public class TrollScriptEngine_ESTest extends TrollScriptEngine_ESTest_scaffolding {

    @Test(timeout = 4000)
    public void test00() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(56);
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.interpret("oll");
        trollScriptEngine0.isValidToken("llo");
        try {
            trollScriptEngine0.interpret((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.TrollScriptEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test01() throws Throwable {
        MockPrintStream mockPrintStream0 = new MockPrintStream("o4|p/e6|69;*KdCt>P2");
        PrintStream printStream0 = mockPrintStream0.append('H');
        TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new TrollScriptEngine(0, printStream0, (InputStream) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("java.io.Reader", e);
        }
    }

    @Test(timeout = 4000)
    public void test02() throws Throwable {
        int int0 = (-1279);
        TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new TrollScriptEngine((-1279));
            fail("Expecting exception: NegativeArraySizeException");

        } catch (NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test03() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
        trollScriptEngine0.interpret("LONG");
    }

    @Test(timeout = 4000)
    public void test04() throws Throwable {
        PipedOutputStream pipedOutputStream0 = new PipedOutputStream();
        byte[] byteArray0 = new byte[6];
        byteArray0[0] = (byte) 0;
        byteArray0[1] = (byte) 0;
        byteArray0[2] = (byte) 0;
        byteArray0[3] = (byte) 35;
        byteArray0[4] = (byte) (-1);
        byteArray0[5] = (byte) (-117);
        ByteArrayInputStream byteArrayInputStream0 = new ByteArrayInputStream(byteArray0);
        TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new TrollScriptEngine((-582), pipedOutputStream0, byteArrayInputStream0);
            fail("Expecting exception: NegativeArraySizeException");

        } catch (NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test05() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
        trollScriptEngine0.dataPointer = 0;
        trollScriptEngine0.initate(0);
        trollScriptEngine0.isValidToken("");
        trollScriptEngine0.charPointer = 0;
        trollScriptEngine0.interpret("olo");
        trollScriptEngine0.interpret('?', (char[]) null);
        trollScriptEngine0.charPointer = 3;
        trollScriptEngine0.interpret("net.mooctest.TrollScriptEngine");
        trollScriptEngine0.isValidToken("olo");
        trollScriptEngine0.interpret("");
        try {
            trollScriptEngine0.interpret((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.TrollScriptEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test06() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(4);
        BufferedReader bufferedReader0 = trollScriptEngine0.fileReader;
        trollScriptEngine0.fileReader = null;
        trollScriptEngine0.charPointer = 62;
        trollScriptEngine0.interpret("`X=l ");
    }

    @Test(timeout = 4000)
    public void test07() throws Throwable {
        MockFile mockFile0 = new MockFile("ciYF&XzBXCH", "ciYF&XzBXCH");
        MockFileOutputStream mockFileOutputStream0 = new MockFileOutputStream(mockFile0, false);
        MockPrintStream mockPrintStream0 = new MockPrintStream(mockFileOutputStream0);
        String string0 = TrollScriptEngine.Token.START;
        PrintStream printStream0 = mockPrintStream0.append((CharSequence) "tro", 0, 0);
        PipedInputStream pipedInputStream0 = new PipedInputStream();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(1521, mockFileOutputStream0, pipedInputStream0);
        trollScriptEngine0.interpret("y%/AzJIxUxy");
        TrollScriptEngine trollScriptEngine1 = new TrollScriptEngine(0, printStream0);
        trollScriptEngine1.isValidToken("ciYF&XzBXCH");
        TrollScriptEngine trollScriptEngine2 = new TrollScriptEngine(0, printStream0, pipedInputStream0);
        trollScriptEngine2.interpret("tro");
        trollScriptEngine1.interpret("com.google.common.hash.BloomFilterStrategies");
    }

    @Test(timeout = 4000)
    public void test08() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine.Token trollScriptEngine_Token1 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
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

    @Test(timeout = 4000)
    public void test09() throws Throwable {
        MockFileOutputStream mockFileOutputStream0 = new MockFileOutputStream("net.mooctest.TrollScriptEngine$Token");
        MockPrintStream mockPrintStream0 = new MockPrintStream(mockFileOutputStream0);
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(120, mockPrintStream0);
        Integer integer0 = new Integer((-1750));
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.isValidToken("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.isValidToken("!yd]9y:I'p_1xZ/sJ");
    }

    @Test(timeout = 4000)
    public void test10() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
        byte[] byteArray0 = new byte[3];
        byteArray0[0] = (byte) 57;
        byteArray0[1] = (byte) (-63);
        byteArray0[2] = (byte) 85;
        trollScriptEngine0.data = byteArray0;
        // Undeclared exception!
        try {
            trollScriptEngine0.isValidToken((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
        }
    }

    @Test(timeout = 4000)
    public void test11() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine.Token trollScriptEngine_Token1 = new TrollScriptEngine.Token();
        MockPrintStream mockPrintStream0 = new MockPrintStream("lll");
        TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new TrollScriptEngine((-331), mockPrintStream0);
            fail("Expecting exception: NegativeArraySizeException");

        } catch (NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test12() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        File file0 = MockFile.createTempFile("ll.", (String) null, (File) null);
        MockPrintStream mockPrintStream0 = new MockPrintStream(file0);
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(114, mockPrintStream0);
        trollScriptEngine0.charPointer = (-468);
        mockPrintStream0.format((Locale) null, "ool", (Object[]) null);
        trollScriptEngine0.lineCount = 114;
        try {
            trollScriptEngine0.interpret("ool");
            fail("Expecting exception: StringIndexOutOfBoundsException");

        } catch (StringIndexOutOfBoundsException e) {
        }
    }

    @Test(timeout = 4000)
    public void test13() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
        trollScriptEngine0.isValidToken("lll");
        trollScriptEngine0.interpret("tro");
    }

    @Test(timeout = 4000)
    public void test14() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(77);
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.isValidToken("llo");
        trollScriptEngine0.interpret("ooo");
        trollScriptEngine0.isValidToken(":OADV}fxbkmp|fOn");
    }

    @Test(timeout = 4000)
    public void test15() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(0);
        trollScriptEngine0.interpret("Try has no finally, no catch, and no resources.");
    }

    @Test(timeout = 4000)
    public void test16() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(2044);
        trollScriptEngine0.interpret("lol");
    }

    @Test(timeout = 4000)
    public void test17() throws Throwable {
        String string0 = "gW";
        FileSystemHandling.appendStringToFile((EvoSuiteFile) null, "gW");
        int int0 = 2147483645;
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(2147483645);
    }

    @Test(timeout = 4000)
    public void test18() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = null;
        try {
            trollScriptEngine0 = new TrollScriptEngine((-884));
            fail("Expecting exception: NegativeArraySizeException");

        } catch (NegativeArraySizeException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.BrainfuckEngine", e);
        }
    }

    @Test(timeout = 4000)
    public void test19() throws Throwable {
        ByteArrayOutputStream byteArrayOutputStream0 = new ByteArrayOutputStream(1804);
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(1804, byteArrayOutputStream0);
    }

    @Test(timeout = 4000)
    public void test20() throws Throwable {
        PipedOutputStream pipedOutputStream0 = new PipedOutputStream();
        FileSystemHandling.appendStringToFile((EvoSuiteFile) null, "tro");
        FileSystemHandling.shouldAllThrowIOExceptions();
        pipedOutputStream0.flush();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(1326, pipedOutputStream0);
        trollScriptEngine0.interpret("6");
        trollScriptEngine0.interpret("6");
        FileSystemHandling.setPermissions((EvoSuiteFile) null, true, true, true);
        trollScriptEngine0.isValidToken("6");
        trollScriptEngine0.isValidToken("TYPE");
        trollScriptEngine0.interpret("tro");
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.interpret("");
        trollScriptEngine0.isValidToken("TYPE");
        trollScriptEngine0.isValidToken("I5@.U*eEG/K29..9M'u");
        trollScriptEngine0.interpret("com.google.common.cache.ForwardingLoadingCache$SimpleForwardingLoadingCache");
    }

    @Test(timeout = 4000)
    public void test21() throws Throwable {
        MockFileOutputStream mockFileOutputStream0 = new MockFileOutputStream("net.mooctest.TrollScriptEngine$Token");
        MockPrintStream mockPrintStream0 = new MockPrintStream(mockFileOutputStream0);
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(120, mockPrintStream0);
        Integer integer0 = new Integer((-1750));
        String string0 = "net.moontest.TrollScriptEngine$Token";
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        trollScriptEngine0.interpret("net.moontest.TrollScriptEngine$Token");
        PipedInputStream pipedInputStream0 = new PipedInputStream(474);
        PushbackInputStream pushbackInputStream0 = new PushbackInputStream(pipedInputStream0, 1445);
        PushbackInputStream pushbackInputStream1 = new PushbackInputStream(pushbackInputStream0);
        InputStreamReader inputStreamReader0 = null;
        try {
            inputStreamReader0 = new InputStreamReader(pushbackInputStream1, (CharsetDecoder) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // charset decoder
            //
            verifyException("java.io.InputStreamReader", e);
        }
    }

    @Test(timeout = 4000)
    public void test22() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(1);
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

    @Test(timeout = 4000)
    public void test23() throws Throwable {
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(3919);
        trollScriptEngine0.interpret("a)Z7'8eT:Nx}(M=j'@3");
        trollScriptEngine0.charPointer = 191;
        trollScriptEngine0.interpret("Z/:");
    }

    @Test(timeout = 4000)
    public void test24() throws Throwable {
        MockFile mockFile0 = new MockFile("ciYF&XzBXCH", "ciYF&XzBXCH");
        MockFileOutputStream mockFileOutputStream0 = new MockFileOutputStream(mockFile0, false);
        MockPrintStream mockPrintStream0 = new MockPrintStream(mockFileOutputStream0);
        String string0 = TrollScriptEngine.Token.START;
        PrintStream printStream0 = mockPrintStream0.append((CharSequence) "tro", 0, 0);
        PipedInputStream pipedInputStream0 = new PipedInputStream();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(1521, mockFileOutputStream0, pipedInputStream0);
        trollScriptEngine0.interpret("y%/AzJIxUxy");
        TrollScriptEngine trollScriptEngine1 = new TrollScriptEngine(0, printStream0);
        trollScriptEngine1.isValidToken("ciYF&XzBXCH");
        TrollScriptEngine trollScriptEngine2 = new TrollScriptEngine(0, printStream0, pipedInputStream0);
        trollScriptEngine2.interpret("tro");
        trollScriptEngine1.interpret("com.google.common.hash.B$oomFilterStrategies");
    }

    @Test(timeout = 4000)
    public void test25() throws Throwable {
        TrollScriptEngine.Token trollScriptEngine_Token0 = new TrollScriptEngine.Token();
        TrollScriptEngine trollScriptEngine0 = new TrollScriptEngine(9);
        trollScriptEngine0.dataPointer = 9;
        trollScriptEngine0.interpret("=]%e*I|Q5G");
        trollScriptEngine0.interpret("ll.");
        trollScriptEngine0.isValidToken("");
        byte[] byteArray0 = new byte[9];
        byteArray0[0] = (byte) 1;
        byteArray0[1] = (byte) (-20);
        byteArray0[2] = (byte) 114;
        byteArray0[3] = (byte) 84;
        byteArray0[4] = (byte) (-122);
        byteArray0[5] = (byte) (-122);
        byteArray0[6] = (byte) 21;
        byteArray0[7] = (byte) 124;
        byteArray0[8] = (byte) 1;
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

/*
 * This file was automatically generated by EvoSuite
 * Sun Oct 25 06:11:33 GMT 2020
 */

package net.mooctest;

import org.junit.Test;
import static org.junit.Assert.*;
import static org.evosuite.runtime.EvoAssertions.*;
import java.util.Set;
import net.mooctest.Utils;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class) @EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true)
public class Utils_ESTest extends Utils_ESTest_scaffolding {

  @Test(timeout = 4000)
  public void utils_test0()  throws Throwable  {
      String string0 = Utils.normalize("9");
      assertEquals("9", string0);
  }

  @Test(timeout = 4000)
  public void utils_test1()  throws Throwable  {
      String string0 = Utils.normalize("`Xtt_[4l$sj.010");
      assertEquals("xtt4lsj010", string0);
  }

  @Test(timeout = 4000)
  public void utils_test2()  throws Throwable  {
      String string0 = Utils.normalize("qkVpOCHZ`");
      assertEquals("qkvpochz", string0);
  }

  @Test(timeout = 4000)
  public void utils_test3()  throws Throwable  {
      String string0 = Utils.normalize("");
      assertEquals("", string0);
  }

  @Test(timeout = 4000)
  public void utils_test4()  throws Throwable  {
      Set<String> set0 = Utils.getSubstrings("");
      assertFalse(set0.contains(""));
  }

  @Test(timeout = 4000)
  public void utils_test5()  throws Throwable  {
      // Undeclared exception!
      try {
        Utils.normalize((String) null);
        fail("Expecting exception: NullPointerException");

      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.Utils", e);
      }
  }

  @Test(timeout = 4000)
  public void utils_test6()  throws Throwable  {
      // Undeclared exception!
      try {
        Utils.getSubstrings((String) null);
        fail("Expecting exception: NullPointerException");

      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.Utils", e);
      }
  }

  @Test(timeout = 4000)
  public void utils_test7()  throws Throwable  {
      Set<String> set0 = Utils.getSubstrings("A'(I?Mg{d{wOh3Riqpr");
      assertEquals(189, set0.size());
  }

  @Test(timeout = 4000)
  public void utils_test8()  throws Throwable  {
      String string0 = Utils.normalize("A'(I?Mg{d{wOh3Riqpr");
      assertEquals("aimgdwoh3riqpr", string0);
  }

  @Test(timeout = 4000)
  public void utils_test9()  throws Throwable  {
      Utils utils0 = new Utils();
  }
}

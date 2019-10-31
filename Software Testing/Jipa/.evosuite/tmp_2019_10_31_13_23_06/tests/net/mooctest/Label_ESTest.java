/*
 * This file was automatically generated by EvoSuite
 * Thu Oct 31 05:23:49 GMT 2019
 */

package net.mooctest;

import org.junit.Test;
import static org.junit.Assert.*;
import static org.evosuite.runtime.EvoAssertions.*;
import net.mooctest.Jipa;
import net.mooctest.Label;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.evosuite.runtime.System;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class) @EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true) 
public class Label_ESTest extends Label_ESTest_scaffolding {

  @Test(timeout = 4000)
  public void test00()  throws Throwable  {
      Jipa.TOTAL_INSTRUCTIONS = (-156);
      Label.buildLabelList();
  }

  @Test(timeout = 4000)
  public void test01()  throws Throwable  {
      Label label0 = new Label((-443), "lbl kdo)~g*w%{");
      label0.getName();
      assertEquals((-443), label0.getLine());
  }

  @Test(timeout = 4000)
  public void test02()  throws Throwable  {
      Label label0 = new Label(852, "");
      label0.getName();
      assertEquals(852, label0.getLine());
  }

  @Test(timeout = 4000)
  public void test03()  throws Throwable  {
      Label label0 = new Label(0, "");
      int int0 = label0.getLine();
      assertEquals(0, int0);
  }

  @Test(timeout = 4000)
  public void test04()  throws Throwable  {
      Label label0 = new Label((-156), "lbl ");
      int int0 = label0.getLine();
      assertEquals((-156), int0);
  }

  @Test(timeout = 4000)
  public void test05()  throws Throwable  {
      Label.labelList = null;
      // Undeclared exception!
      try { 
        Label.findLabel("");
        fail("Expecting exception: NullPointerException");
      
      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.Label", e);
      }
  }

  @Test(timeout = 4000)
  public void test06()  throws Throwable  {
      Label.findLabel("lblk");
      Label.findLabel("lblk");
      Label.findLabel("lblk");
      Label.buildLabelList();
      Label.findLabel("lbl ");
      System.setCurrentTimeMillis((-1L));
      Label.buildLabelList();
      Label.buildLabelList();
      Label.buildLabelList();
      Label.findLabel("lblk");
      Label.buildLabelList();
      Label.buildLabelList();
      Label.buildLabelList();
      Label.findLabel("lbl ");
      Label.buildLabelList();
      System.setCurrentTimeMillis((-1));
      Label.findLabel("kdo)~g*w%{");
      System.setCurrentTimeMillis(2207L);
      int int0 = Label.findLabel("i'uS:~d1s)uO:bKO1\u0002");
      assertEquals((-1), int0);
  }

  @Test(timeout = 4000)
  public void test07()  throws Throwable  {
      Jipa.TOTAL_INSTRUCTIONS = 3345;
      String[] stringArray0 = new String[2];
      stringArray0[0] = "kdo)~.g*.{";
      Jipa.instruction = stringArray0;
      // Undeclared exception!
      try { 
        Label.buildLabelList();
        fail("Expecting exception: NullPointerException");
      
      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.Label", e);
      }
  }

  @Test(timeout = 4000)
  public void test08()  throws Throwable  {
      Label label0 = new Label(921, (String) null);
      Label.labelList = label0.labelList;
      Jipa.TOTAL_INSTRUCTIONS = 921;
      Label.labelList = label0.labelList;
      label0.getLine();
      label0.getLine();
      Jipa.TOTAL_INSTRUCTIONS = 4269;
      Label.findLabel("");
      label0.getLine();
      Jipa.TOTAL_INSTRUCTIONS = 921;
      Jipa.TOTAL_INSTRUCTIONS = 921;
      // Undeclared exception!
      try { 
        Label.buildLabelList();
        fail("Expecting exception: ArrayIndexOutOfBoundsException");
      
      } catch(ArrayIndexOutOfBoundsException e) {
         //
         // 0
         //
         verifyException("net.mooctest.Label", e);
      }
  }

  @Test(timeout = 4000)
  public void test09()  throws Throwable  {
      Label label0 = new Label(921, (String) null);
      label0.getName();
      assertEquals(921, label0.getLine());
  }

  @Test(timeout = 4000)
  public void test10()  throws Throwable  {
      Jipa.TOTAL_INSTRUCTIONS = 802;
      String[] stringArray0 = new String[2];
      stringArray0[0] = "lbl kdo)~g*w%{";
      Jipa.instruction = stringArray0;
      // Undeclared exception!
      try { 
        Label.buildLabelList();
        fail("Expecting exception: NullPointerException");
      
      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.Label", e);
      }
  }
}

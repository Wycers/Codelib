/*
 * This file was automatically generated by EvoSuite
 * Sat Nov 02 00:40:24 GMT 2019
 */

package net.mooctest;

import org.junit.Test;
import static org.junit.Assert.*;
import net.mooctest.EmptyTreeException;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class) @EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true) 
public class EmptyTreeException_ESTest extends EmptyTreeException_ESTest_scaffolding {

  @Test(timeout = 4000)
  public void test0()  throws Throwable  {
      EmptyTreeException emptyTreeException0 = new EmptyTreeException((String) null);
  }

  @Test(timeout = 4000)
  public void test1()  throws Throwable  {
      EmptyTreeException emptyTreeException0 = new EmptyTreeException();
  }
}
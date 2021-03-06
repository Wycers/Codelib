/*
 * This file was automatically generated by EvoSuite
 * Sun Oct 25 06:20:43 GMT 2020
 */

package net.mooctest;

import org.junit.Test;
import static org.junit.Assert.*;
import static org.evosuite.runtime.EvoAssertions.*;
import java.util.Collection;
import java.util.LinkedList;
import net.mooctest.ArrayMultiTreeNode;
import net.mooctest.LinkedMultiTreeNode;
import net.mooctest.MultiTreeNode;
import net.mooctest.TreeNode;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class) @EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true) 
public class MultiTreeNode_ESTest extends MultiTreeNode_ESTest_scaffolding {

  @Test(timeout = 4000)
  public void test00()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("getkmooct<st.MultiTreeNode");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      Collection<? extends MultiTreeNode<Object>> collection0 = linkedMultiTreeNode0.siblings();
      assertNotNull(collection0);
  }

  @Test(timeout = 4000)
  public void test01()  throws Throwable  {
      Integer integer0 = new Integer(0);
      LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
      // Undeclared exception!
      try { 
        linkedMultiTreeNode0.siblings();
        fail("Expecting exception: RuntimeException");
      
      } catch(RuntimeException e) {
         //
         // Unable to find the siblings. The tree node 
         // +- 0
         //  is root
         //
         verifyException("net.mooctest.LinkedMultiTreeNode", e);
      }
  }

  @Test(timeout = 4000)
  public void test02()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("net.mooctest.cultiTreeNode");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      // Undeclared exception!
      linkedMultiTreeNode0.siblings();
  }

  @Test(timeout = 4000)
  public void test03()  throws Throwable  {
      Object object0 = new Object();
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(object0);
      ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0);
      ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
      ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode1, 1);
      arrayMultiTreeNode2.parent = (TreeNode<MultiTreeNode<Object>>) arrayMultiTreeNode0;
      // Undeclared exception!
      try { 
        arrayMultiTreeNode2.siblings();
        fail("Expecting exception: IllegalArgumentException");
      
      } catch(IllegalArgumentException e) {
         //
         // Illegal initial capacity: -1
         //
         verifyException("java.util.HashMap", e);
      }
  }

  @Test(timeout = 4000)
  public void test04()  throws Throwable  {
      LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
      ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
      linkedMultiTreeNode0.parent = (TreeNode<ArrayMultiTreeNode<String>>) arrayMultiTreeNode0;
      // Undeclared exception!
      try { 
        linkedMultiTreeNode0.siblings();
        fail("Expecting exception: ClassCastException");
      
      } catch(ClassCastException e) {
         //
         // no message in exception (getMessage() returned null)
         //
      }
  }

  @Test(timeout = 4000)
  public void test05()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("-nKNU*@@WXwEP3)O3");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedMultiTreeNode0);
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
      linkedList0.addLast(linkedMultiTreeNode0);
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      // Undeclared exception!
      linkedMultiTreeNode0.hasSubtrees(linkedList0);
  }

  @Test(timeout = 4000)
  public void test06()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("net.mooctest.MultiTreeNode");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedList0);
      linkedList0.add((MultiTreeNode<Object>) arrayMultiTreeNode0);
      // Undeclared exception!
      try { 
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        fail("Expecting exception: ClassCastException");
      
      } catch(ClassCastException e) {
         //
         // net.mooctest.ArrayMultiTreeNode cannot be cast to net.mooctest.LinkedMultiTreeNode
         //
         verifyException("net.mooctest.LinkedMultiTreeNode", e);
      }
  }

  @Test(timeout = 4000)
  public void test07()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("t>");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
      LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedList0);
      linkedList1.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
      boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList1);
      assertFalse(linkedMultiTreeNode0.isRoot());
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test08()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("NU@@W&SwEP)yPb3:");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedList0.addLast(linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList0);
      assertFalse(linkedMultiTreeNode0.isLeaf());
      assertTrue(boolean0);
  }

  @Test(timeout = 4000)
  public void test09()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
      boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList1);
      assertFalse(linkedMultiTreeNode0.isRoot());
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test10()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("getkmooct<st.MultiTreeNode");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList0);
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test11()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("t>");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedList0);
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
      boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList0);
      assertFalse(linkedMultiTreeNode0.isRoot());
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test12()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
      boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList1);
      assertFalse(linkedMultiTreeNode0.isLeaf());
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test13()  throws Throwable  {
      Integer integer0 = new Integer(3638);
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
      boolean boolean0 = linkedMultiTreeNode0.hasSubtrees((Collection<? extends MultiTreeNode<Object>>) null);
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test14()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) null);
      linkedList0.addLast(linkedMultiTreeNode0);
      boolean boolean0 = linkedMultiTreeNode0.addSubtrees(linkedList0);
      assertFalse(boolean0);
      assertTrue(linkedMultiTreeNode0.isRoot());
  }

  @Test(timeout = 4000)
  public void test15()  throws Throwable  {
      Integer integer0 = new Integer(3638);
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
      boolean boolean0 = linkedMultiTreeNode0.addSubtrees((Collection<? extends MultiTreeNode<Object>>) null);
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test16()  throws Throwable  {
      LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
      LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
      linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
      linkedMultiTreeNode0.addSubtrees(linkedList0);
      boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList0);
      assertFalse(linkedMultiTreeNode0.isLeaf());
      assertTrue(boolean0);
  }
}

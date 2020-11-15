/*
 * This file was automatically generated by EvoSuite
 * Sun Oct 25 06:11:41 GMT 2020
 */

package net.mooctest;

import org.junit.Test;
import static org.junit.Assert.*;
import static org.evosuite.shaded.org.mockito.Mockito.*;
import static org.evosuite.runtime.EvoAssertions.*;
import java.util.Collection;
import java.util.function.BiFunction;
import net.mooctest.Edge;
import net.mooctest.EdgeBag;
import net.mooctest.Node;
import org.evosuite.runtime.EvoRunner;
import org.evosuite.runtime.EvoRunnerParameters;
import org.evosuite.runtime.ViolatedAssumptionAnswer;
import org.junit.runner.RunWith;

@RunWith(EvoRunner.class) @EvoRunnerParameters(mockJVMNonDeterminism = true, useVFS = true, useVNET = true, resetStaticState = true, separateClassLoader = true, useJEE = true) 
public class EdgeBag_ESTest extends EdgeBag_ESTest_scaffolding {

  @Test(timeout = 4000)
  public void test00()  throws Throwable  {
      Character character0 = new Character('');
      EdgeBag edgeBag0 = new EdgeBag();
      Character character1 = new Character('D');
      Node node0 = new Node();
      Edge edge0 = new Edge("Not implemented", node0);
      edgeBag0.put(character0, edge0);
      edgeBag0.putIfAbsent(character1, (Edge) null);
      assertEquals(2, edgeBag0.size());
  }

  @Test(timeout = 4000)
  public void test01()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character(' ');
      edgeBag0.putIfAbsent(character0, (Edge) null);
      Character character1 = Character.valueOf('y');
      edgeBag0.put(character1, (Edge) null);
      edgeBag0.get('y');
      assertEquals(2, edgeBag0.size());
  }

  @Test(timeout = 4000)
  public void test02()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character('\uDC4E');
      BiFunction<Object, Object, Edge> biFunction0 = (BiFunction<Object, Object, Edge>) mock(BiFunction.class, new ViolatedAssumptionAnswer());
      // Undeclared exception!
      try { 
        edgeBag0.compute(character0, biFunction0);
        fail("Expecting exception: IllegalArgumentException");
      
      } catch(IllegalArgumentException e) {
         //
         // Illegal input character \uDC4E.
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test03()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character(' ');
      edgeBag0.putIfAbsent(character0, (Edge) null);
      Character character1 = Character.valueOf('y');
      edgeBag0.put(character1, (Edge) null);
      edgeBag0.put(character1, (Edge) null);
      assertEquals(2, edgeBag0.size());
  }

  @Test(timeout = 4000)
  public void test04()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('5');
      Edge edge0 = edgeBag0.get((Object) character0);
      assertNull(edge0);
  }

  @Test(timeout = 4000)
  public void test05()  throws Throwable  {
      Character character0 = new Character('');
      EdgeBag edgeBag0 = new EdgeBag();
      Node node0 = new Node();
      Edge edge0 = new Edge("Not implemented", node0);
      edgeBag0.put(character0, edge0);
      Edge edge1 = edgeBag0.get((Object) character0);
      assertSame(edge1, edge0);
  }

  @Test(timeout = 4000)
  public void test06()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.put((Character) null, (Edge) null);
        fail("Expecting exception: NullPointerException");
      
      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test07()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.get((Object) null);
        fail("Expecting exception: NullPointerException");
      
      } catch(NullPointerException e) {
         //
         // no message in exception (getMessage() returned null)
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test08()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Collection<Edge> collection0 = edgeBag0.values();
      // Undeclared exception!
      try { 
        edgeBag0.get((Object) collection0);
        fail("Expecting exception: ClassCastException");
      
      } catch(ClassCastException e) {
         //
         // java.util.Arrays$ArrayList cannot be cast to java.lang.Character
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test09()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('s');
      Node node0 = new Node();
      Edge edge0 = new Edge("/9M'9Y|ABQM&,8j}Q=V", node0);
      edgeBag0.put(character0, edge0);
      Edge edge1 = edgeBag0.get('s');
      assertEquals("/9M'9Y|ABQM&,8j}Q=V", edge1.getLabel());
  }

  @Test(timeout = 4000)
  public void test10()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.get('\u008C');
        fail("Expecting exception: IllegalArgumentException");
      
      } catch(IllegalArgumentException e) {
         //
         // Illegal input character \u008C.
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test11()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Edge edge0 = edgeBag0.get('|');
      assertNull(edge0);
  }

  @Test(timeout = 4000)
  public void test12()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('a');
      Node node0 = new Node();
      Edge edge0 = new Edge("Not implemented", node0);
      edgeBag0.put(character0, edge0);
      edgeBag0.put(character0, edge0);
      assertEquals(1, edgeBag0.size());
  }

  @Test(timeout = 4000)
  public void test13()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      int int0 = edgeBag0.size();
      assertEquals(0, int0);
  }

  @Test(timeout = 4000)
  public void test14()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('|');
      edgeBag0.put(character0, (Edge) null);
      int int0 = edgeBag0.size();
      assertEquals(1, int0);
  }

  @Test(timeout = 4000)
  public void test15()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('|');
      edgeBag0.put(character0, (Edge) null);
      boolean boolean0 = edgeBag0.isEmpty();
      assertFalse(boolean0);
  }

  @Test(timeout = 4000)
  public void test16()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      boolean boolean0 = edgeBag0.isEmpty();
      assertTrue(boolean0);
  }

  @Test(timeout = 4000)
  public void test17()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('|');
      edgeBag0.put(character0, (Edge) null);
      Collection<Edge> collection0 = edgeBag0.values();
      assertNotNull(collection0);
  }

  @Test(timeout = 4000)
  public void test18()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = Character.valueOf('\u0081');
      // Undeclared exception!
      try { 
        edgeBag0.get((Object) character0);
        fail("Expecting exception: IllegalArgumentException");
      
      } catch(IllegalArgumentException e) {
         //
         // Illegal input character \u0081.
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test19()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character('\u0094');
      // Undeclared exception!
      try { 
        edgeBag0.put(character0, (Edge) null);
        fail("Expecting exception: IllegalArgumentException");
      
      } catch(IllegalArgumentException e) {
         //
         // Illegal input character \u0094.
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test20()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.entrySet();
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test21()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.putAll(edgeBag0);
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test22()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.keySet();
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test23()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Collection<Edge> collection0 = edgeBag0.values();
      // Undeclared exception!
      try { 
        edgeBag0.containsValue(collection0);
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test24()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      // Undeclared exception!
      try { 
        edgeBag0.clear();
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test25()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character(')');
      // Undeclared exception!
      try { 
        edgeBag0.remove((Object) character0);
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }

  @Test(timeout = 4000)
  public void test26()  throws Throwable  {
      EdgeBag edgeBag0 = new EdgeBag();
      Character character0 = new Character('\\');
      // Undeclared exception!
      try { 
        edgeBag0.containsKey(character0);
        fail("Expecting exception: UnsupportedOperationException");
      
      } catch(UnsupportedOperationException e) {
         //
         // Not implemented
         //
         verifyException("net.mooctest.EdgeBag", e);
      }
  }
}
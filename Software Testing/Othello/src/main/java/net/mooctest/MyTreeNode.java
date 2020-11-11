package net.mooctest;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;



/*
 * We used tree structure to store possible white moves 
 * in Alpha-Beta Pruning Algorithm.
 * */

public class MyTreeNode<T>{
    private T data = null;
    private int alpha = -10000;         	// alpha = -INF at the beginning
    private int beta = 10000;				// beta = INF at the beginning 
    private int value = 0;
    
    private List<MyTreeNode> children = new ArrayList<MyTreeNode>();
    private MyTreeNode parent = null;
   
    public MyTreeNode(T data) {
        this.data = data;
    }
    
    public MyTreeNode(int alpha, int beta) {
        this.alpha = alpha;
        this.beta = beta;
    }
    
    public MyTreeNode(int value) {
        this.value = value;
    }

    public void addChild(MyTreeNode child) {
        child.setParent(this);
        this.children.add(child);
    }

    public void addChild(T data) {
        MyTreeNode<T> newChild = new MyTreeNode<T>(data);
        newChild.setParent(this);
        children.add(newChild);
    }
    
    public void addChildren(List<MyTreeNode> children) {
        for(MyTreeNode t : children) {
            t.setParent(this);
        }
        this.children.addAll(children);
    }

    public List<MyTreeNode> getChildren() {
        return children;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }
    
    public int getAlpha() {
        return alpha;
    }

    public void setAlpha(int alpha) {
        this.alpha = alpha;
    }

    public int getBeta() {
        return beta;
    }

    public void setBeta(int beta) {
        this.beta = beta;
    }
    
    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
    
    private void setParent(MyTreeNode parent) {
        this.parent = parent;
    }

    public MyTreeNode getParent() {
        return parent;
    }
}
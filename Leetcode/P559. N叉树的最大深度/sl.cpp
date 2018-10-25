/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
  public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int mx = 0;
        for (int i = 0, len = root->children.size(); i < len; ++i)
            mx = max(mx, maxDepth(root->children[i]));
        return mx + 1;
    }
};
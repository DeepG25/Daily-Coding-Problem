#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Node{
public :
	// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "NULL";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

     // Helper for deserialization
    TreeNode* deserializeHelper(istringstream &ss) {
        string str;
        ss >> str;

        if (str == "NULL") return NULL;

        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        istringstream ss(data);
        return deserializeHelper(ss);
    }
};

int main()
{
	//input is in preorder format which makes the deserialization simple due to format of (D,L,R)
	string input = "1 2 NULL NULL 3 4 NULL NULL 5 NULL NULL";

	Node node;
	string output = node.serialize(node.deserialize(input));

	if(input == output){
		cout << "Serialization and Deserialization done successfully" << endl;
	}
	else
	{
		cout << "Error reported" << endl;
	}
	return 0;
}

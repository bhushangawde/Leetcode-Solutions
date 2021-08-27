/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string delimitter = ",";
    string marker = "x";
	int index = 0;
	
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return marker + delimitter;
        }
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + delimitter + left + right;
            
    }
    
    TreeNode* deserializeUtil(vector<string> &data){
        if(data[index] == "x" || index == data.size()){
            index += 1;
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(data[index]));
        index++;
        root->left = deserializeUtil(data);
        root->right = deserializeUtil(data);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;
        // cout<<data<<endl;
        istringstream ss(data);
        vector<string> data2;
        string word;
        while(getline(ss, word, ',')){
            // cout<<word<<endl;
            data2.push_back(word);
        }
        
        root = deserializeUtil(data2);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));




// Solution 2 

/* 
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
}; */
//Link of the question
//https://www.hackerrank.com/challenges/is-binary-search-tree/problem


/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
vector<long unsigned int>v1;
void check(Node* root)
{
    if(root==NULL)
        return ;
    check(root->left);
    v1.push_back(root->data);
    check(root->right);
}
	bool checkBST(Node* root) {
		check(root);
        for(int i=0;i<v1.size()-2;i++)
        {
            if(v1[i]>=v1[i+1])
                return false;
        }
        return true;
	}




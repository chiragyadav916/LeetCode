class Solution {
private:
void sumIt(TreeNode *root,int &sum,int &result){
   if(root->right==NULL and root->left==NULL){
       sum=sum*10+root->val;
       result+=sum;
       sum/=10;
       return;
   }
   sum=sum*10+root->val;

   if(root->left) sumIt(root->left,sum,result);
   if(root->right) sumIt(root->right,sum,result);

   sum/=10;
}
public:
    int sumNumbers(TreeNode* root) {
        int sum=0,result=0;

        sumIt(root,sum,result);

        return result;
    }
};
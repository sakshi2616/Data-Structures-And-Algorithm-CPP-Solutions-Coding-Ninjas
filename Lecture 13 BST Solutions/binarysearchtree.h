#include<binarytreenode.h>
class bst{
   binarytreenode<int>* root;

   private:
   bool hasdata(int data, binarytreenode<int>* node){
     if(root==nullptr){
        return false;
    }
    if(root->data==data){
        return true;
    }
    else if(data<root->data){
        return hasdata(data, node->left);
    }
    else{
        return hasdata(data,node->right);
    }
   }

   void insert(int data, binarytreenode<int>*node){
        
   }


   public:

   bst(){
    root=nullptr;
   }

   ~bst(){
    delete root;
   }

   void deletedata(int data){
   }

   void insertdata(int data){

   }

   bool hasdata(int data){
    return hasdata(data,root);
   } 
   
};
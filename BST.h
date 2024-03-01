// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

//void insertNode( BST *, int );

/*void insertNode_R(TreeNodePtr * t,int value){
   int count;
  if((*t)==NULL){
   (*t) =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	 if(t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
		(*t)->data=value;
      count = 0;
   }
  }
  else{
     if((*t)->data>=value){//left
         insertNode_R(&(*t)->leftPtr,value);
     }
     else{
         insertNode_R(&(*t)->rightPtr,value);
     }
   }
}*/

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0,count=1;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
while(!inserted){
   if(t->data >=value){//if value <= data
     /* move/insert to the left*/
     if(!t->leftPtr){
         t->leftPtr=new_node;
         inserted = 1;
     }
     else {
      t=t->leftPtr;
     }
  	 
  }
   else{//if value > data
	   /* move/ insert to the right*/
      if(!t->rightPtr){
         t->rightPtr=new_node;
         inserted = 1;
     }
     else {
      t=t->rightPtr;
     }
	}
   
  }//end while		
  }//end else;
  b->size++;
  }
  
}//end function

void inOrderR( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrderR( treePtr->rightPtr ); //Recursion to the left
 
      printf("%3d\n",treePtr->data) ;  //print the value 
   
      inOrderR( treePtr->leftPtr ); //Recursion to the right
   } // end if                          
} // end 

void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void preOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      printf("%3d",treePtr->data) ;  //print the value 

      preOrder( treePtr->leftPtr ); //Recursion to the left
   
      preOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void postOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      postOrder( treePtr->leftPtr ); //Recursion to the left

      postOrder( treePtr->rightPtr ); //Recursion to the right

      printf("%3d",treePtr->data) ;  //print the value 
   } // end if                          
} // end 

void printTree( TreeNodePtr treePtr ,int l){
   int i;
   if(treePtr != NULL){
      l++;
      printTree( treePtr->rightPtr,l);
      for(i=1;i<l;i++)printf("   ");
      printf("%3d\n",treePtr->data);
      printTree( treePtr->leftPtr,l);
   }
}

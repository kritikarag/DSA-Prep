struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    stack<Node*>st;
    Node*root=new Node(pre[0]);
    if(preLN[0]=='N')st.push(root);
    
    int i=1;
    while(!st.empty()){
        Node* child=new Node(pre[i]);
        Node* par=st.top();
        if(par->left==NULL)par->left=child;
        
        else{
        par->right = child;
        st.pop();
    }
    if(preLN[i]=='N')st.push(child);
    i++;
    }
    return root;
}

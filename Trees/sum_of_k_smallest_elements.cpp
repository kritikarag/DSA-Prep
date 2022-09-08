// https://practice.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

//APPROACH 1 USING PRIORITY QUEUE
void traverse(Node *root, priority_queue<int, vector<int>, greater<int>> &pq)
{
    if (root == NULL)
        return;
    pq.push(root->data);
    if (root->left)
        traverse(root->left, pq);
    if (root->right)
        traverse(root->right, pq);
}

int sum(Node *root, int k)
{
    // Your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    traverse(root, pq);

    int res = 0;
    while (k--)
    {
        res += pq.top();
        pq.pop();
    }

    return res;
}

//APPROACH 2 USING INORDER TRAVERSAL

int sum(Node * root, int k){
    if(root==NULL)return 0;
    int res=0;
    res+=sum(root->left,k);
    if(k--){
        res+=root->data;
    }
    res+=sum(root->right,k);
    return res;
}
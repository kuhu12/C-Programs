#include<stdio.h>
#define MARKER -1
struct node
{
int data;
struct node* left, *right;
};
node* newnode(int key)
{
    node* temp= new node;
    temp->data=key;
    temp->left=temp->right= NUll;
    return(temp);
}
void serialize(node *root,FILE *fp)
{
    if(root== NULL)
    {
        fprintf(fp,"%d",MARKER);
        return;
    }
    fprintf(fp,"%d",root->key);
    serialize(root->left,fp);
    serialize(root->right,fp);
}
void deserialize(node *&root,FILE *fp)
{
    int val;
    if(!fscanf(fp,"%d",&val)||val==MARKER)
        return;
    root=newnode(val);
    deserialize(root->left,fp);
    deserialize(root->right,fp);
}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->key)
        inoder(root->right);
    }
}
int main()
{
    struct node *root =newnode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    FILE *fp= fopen("tree.txt",w);
    if (fp==NULL)
    {
        puts("could not open file")
        return 0;
    }
        serialize(root,fp);
        fclose(fp);
    node *root1=NULL;
    fp=fopen("tree.txt","r");
    deserialize(root1,fp);
    printf("inorder traversal")
    inorder(root1);
    return 0;

}

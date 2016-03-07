#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;

char color[1001];
int* R = new int[1000];
int* B = new int[1000];
int (*ans)[1024]= new int[1024][1024];
int* c = new int[1024*1024];
int KEY[1024];
int N,K;
int best;

class Node
{
public:
    int index;
    int key;
    int value;
    int C; //if this is Node, C is the ans
    Node *left,*right,*parent;
    Node(int index)
    {
        this->index = index;
        this->key = KEY[index];
        left = right = parent = NULL;
    }

};

class Tree
{
public:
    Node* nodes[1024];
    Node* root;
    Tree(Node* node)
    {
        root = node;
    }
    Node* getNodeByIndex(int index)
    {
        assert(index>=0);
        return nodes[index];
    }
};



Tree* insert(Tree* tree, Node* node)
{
    if(tree == NULL)
    {
        return new Tree(z);
    }

    Node* k = tree->getNodeByIndex(z->index-1);
    assert(k->right == NULL);
    k->right = node;
    node->value = node->key;

    for (; ; )
    {
        if (k->left == NULL)
        {
            //make k->right be root, mean roate, attem to left value be less.
            //int a = k->key +
            //let k still be root
            int b = k->key + k->right->value;
            k->value = b;
        }
        else if (k->right->key > k->left->key)
        {
            //rotate
            Node* l = k->left;
            Node* r = k->right;
            Tree* new_left = insert(new Tree(l),k);
            int t = new_left->root->value;

            int a = r->key + ;
            //

            int b = k->key + r->value;

        }
        else
        {
            break;
        }
    }
}
int main(int argc, char** argv) {
    int T = 0;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d",&N,&K);
        for (int i = 0; i <N; i++) {
            scanf("%d",&R[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d",&B[i]);
        }
        scanf("\n");
		scanf("%s\n",color);
		clock_t time = clock();
        for (int i=0; i<N; i++)
		{
			int j = i;
        	if (color[j] == 'R') {
                best = R[j]<(B[j] + K)?R[j]:(B[j] + K);
            }
			else
            {
                best = B[j]<(R[j]+K)?B[j]:(R[j]+K);
            }
			KEY[i] = best;
//			cout << "ans[" << i << "][" << j << "]=" << c[num_of[j]+i]<< endl;
		}
        Tree* tree_now = NULL;
        for (int n=1; n<=N; n++)
        {
            Node* z = new Node(n-1);
            tree_now = insert(tree_now,z);
        }

		cout << tree_now->root->value << endl;
		time = clock()- time;
        cout << ((float)time)/CLOCKS_PER_SEC << endl;
    }

	return 0;
}

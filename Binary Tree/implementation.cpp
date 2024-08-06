#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int main()
{
    cout << "enter the value for root node:- " << endl;
    int val;
    cin >> val;
    Node *temp = new Node(val);
    queue<Node *> q;
    q.push(temp);

    // loop
    while (!q.empty())
    {
        Node *currNode = q.front();
        cout << "enter the value of left node of node having value " << currNode->data << " :- " << endl;
        int leftval;
        cin >> leftval;
        if (leftval != -1)
        {
            currNode->left = new Node(leftval);
            q.push(currNode->left);
        }

        cout << "enter the value of right node of node having value " << currNode->data << " :- " << endl;
        int rightval;
        cin >> rightval;
        if (rightval != -1)
        {
            currNode->right = new Node(rightval);
            q.push(currNode->right);
        }

        q.pop();
    }

    return 0;
}

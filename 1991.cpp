#include <iostream>
#include <vector>

using namespace std;

typedef struct node {
    char name;
    struct node* parents;
    struct node* left;
    struct node* right;
} NODE; // 트리의 노드

void pre(NODE*);
void in(NODE*);
void post(NODE*);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<NODE> tree(n); // 트리를 구현한 배열
    char name;
    char node_name;

    for(int i = 0; i < n; ++i) {
        cin >> name;
        tree[(int)name - 'A'].name = name;

        if(i == 0) // 첫번째는 부모 노드가 없음!
            tree[0].parents = NULL;

        cin >> node_name;

        // left 연결
        if(node_name == '.') {
            tree[(int)name - 'A'].left = NULL;
        } else {
            tree[(int)name - 'A'].left = &(tree[(int) node_name - 'A']);
            tree[(int)name - 'A'].left->parents = &(tree[(int) name - 'A']);
        } 

        cin >> node_name;

        // right 연결
        if(node_name == '.') {
            tree[(int)name - 'A'].right = NULL;
        } else {
            tree[(int)name - 'A'].right = &(tree[(int) node_name - 'A']);
            tree[(int)name - 'A'].right->parents = &(tree[(int) name - 'A']);
        }
    }

    pre(&tree[0]); // 전위 순회

    cout << '\n';

    in(&tree[0]); // 중위 순회

    cout << '\n';

    post(&tree[0]); // 후위 순회

    return 0;
}

void pre(NODE* parents) {
    cout << parents->name; // 부모

    if(parents->left)
        pre(parents->left); // 왼쪽

    if(parents->right)
        pre(parents->right); // 오른쪽
}

void in(NODE* parents) {
    if(parents->left)
        in(parents->left); // 왼쪽

    cout << parents->name; // 부모

    if(parents->right)
        in(parents->right); // 오른쪽
}

void post(NODE* parents) {
    if(parents->left)
        post(parents->left); // 왼쪽

    if(parents->right)
        post(parents->right); // 오른쪽

    cout << parents->name; // 부모
}
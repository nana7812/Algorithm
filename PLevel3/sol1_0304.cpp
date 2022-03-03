#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree{
    int idx;
    int x;
    int y;
    Tree *Left;
    Tree *Right; 
};

bool compare(Tree A, Tree B){
    if(A.y >= B.y){
       if(A.y == B.y){
           if(A.x < B.x){
               return true;
           }
           return false;
       }
        return true;
    }
    return false;
}

void makeTree(Tree *Root, Tree *Child){
    if(Root-> x > Child->x ){
        if(Root->Left == NULL){
            Root->Left = Child;
            return;
        }
        makeTree(Root->Left,Child);
    }else{
        if(Root->Right == NULL){
            Root->Right = Child;
            return;
        }
        makeTree(Root->Right, Child);
    }
}

void preOrder(Tree *Root,vector<int> &ans){
    if(Root == NULL) return;
    ans.push_back(Root->idx);
    preOrder(Root->Left,ans);
    preOrder(Root->Right,ans);
}

void postOrder(Tree *Root, vector<int> &ans){
    if(Root == NULL) return;
    postOrder(Root->Left,ans);
    postOrder(Root->Right,ans);
    ans.push_back(Root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Tree> tree;
    for(int i = 0; i < nodeinfo.size(); i++){
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int idx = i+1;
        tree.push_back({idx,x,y,NULL,NULL});
    }
    sort(tree.begin(),tree.end(),compare);
    Tree *Root = &tree[0];
    for(int i = 1; i < tree.size(); i++){
        makeTree(Root, &tree[i]);
    }
    vector<int> pre; vector<int> post;
    preOrder(Root,pre);
    postOrder(Root,post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
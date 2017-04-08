#include <iostream>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(NULL == node) {
        return NULL;
    }   
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode* > copy;
    queue<UndirectedGraphNode*> q;
    UndirectedGraphNode* nn = new UndirectedGraphNode(node->label);
    copy[node] = nn;
    q.push(node);
    while(!q.empty()) {
        UndirectedGraphNode* front = q.front();
        q.pop();
        for(int i=0; i<front->neighbors.size(); ++i) {
            UndirectedGraphNode* temp = front->neighbors[i];
            if (copy.end() == copy.find(temp)) {
                nn = new UndirectedGraphNode(temp->label);
                copy[temp] = nn;
                q.push(temp);
            }
            copy[front]->neighbors.push_back(copy[temp]);
        }                     

    }   

    return copy[node];
}

int main(int argc, const char *argv[])
{

    return 0;
}

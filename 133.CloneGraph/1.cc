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

unordered_map<UndirectedGraphNode*, UndirectedGraphNode* > hash;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    // 先判断为空的情况
    if(NULL == node) {
        return NULL;
    }   
    // 再判断当前节点是不是被访问过
    auto it = hash.find(node);
    if (hash.end() != it) {
        return it->second;
    }
    hash[node] = new UndirectedGraphNode(node->label);
    for (auto neighbor : node->neighbors) {
        (hash[node]->neighbors).push_back(clone(neighbor));
    }
    return hash[node];


}

int main(int argc, const char *argv[])
{

    return 0;
}

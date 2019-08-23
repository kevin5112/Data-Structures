#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


struct node {
	node(int v) : val(v), visited(false) {}
	int val;
	vector<node*> children;
	bool visited;
};

struct graph {
	vector<node*> nodes;
};

void printBFS(graph g) {
	queue<node*> q;
	q.push(g.nodes[0]);

	while(!q.empty()) {
		auto curr = q.front();
		q.pop();

		if(!curr->visited)
		{
			cout << curr->val << endl;
			for(auto n = curr->children.begin(); n != curr->children.end(); ++n)
			{
				q.push(*n);
			}
			curr->visited = true;
		}
	}

}

void printDFS(graph g){
	stack<node*> s;
	s.push(g.nodes[0]);

	while(!s.empty()) {
		auto curr = s.top();
		//cout << "top: " << s.top()->val << endl;
		s.pop();

		if(!curr->visited)
		{
			cout << curr->val << endl;
			for(auto n = curr->children.begin(); n != curr->children.end(); ++n) {
				s.push(*n);
				//cout << (*n)->val << endl;
			}
			curr->visited = true;
		}
		//cout << "size: " << s.size() << endl;
	}
}


int main() {
	node* node0 = new node(0);
	node* node1 = new node(1);
	node* node2 = new node(2);
	node* node3 = new node(3);
	node* node4 = new node(4);
	node* node5 = new node(5);

	node0->children.push_back(node1);
	node0->children.push_back(node4);
	node0->children.push_back(node5);

	node1->children.push_back(node3);
	node1->children.push_back(node4);

	node2->children.push_back(node1);

	node3->children.push_back(node2);
	node3->children.push_back(node4);

	graph g;

	g.nodes.push_back(node0);
	g.nodes.push_back(node1);
	g.nodes.push_back(node2);
	g.nodes.push_back(node3);
	g.nodes.push_back(node4);
	g.nodes.push_back(node5);

	// printDFS(g);
	printBFS(g);

	return 0;
}
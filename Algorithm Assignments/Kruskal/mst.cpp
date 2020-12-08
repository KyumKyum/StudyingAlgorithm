//2019014266 Lim Kyu Min 11802

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

class Vertex{
	public:
	int from;
	int dest;
	int weight;

	Vertex(int from, int dest, int weight){
		this->from = from;
		this->dest = dest;
		this->weight = weight;
	}

	//bool operator <(Node &node){
	//	return this->weight < node.weight;
	//}
};

class Node{
	public:
	int parent;
	int rank;
};



int getParent(Node[], int);
bool findSet(Node[],int,int);
void unionSet(Node[],int,int);
void merge(Node[],int,int);
bool compare(Vertex,Vertex);

int main(void){
	int N,M = 0;
	int from,dest,weight = 0;
	int edges = 0;
	Node* parent = NULL;
	vector<Vertex> vec;
	vector<Vertex> selected;

	scanf("%d %d",&N,&M);

	parent = (Node*)malloc(sizeof(Node)*(N+1));

	for(int i = 0; i <= N; i++){
		parent[i].parent = i;
		parent[i].rank = 0;
	}

	for(int i = 0; i < M; i++){
		scanf("%d %d %d",&from,&dest,&weight);
		vec.push_back(Vertex(from,dest,weight));
	}

	sort(vec.begin(),vec.end(),compare);

	for(int i = 0; i < vec.size(); i++){
		if(!(findSet(parent,vec[i].from,vec[i].dest))){
			unionSet(parent,vec[i].from,vec[i].dest);
			selected.push_back(vec[i]);
			++edges;
		}
	}

	cout<<edges<<endl;

	for(int i = 0; i < selected.size(); i++){
		Vertex select = selected[i];
		cout<<select.from<<" "<<select.dest<<" "<<select.weight<<endl;
	}

	return 0;

}

int getParent(Node parent[],int curNode){
	if(parent[curNode].parent == curNode){
		return curNode;
	}else{
		return getParent(parent,parent[curNode].parent);
	}
}

bool findSet(Node parent[],int firstNode, int secondNode){
	int x = getParent(parent,firstNode);
	int y = getParent(parent,secondNode);

	if(x == y){
		return true;
	}else{
		return false;
	}
}

void unionSet(Node parent[],int firstNode, int secondNode){
	int x = getParent(parent,firstNode);
	int y = getParent(parent,secondNode);

	merge(parent,x,y);
}

void merge(Node parent[], int first, int second){
	if(parent[first].rank > parent[second].rank){
		parent[second].parent = first;
	}else{
		parent[first].parent = second;
		if(parent[first].rank == parent[second].rank){
			parent[second].rank += 1;
		}
	}
}

bool compare(Vertex vertFirst, Vertex vertSecond){
	if(vertFirst.weight != vertSecond.weight){
		return vertFirst.weight < vertSecond.weight;
	}else if(vertFirst.from != vertSecond.from){
		return vertFirst.from < vertSecond.from;
	}
	return vertFirst.dest < vertSecond.dest;
}

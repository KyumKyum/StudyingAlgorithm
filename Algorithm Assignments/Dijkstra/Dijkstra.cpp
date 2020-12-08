//2019014266 Lim Kyu Min 11802

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

class Edge{
	public:
	int dest;
	int cost;

	Edge(int dest, int cost){
		this->dest = dest;
		this->cost = cost;
	}
};

class Vertex{
	public:
	vector<Edge> vec;
	int weight;
	int idx;
	Vertex(){
		this->weight = INT_MAX;
	}
};

struct compare{
	bool operator()(Vertex &v1, Vertex &v2){
		return v1.weight < v2.weight;
	}
};

bool isMin(int,int);

int main(void){
	int N,M = 0;
	int f,d,c = 0;
	int maxWeight = -1;
	Edge*edges = NULL;
	Vertex* node = NULL;
	priority_queue<Vertex,vector<Vertex>,compare> pq;

	scanf("%d %d",&N,&M);

	node = new Vertex[N + 1];
	for(int i = 0; i <= N; i++){
		node[i].idx = i;
	}
	
	for(int i = 0; i < M; i++){
		scanf("%d %d %d",&f,&d,&c);
		node[f].vec.push_back(Edge(d,c));
	}
	//Start from vertex 1
	node[1].weight = 0;
	pq.push(node[1]);

	while(!(pq.empty())){
		 int cur = pq.top().idx;
		 pq.pop();
		 Vertex &curVertex = node[cur];
		for(int i = 0; i < curVertex.vec.size(); i++){
			int curWeight = curVertex.weight;
			int dest = curVertex.vec[i].dest;
			int cost = curVertex.vec[i].cost;
			if(!(isMin(node[dest].weight,curWeight + cost))){
				node[dest].weight = curWeight + cost;
				pq.push(node[dest]);
			}
		}
	}

//	for(int i = 1; i <= N; i++){
//		printf("%d: %d",i,node[i].weight);
//	}
	
	for(int i = 1; i <= N; i++){
		if(maxWeight < node[i].weight){
			maxWeight = node[i].weight;
		}
	}

	printf("%d\n",maxWeight);

	return 0;

}

bool isMin(int cur, int mod){
	if(cur < mod){
		return true;
	}else{
		return false;
	}
}

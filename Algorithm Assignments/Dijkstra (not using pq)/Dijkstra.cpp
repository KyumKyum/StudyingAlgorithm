//2019013266 Lim Kyu Min

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
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
	bool selected;
	int weight;
	vector<Edge> edge;

	Vertex(){
		this->weight = INT_MAX;
		this->selected = false;
	}
};

int getMinWeight(vector<Vertex>&);

int N,M = 0;
int cnt = 0;

int main(void){
	int f,d,c = 0;
	int maxWeight = -1;
	scanf("%d %d",&N,&M);

	vector<Vertex> vec(N+1);
	//vector<Vertex> sorted(N);

	//printf("sortedSize: %d\n",sorted.size());

	for(int i = 0; i < M; i++){
		scanf("%d %d %d",&f,&d,&c);
		vec[f].edge.push_back(Edge(d,c));
	}

	vec[1].weight = 0;

	while(cnt < N){
		int min = getMinWeight(vec);
		Vertex &curVer = vec[min];
		//curVer.selected = true;
		int edgeNum = curVer.edge.size();
		for(int i = 0; i < edgeNum; i++){
			int target = curVer.edge[i].dest;
			int cost = curVer.edge[i].cost;
			
			if(vec[target].weight > curVer.weight + cost){
				vec[target].weight = curVer.weight + cost;
			}
		}
		curVer.selected = true;
		cnt++;
	}

	for(int i = 1; i <= N; i++){
		if(maxWeight < vec[i].weight){
			maxWeight = vec[i].weight;
		}
	}

	printf("%d\n",maxWeight);

	return 0;
	
}

int getMinWeight(vector<Vertex> &vec){
	int minVal = INT_MAX;
	int returnIdx = -1;
//	printf("Get Min\n");
	for(int i = 1; i <=N; i++){
	//	printf("Node %d selected\n",i);
		if(vec[i].selected == false && minVal > vec[i].weight){
			minVal = vec[i].weight;
			returnIdx = i;
			//printf("MinVal: %d\n",minVal);
		}
	}

	return returnIdx;
}

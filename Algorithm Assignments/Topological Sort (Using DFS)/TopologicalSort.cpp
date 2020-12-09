//2019014266 Lim Kyu Min 11802

#include <stdio.h>
#include <iostream>
#include <vector>
//#include <stack>
#include <algorithm>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class Vertex{
	public:
	int id;
	int color;
	int start;
	int finish;
	vector<int> points;

	Vertex(){
		color = WHITE;
		start = 0;
		finish = 0;
	}
};

int N,M = 0;
int isCycle = false;
int searchTime = 0;
//stack<Vertex> s;

void DFS(Vertex[]);
void DFS_Search(Vertex[],int);
void topoSort(Vertex[]);
bool compare(Vertex,Vertex);

int main(void){
	int f,d;

	scanf("%d %d",&N,&M);
	
	Vertex* vertex = new Vertex[N + 1];

	for(int i =1; i <= N; i++){
		vertex[i].id = i;
	}

	for(int i = 0; i < M; i++){
		scanf("%d %d",&f,&d);
		vertex[f].points.push_back(d);
		//vertex[d].engress += 1;
	}

	for(int i = 1; i <= N; i++){
		sort(vertex[i].points.begin(),vertex[i].points.end());
	}

	DFS(vertex);

	if(isCycle){
		printf("0\n");
	}else{
		printf("1\n");
		topoSort(vertex);
		printf("\n");
	}

}

void DFS(Vertex vertex[]){
	for(int i = 1; i <= N; i++){
		if(vertex[i].color == WHITE){
			DFS_Search(vertex,i);
			if(isCycle){
				return;
			}
		}
	}
}

void DFS_Search(Vertex vertex[], int current){
	Vertex &curVert = vertex[current];
	curVert.start = ++searchTime;
	curVert.color = GRAY;

	for(int i = 0; i < curVert.points.size(); i++){
		int adjacent = curVert.points[i];
		Vertex &adjVert = vertex[adjacent];

		if(adjVert.color == GRAY){//IS A CYCLE
			isCycle = true;
			return;
		}else if(adjVert.color == WHITE){
			DFS_Search(vertex,adjacent);
		}

		if(isCycle){
			return;
		}
	}

	curVert.color = BLACK;
	curVert.finish = ++searchTime;
	//s.push(curVert);

}

void topoSort(Vertex vertex[]){
	//while(!(s.empty())){
		//Vertex &curVert = s.top();
		//printf("%d ",curVert.id);
		//s.pop();
	//}
	sort(vertex + 1,vertex+(N+1),compare);

	for(int i = N; i >= 1; i--){
		printf("%d ",vertex[i].id);
	}
}

bool compare(Vertex v1, Vertex v2){
	return v1.finish < v2.finish;
}

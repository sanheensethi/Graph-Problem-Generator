#include <iostream>
#include <vector>
#include<ctime>
#include<string>
using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
	Edge(int source,int dest,int weight){
		this->source = source;
		this->dest = dest;
		this->weight = weight;
	}
};

void printAdjacancy(vector<Edge*> v,int n){
	int** matrix = new int*[n];
	for(int i=0;i<n;i++){
		matrix[i] = new int[n];
		for(int j=0;j<n;j++) matrix[i][j] = 0;
	}
	for(int i=0;i<v.size();i++){
		matrix[v[i]->source][v[i]->dest] = v[i]->weight;
		matrix[v[i]->dest][v[i]->source] = v[i]->weight;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<Edge*> input;
	cout<<"Enter No. of Vertex Required : ";
	int vertexRange;cin>>vertexRange;
	int minVertex;
	cout<<"Enter Minimum No. of Vertex Required : ";
	cin>>minVertex;
	srand((unsigned)time(nullptr));
	int randomNumber = rand();
	int vertex = randomNumber%vertexRange + minVertex; // 5-11
	while(vertex > vertexRange){
		vertex -= vertexRange;
		vertex += minVertex;
	}
	int edgesRange = (vertex*(vertex-1))/2;
	int edges = rand()%edgesRange + 4;
	int weightRange;cout<<"Enter Minimim and Maximum Number of Weight : ";
	int min;
	cin>>min>>weightRange;
	cout<<endl;
	cout<<"Vertex : "<<vertex<<endl;
	cout<<"Edges : "<<edges<<endl;
	for(int i=0;i<edges;i++){
		int randomSource = rand()%vertex;
		int randomDest = rand()%vertex;
		int randomWeight = rand()%weightRange + min;
		while(randomWeight > weightRange){
			randomWeight -= weightRange;
			randomWeight += min;
		}
		while(randomSource == randomDest){
			randomDest = rand()%vertex;
		}
		input.push_back(new Edge(randomSource,randomDest,randomWeight));
		cout<<randomSource<<" "<<randomDest<<" "<<randomWeight<<endl;
		}
	cout<<endl;
	cout<<"Adjacancy Matrix : ";
	cout<<endl;
	printAdjacancy(input,vertex);
}
#include<bits/stdc++.h>
using namespace std;

class Graph{
	list<int> *l;
	int V;
public:
	Graph(int v){
		V = v;
		//Array of Linked List
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool bidir=true){
		l[i].push_back(j);
		if(bidir){
			l[j].push_back(i);
		}
	}
	int traverseHelper(int s,bool *visited){
		visited[s] = true;
		int size = 1;

		//visit the neighbours of s and thier neighbours recursilvely
		for(int nbr:l[s]){
			if(!visited[nbr]){
				size += traverseHelper(nbr,visited);
			}
		}
		return size;
	}
	//DFS - Depth First Search O(V+E) Linear
	int countAstronauts(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){

				
				 int csize = traverseHelper(i,visited);
				 ans -= (csize)*(csize-1)/2;
				 
			}
		}
		return ans;
	}

};

int count_pairs(int n, vector<pair<int,int> > astronauts){
    //complete this method
    Graph g(n);
    
    for(auto edge : astronauts){
        g.addEdge(edge.first,edge.second);
    }
    
    return g.countAstronauts();
}

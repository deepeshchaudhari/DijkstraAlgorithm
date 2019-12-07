#include<iostream>
using namespace std;

int findMinvertex(int* distance,bool* visited,int n){
// for finding next minimum distance vertex
      int minvertex=-1;
      for(int i=0;i<n;i++){
        if(!visited[i] &&(minvertex == -1 || distance[i]<distance[minvertex]))
        minvertex=i;
      }
      return minvertex;
}
void dijkstra(int** edges, int n){
    cout<<"Showing Adjancy matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
    //-----------Dijkstra Algorithm Initialization ---------------------------
    int* distance = new int[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        distance[i]= INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;
    //-----------------Main Logic----------------------------------
    for(int i=0;i<n-1;i++){
        int minvertex = findMinvertex(distance,visited,n);

        visited[minvertex]=true;

        for(int j=0;j<n;j++){
            if(edges[minvertex][j]!=0 && !visited[j]){
                int dist = distance[minvertex]+ edges[minvertex][j];
                if(dist< distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    //------------------- Printing Shortest path---------------------------
    for(int i=0;i<n;i++){
        cout<<i<< " "<< distance[i]<<endl;
    }
    //------------------- deleting used array -----------------------------
    delete [] distance;
    delete [] visited;
    //-------------------- end --------------------------------------------
}
int main(){
    int n ,e;
    //------------------- Making Adjacency matrix--------------------------
    cin >> n >> e ;
    int **edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    //---------------Taking Adjacency Graph Input--------------------------
    for(int i=0;i<e;i++){
        int f,s, weight;
        cin>>f >> s >> weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    cout<<endl;
    //---------------Calling Dijkstra ------------------------------------
    dijkstra(edges,n);
}

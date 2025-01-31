#include<bits/stdc++.h>
 
using namespace std;
 
int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool vis[100011];
 
void greedyColoring()
{
    color[0]  = 0;
    for (i=1;i<n;i++)
        color[i] = -1;
 
    bool unused[n];
 
    for (i=0;i<n;i++)
        unused[i]=0;
 
 
    for (i = 1; i < n; i++)
    {
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = true;
        int cr;
        for (cr=0;cr<n;cr++)
            if (unused[cr] == false)
                break;
 
        color[i] = cr; 
 
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = false;
    }
}
 
int main()
{
    int x,y;
    cout<<"Enter number of vertices and edges respectively:";
    cin>>n>>e;
    cout<<"\n";
    graph.resize(n);
    color.resize(n);
    memset(vis,0,sizeof(vis));
    for(i=0;i<e;i++)
    {
        cout<<"\nEnter edge vertices of edge "<<i+1<<" :";
        cin>>x>>y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    greedyColoring();
    for(i=0;i<n;i++)
    {
        cout<<"Vertex "<<i+1<<" is coloured "<<color[i]+1<<"\n";
    }
}

/**
Output:-
Enter number of vertices and edges respectively:4 5
 
 
Enter edge vertices of edge 1 :1 2
 
Enter edge vertices of edge 2 :2 3
 
Enter edge vertices of edge 3 :3 4
 
Enter edge vertices of edge 4 :4 1
 
Enter edge vertices of edge 5 :2 4
Vertex 1 is coloured 0
Vertex 2 is coloured 1
Vertex 3 is coloured 0
Vertex 4 is coloured 2
*/

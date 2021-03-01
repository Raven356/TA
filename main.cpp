#include <iostream>
#include <vector>
#include <cstring>

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
    int x,y, m[80][80]{};
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
        m[x][y] = 1;
        m[y][x] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)    //���� �������
        cout << m[i][j] << " ";
    cout << endl;
    }
    cout << endl;
    greedyColoring();
    for(i=0;i<n;i++)
    {
        cout<<"Vertex "<<i+1<<" is coloured "<<color[i]+1<<"\n";
    }
}

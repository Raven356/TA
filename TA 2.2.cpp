#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool vis[100011];
int check_Argument();

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

int  m[20000][20000]{};
int main()
{
    do
    {
    system("cls");
    for(int i = 0; i < 20000; i++)
        for(int j = 0; j < 20000; j++)
        {
            m[i][j] = 0;
        }
    int x,y;
    cout<<"Enter number of vertices and edges respectively:";
    cin>>n>>e;
    cout<<"\n";
    cout << "1 - rand\t2 - mainualy\n";
    int sw{};
    again:
    sw = check_Argument();
    if(sw != 1 && sw != 2)
        goto again;
    int itter{};
    graph.resize(n);
    color.resize(n);
    if (sw == 1)
        srand(time(0));
    memset(vis,0,sizeof(vis));
    for(i=0;i<e;i++, itter++)
    {
        if(sw == 2)
        {
        cout<<"\nEnter edge vertices of edge "<<i+1<<" :";
        cin>>x>>y;
        }
        if(sw == 1)
            {
                if(itter > 0)
                    srand(itter + 1);
                    x = rand() % (n-1) + 1;
                    y = rand() % (n-1) + 2;
                    if(x == y && (y < n-1))
                        y++;
                    if(x == y && (y > n-1 && y > 2))
                        y--;
            }
        x--; y--;
        if(x != y)
        {
        graph[x].push_back(y);
        graph[y].push_back(x);
        m[x][y] = 1;
        m[y][x] = 1;
        }
        else
            i--;
    }
    if(n < 100)
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)    //вивід матриці
        cout << m[i][j] << " ";
    cout << endl;
    }
    cout << endl;
    double start = clock();
    greedyColoring();
    double stop = clock();
    for(i=0;i<n;i++)
    {
        cout<<"Vertex "<<i+1<<" is coloured "<<color[i]+1<<"\n";
    }
    cout << "Time = " << scientific << (stop-start) / 1e5 << endl;
    }
    while(getch() != 27);
}

int check_Argument()
{
    int x;
    do
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "You entered wrong symbol\n";
            continue;
        }
        char c[256];
        fgets(c, 256, stdin);
        if(strlen(c) > 1)
        {
            cout << "There were some wrong symbols , try again please\n";
            continue;
        }
        return x;
    }while(true);
}

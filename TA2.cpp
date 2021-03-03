#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

struct graf{
int stepeni;
int color;
int number;
};

using namespace std;
void ShowGraf(graf arr[22],int n);
int CheckColor(graf arr[22],int n);
void InitGraf(graf arr[22],int n);
int m[20000][20000] = {};
int main()
{
    do
    {
    system("cls");
    int color1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    struct graf arr[20000];


            for(int i = 0; i < 20000; i++)
                for(int j = 0; j < 20000; j++)
            {
                m[i][j] = 0;
            }
            cout << "Enter amount of tops of graf\n";
            int n{};
            cin >> n;
            cout << "Enter amount of connections\n";
            int con{};
            cin >> con;
            cout << "1 - rand\t2 - mainualy\n";
            int sw{};
            cin >> sw;
            if(sw == 2)
            cout << "Enter connections\n";
            int x1{}, y1{};
            if (sw == 1)
                srand(time(0));
            int itter{};
            for(int i = 0; i < con; i++, itter++)
            {
                if(sw == 2)
                    cin >> x1 >> y1;
                if(sw == 1)
                    {
                        if(itter > 0)
                            srand(itter + 1);
                        x1 = rand() % (n-1) + 1;
                        y1 = rand() % (n-1) + 2;
                        if(x1 == y1 && (y1 < n-1))
                           y1++;
                        if(x1 == y1 && (y1 > n-1 && y1 > 2))
                            y1--;
                    }
                m[x1 - 1][y1 - 1] = 1;
                m[y1 - 1][x1 - 1] = 1;
                if(x1 == y1)
                {
                    m[x1 - 1][y1 - 1] = 0;
                    m[y1 - 1][x1 - 1] = 0;
                    i--;
                }
            }
    if(n < 100)
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)    //вивід матриці
        cout << m[i][j] << " ";
    cout << endl;
    }
    cout << endl;
    int versh=0;

    auto start = clock();
    InitGraf(arr,n);//ініціалізація кольору за значенням 66

//находимо степені вершин
    for(int i=0; i < n; i++,versh++)
        {
            arr[versh].stepeni=0;
            arr[versh].number=i;
            for(int j=0; j < n; j++)
                if( m[i][j] == 1 )
                    arr[versh].stepeni++;
        }

//сортування по степеням від найбільшого до найменшого
    struct graf temp;

        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
                if(arr[i].stepeni > arr[j].stepeni)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

   //алгоритм присвоєння кольору
    int x=0,t,i,j,flag=0,metk=0,s;

    for(x=0; CheckColor(arr,n)!=0 ; x++)  //цикл присвоєння кольору доки все не окрашено
    {
        if(arr[x].color == 66) arr[x].color = color1[x];      //присвоєння першого кольору

        for(i=0; i < n; i++) //цикл для розфарбування усіх несміжних вершин
        {
            t=arr[i].number; //номер строки матриці суміжності
            flag=0;
            for(j=0; j < n; j++)    //ідемо у строку матриці по номеру
            {
                if((m[t][j] == 1 && t!=j))
                {
                    for(s=0; s < n; s++)
                    if(j == arr[s].number && arr[s].color != color1[x] )
                    {
                        ++flag;
                    }
                }

            if( arr[j].number == t ) metk=j;

            if(flag==arr[metk].stepeni && arr[metk].color == 66 )
                arr[metk].color = color1[x];
            }
       }
  }
  auto stop = clock();
    ShowGraf(arr,n);
      cout << "Time = " << (stop-start) / 1e5 << endl;
    }
    while(getch() != 27);
    return 0;
}


//inicializiruem vse cveta v strukture v 66
void InitGraf(graf arr[22],int n)
{
         for(int s=0;s < n; s++)
         {
           arr[s].color=66;
         }
}


//vivodit rezulitat
void ShowGraf(graf arr[80],int n)
{
         for(int s=0;s < n; s++)
         {
           cout<<arr[s].number + 1 <<"-"<<arr[s].stepeni<<"-"<<arr[s].color<<endl;
         }
}

//vozvrashaiet 0 esli vse cveta uje prisvoeni
int CheckColor(graf arr[80],int n)
{
  int flag2=0;
  for(int xx=0; xx < n; xx++) //cikl provereaite vse li cveta prisvoeni
  {
   if(arr[xx].color <= 16)
   ++flag2;
      }
   if(flag2==n) return 0;
   else return 1;
}

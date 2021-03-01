#include <iostream>
#include <conio.h>

struct graf{
int stepeni;
int color;
int number;
};

using namespace std;
void ShowGraf(graf arr[22],int n);
int CheckColor(graf arr[22],int n);
void InitGraf(graf arr[22],int n);

int main()
{
    do
    {
    int color1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    struct graf arr[80];


    int m[80][80] = {};
            cout << "Enter amount of tops of graf\n";
            int n{};
            cin >> n;
            cout << "Enter amount of connections\n";
            int con{};
            cin >> con;
            cout << "Enter connections\n";
            int x1{}, y1{};
            for(int i = 0; i < con; i++)
            {
                cin >> x1 >> y1;
                m[x1 - 1][y1 - 1] = 1;
                m[y1 - 1][x1 - 1] = 1;
            }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)    //���� �������
        cout << m[i][j] << " ";
    cout << endl;
    }
    cout << endl;
    int versh=0;

    InitGraf(arr,n);//����������� ������� �� ��������� 66

//�������� ������ ������
    for(int i=0; i < n; i++,versh++)
        {
            arr[versh].stepeni=0;
            arr[versh].number=i;
            for(int j=0; j < n; j++)
                if( m[i][j] == 1 )
                    arr[versh].stepeni++;
        }

//���������� �� �������� �� ���������� �� ����������
    struct graf temp;

        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
                if(arr[i].stepeni > arr[j].stepeni)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

   //�������� ��������� �������
    int x=0,t,i,j,flag=0,metk=0,s;

    for(x=0; CheckColor(arr,n)!=0 ; x++)  //���� ��������� ������� ���� ��� �� ��������
    {
        if(arr[x].color == 66) arr[x].color = color1[x];      //��������� ������� �������

        for(i=0; i < n; i++) //���� ��� ������������� ��� �������� ������
        {
            t=arr[i].number; //����� ������ ������� ��������
            flag=0;
            for(j=0; j < n; j++)    //����� � ������ ������� �� ������
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
    ShowGraf(arr,n);
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

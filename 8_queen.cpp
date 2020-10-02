#include<bits/stdc++.h>
using namespace std;

struct queen{
int array[8];
struct queen *next;
};
struct queen *fd = NULL;
struct queen *bk = NULL;
struct queen* temp;
void push(int value,int Ar[8]) {
int check =0;
   if (bk == NULL) {
      bk = (struct queen *)malloc(sizeof(struct queen));
      bk->next = NULL;
      for(int i=0;i<8;i++)
      {
		  if(Ar[i]==0 && check==0)
		  {
			  bk->array[i]=value;
			  check++;
		  }
		  else
		  {
			  bk->array[i]=Ar[i];
		  }
      }
      fd = bk;
   } else {
      temp=(struct queen *)malloc(sizeof(struct queen));
      bk->next = temp;
       for(int i=0;i<8;i++)
      {
      if(Ar[i]==0 && check==0)
      {
      temp->array[i]=value;
      check++;
 }
else
{
temp->array[i]=Ar[i];
}
 }
      temp->next = NULL;
      bk = temp;
   }
}
int *pop() {
   temp = fd;
   if (temp->next != NULL) {
      fd=fd->next;
      return temp->array;
   } else {
     temp = fd;
      fd = NULL;
      bk = NULL;
      return temp->array;

   }

}
void State(int Boards[8][8],int ls[8])
{
	for(int i=0;i<8;i++)
	{
	Boards[i][ls[i]-1]=1;
	}
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << " " << Boards[i][j];
        cout << "\n";
    }
    exit(0);

}

bool clear(int Boards[8][8], int cols, int d[8])
{
int flag = 0;

    int i, j,rows,b[8][8]={0};

    for(int i=0;i<8;i++)
    {
    if(d[i]==0 && flag==0)
    {
    rows=i;
    break;
}
if(d[i]!=0)
{
b[i][d[i]-1]=1;
}
}
    for (i = 0; i < rows; i++)
        if (b[i][cols])
            return false;

    for (i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;

    for (i = rows, j = cols; i >= 0 && j < 8; i--, j++)
        if (b[i][j])
            return false;

    if(rows==7)
    {
    d[rows]=cols+1;
    State(Boards,d);
}

    return true;
}

void reccurcive(int Boards[8][8],int flag)
{
int array[8]= {0};
    if(!flag)
    {
		int *Ptr;
		Ptr = pop();
		for(int i=0;i<8;i++)
		{
		array[i]=*Ptr;
		Ptr++;
		}

		for(int i=0;i<8;i++)
		{
			if(clear(Boards,i,array))
				{
					push(i+1,array);
				}
		}
	}

		if(flag)
		{
			for (int i = 0; i < 8; i++)
			{
				  push(i+1,array);
			}
			flag=0;
		}
		reccurcive(Boards,flag);
}

int main()
{

    int Boards[8][8],i,j;
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
       Boards[i][j]=0;

    reccurcive(Boards, 1);

    return 0;
}

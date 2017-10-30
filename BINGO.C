#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void cross(int *c[5][5],int *d[5][5],int a)
{
	int i,j;
	for(i=0;i<5;i++)
	{

		for(j=0;j<5;j++)
		{
			if(*(&c[i][j])==a)
				*(&c[i][j])=0;
			if(*(&d[i][j])==a)
				*(&d[i][j])=0;
		}
	}
}
int bingo(int a[5][5])
{
	int i,j,h=0,l=0,k;
	for(i=0;i<5;i++)
	{
		h=0;
		for(j=0;j<5;j++)
		{
			if(a[i][j]==0)
			{
				h=1;
			}
			else
			{
				h=0;
				goto q;
			}
		}
		q:
		if(h==1)
		{
			l++;
		}
	}
	for(i=0;i<5;i++)
	{
		h=0;
		for(j=0;j<5;j++)
		{
			if(a[j][i]==0)
			{
				h=1;
			}
			else
			{
				h=0;
				goto a;
			}
		}
		a:
		if(h==1)
		{
			l++;
		}
	}
	h=0;
	for(k=0;k<5;k++)
	{
		if(a[k][k]==0)
		{
			h=1;
		}
		else
		{
			h=0;
			goto b;
		}
	}
	b:
	if(h==1)
	{
		l++;
	}
	h=0;
	for(k=0;k<5;k++)
	{
		if(a[k][5-k]==0)
		{
			h=1;
		}
		else
		{
			h=0;
			goto c;
		}
	}
	c:
	if(h==1)
	{
		l++;
	}
	return l;
}
void show(int a[5][5],int b[5][5])
{
	int i,j;
	printf("PLAYER:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("\n\nCOMPUTER:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
}
void show1(int a[5][5])
{
	int i,j;
	printf("PLAYER:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
void show2()
{
	printf("****************************************************\n");
	printf("                   BINGO                             \n");
	printf("****************************************************\n");
}




void main()
{
	int a[5][5],b[25],c[5][5],i,j,n,t=0,f=0,l,m,k=0,s=0,p,w[25],x=0,q,z;
	clrscr();
	show2();
	printf("PLAYER:\nEnter your numbers:");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{

			for(l=0;l<5;l++)
			{
				for(m=0;m<5;m++)
				{
					if(a[i][j]==a[l][m])
					{
						if(i!=l || j!=m)
						{
							f=1;
							goto r;
					       }
					}
					if(a[i][j]>25 || a[i][j]<1)
					{
						f=1;
						goto r;
					}
				}
			}
		}
	}
	while(t!=25)
	{
		f=0;
		n=random(25)+1;
		for(i=0;i<t;i++)
		{
			if(b[i]==n)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			b[t]=n;
			t++;
		}

	}
	clrscr();
	show2();
	r:
	if(f==1)
		printf("\n*********Again enter numbers:************");
	else
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		f=0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				c[i][j]=b[f];
				f++;
			}
		}
		while(s!=5 || z==5)
		{
			show2();
			printf("PLAYER:\nEnter number:");
			scanf("%d",&p);
			cross(&a,&c,p);
			s=bingo(a);
			z=bingo(c);
			if(s==5)
			{
				show(a,c);
				printf("*************Player wins************");
				goto s;
			}
			else if(z==5)
			{
				show(a,c);
				printf("*************Computer wins**********");
				goto s;
			}
			else
			{
				clrscr();
				show2();
				show1(a);
			}
			t=0;
			l=0;
			while(t!=1)
			{
				l=0;
				w[x]=random(25)+1;
				for(i=0;i<x;i++)
				{
					if(w[x]==w[i])
					{
						l=1;
						break;
					}
				}
				if(l==1)
					t=0;
				else
					t=1;
			}
			q=w[x];
			cross(&a,&c,q);
			s=bingo(a);
			z=bingo(c);
			printf("Computer's picking=%d\n",q);
			if(z==5)
			{
				show(a,c);
				printf("*****************Computer wins***********");
				goto s;
			}
			else if(s==5)
			{
				show(a,c);
				printf("****************Player wins***************");
				goto s;
			}
			else
			{
				show1(a);
			}
			x++;
		}

	}
	s:
	getch();
}



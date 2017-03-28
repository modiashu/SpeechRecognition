#include<stdio.h>
#include<conio.h>

struct dtwnode
{
	int cellno,minno,loc[2];
};
struct dtwnode **dn;

void main()
{
	int i,j,row,col;
	clrscr();
	printf("\nEnter the number of rows :: ");
	scanf("%d",&row);
	printf("\nEnter the number of columns :: ");
	scanf("%d",&col);

	dn = (struct dtwnode **)calloc(row,sizeof(struct dtwnode*));
	for(i=0;i<row;i++)
		dn[i]=(struct dtwnode *)calloc(col,sizeof(struct dtwnode));

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Enter dn[%d][%d]: ",i,j);
			scanf("%d",&dn[i][j].cellno);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\t%3d",dn[i][j].cellno);
		}
		printf("\n");
	}

	calcmatrix(row,col);
	findpath(row,col);

	getch();

}

calcmatrix(int row, int col)
{
	int sum=0,i,j;
	for(i=row-1;i>=0;i--)
	{
		dn[i][0].minno=dn[i][0].cellno;
		dn[i][0].minno+=sum;
		dn[i][0].loc[0]=i+1;
		dn[i][0].loc[1]=0;
		sum=dn[i][0].minno;
	}
	sum=0;
	for(i=0;i<col;i++)
	{
		dn[row-1][i].minno=dn[row-1][i].cellno;
		dn[row-1][i].minno+=sum;
		dn[row-1][i].loc[0]=row-1;
		dn[row-1][i].loc[1]=i-1;
		sum=dn[row-1][i].minno;
	}

	for(i=row-2;i>=0;i--)
		for(j=1;j<col;j++)
			eval(i,j);
	return(0);
}

eval(int i, int j)
{
	int minsum;
	dn[i][j].loc[0]=i+1;
	dn[i][j].loc[1]=j-1;
	minsum=dn[i+1][j-1].minno;
	if(minsum> dn[i][j-1].minno)
	{
		minsum=dn[i][j-1].minno;
		dn[i][j].loc[0]=i;
		dn[i][j].loc[1]=j-1;
	}

	if(minsum>dn[i+1][j].minno)
	{
		minsum=dn[i+1][j].minno;
		dn[i][j].loc[0]=i+1;
		dn[i][j].loc[1]=j;
	}
	dn[i][j].minno=dn[i][j].cellno+minsum;
	return(0);
}

findpath(int row,int col)
{
	int i,j,temp;
	i=0;

	j=col-1;
	while(1)
	{
		printf("\nvalue %d at row %d & col %d",dn[i][j].cellno,i,j);
		temp=dn[i][j].loc[0];
		j=dn[i][j].loc[1];
		i=temp;
		if(i==row-1 && j==0)
		{
			printf("\nvalue %d at row %d & col %d",dn[i][j].cellno,i,j);
			break;
		}
	}
	return(0);
}
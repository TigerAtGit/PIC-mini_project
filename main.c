#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int determinant(int [][10],int);
int determinant4(int [][10],int);
void inverse(int [][10],int);
void inverse4(int [][10],int);
int trace(int[][10],int);
void transpose(int [][10],int,int);
void addition(int [][10],int [][10],int,int);
void sbtraction(int [][10],int [][10],int,int);
void multiplication(int [][10],int [][10],int,int,int);
int main()
{
	int i,j;
	int A[10][10],B[10][10];
	int ra,ca,rb,cb;
	char opt,opt2;
	xyz:
	system("cls");
	for(i=0;i<100;++i)
	printf("*");
	printf("\n\t\t\t\t\tMATRIX BASED CALCULATOR\n");
	for(i=0;i<100;++i)
	printf("*");
	printf("\nWhich matrix operation you want to perform?\n");
	printf("1.Determinant\n2.Transpose\n3.Inverse\n4.Trace\n5.Matrix Addition\n6.Matrix Subtraction\n7.Matrix Multiplication\n8.Exit\n");
	scanf("%c",&opt);
	if(opt=='8')
	exit(0);
	else if(opt=='1'||opt=='3'||opt=='4')
	{
		if(opt=='1'||opt=='3')
        {
            printf("Enter order of matrix A(2-4) : ");
            scanf("%d",&ra);
            if(ra<=4)
            {
                printf("Enter martix A : \n");
                for(i=0;i<ra;++i)
                {
                    for(j=0;j<ra;++j)
                    scanf("%d",&A[i][j]);
                }
            }
            else
            printf("Please enter order of matrix upto 4 only!!\n");
        }
        else
        {
            printf("Enter order of matrix A : ");
            scanf("%d",&ra);
            printf("Enter martix A : \n");
            for(i=0;i<ra;++i)
            {
                for(j=0;j<ra;++j)
                scanf("%d",&A[i][j]);
            }
        }
	}
	else if(opt=='2'||opt=='5'||opt=='6'||opt=='7')
	{
		printf("No. of rows of A : ");
		scanf("%d",&ra);
		printf("No of columns of A : ");
		scanf("%d",&ca);
		printf("Enter matrix A : \n");
		for(i=0;i<ra;++i)
		{
			for(j=0;j<ca;++j)
			scanf("%d",&A[i][j]);
		}
		if(opt=='5'||opt=='6'||opt=='7')
		{
			printf("No. of rows of B : ");
			scanf("%d",&rb);
			printf("No of columns of B : ");
			scanf("%d",&cb);
			printf("Enter matrix B : \n");
			for(i=0;i<rb;++i)
			{
				for(j=0;j<cb;++j)
				scanf("%d",&B[i][j]);
			}
		}
	}
	else
	{
		printf("\nEnter valid option !!\n");
		printf("Press any key to continue... ");
		getch();
		goto xyz;
	}
	opt2=opt;
	switch(opt2)
	{
		case '1':
		{
			if(ra==2||ra==3)
			printf("Determinant of matrix A : %d\n",determinant(A,ra));
			else if(ra==4)
			printf("Determinant of matrix A : %d\n",determinant4(A,ra));
			else
			printf("Please enter matrix of order upto 4 only!\n");
			break;
		}
		case '2':
			transpose(A,ra,ca);
			break;
		case '3':
		{
			if(ra==2||ra==3)
			{
				if(determinant(A,ra)!=0)
				inverse(A,ra);
				else
				printf("Inverse Not possible as determinant is zero!!\n");
			}
			else if(ra==4)
			{
				if(determinant4(A,ra)!=0)
				inverse4(A,ra);
				else
				printf("Inverse Not possible as determinant is zero!!\n");
			}
			break;
		}
		case '4':
			printf("Trace of matrix A : %d\n",trace(A,ra));
			break;
		case '5':
		{
			if(ra==rb&&ca==cb)
			addition(A,B,ra,ca);
			else
			printf("\nAdditon Not Possible!\n");
			break;
		}
		case '6':
		{
			if(ra==rb&&ca==cb)
			subtraction(A,B,ra,ca);
			else
			printf("\nSubtraction Not Possible!\n");
			break;
		}
		case '7':
		{
			if(ca==rb)
			multiplication(A,B,ra,ca,cb);
			else
			printf("\nMultiplication Not Possible!\n");
			break;
		}
	}
	printf("Press any key to continue the calculator... ");
	getch();
	goto xyz;
}
determinant(int a[10][10],int n)//Function for finding determinant of 2x2 and 3x3 matrix
{
	int i,j;
	int det;
	if(n==2)
	det=a[0][0]*a[1][1]-a[1][0]*a[0][1];
	else if(n==3)
	{

		int x=(a[1][1]*a[2][2])-(a[2][1]*a[1][2]);
    	int y=(a[1][0]*a[2][2])-(a[2][0]*a[1][2]);
    	int z=(a[1][0]*a[2][1])-(a[2][0]*a[1][1]);
		det=(a[0][0]*x)-(a[0][1]*y)+(a[0][2]*z);
	}
	return det;
}
determinant4(int a[10][10],int n)//Function for finding determinant of 4x4 matrix
{
	int i,j,c[10][10];
	int Det,det1,det2,det3,det4;
	for(i=1;i<4;++i)
	{
		for(j=1;j<4;++j)
		c[i-1][j-1]=a[i][j];
	}
	det1=determinant(c,3);
	for(i=1;i<4;++i)
	{
		for(j=0;j<4;++j)
		if(j!=1)
		{
			if(j==0)
			c[i-1][j]=a[i][j];
			else
			c[i-1][j-1]=a[i][j];
		}
	}
	det2=determinant(c,3);
	for(i=1;i<4;++i)
	{
		for(j=0;j<4;++j)
		if(j!=2)
		{
			if(j==0||j==1)
			c[i-1][j]=a[i][j];
			else
			c[i-1][j-1]=a[i][j];
		}
	}
	det3=determinant(c,3);
	for(i=1;i<4;++i)
	{
		for(j=0;j<3;++j)
		c[i-1][j]=a[i][j];
	}
	det4=determinant(c,3);
	Det=a[0][0]*det1-a[0][1]*det2+a[0][2]*det3-a[0][3]*det4;
	return Det;
}
void transpose(int a[10][10],int r,int c)//Function for performing transpose
{
	int i,j;
	int temp[10][10];
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		temp[j][i]=a[i][j];
	}
	printf("Transpose of Matrix:\n");
	for(i=0;i<c;++i)
	{
		for(j=0;j<r;++j)
		{
			a[i][j]=temp[i][j];
			printf("%d\t",a[i][j]);
		}
		printf("\n");

	}
}
void inverse(int a[10][10],int n)//Function for finding inverse of 2x2 and 3x3 matrix
{
	int i,j,det;
	float c[10][10];
	if(n==2)
	{
		c[0][0]=a[1][1];
		c[1][1]=a[0][0];
		c[0][1]=-a[0][1];
		c[1][0]=-a[1][0];
		det=determinant(a,2);
		printf("Inverse of Matrix A :\n");
		for(i=0;i<2;++i)
		{
			for(j=0;j<2;++j)
			printf("%f\t",c[i][j]/det);
			printf("\n");
		}
	}
	if(n==3)
	{
		c[0][0]=a[1][1]*a[2][2]-a[2][1]*a[1][2];
		c[1][0]=-(a[1][0]*a[2][2]-a[2][0]*a[1][2]);
		c[2][0]=a[1][0]*a[2][1]-a[1][1]*a[2][0];
		c[0][1]=-(a[0][1]*a[2][2]-a[2][1]*a[0][2]);
		c[1][1]=a[0][0]*a[2][2]-a[2][0]*a[0][2];
		c[2][1]=-(a[0][0]*a[2][1]-a[2][0]*a[0][1]);
		c[0][2]=a[0][1]*a[1][2]-a[1][1]*a[0][2];
		c[1][2]=-(a[0][0]*a[1][2]-a[1][0]*a[0][2]);
		c[2][2]=a[1][1]*a[0][0]-a[1][0]*a[0][1];
		det=determinant(a,3);
		printf("Inverse of Matrix A :\n");
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			printf("%f\t",c[i][j]/det);
			printf("\n");
		}
	}
}
void inverse4(int a[10][10],int n)//Function for finding inverse of 4x4 matrix
{
	int z=0,cof[16],det;
	int cmat[10][10];
	float t[10][10];
	int i,j,r,c,x,y;
	det=determinant4(a,4);
	for(r=0;r<4;++r)
	{
	    for(c=0;c<4;++c)
        {
            x=0;
            for(i=0;i<4;++i)
            {
                y=0;
                for(j=0;j<4;++j)
                {
                    if(i==r||j==c) continue;
                    cmat[x][y]=a[i][j];
                    y++;
                }
                if(i==r||j==c) continue;
                x++;
            }
            cof[z]=pow(-1,r+c)*determinant(cmat,3);
            z++;
        }
	}
    x=0;
	for(i=0;i<4;++i)
	{
		for(j=0;j<4;++j)
		{
			t[i][j]=cof[x];
			x++;
		}
	}
	printf("Inverse of Matrix A : \n");
	for(i=0;i<4;++i)
	{
		for(j=0;j<4;++j)
		printf("%f\t",t[j][i]/det);
		printf("\n");
	}
}
int trace(int a[10][10],int n)//Function for finding trace of matrix
{
	int tr=0,i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		if(i==j)
		tr=tr+a[i][j];
	}
	return tr;
}
void addition(int a[10][10],int b[10][10],int r,int c)//Function for matrix Addition
{
	int i,j;
	printf("Addition of two Matrix A and Matrix B :\n");
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		printf("%d\t",a[i][j]+b[i][j]);
		printf("\n");
	}
}
void subtraction(int a[10][10],int b[10][10],int r,int c)//Function for matrix Subtraction
{
	int i,j;
	printf("Subtracting Matrix B from Matrix A (MatA-MatB):\n");
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		printf("%d\t",a[i][j]-b[i][j]);
		printf("\n");
	}
}
void multiplication(int a[10][10],int b[10][10],int p,int q,int r)//Function for matrix multiplication
{
	int i,j,k;
	int c[10][10];
	for(i=0;i<p;++i)
	{
		for(j=0;j<r;++j)
		c[i][j]=0;
	}
	for(i=0;i<p;++i)
	{
		for(j=0;j<r;++j)
		{
			for(k=0;k<q;++k)
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
	printf("Product of Matrix A and Matrix B :\n");
	for(i=0;i<p;++i)
	{
		for(j=0;j<r;++j)
		printf("%d\t",c[i][j]);
		printf("\n");
	}
}

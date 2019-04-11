#include <stdio.h>
#include <stdlib.h>
#define  SIZE 500
int main()
{
     int n;
     printf("ENTER THE NUMBER OF MINTERMS:");
     scanf("%d\n",&n);
     int minterms[n];
   for(int i=0;i<n;i++){
scanf("%d",&minterms[i]);
   }

int counter[SIZE][SIZE];

for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
        counter[i][j]=0;
    }
}
int a1[SIZE][2];
int c=0;
for(int i=0;i<SIZE;i++){
    for(int j=0;j<2;j++){
   a1[i][j]=-100;
    }
}
for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){
   if(minterms[i]<minterms[j]){
    int subt=minterms[j]^minterms[i];
    if(subt==1||subt==2||subt==4||subt==8||subt==16||subt==32){
        a1[c][0]=minterms[i];
        a1[c][1]=subt;
        counter[0][i]++;
        counter[0][j]++;
        c++;
    }


    }
}
}
int a2[SIZE][3];
for(int i=0;i<SIZE;i++){
    for(int j=0;j<3;j++){
   a2[i][j]=-100;
    }
}
int c1=0;
for(int i=0;i<SIZE;i++){
    for(int j=i+1;j<SIZE;j++){
  if(a1[i][1]==a1[j][1]){
        if(a1[i][0]<a1[j][0]){
    int subt=a1[i][0]^a1[j][0];
    if((subt==1||subt==2||subt==4||subt==8||subt==16||subt==32)&& a1[i][1]==a1[j][1]){
        a2[c1][0]=a1[i][0];
        a2[c1][1]=a1[i][1];
        a2[c1][2]=subt;
        if(a2[c1][1]>a2[c1][2]){
            int temp = a2[c1][1];
            a2[c1][1]=a2[c1][2];
            a2[c1][2]=temp;
        }
        counter[1][i]++;
        counter[1][j]++;
        c1++;
    }

}
    }
}
}for(int i=0;i<SIZE;i++){
    for(int j=i+1; j<SIZE;j++){
        if(a2[i][0]==a2[j][0] && a2[i][1]==a2[j][1] && a2[i][2]==a2[j][2]){
            a2[j][0]=a2[j][1]=a2[j][2]=-100;
        }
    }
}
int a3[SIZE][4];
for(int i=0;i<SIZE;i++){
    for(int j=0;j<4;j++){
   a3[i][j]=-100;
    }
}
int c2=0;
for(int i=0;i<SIZE;i++){
    for(int j=i+1;j<SIZE;j++){
        if(a2[i][0]<a2[j][0]){
    int subt=a2[i][0]^a2[j][0];
    if((subt==1||subt==2||subt==4||subt==8||subt==16||subt==32)&& a2[i][1]==a2[j][1] && a2[i][2]==a2[j][2]){
        a3[c2][0]=a2[i][0];
        a3[c2][1]=a2[i][1];
        a3[c2][2]=a2[i][2];
        a3[c2][3]=subt;
        if(a3[c2][3]<a3[c2][1]){
                int temp = a3[c2][3];
        a3[c2][3]=a3[c2][2];
        a3[c2][2]=a3[c2][1];
        a3[c2][1]=temp;
        }
        else if (a3[c2][3]>a3[c2][1] && a3[c2][3]<a3[c2][2]){
            int temp = a3[c2][3];
            a3[c2][3]=a3[c2][2];
            a3[c2][2]=temp;
        }
        counter[2][i]++;
        counter[2][j]++;
        c2++;
    }

}

}
}

for(int i=0;i<SIZE;i++){
    for(int j=i+1; j<SIZE;j++){
        if(a3[i][0]==a3[j][0] && a3[i][1]==a3[j][1] && a3[i][2]==a3[j][2] && a3[i][3]==a3[j][3]){
            a3[j][0]=a3[j][1]=a3[j][2]=a3[j][3]=-100;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
int a4[SIZE][5];
for(int i=0;i<SIZE;i++){
    for(int j=0;j<5;j++){
   a4[i][j]=-100;
    }
}
int c3=0;
for(int i=0;i<SIZE;i++){
    for(int j=i+1;j<SIZE;j++){
        if(a3[i][0]<a3[j][0]){
    int subt=a3[i][0]^a3[j][0];
    if((subt==1||subt==2||subt==4||subt==8||subt==16||subt==32)&& a3[i][1]==a3[j][1] && a3[i][2]==a3[j][2] && a3[i][3]==a3[j][3]){
        a4[c3][0]=a3[i][0];
        a4[c3][1]=a3[i][1];
        a4[c3][2]=a3[i][2];
        a4[c3][3]=a3[i][3];
        a4[c3][4]=subt;
        if(a4[c3][4]<a4[c3][1]){
                int temp = a4[c3][4];
        a4[c3][4]=a4[c3][3];
        a4[c3][3]=a4[c3][2];
        a4[c3][2]=a4[c3][1];
        a4[c3][1]=temp;
        }
        else if (a4[c3][4]>a4[c3][1] && a4[c3][4]<a4[c3][2]){
            int temp = a4[c3][4];
            a4[c3][4]=a4[c3][3];
            a4[c3][3]=a4[c3][2];
            a4[c3][2]=temp;
        }
        else if (a4[c3][4]>a4[c3][2] && a4[c3][4]<a4[c3][3]){
            int temp = a4[c3][4];
            a4[c3][4]=a4[c3][3];
            a4[c3][3]=temp;
        }
        counter[3][i]++;
       counter[3][j]++;
        c3++;
    }

}

}
}
for(int i=0;i<SIZE;i++){
    for(int j=i+1; j<SIZE;j++){
        if(a4[i][0]==a4[j][0] && a4[i][1]==a4[j][1] && a4[i][2]==a4[j][2] && a4[i][3]==a4[j][3] && a4[i][4]==a4[j][4]){
           a4[j][0]=a4[j][1]=a4[j][2]=a4[j][3]=a4[j][4]=-100;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////
int a5[SIZE][6];
for(int i=0;i<SIZE;i++){
    for(int j=0;j<6;j++){
   a5[i][j]=-100;
    }
}
int c4=0;
for(int i=0;i<SIZE;i++){
    for(int j=i+1;j<SIZE;j++){
        if(a4[i][0]<a4[j][0]){
    int subt=a4[i][0]^a4[j][0];
    if((subt==1||subt==2||subt==4||subt==8||subt==16||subt==32)&& a4[i][1]==a4[j][1] && a4[i][2]==a4[j][2] && a4[i][3]==a4[j][3]&&a4[i][4]==a4[j][4]){
        a5[c4][0]=a4[i][0];
        a5[c4][1]=a4[i][1];
        a5[c4][2]=a4[i][2];
        a5[c4][3]=a4[i][3];
        a5[c4][4]=a4[i][4];
        a5[c4][5]=subt;
        if(a5[c4][5]<a5[c4][1]){
                int temp = a5[c4][5];
        a5[c4][5]=a5[c4][4];
        a5[c4][4]=a5[c4][3];
        a5[c4][3]=a5[c4][2];
        a5[c4][2]=a5[c4][1];
        a5[c4][1]=temp;
        }
        else if (a5[c4][5]>a5[c4][1] && a5[c4][5]<a5[c4][2]){
            int temp = a5[c4][5];
            a5[c4][5]=a5[c4][4];
            a5[c4][4]=a5[c4][3];
            a5[c4][3]=a5[c4][2];
            a5[c4][2]=temp;
        }
        else if (a5[c4][5]>a5[c4][2] && a5[c4][5]<a5[c4][3]){
            int temp = a5[c4][5];
            a5[c4][5]=a5[c4][4];
            a5[c4][4]=a5[c4][3];
            a5[c4][3]=temp;
        }
        else if (a5[c4][5]>a5[c4][3] && a5[c4][5]<a5[c4][4]){
            int temp = a5[c4][5];
            a5[c4][5]=a5[c4][4];
            a5[c4][4]=temp;
        }
        counter[4][i]++;
       counter[4][j]++;
        c4++;
    }

}

}
}
for(int i=0;i<SIZE;i++){
    for(int j=i+1; j<SIZE;j++){
        if(a5[i][0]==a5[j][0] && a5[i][1]==a5[j][1] && a5[i][2]==a5[j][2] && a5[i][3]==a5[j][3] && a5[i][4]==a5[j][4] && a5[i][5]==a5[j][5]){
           a5[j][0]=a5[j][1]=a5[j][2]=a5[j][3]=a5[j][4]=a5[j][5]=-100;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
int pi[SIZE][6];
int count=0;
for(int i=0;i<SIZE;i++){
    for(int j=0;j<6;j++){
   pi[i][j]=-100;
    }
}
for(int i=0;i<SIZE;i++)
{
if(i==0){
    for(int j=0;j<n;j++){
        if(counter[i][j]==0){
            pi[count++][0]=minterms[j];

        }

    }
}
else if(i==1){
    for(int j=0;j<c;j++){
        if(counter[i][j]==0){
            pi[count][0]=a1[j][0];
            pi[count][1]=a1[j][1];
            count++;
        }
    }
}
else if(i==2){
    for(int j=0;j<c1;j++){
        if(counter[i][j]==0){
            pi[count][0]=a2[j][0];
            pi[count][1]=a2[j][1];
              pi[count][2]=a2[j][2];
            count++;
        }
    }
}
else if(i==3){
    for(int j=0;j<c2;j++){
        if(counter[i][j]==0){
            pi[count][0]=a3[j][0];
            pi[count][1]=a3[j][1];
              pi[count][2]=a3[j][2];
                pi[count][3]=a3[j][3];
            count++;
        }
    }
}
else if(i==4){
    for(int j=0;j<c3;j++){
        if(counter[i][j]==0){
            pi[count][0]=a4[j][0];
            pi[count][1]=a4[j][1];
              pi[count][2]=a4[j][2];
                pi[count][3]=a4[j][3];
                 pi[count][4]=a4[j][4];
            count++;
        }
    }
}
else if(i==5){
    for(int j=0;j<c4;j++){
        if(counter[i][j]==0){
            pi[count][0]=a5[j][0];
            pi[count][1]=a5[j][1];
              pi[count][2]=a5[j][2];
                pi[count][3]=a5[j][3];
                 pi[count][4]=a5[j][4];
            count++;
        }
    }
}
}
int b[6];
int s;
for(int i=0;i<SIZE;i++){
    int q =0;
      for (int i=0;i<6;i++){
        b[i]=0;
        }
       s=pi[i][0];
        while(s>0){
            b[q]=s%2;
            s/=2;
            q++;
        }
    for(int f=0;f<(6/2);f++){
          int tmp =b[f];
          b[f]=b[6-f-1];
          b[6-f-1]=tmp;

      }
      if(pi[i][0]!=-100){
      for(int j=1;j<6;j++){
        if(pi[i][j]==1){
            b[5]=-100;
        }
        else if(pi[i][j]==2){
            b[4]=-100;
        }
        else if(pi[i][j]==4){
            b[3]=-100;
        }
        else if(pi[i][j]==8){
            b[2]=-100;
        }
        else if(pi[i][j]==16){
            b[1]=-100;
        }
        else if(pi[i][j]==32){
            b[0]=-100;
        }
      }

     if(b[0]==1) printf("A");
     else if (b[0]==0) printf("A'");
     if(b[1]==1) printf("B");
     else if (b[1]==0) printf("B'");
     if(b[2]==1) printf("C");
     else if (b[2]==0) printf("C'");
     if(b[3]==1) printf("D");
     else if (b[3]==0) printf("D'");
     if(b[4]==1) printf("E");
     else if (b[4]==0) printf("E'");
     if(b[5]==1) printf("F");
     else if (b[5]==0) printf("F'");

     printf("\n");
      }





}



int j;
for(int i=0;i<SIZE;i++){
    for(j=0;j<6;j++){
 printf("%d ",pi[i][j]);


} printf("\n");}
        return 0;
}

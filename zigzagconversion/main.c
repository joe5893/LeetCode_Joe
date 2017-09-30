#include <stdio.h>
#include <string.h>



int main(){
	const int nRows = 4;
	char a[nRows][10]; 
	char str[30] = "PAYPALISHIRING";
	//gets(str);
	int num=strlen(str);	
	int i,j=0,k=0;
	int flag;
	char ch;
	for(i=0;i<nRows;i++){
	    for(j=0;j<10;j++)
	    {
	    	a[i][j] = ' ';//初始化避免最后打印出来有垃圾 
	    }   			
	}
	
	i=0,j=0,k=0,flag=0;
	for(i=0;i<num;i++){
		ch = str[i];
		if(flag==0){//向下填					
			a[j][k]=ch;		
			//printf("a[%d][%d]=%c\n",j,k,ch);			
			if((j+1)==nRows){				
				j--;
				k++;
				flag = 1;
				//continue;
			}
			else{			
				j++;
			}
		}
		else if(flag==1){//向右上角填			 
			a[j][k]=ch;			
			//printf("a[%d][%d]=%c\n",j,k,ch);		
			if(j==0){				
				flag = 0;
				j++;
				//continue;
			}
			else{
				j--;
				k++;
			}			
		}	
	}

	printf("\n");
	for(i=0;i<nRows;i++){
	    for(j=0;j<8;j++)
	    {
	    	printf("%c ",a[i][j]);
	    }   
		printf("\n");
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	while(1){
		int arr[3][3];
		char player='X';
		int i,j,t=0;    
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				t++;			
				arr[i][j]=t;
			}
		}
		int y=0;
		while(1)
		{
			
			y++;
	        
			for(i=0;i<3;++i)
			{
				for(j=0;j<3;++j)
				{	
				if(arr[i][j]==88)printf("  X");
				else if(arr[i][j]==79)printf("  O");
				else
					printf("  %d",arr[i][j]);
				}
				printf("\n");
			}
			printf("----------------------\n");
			
			{
				if(
	 			   arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]||
				   arr[1][0]==arr[1][1]&&arr[1][0]==arr[1][2]||
				   arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]||
				   arr[0][0]==arr[1][0]&&arr[0][0]==arr[2][0]||
				   arr[0][1]==arr[1][1]&&arr[0][1]==arr[2][1]||
				   arr[0][2]==arr[1][2]&&arr[0][2]==arr[2][2]||
				   arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2]||
	 			   arr[0][2]==arr[1][1]&&arr[0][2]==arr[2][0]
	   	          )
				{	
				
					printf(" player %c win\n",player);
					
	                //sleep(5);
					break;
				}
			
			}
			
			if(y==10)
			{
				printf("berabere");
				//sleep(5);
				break;
			}
			
			if(player=='X')
			{
	            player='O';
	            printf("   player O\n");
	        }
			else
			{ 
			    player='X';
			    printf("   player X\n");
	        }
			
			
			int x=1,loc;
			
			
			while(x)
			{
			    printf(" Select Location:");
				scanf("%d",&loc);
				
				for(i=0;i<3;++i)
				{
					for(j=0;j<3;++j)
					{	
						if(player=='X'&&loc==arr[i][j]){
						arr[i][j]='X';
						x=0;
						}
						if(player=='O'&&loc==arr[i][j])
						{
						x=0;
						arr[i][j]='O';
						}					
				    }
				}
				
				
	            if(x==1)
				printf(" This place is not empty \n");
				else	
				system("CLS");
			}
			
	        
		}getch();
	}
	return 0;
}



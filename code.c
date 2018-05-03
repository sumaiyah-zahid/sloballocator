#include<stdio.h>
int main() {
	int fragmentation[15],blocks[15],Process[15],i,j,blocknum,processnum,temp,lowest=10000,highest=0,ch;
	static int bf[15],pf[15];
	static int bf1[15],pf1[15];
	static int bf2[15],pf2[15];
	printf("\n===================================================");
	printf("\n\t\tSLOB ALLOCATOR\n");
	printf("\n\t First-Fit | Best-Fit | Worst-Fit\n");
	printf("===================================================\n");
	printf("\nEnter The Number Of Blocks : ");
	scanf("%d",&blocknum);
	printf("Enter The Number Of Procceses : ");
	scanf("%d",&processnum);
	printf("\nEnter The Sizes Of Blocks : \n");
	
	for(i=1;i<=blocknum;i++){
		printf("Block-%d :",i);
		scanf("%d",&blocks[i]);
	}
	
	printf("\nEnter the Sizes Of Processes : \n");
	for(i=1;i<=processnum;i++) {
		printf("Process-%d :",i);
		scanf("%d",&Process[i]);
	}
	printf("\n1.First-Fit\n2.Best-Fit \n3.Worst-Fit");
	
	do {
		printf("\n\n==================================================\n");
		printf("\nEnter Your Choice.....! : ");
		scanf("%d",&ch);
	
		switch(ch) {
		case 1:    //First Fit
			printf("\n****************************************************\n");
			printf("\t\tFirst Fit\n");
			printf("****************************************************\n");
		
			for(i=1;i<=processnum;i++) {
				for(j=1;j<=blocknum;j++) {
					if(bf2[j]!=1) {
						temp=blocks[j]-Process[i];
						if(temp>=0) {
							pf2[i]=j;
							break;
						}
					}
				}
			fragmentation[i]=temp;
			bf2[pf2[i]]=1;
			}	
		
			printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
			for(i=1;i<=processnum;i++) {
			  printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,Process[i],pf2[i],blocks[pf2[i]],fragmentation[i]);
			}
		
		break;
		
		case 2: //Best Fit 
		
			printf("\n****************************************************\n");
			printf("\t\tBest Fit\n");
			printf("****************************************************\n");
			for(i=1;i<=processnum;i++) {
					for(j=1;j<=blocknum;j++) {
						if(bf1[j]!=1){
							temp=blocks[j]-Process[i];
								if(temp>=0)
									if(lowest>temp){
										pf1[i]=j;
										lowest=temp;
									}
						}
					}
				fragmentation[i]=lowest;
				bf1[pf1[i]]=1;
				lowest=10000;
			}
			printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
			
			for(i=1;i<=processnum;i++) {
			  printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,Process[i],pf1[i],blocks[pf1[i]],fragmentation[i]);
			}
			
		temp=0;
		break;
		
		case 3 :  // Worst Fit
			printf("\n****************************************************\n");
			printf("\t\tWorst Fit\n");
			printf("****************************************************\n");
			for(i=1;i<=processnum;i++) {
				for(j=1;j<=blocknum;j++) {
					if(bf[j]!=1){ //if bf[j] is not allocated {
					temp=blocks[j]-Process[i];
						if(temp>=0)
							if(highest<=temp) {
							pf[i]=j;
							highest=temp;
							}	
						}
					}
				fragmentation[i]=highest;
				bf[pf[i]]=1;
				highest=0;
				
				}
				printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
				
				for(i=1;i<=processnum;i++) {
				  printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,Process[i],pf[i],blocks[pf[i]],fragmentation[i]);
				}
				temp=0;
				break;
				
		default:
			printf("Invalid Choice.....!");break;
		}// switch case over
			
		} while(ch<=3); //do while over
		    return 0;
}

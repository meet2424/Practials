#include <stdio.h> 
#include <string.h>
 
int main(){

    int opt;
    do
    {
        printf("\n\n1. Character Count\n2. Character Stuffing\n3. Bit Stuffng.\n4. Exit");
        printf("\n\nEnter an option: "); 
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
        {
            int n;
            printf("Enter the number of frames: "); 
            scanf("%d", &n);
            
            char string[50][50];

            int i; 
            for(i=0; i< n ; i++) {
                printf("Enter frame data %d : ",i+1);
                scanf("%s",string[i]);
            }

            printf("The final frame data : \n");
            
            for(i=0; i< n ; i++) {
                printf("%ld", strlen(string[i])+1);
                printf("%s", string[i]);
            }  
            break;
        } 
        case 2:
        { 
            char string[50],stuffed[50],start[5],end[5];
            printf("Enter the frame data : ");
            scanf("%s",string);
            printf("Enter start frame flag : ");
            scanf("%s",start);
            printf("Enter end frame flag : ");
            scanf("%s",end);

            printf("Stuffed frame:\n");
            stuffed[0]=start[0];
            int k=1;
            
            for(int i=0;i<strlen(string);i++){
                if(string[i]!=start[0] && string[i]!=end[0]){
                    stuffed[k]=string[i];
                    k++;
                }
                else{
                    if(string[i]==start[0]){
                        stuffed[k]=start[0];
                        k++;
                        stuffed[k]=string[i];
                        k++;
                    }
                    else{
                        stuffed[k]=end[0];
                        k++;
                        stuffed[k]=string[i];
                        k++;    
                    }
            }

            }
            stuffed[k]=end[0];
            stuffed[k+1]='\0';
            printf("%s",stuffed);

            break;
        }
        case 3:
        {
            char string[50];
            printf("Enter the Frame\n");
            scanf("%s",string);
            printf("The stuffed frame is : ");
            int count=0;
            int l=strlen(string);
            for(int i=0;i<l;i++){
            printf("%c",string[i]);
            if(string[i]=='1'){
            count++;
            }
            else{
            count=0;
            }
            if(count==5){
            printf("0");
            count=0;
            }
            }

            break;
        }
        case 4:
        {
            printf("Exiting..!\n");
            break;
        }
        default:
        {
            printf("Enter an valid OPTION!!");
        }
        }
    } while (opt != 4);
    return 0;
}

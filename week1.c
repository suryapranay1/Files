#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct  student

{
  int id;
  char name[20];
  char dept[10];
};

int main()
{
    int option,no;
    

    char search[20];

   FILE *fp;
   struct student s[3];
   fp=fopen("file1.txt","w");
   printf("\nEnter The 3 Students Detials\n");
   for(int i=0;i<3;i++)
   {
    printf("\nEnter The %d Student Id:\n",i+1);
    scanf("%d",&s[i].id);
    printf("\nEnter The %d Student Name:\n",i+1);
    scanf("%s",s[i].name);
    printf("\nEnter The %d Student Dept:\n",i+1);
    scanf("%s",s[i].dept);

   }
   fwrite(&s,sizeof(struct student),3,fp);
   fclose(fp);

   //Here again We Opened In Read Mode
    fp=fopen("file1.txt","r");
     
     do
     {
        printf("\nEnter The Option\n");
        printf("\n 1.Search By Id\n");
         printf("\n 2.Search By name\n");
          printf("\n 3.Search By Dept\n");
          scanf("%d",&option);
          switch (option)
          {
            
            case 1:
          +  printf("\nEnter The Id:\n");
            scanf("%d",&no);
             for(int i=0;i<3;i++)
                      {
                      if(no==s[i].id)
                      {
                       printf("%s ",s[i].name);
                        printf("%s ",s[i].dept);
                      }

                      }
                       break;
            case 2:
            printf("\nEnter The name:\n");
            scanf("%s",search);
             for(int i=0;i<3;i++)
                      {
                      if(strcmp(search,s[i].name)==0)
                      {
                       printf("%d ",s[i].id);
                        printf("%s ",s[i].dept); 
                      }
                      }
                       break;
            case 3:
            printf("Enter The Dept:");
            scanf("%s",search);
             for(int i=0;i<3;i++)
                      {
                      if(strcmp(search,s[i].dept)==0)
                      {
                       printf("%s",s[i].name);
                        printf("%d",s[i].id); 
                      }
                      }
                       break;
            default:
            printf("\nExit\n");
            exit(0);
          }
     }
          while (option!=4);
          fclose(fp);
}

          
          





         
         
#include <stdio.h>
#include <stdlib.h>
#include<process.h>
   FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
     char ch,c;
     int i,choice;
     char filename[50],filename1[50];

 void raid0()
 {
     printf("enter filename to stripe\n");
     scanf("%s",filename);

     printf("%s",filename);

     fp = fopen(filename,"r");
     fp1=fopen("C:/TC/raid/d1/file1.txt","w");
     fp2=fopen("C:/TC/raid/d2/file2.txt","w");
     fp3=fopen("C:/TC/raid/d3/file3.txt","w");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=16;i++)
	  if((c=getc(fp))!=EOF)
	   putc(c,fp1);


	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   if((c=getc(fp))!=EOF)
	   putc(c,fp2);

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   if((c=getc(fp))!=EOF)
	   putc(c,fp3);

	    }while(!feof(fp));
      printf("Before striping the size of file=%ld\n",ftell(fp));
      fseek(fp,0,0);
      printf("After striping the size of file=%ld\n",ftell(fp));

      fclose(fp);
      printf("The size of Disk1=%ld\n\n",ftell(fp1));
      fclose(fp1);
      printf("The size of Disk2=%ld\n\n",ftell(fp2));
      fclose(fp2);
      printf("The size of Disk3=%ld\n\n",ftell(fp3));
      fclose(fp3);
      return ;
  }

   void raid1()
 {
     char ch2;
     printf("enter filename for mirraring\n");
     scanf("%s",filename);
     fp = fopen(filename, "r");
     fp1=fopen("C:/TC/raid/d1/file1.txt", "w");
     fp2=fopen("C:/TC/raid/mirror/mirrer1.txt", "w");

     while(!feof(fp))
     {
	 if((ch2=getc(fp))!=EOF)
	  {
	     putc(ch2,fp1);
	     putc(ch2,fp2);
	   }
      }
      fseek(fp,0,0);
      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      return ;
  }
  void raid01()
 {
     char ch2;
     printf("enter filename for mirroring\n");
     scanf("%s",filename);
     fp = fopen(filename, "r");
     fp1=fopen("C:/TC/raid/d1/file1.txt", "w");
     fp2=fopen("C:/TC/raid/d2/file2.txt", "w");
     fp3=fopen("C:/TC/raid/d3/file3.txt", "w");
     fp4=fopen("C:/TC/mirrer/d1/mirrer1.txt", "w");
     fp5=fopen("C:/TC/mirrer/d2/mirrer2.txt", "w");
     fp6=fopen("C:/TC/mirrer/d3/mirrer3.txt", "w");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	    if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp4);
	    putc(ch2,fp1);}
	   }

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	   if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp2);
	    putc(ch2,fp5);   }
	    }

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	    if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp3);
	    putc(ch2,fp6);}
	   }

	    }while(!feof(fp));
      fseek(fp,0,0);

      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);
      fclose(fp4);
      fclose(fp5);
      fclose(fp6);
      return ;
  }
  void raid10()
 {
     char ch2;
     printf("enter filename for mirraring\n");
     scanf("%s",filename);
     fp = fopen(filename, "r");
     fp1=fopen("C:/TC/raid/d1/file1.txt", "w");
     fp2=fopen("C:/TC/raid/d2/file2.txt", "w");
     fp3=fopen("C:/TC/raid/d3/file3.txt", "w");
     fp4=fopen("C:/TC/mirrer/d1/mirrer1.txt", "w");
     fp5=fopen("C:/TC/mirrer/d2/mirrer2.txt", "w");
     fp6=fopen("C:/TC/mirrer/d3/mirrer3.txt", "w");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	    if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp4);
	    putc(ch2,fp1);}
	   }

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	   if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp2);
	    putc(ch2,fp5);   }
	    }

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	    if((ch2=getc(fp))!=EOF){
	    putc(ch2,fp3);
	    putc(ch2,fp6);}
	   }

	    }while(!feof(fp));
      fseek(fp,0,0);

      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);
      fclose(fp4);
      fclose(fp5);
      fclose(fp6);
      return ;
  }
 void Reconstruct1()
 {
     int ch1,j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "w");
     fp1=fopen("C:/TC/raid/d1/file1.txt", "r");
     fp2=fopen("C:/TC/raid/d2/file2.txt", "r");
     fp3=fopen("C:/TC/raid/d3/file3.txt", "r");
     do
     {
     for(j=1;j<=16;j++)
     if((c=getc(fp1))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp2))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp3))!=EOF)
     fprintf(fp, "%c", c);

     }while(!feof(fp1) && !feof(fp2) && !feof(fp3));
      printf("After reconstruction the size of file=%ld\n",ftell(fp));
      fclose(fp);

      fseek(fp1,0,0);
      fseek(fp2,0,0);
      fseek(fp3,0,0);

      fp1=fopen("C:/raid/d1/file1.txt","w");
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);

 }
  void Reconstruct2()
 {
     int ch1,j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "w");
     if((fp1=fopen("C:/TC/raid/d1/file1.txt", "r"))==NULL)
     {
	printf("Original Hard disk has missed so i m using mirrored disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/raid/mirror/mirrer1.txt", "r");
      }
	  while(!feof(fp1))
	  {
		if((c=getc(fp1))!=EOF)
		fprintf(fp, "%c", c);
	  }
      fclose(fp);
      fclose(fp1);
 }

 void Reconstruct3()
 {
     int ch1,j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "w");
     if((fp1=fopen("C:/TC/raid/d1/file1.txt", "r"))==NULL)
     {
	printf("hard disk1 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/mirrer/d1/mirrer1.txt", "r");
      }
    if((fp2=fopen("C:/TC/raid/d2/file2.txt", "r"))==NULL)
     {
	printf("hard disk2 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp2);
	fp2=fopen("C:/TC/mirrer/d2/mirrer2.txt","r");
     }
     if((fp3=fopen("C:/TC/raid/d3/file3.txt", "r"))==NULL)
     {
	printf("hard disk3 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp3);
	fp3=fopen("C:/TC/mirrer/d3/mirrer2.txt","r");
     }

 while(!feof(fp1) && !feof(fp2) && !feof(fp3))
 {
     for(j=1;j<=16;j++)
     if((c=getc(fp1))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp2))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp3))!=EOF)
     fprintf(fp, "%c", c);
 }
      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);
 }

 void Reconstruct4()
 {
     int ch1,j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "w");
     if((fp1=fopen("C:/TC/raid/d1/file1.txt", "r"))==NULL)
     {
	printf("hard disk1 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/mirrer/d1/mirrer1.txt", "r");
      }
    if((fp2=fopen("C:/TC/raid/d2/file2.txt", "r"))==NULL)
     {
	printf("hard disk2 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp2);
	fp2=fopen("C:/TC/mirrer/d2/mirrer2.txt","r");
     }
     if((fp3=fopen("C:/TC/raid/d2/file3.txt", "r"))==NULL)
     {
	printf("hard disk3 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp3);
	fp3=fopen("C:/TC/mirrer/d3/mirrer2.txt","r");
     }

 do
 {
     for(j=1;j<=16;j++)
     if((c=getc(fp1))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp2))!=EOF)
     fprintf(fp, "%c", c);

     for(j=1;j<=16;j++)
     if((c=getc(fp3))!=EOF)
     fprintf(fp, "%c", c);

 }while(!feof(fp1) && !feof(fp2) && !feof(fp3));
      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);
 }

void main()
{

     clrscr();
     for(;;){
     printf(" 1:stripe the file(RAID 0)\n\n 2:Miraring of the file(RAID 1) \n\n 3:RAID 0+1:Mirrored stripes \n\n 4:RAID 10:Striped mirrors\n\n 5:Reconstruct the striped file\n\n 6:Reconstuct the mirrared file \n\n 7:Reconstruct from RAID 0+1 \n\n 8:Reconstruct from RAID 10\n 9:Exit\n\n ");

     printf("Enter the choice\n");
     scanf("%d",&choice);

    switch(choice)
     {
      case 1:raid0();
		break;
      case 2:raid1();
		break;
      case 3:raid01();
		break;
      case 4:raid10();
		break;
      case 5:Reconstruct1();
		break;
      case 6:Reconstruct2();
		break;
      case 7:Reconstruct3();
		break;
      case 8:Reconstruct4();
		break;
      case 9:return;
     }
     }
     getch();
}


#include <stdio.h>
#include <stdlib.h>
#include<process.h>
   FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
     long int ch;
     long int i,choice,n;
     char filename[50],filename1[50];

 void raid0()
 {
     printf("enter filename to stripe\n");
     scanf("%s",filename);
     fp = fopen(filename,"rb");
     fseek(fp,0,2);
     printf("Before striping the size of file=%ld\n",ftell(fp));
     fseek(fp,0,0);
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     printf("\n");
     fp1=fopen("C:/TC/raid/d1/file1.mp3","wb");
     fp2=fopen("C:/TC/raid/d2/file2.mp3","wb");
     fp3=fopen("C:/TC/raid/d3/file3.mp3","wb");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=n;i++)
	  if((ch=getc(fp))!=EOF)
	   putc(ch,fp1);

	   if(!feof(fp))
	   for(i=1;i<=n;i++)
	   if((ch=getc(fp))!=EOF)
	   putc(ch,fp2);

	   if(!feof(fp))
	   for(i=1;i<=n;i++)
	   if((ch=getc(fp))!=EOF)
	   putc(ch,fp3);

   }while(!feof(fp));
      fseek(fp,0,0);
      printf("After striping the size of file=%ld\n",ftell(fp));
      fclose(fp);
      fp = fopen(filename,"wb");
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
     printf("enter filename for mirraring\n");
     scanf("%s",filename);
     fp = fopen(filename, "rb");
     fseek(fp,0,2);
     printf("Before striping the size of file=%ld\n",ftell(fp));
     fseek(fp,0,0);
     printf("enter the chunk size to stripe: ");
     scanf("%ld",&n);
     printf("\n");
     fp1=fopen("C:/TC/raid/d1/file1.mp3", "wb");
     fp2=fopen("C:/TC/raid/mirror/mirrer1.mp3", "wb");

     while(!feof(fp))
     {
	 if((ch=getc(fp))!=EOF)
	  {
	     putc(ch,fp1);
	     putc(ch,fp2);
	   }
      }
      fclose(fp);
      fp = fopen(filename, "wb");
      fclose(fp);
      printf("The size of file after Mirroring=%ld\n\n",ftell(fp));
      printf("Know the size of Original hard disk=%ld\n\n",ftell(fp1));
      printf("Know the size of Redundant hard disk=%ld\n\n",ftell(fp2));
      fclose(fp1);
      fclose(fp2);
      return ;
  }
  void raid01()
 {
     printf("enter filename for mirroring\n");
     scanf("%s",filename);
     fp = fopen(filename, "rb");
     printf("Before striping the size of file=%ld\n",ftell(fp));
     fseek(fp,0,0);
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     printf("\n");
     fp1=fopen("C:/TC/raid/d1/file1.mp3", "wb");
     fp2=fopen("C:/TC/raid/d2/file2.mp3", "wb");
     fp3=fopen("C:/TC/raid/d3/file3.mp3", "wb");
     fp4=fopen("C:/TC/mirrer/d1/mirrer1.mp3", "wb");
     fp5=fopen("C:/TC/mirrer/d2/mirrer2.mp3", "wb");
     fp6=fopen("C:/TC/mirrer/d3/mirrer3.mp3", "wb");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=n;i++)
	   {
	    if((ch=getc(fp))!=EOF){
	    putc(ch,fp4);
	    putc(ch,fp1);}
	   }

	   if(!feof(fp))
	   for(i=1;i<=n;i++)
	   {
	   if((ch=getc(fp))!=EOF){
	    putc(ch,fp2);
	    putc(ch,fp5);   }
	    }

	   if(!feof(fp))
	   for(i=1;i<=n;i++)
	   {
	    if((ch=getc(fp))!=EOF){
	    putc(ch,fp3);
	    putc(ch,fp6);}
	   }

     }while(!feof(fp));
      fseek(fp,0,0);
      fclose(fp);
      printf("Know the size of Original hard disk1=%ld\n\n",ftell(fp1));
      printf("Know the size of Original hard disk2=%ld\n\n",ftell(fp2));
      printf("Know the size of Original hard disk3=%ld\n\n",ftell(fp3));
      printf("Know the size of Redundant hard disk1=%ld\n\n",ftell(fp4));
      printf("Know the size of Redundant hard disk2=%ld\n\n",ftell(fp5));
      printf("Know the size of Redundant hard disk3=%ld\n\n",ftell(fp6));
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
     printf("Before striping the size of file=%ld\n",ftell(fp));
     fseek(fp,0,0);
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     printf("\n");
     fp1=fopen("C:/TC/raid/d1/file1.mp3", "wb");
     fp2=fopen("C:/TC/raid/d2/file2.mp3", "wb");
     fp3=fopen("C:/TC/raid/d3/file3.mp3", "wb");
     fp4=fopen("C:/TC/mirrer/d1/mirrer1.mp3", "wb");
     fp5=fopen("C:/TC/mirrer/d2/mirrer2.mp3", "wb");
     fp6=fopen("C:/TC/mirrer/d3/mirrer3.mp3", "wb");
     do
     {
	    if(!feof(fp))
	   for(i=1;i<=n;i++)
	   {
	    if((ch=getc(fp))!=EOF){
	    putc(ch,fp4);
	    putc(ch,fp1);}
	   }

	   if(!feof(fp))
	   for(i=1;i<=n;i++)
	   {
	   if((ch=getc(fp))!=EOF){
	    putc(ch,fp2);
	    putc(ch,fp5);   }
	    }

	   if(!feof(fp))
	   for(i=1;i<=16;i++)
	   {
	    if((ch=getc(fp))!=EOF){
	    putc(ch,fp3);
	    putc(ch,fp6);}
	   }

	    }while(!feof(fp));
      fseek(fp,0,0);
      fclose(fp);
      printf("Know the size of Original hard disk1=%ld\n\n",ftell(fp1));
      printf("Know the size of Original hard disk2=%ld\n\n",ftell(fp2));
      printf("Know the size of Original hard disk3=%ld\n\n",ftell(fp3));
      printf("Know the size of Redundant hard disk1=%ld\n\n",ftell(fp4));
      printf("Know the size of Redundant hard disk2=%ld\n\n",ftell(fp5));
      printf("Know the size of Redundant hard disk3=%ld\n\n",ftell(fp6));
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
     int j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "wb");
      printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     printf("\n");
     fp1=fopen("C:/TC/raid/d1/file1.mp3","rb");
     fp2=fopen("C:/TC/raid/d2/file2.mp3","rb");
     fp3=fopen("C:/TC/raid/d3/file3.mp3","rb");
 while(!feof(fp1) && !feof(fp2) && !feof(fp3))
 {
     for(j=1;j<=n;j++)
     if((ch=getc(fp1))!=EOF)
     putc(ch,fp);
     printf("hai");
     printf("%ld",ftell(fp));
     return;
     for(j=1;j<=n;j++)
     if((ch=getc(fp2))!=EOF)
     putc(ch,fp);

     for(j=1;j<=n;j++)
     if((ch=getc(fp3))!=EOF)
     putc(ch,fp);
 }
      printf("After reconstruction the size of file=%ld\n",ftell(fp));
      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);

 }
  void Reconstruct2()
 {
     int ch1,j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "wb");
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     if((fp1=fopen("C:/TC/raid/d1/file1.mp3", "rb"))==NULL)
     {
	printf("Original Hard disk has missed so i m using mirrored disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/raid/mirror/mirrer1.mp3", "rb");
     }
	  while(!feof(fp1))
	  {
		if((ch=getc(fp1))!=EOF)
		  putc(ch,fp);
	  }
      printf("After reconstruction the size of file=%ld\n",ftell(fp));
      fclose(fp);
      fclose(fp1);
 }

 void Reconstruct3()
 {
     int j;
     printf("enter filename to be reconstructed\n");
     scanf("%s",filename);
     fp = fopen(filename, "wb");
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     if((fp1=fopen("C:/TC/raid/d1/file1.mp3", "rb"))==NULL)
     {
	printf("hard disk1 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/mirrer/d1/mirrer1.mp3", "rb");
      }
    if((fp2=fopen("C:/TC/raid/d2/file2.mp3", "rb"))==NULL)
     {
	printf("hard disk2 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp2);
	fp2=fopen("C:/TC/mirrer/d2/mirrer2.mp3","rb");
     }
     if((fp3=fopen("C:/TC/raid/d3/file3.mp3", "rb"))==NULL)
     {
	printf("hard disk3 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp3);
	fp3=fopen("C:/TC/mirrer/d3/mirrer2.mp3","rb");
     }

 while(!feof(fp1) && !feof(fp2) && !feof(fp3))
 {
     for(j=1;j<=n;j++)
     if((ch=getc(fp1))!=EOF)
     putc(ch,fp);

     for(j=1;j<=n;j++)
     if((ch=getc(fp2))!=EOF)
     putc(ch,fp);

     for(j=1;j<=n;j++)
     if((ch=getc(fp3))!=EOF)
     putc(ch,fp);
 }
      printf("After reconstruction the size of file=%ld\n",ftell(fp));
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
     fp = fopen(filename, "wb");
     printf("enter the chunk to stripe size: ");
     scanf("%ld",&n);
     if((fp1=fopen("C:/TC/raid/d1/file1.mp3", "rb"))==NULL)
     {
	printf("hard disk1 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp1);
	fp1 = fopen("C:/TC/mirrer/d1/mirrer1.mp3", "rb");
      }
    if((fp2=fopen("C:/TC/raid/d2/file2.mp3", "rb"))==NULL)
     {
	printf("hard disk2 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp2);
	fp2=fopen("C:/TC/mirrer/d2/mirrer2.mp3","rb");
     }
     if((fp3=fopen("C:/TC/raid/d3/file3.mp3", "rb"))==NULL)
     {
	printf("hard disk3 has missed so i m using mirred disk to reconstruct file\n");
	fclose(fp3);
	fp3=fopen("C:/TC/mirrer/d3/mirrer2.mp3","rb");
     }

 do
 {
     for(j=1;j<=n;j++)
     if((ch=getc(fp1))!=EOF)
     putc(ch,fp);

     for(j=1;j<=n;j++)
     if((ch=getc(fp2))!=EOF)
     putc(ch,fp);

     for(j=1;j<=n;j++)
     if((ch=getc(fp3))!=EOF)
     putc(ch,fp);

 }while(!feof(fp1) && !feof(fp2) && !feof(fp3));
       printf("After reconstruction the size of file=%ld\n",ftell(fp));
      fclose(fp);
      fclose(fp1);
      fclose(fp2);
      fclose(fp3);
 }

void main()
{
     clrscr();
/*   for(;;)
   {
     printf("1:Text file(.txt) \n\n 2:Audio file(.mp3)\n\n 3:Video file 4:For exit press any key\n");
     printf("enter choice:");
     scanf("%d",&choice);
     printf("\n");
     switch(choice)
     {
     case 1:

     case 2:
     case 3:
     case 4:
     default:return;
     }
   }                */
     for(;;){
     printf("************************************************************\n");
     printf(" 1:stripe the file(RAID 0)\n\n 2:Miraring of the file(RAID 1) \n\n 3:RAID 0+1:Mirrored stripes \n\n 4:RAID 10:Striped mirrors\n\n 5:Reconstruct the striped file\n\n 6:Reconstuct the mirrared file \n\n 7:Reconstruct from RAID 0+1 \n\n 8:Reconstruct from RAID 10\n\n 9:for Exit press key\n\n ");
     printf("************************************************************\n");
     printf("Enter the choice:");
     scanf("%d",&choice);
     printf("\n");
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
      default: return;
     }
     }
     getch();
}


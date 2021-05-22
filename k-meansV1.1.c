#include<stdio.h>

struct veriSeti
{
	char koyler[15];
	int nufuz;
	char kumeK[15];
	int kumeN;
}veri[30],kume[30];

void veriCek();
void kumeOlustur();
void altKumeVerisiAl();
void ustKumeVerisiAl();
void ustKumeYazdir();
void altKumeYazdir();

int a,i,j,sizeVeri,temp,sizeTemp,sizeTemp2,enUzun,sonuc1,sonuc2,baraj=5000;

main()
{
	
	veriCek();
	kumeOlustur();
	printf("Belediye olabilecek ve olamayacak koyler\n\n");
	printf("Baraj siniri: %d\n",baraj);
	printf("Belediye olabilecek koyler ilk kume sirasi:\n");
	ustKumeYazdir();
	printf("Belediye olamayacak koyler ilk kume sirasi:\n");
	altKumeYazdir();
	
	int t=0;
	while(t!=1)
	{
	  veriCek();
      kumeOlustur();
	  altKumeVerisiAl();
	  ustKumeVerisiAl();
	  baraj=(sonuc1+sonuc2)/2;
	  printf("Ara barajlar(ortalamalar): %d\n",baraj);
	  if(temp==baraj)
	  {
	  	t=1;
	  	printf("Baraj siniri(ortalama) esit oldu\n");
	  	printf("\nBaraj siniri: %d\n",baraj);
	  	printf("Belediye olabilecek koylerin k-means ile siralandiktan sonraki sirasi:\n");
	  	ustKumeYazdir();
	  	printf("Belediye olamayacak koylerin k-means ile siralandiktan sonraki sirasi:\n");
	    altKumeYazdir();
	  }
	  else
	  {
	  	temp=baraj;
	  }
	}	
}
//-----------------------------------------------------------------------------------------------
void veriCek()
{
	FILE *file;
	if ((file = fopen("veri_seti.txt", "r")) == NULL) 
    {
        return -1; 
    }
    int a=0;
    while(!feof(file))
    {
    	fscanf(file,"%s%d",&veri[a].koyler,&veri[a].nufuz);
        a++;
	}
	sizeVeri=a-1;
	fclose(file);	
	return 0;
}
//-----------------------------------------------------------------------------------------------
void kumeOlustur()
{
	int a=0;
	FILE *yazdir,*yazdir2;
    yazdir=fopen("nufuz_baraj_alti.txt","w");
    yazdir2=fopen("nufuz_baraj_ustu.txt","w");
	for(i=0;i<sizeVeri;i++)
	{
		if(veri[a].nufuz<baraj)
    	{
    		fprintf(yazdir,"%s %d\n",veri[i].koyler,veri[i].nufuz);
    		a++;
		}
		else if(veri[a].nufuz>=baraj)
		{
    		fprintf(yazdir2,"%s %d\n",veri[i].koyler,veri[i].nufuz);
    		a++;
		}
	}
	fclose(yazdir);
	fclose(yazdir2);
	return 0;
}
//-----------------------------------------------------------------------------------------------
void altKumeVerisiAl()
{
	FILE *file;
	if ((file = fopen("nufuz_baraj_alti.txt", "r")) == NULL) 
    {
        return -1; 
    }
    int a=0,toplam=0;
    while(!feof(file))
    {
    	fscanf(file,"%s%d",&kume[a].kumeK,&kume[a].kumeN);
        a++;
	}
	fclose(file);
	for(i=0;i<(a-1);i++)
	{
		toplam=toplam+kume[i].kumeN;
	}
	sonuc2=toplam/(a-1);
}
//-----------------------------------------------------------------------------------------------
void ustKumeVerisiAl()
{
	FILE *file;
	if ((file = fopen("nufuz_baraj_ustu.txt", "r")) == NULL) 
    {
        return -1; 
    }
    int a=0,toplam=0;
    while(!feof(file))
    {
    	fscanf(file,"%s%d",&kume[a].kumeK,&kume[a].kumeN);
        a++;
	}
	fclose(file);
	for(i=0;i<(a-1);i++)
	{
		toplam=toplam+kume[i].kumeN;
	}
	sonuc1=toplam/(a-1);
}

//-----------------------------------------------------------------------------------------------
void ustKumeYazdir()
{
	FILE *file;
	if ((file = fopen("nufuz_baraj_ustu.txt", "r")) == NULL) 
    {
        return -1; 
    }
    int a=0;
    while(!feof(file))
    {
    	fscanf(file,"%s%d",&kume[a].kumeK,&kume[a].kumeN);
        a++;
	}
	fclose(file);
	for(i=0;i<(a-1);i++)
	{
		sizeTemp=strlen(kume[i].kumeK);
		if(sizeTemp>enUzun)
		{
			enUzun=sizeTemp;
		}
	}
	for(i=0;i<(a-1);i++)
	{
		printf("%d    ",i+1,kume[i].kumeK);
		if(i<9)
		{
			printf(" ");
		}
		printf("%s  ",kume[i].kumeK);
		sizeTemp=strlen(kume[i].kumeK);
		for(j=0;j<(enUzun-sizeTemp);j++)
		{
			printf(" ");
		}
		printf("Nufuz-->%d\n",kume[i].kumeN);
	}
    printf("\n**************************************************\n\n");
}
//-----------------------------------------------------------------------------------------------
void altKumeYazdir()
{
	FILE *file;
	if ((file = fopen("nufuz_baraj_alti.txt", "r")) == NULL) 
    {
        return -1; 
    }
    int a=0;
    while(!feof(file))
    {
    	fscanf(file,"%s%d",&kume[a].kumeK,&kume[a].kumeN);
        a++;
	}
	fclose(file);
	for(i=0;i<(a-1);i++)
	{
		sizeTemp=strlen(kume[i].kumeK);
		if(sizeTemp>enUzun)
		{
			enUzun=sizeTemp;
		}
	}
	for(i=0;i<(a-1);i++)
	{
		printf("%d    ",i+1,kume[i].kumeK);
		if(i<9)
		{
			printf(" ");
		}
		printf("%s  ",kume[i].kumeK);
		sizeTemp=strlen(kume[i].kumeK);
		for(j=0;j<(enUzun-sizeTemp);j++)
		{
			printf(" ");
		}
		printf("Nufuz-->%d\n",kume[i].kumeN);
	}
    printf("\n**************************************************\n\n");
}


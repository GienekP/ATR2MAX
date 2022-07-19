/*--------------------------------------------------------------------*/
/* SectorMap                                                          */
/* by GienekP                                                         */
/* (c) 2022                                                           */
/*--------------------------------------------------------------------*/
#include <stdio.h>
/*--------------------------------------------------------------------*/
#define SECSIZE128 128
#define SECSIZE256 256
#define PROCSIZE128 256
#define PROCSIZE256 256
/*--------------------------------------------------------------------*/
const unsigned char maxpos128=((8192-PROCSIZE128)/SECSIZE128);
const unsigned int maxsec128=((8192-PROCSIZE128)*((512-1)*1024/8192)/SECSIZE128)-200;
const unsigned char maxpos256=((8192-PROCSIZE256)/SECSIZE256);
const unsigned int maxsec256=((8192-PROCSIZE256)*((512-1)*1024/8192)/SECSIZE256);
/*--------------------------------------------------------------------*/
int main( int argc, char* argv[] )
{	
	int i;
	unsigned char bank=1;
	unsigned char pos=0;
	FILE *pf;
	printf("SectorMap-128 Generator\nMax Disk Size: %ibytes (%i sectors)\n",maxsec128*SECSIZE128,maxsec128);
	pf=fopen("SectorMap128.dta","wb");
	if (pf)
	{
		printf("Build SectorMap128.dta\n");
		fputc(0xFF,pf);
		fputc(0xFF,pf);
		for (i=1; i<=maxsec128; i++)
		{
			putc(bank,pf);
			putc(pos,pf);
			printf("Sector: %i -> Side: %X Bank: %X  Pos: %02X ($%04X 0x%05X)\n",i,(bank>>4)&3,bank&15,pos,SECSIZE128*pos+0xA000,bank*8192+SECSIZE128*pos);
			pos++;
			if (pos==maxpos128)
			{
				pos=0;
				bank++;
				bank&=0x3F;
			};
		};	
		fclose(pf);
	};
	bank=1;
	pos=0;
	printf("SectorMap-256 Generator\nMax Disk Size: %ibytes (%i sectors)\n",maxsec256*SECSIZE256,maxsec256);
	pf=fopen("SectorMap256.dta","wb");
	if (pf)
	{
		printf("Build SectorMap256.dta\n");
		fputc(0xFF,pf);
		fputc(0xFF,pf);
		for (i=1; i<=maxsec256; i++)
		{
			putc(bank,pf);
			putc(pos,pf);
			printf("Sector: %i -> Side: %X Bank: %X  Pos: %02X ($%04X 0x%05X)\n",i,(bank>>4)&3,bank&15,pos,SECSIZE256*pos+0xA000,bank*8192+SECSIZE256*pos);
			pos++;
			if (pos==maxpos256)
			{
				pos=0;
				bank++;
				bank&=0x3F;
			};
		};	
		fclose(pf);
	};
	printf("\n");
	return 0;
}
/*--------------------------------------------------------------------*/

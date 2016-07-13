// timestamp.cpp : Outputs timestamps and incremental build numbers
// Author: kuro68k

//#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	bool unix_time = false;
	bool define_str = false;
	bool build_num = false;
	int bn = 0;
	
	// parse command line
	for (int a = 1; a < argc; a++)
	{
		//printf("%s\n", argv[a]);
		if (strcmp(argv[a], "-d") == 0)
			define_str = true;
		else if (strcmp(argv[a], "-u") == 0)
			unix_time = true;
		else if (strcmp(argv[a], "-b") == 0)
			build_num = true;
		else
		{
			printf("Unknown parameter: \"%s\"\n", argv[a]);
			return 1;
		}
	}

	// find and increment build number
	if (build_num)
	{
		FILE *fp = fopen("buildnum.txt", "r");
		if (fp == NULL)
		{
			printf("Could not open buildnum.txt for reading\n");
		}
		else
		{
			char line[256];
			fgets(line, sizeof line, fp);
			fclose(fp);
			bn = atoi(line);
		}
		
		bn++;

		fp = fopen("buildnum.txt", "w");
		if (fp == NULL)
		{
			printf("Could not open buildnum.txt for writing\n");
			return 1;
		}
		fprintf(fp, "%d", bn);
		fclose(fp);
	}

	if (define_str)
	{
		if (!unix_time)
			printf("// seconds since 2000/01/01 00:00:00\n");
		else
			printf("// seconds since 1970/01/01 00:00:00\n");
	}

	__time64_t t = _time64(NULL);
	if (!unix_time)
		t -= 946684800;		// convert from Unix epoch to 1/1/2000 epoch
	if (define_str)
		printf("#define BUILD_TIME\t");
	
	printf("%ld\n", t);

	if (build_num)
	{
		if (define_str)
			printf("#define BUILD_NUMBER\t");
		printf("%d\n", bn);
	}

	return 0;
}


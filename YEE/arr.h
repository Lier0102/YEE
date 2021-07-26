#ifndef __YEE
#define __YEE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define VERSION "v.1.2.7"

typedef struct _arrayList {
	int* arr;
	int size;
	int maxSize;
} arrayList;

void init();
int sizeup();
void print();
int add(int idx, int v);
int addfirst(int v);
int addlast(int v);

//나머지 함수 미국갔어!!
//바부야 미국이 아니라 호주겠지!!

#endif
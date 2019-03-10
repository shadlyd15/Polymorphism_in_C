#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "debug.h"

typedef struct A_t{
	char name[64];
}A_t;

typedef struct B_t{
	char name[64];
	int data;
}B_t;

typedef struct Abstruct_t{
	char name[64];
}Abstruct_t;

typedef union{
	A_t A;
	B_t B;
	Abstruct_t abstruct;
} abstract_interface_t;

int main(int argc, char const *argv[]){
	DEBUG_OK("Polymorphic Interface Test In C");
	
	A_t A = {0};
	memcpy(A.name, "A", strlen("A"));
	
	B_t B = {0};
	B.data = 100;
	memcpy(B.name, "B", strlen("B"));

	abstract_interface_t abstract_interface = {0};
	memcpy(abstract_interface.abstruct.name, "abstract_interface", strlen("abstract_interface"));
	
	DEBUG_OK("A : %s", A.name);
	DEBUG_OK("B : %s", B.name);
	DEBUG_OK("B.data : %d", B.data);
	DEBUG_OK("abstract_interface : %s", abstract_interface.abstruct.name);
	return 0;
}
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

typedef struct abstract_t{ // Virtual Struct
	char name[64];
}abstract_t;

typedef union{
	A_t A;
	B_t B;
	abstract_t abstract;
} abstract_interface_t;

void print_abstract_name(abstract_t * abs){
	DEBUG_OK("Polymorphic Name : %s", abs->name);
}

int main(int argc, char const *argv[]){
	DEBUG_OK("Polymorphic Interface Test In C");
	
	A_t A = {0};
	memcpy(A.name, "A", strlen("A"));
	
	B_t B = {0};
	B.data = 100;
	memcpy(B.name, "B", strlen("B"));

	abstract_interface_t * abstract_interface = NULL;


	DEBUG_OK("A : %s", A.name);
	abstract_interface = &A;
	print_abstract_name(abstract_interface);
	
	
	DEBUG_OK("B : %s", B.name);
	abstract_interface = &B;
	print_abstract_name(abstract_interface);
	return 0;
}
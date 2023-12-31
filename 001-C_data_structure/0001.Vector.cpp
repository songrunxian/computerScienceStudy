#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Vector{
	int *data;		//存储数据类型
	int size, length;	//size Vector总长，length当前长度
} Vector;

Vector *init(int n) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	vec->data = (int *)malloc(sizeof(int)*n);
	vec->size = n;
	vec->length = 0;
	return vec;
}

void clear(Vector *vec){
	if(vec == NULL) return;
	free(vec->data);
	free(vec);
	return ;
}

int expand(Vector *vec) {
	int extr_size = vec->size;
	int *p;
	while(extr_size) {
		//这样是防止内存泄漏，要理解realloc的原理
		p = (int *)realloc(vec->data, sizeof(int)*(vec->size + extr_size));
		if(p) break;
		extr_size /= 2;
	}
	if(p == NULL) return 0;
	vec->data = p;
	vec->size += extr_size;
	return 1;
}

int insert(Vector *vec, int ind, int val) {
	if(vec == NULL) return 0;
	if(ind < 0 || ind > vec->length) return 0;
	if(vec->length == vec->size) {
		if(!expand(vec)) return 0;
		printf("expand successfully ! size = %d\n", vec-> size);
	};
	for(int i = vec->length; i > ind; i--) {
		vec->data[i] = vec->data[i-1];
	}
	vec->data[ind] = val;
	vec->length += 1;
	return 1;
}

int erase(Vector *vec, int ind) {
	if(vec == NULL) return 0;
	if(ind < 0 || ind >= vec->length) return 0;
	for(int i = ind + 1; i < vec->length; i++) {
		vec->data[i-1] = vec->data[i];
	}
	vec->length -= 1;
	return 1;
}

void output(Vector *vec) {
	printf("Vector(%d) = [", vec->length);
	for(int i = 0; i < vec->length; i++) {
		i && printf(", ");	//这是if的变型
		printf("%d", vec->data[i]);
	}
	printf("]\n");
	return ;
}

int main() {
	srand(time(0));
	#define max_op 10
	Vector *vec = init(3);
	int op, ind, val;
	for(int i = 0; i < max_op; i++) {
		op = rand() % 2;	//设计了2种操作，那就%2，0是一种操作，1是另外一种操作
		//ind = rand() %(vec->length + 1);	// + 1 是因为，最开始length 是0,这样生成的永远是正确的索引，调试要求是生成真正的随机数
		ind = rand() %(vec->length + 3) -1; //这样可以生成负数索引
		val = rand() % 100;
		switch(op) {
			case 0: 
			case 1: 
			case 2: {
				printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
			} break;
			case 3: {
				printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));
			} break;
		}
		output(vec);
		printf("\n");
	}
	clear(vec);
	return 0;
}

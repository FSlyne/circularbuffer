#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"

void dummyfn () {
    printf("Hello\n");
}

int main() {
void (*func_ptr)();
struct wbuffer *st = NULL, *en = NULL;

//char value[BUFSIZE];

for (int key=0; key<10; key++) {
   wrpush(&st,&en,dummyfn, key);
//   rpop(&st,&en, value,&size);
//   printf("%s\n",value);
}

int find = wexist(&st, &en, 27);

if (find > 0) printf("Found\n");

for (int key=0; key<10; key++) {
    wsearch(&st,&en, &func_ptr, key);
    if (func_ptr != NULL) {
        (*func_ptr)();
    }
}

//printf("%s\n",value);

printstack(st);

}

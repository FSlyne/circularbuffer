#define BUFSIZE 2000

struct cbuffer
{
    char data[BUFSIZE];
    int size;
    int key;
    struct cbuffer *next;
    struct cbuffer *prev;
};

// http://blog.olkie.com/2013/11/05/online-c-function-prototype-header-generator-tool/
void clear(struct cbuffer **st, struct cbuffer **en);
void lpop(struct cbuffer **st, struct cbuffer **en, char value[], int *size);
void lpush(struct cbuffer **st, struct cbuffer **en, char value[], int size);
void printstack(struct cbuffer *st);
void rpop(struct cbuffer **st, struct cbuffer **en, char value[], int *size);
void rpush(struct cbuffer **st, struct cbuffer **en, char value[], int size);
void insert(struct cbuffer **st, struct cbuffer **en, char value[], int size, int key);


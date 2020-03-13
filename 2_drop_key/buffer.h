
struct wbuffer
{
    void (*func_ptr)();
    int key;
    struct wbuffer *next;
    struct wbuffer *prev;
};

// http://blog.olkie.com/2013/11/05/online-c-function-prototype-header-generator-tool/
void printstack(struct wbuffer *st);
void wclear(struct wbuffer **st, struct wbuffer **en);
void wcount(struct wbuffer **st, struct wbuffer **en);
int wexist(struct wbuffer **st, struct wbuffer **en, int key);
void wsearch(struct wbuffer **st, struct wbuffer **en,  void (**func_ptr)(), int key);
void wrpop(struct wbuffer **st, struct wbuffer **en, void (**func_ptr)(), int *key);
void winsert(struct wbuffer **st, struct wbuffer **en,  void(*func_ptr)(), int key);
void wrpush(struct wbuffer **st, struct wbuffer **en, void (*func_ptr)(), int key);
void wlpush(struct wbuffer **st, struct wbuffer **en,   void (*func_ptr)(), int key);

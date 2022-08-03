#define MAX_NAME_LENGTH 50

struct Widget
{
    char name[MAX_NAME_LENGTH];
    int x;
    int y;
    char label[MAX_NAME_LENGTH];
    Widget *prev;
    Widget *next;
    void (*action)(void);
};
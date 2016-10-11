
#include "lib.h"

class Bar
{
public:
    void bar() { printf("bar\n"); }
};

int main()
{
    Bar b;
    Foo f(b);

    f.bar();
}

#include "Object.h"
#include "ObjectData.h"

void main()
{
    Object o;
    ObjectMap m;
    ObjectData d = { .health = 3.14, .inventory = "hello world!", .flags = HAS_HEALTH | HAS_INVENTORY };

    objset(&o, &d);
    objmap(&m, &o);

    printf("%f\n", *m.health);
    printf("%s\n", *m.inventory);

    objclr(&o);
}

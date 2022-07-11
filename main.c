#include "Object.h"
#include "ObjectData.h"

void main()
{
    ObjectData d = { .health = 3.14, .inventory = "hello world!", .flags = HAS_HEALTH | HAS_INVENTORY };
    Object* o = objnew(&d);
    ObjectMap* m = objmapa(o);

    printf("%f\n", *m->health);
    printf("%s\n", *m->inventory);

    objdel(o);
}

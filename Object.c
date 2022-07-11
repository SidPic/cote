#include "Object.h"
#include "ObjectData.h"
#include <string.h>

#define attrsize( attr )        COTE_SIZEOF_ATTRIBUTE[attr]
#define attroffset_map( attr )  COTE_OFFSETOF_ATTRIBUTE_MAP[attr]
#define attroffset_data( attr ) COTE_OFFSETOF_ATTRIBUTE_DATA[attr]
#define as(type, attr)          *((type*)(attr))

Object* objnew (ObjectData* data) {
    Object* object = (Object*)malloc(sizeof(Object));
    register void*   field       = NULL;
    register int     attr        = 0;
    register size_t  total_size  = 0;

    // counting a total attributes size
    for (;attr < ATTRIBUTES; ++attr)
    {
        if (data->flags & 1u<<attr) total_size += attrsize(attr);
    }

    field = object->attributes = malloc(total_size);

    // copying of the attributes
    for (attr = 0; attr < ATTRIBUTES; ++attr)
    {
        if (data->flags & 1u<<attr) {
            switch (attr) {
            case FRAME:
                as(frame_t, field) = NULL;
                break;
            case ANIMATION:
                as(animation_t, field) = data->animset[0];
                break;
            case INVENTORY:
                as(inventory_t, field) = strdup(data->inventory);
                break;
            default:
                memcpy(
                    field,
                    (void*)data + attroffset_data(attr),
                    attrsize(attr)
                );
            }
            field += attrsize(attr);
        }
    }

    object->data = data;
    object->flags = data->flags | OBJ_TO_FREE;
    return object;
}

ObjectMap* objsetmap (ObjectMap* map, Object* object) {
    register int   attr  = 0;
    register void* field = object->attributes;

    for (; attr < ATTRIBUTES; ++attr)
    {
        if (object->flags & 1u<<attr) {
            as(void*, (void*)map + attroffset_map(attr)) = field;
            field += attrsize(attr);
        } else {
            as(void*, (void*)map + attroffset_map(attr)) = NULL;
        }
    }
    return map;
}

inline ObjectMap* objmap (Object* object) {
    return objsetmap(malloc(sizeof(ObjectMap)),object);
}

/* the objmapa implemented with #define in Object.h */

void objdel (Object* object) {
    if (object->flags & HAS_INVENTORY) {
        register int   attr   = 0;
        register void* field  = object->attributes;

        for (;attr < INVENTORY; ++attr)
        {
            if (object->flags & 1u<<attr) {
                field += attrsize(attr);
            }
        }

        free(as(inventory_t, field));
    }

    free(object->attributes);

    if (object->flags & OBJ_TO_FREE) free(object);
}

const size_t COTE_SIZEOF_ATTRIBUTE[ATTRIBUTES] = {
    [ARMOR]     = sizeof(armor_t),
    [HEALTH]    = sizeof(health_t),
    [DAMAGE]    = sizeof(damage_t),
    [SPEED]     = sizeof(speed_t),
    [DIRECTION] = sizeof(direction_t),
    [COLLISION] = sizeof(collision_t),
    [BEHAVIOR]  = sizeof(behavior_t),
    [ATTACK]    = sizeof(attack_t),
    [INVENTORY] = sizeof(inventory_t),
    [FRAME]     = sizeof(frame_t),
    [ANIMATION] = sizeof(animation_t),
};

const ptrdiff_t COTE_OFFSETOF_ATTRIBUTE_MAP[ATTRIBUTES] = {
    [ARMOR]     = offsetof(ObjectMap,armor),
    [HEALTH]    = offsetof(ObjectMap,health),
    [DAMAGE]    = offsetof(ObjectMap,damage),
    [SPEED]     = offsetof(ObjectMap,speed),
    [DIRECTION] = offsetof(ObjectMap,direction),
    [COLLISION] = offsetof(ObjectMap,collision),
    [BEHAVIOR]  = offsetof(ObjectMap,behavior),
    [ATTACK]    = offsetof(ObjectMap,attack),
    [INVENTORY] = offsetof(ObjectMap,inventory),
    [FRAME]     = offsetof(ObjectMap,frame),
    [ANIMATION] = offsetof(ObjectMap,animation),
};

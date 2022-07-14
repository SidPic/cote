#ifndef COTE_OBJECT_H
#define COTE_OBJECT_H

#include "types.h"
#include <stddef.h>
#include <assert.h>

struct Object {
    void* attributes;
    unsigned   flags;
    ObjectData* data;
};

/* sets Object attributes & flags from ObjectData */
Object*    objset (Object*, ObjectData*);
/* bind ObjectMap to Object */
ObjectMap* objmap (ObjectMap*, Object*);
/* clear  the Object attributes & attributes flags*/
void       objclr (Object*);

/* implementation of direct access to Object attributes */
struct ObjectMap {
    armor_t*     armor;
    health_t*    health;
    damage_t*    damage;
    speed_t*     speed;
    direction_t* direction;
    collision_t* collision;
    behavior_t*  behavior;
    attack_t*    attack;
    inventory_t* inventory;
    frame_t*     frame;
    animation_t* animation;
};

enum /* Attributes & Flags */ {
    ARMOR       =0,  HAS_ARMOR      =1u<<0,
    HEALTH      =1,  HAS_HEALTH     =1u<<1,
    DAMAGE      =2,  HAS_DAMAGE     =1u<<2,
    SPEED       =3,  HAS_SPEED      =1u<<3,
    DIRECTION   =4,  HAS_DIRECTION  =1u<<4,
    COLLISION   =5,  HAS_COLLISION  =1u<<5,
    BEHAVIOR    =6,  HAS_BEHAVIOR   =1u<<6,
    ATTACK      =7,  HAS_ATTACK     =1u<<7,
    INVENTORY   =8,  HAS_INVENTORY  =1u<<8,
    FRAME       =9,  HAS_FRAME      =1u<<9,
    ANIMATION   =10, HAS_ANIMATION  =1u<<10,
    // counter       // begin of custom flags
    ATTRIBUTES  =11, CUSTOM_FLAG    =1u<<11,
};

extern const size_t    COTE_SIZEOF_ATTRIBUTE      [ATTRIBUTES];
extern const ptrdiff_t COTE_OFFSETOF_ATTRIBUTE_MAP[ATTRIBUTES];

#endif /*!COTE_OBJECT_H*/

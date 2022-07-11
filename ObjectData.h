#ifndef COTE_OBJECTDATA_H
#define COTE_OBJECTDATA_H

#include "types.h"

struct ObjectData {
    const char* name;

    armor_t     armor;
    health_t    health;
    damage_t    damage;
    speed_t     speed;
    direction_t direction;
    collision_t collision;
    behavior_t  behavior;
    attack_t    attack;
    inventory_t inventory;
    texture_t   texture;
    animset_t   animset;

    unsigned flags;
};

int loadObjectData (ObjectData*, const char* filename);

extern const ptrdiff_t COTE_OFFSETOF_ATTRIBUTE_DATA[ATTRIBUTES];

#endif /*!COTE_OBJECTDATA_H*/

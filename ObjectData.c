#include "Object.h"
#include "ObjectData.h"

const ptrdiff_t COTE_OFFSETOF_ATTRIBUTE_DATA[ATTRIBUTES] = {
    [ARMOR]     = offsetof(ObjectData,armor),
    [HEALTH]    = offsetof(ObjectData,health),
    [DAMAGE]    = offsetof(ObjectData,damage),
    [SPEED]     = offsetof(ObjectData,speed),
    [DIRECTION] = offsetof(ObjectData,direction),
    [COLLISION] = offsetof(ObjectData,collision),
    [BEHAVIOR]  = offsetof(ObjectData,behavior),
    [ATTACK]    = offsetof(ObjectData,attack),
    [INVENTORY] = offsetof(ObjectData,inventory),
    [FRAME]     = offsetof(ObjectData,texture),
    [ANIMATION] = offsetof(ObjectData,animset),
};

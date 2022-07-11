#ifndef COTE_TYPES_H
#define COTE_TYPES_H

#include <SDL2/SDL.h>

typedef struct Object Object;
typedef struct ObjectMap ObjectMap;
typedef struct ObjectData ObjectData;
typedef struct TileMap TileMap;

typedef float armor_t;
typedef float health_t;
typedef float damage_t;
typedef float speed_t;
typedef float direction_t;

typedef void (*collision_t) (ObjectMap*,TileMap*);
typedef void (*behavior_t) (ObjectMap*,TileMap*);
typedef void (*attack_t) (ObjectMap*,TileMap*);

typedef char* inventory_t;

typedef SDL_Rect* frame_t;
typedef SDL_Rect* animation_t;

typedef SDL_Texture* texture_t;
typedef SDL_Rect** animset_t;


#endif /*!COTE_TYPES_H*/

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <stdlib.h>
#include <sys/time.h>

static int lua_time_now(lua_State *L);

static const luaL_reg lua_utils_misc[] = {
        {"time_now", lua_time_now},
        {NULL, NULL}
};

LUALIB_API int luaopen_utils_misc (lua_State *L) {
  luaL_register(L, "utils_misc", lua_utils_misc);
  return 1;
}

static int lua_time_now(lua_State *L)
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    int us = tp.tv_usec;
    int s  = tp.tv_sec;

    lua_pushinteger(L, s);
    lua_pushinteger(L, us);

    return 2;
}

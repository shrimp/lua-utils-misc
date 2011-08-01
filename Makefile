# change these to reflect your Lua installation
LUA= /usr
LUAINC= $(LUA)/include
LUALIB= $(LUA)/lib
LUABIN= $(LUA)/bin

# no need to change anything below here
CFLAGS= $(INCS) $(DEFS) $(WARN) -O2 -fPIC
WARN= -Wall
INCS= -I$(LUAINC)

OBJS= lua_utils_misc.o

SOS= utils_misc.so

all: $(SOS)

$(SOS): $(OBJS)
	$(CC) -o $@ -shared $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS) $(SOS)

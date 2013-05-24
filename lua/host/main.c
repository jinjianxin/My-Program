#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <iostream>


void report_errors(lua_State *L,int status)
{
	if(status !=0)
	{
		std::cout<<"--  "<<lua_tostring(L,-1)<<std::endl;
		lua_pop(L,1);
	}
}

int my_function(lua_State *L)
{
	int argc = lua_gettop(L);
	std::cout<<"-- my_function() called with"<<argc<<"argument"<<std::endl;
	
	std::cout<<"argc = "<<argc<<std::endl;

	for(int n = 1;n<= argc;++n)
	{
		std::cout<<"-- argument :"<<n<<" "<<lua_tostring(L,n)<<std::endl;
	}

	lua_pushnumber(L,123);
	return 1;
}

int main(int argc,char *argv[])
{
/*	lua_State *L = lua_open();
	lua_close(L);
	return 0;*/


	for(int i = 1;i<argc;++i)
	{
		const char *file = argv[i];

		lua_State *L = lua_open();
		
		luaL_openlibs(L);
		//luaopen_io(L);
		luaopen_base(L);
		luaopen_table(L);
		luaopen_string(L);
		luaopen_math(L);
//luaopen_loadlib(L);

	    lua_register(L,"my_function",my_function);

		std::cout<<"---- Loading file:"<<file<<std::endl;
		int s = luaL_loadfile(L,file);
		if(s ==0)
		{
			s = lua_pcall(L,0,LUA_MULTRET,0);
		}
		
		report_errors(L,s);
		lua_close(L);
		std::cout<<std::endl;
	
	}

	return 0;
}

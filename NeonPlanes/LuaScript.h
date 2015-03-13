#pragma once

#include "core.h"

class LuaScript
{
public:
	LuaScript(const std::string& filename) {
		L = luaL_newstate();
		luaL_openlibs(L);
		if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0)) {
			std::cerr << "script not loaded (" << filename << ")" << std::endl;
			L = 0;
		}
	}

	virtual ~LuaScript() {
		if (L) lua_close(L);
	}

	void printError(const std::string& variableName, const std::string& reason) {
		std::cerr << "can't get [" << variableName << "]. " << reason << std::endl;
	}

	template<typename T>
	T get(const std::string& variableName) {
		if (!L) {
			printError(variableName, "Script is not loaded");
			return lua_getdefault<T>();
		}

		T result;
		if (lua_gettostack(variableName)) { // variable succesfully on top of stack
			result = lua_get<T>(variableName);
		}
		else {
			result = lua_getdefault<T>();
		}

		lua_pop(L, level + 1); // pop all existing elements from stack
		return result;
	}

	bool lua_gettostack(const std::string& variableName) {
		level = 0;
		std::string var = "";
		for (unsigned int i = 0; i < variableName.size(); i++) {
			if (variableName.at(i) == '.') {
				if (level == 0) {
					lua_getglobal(L, var.c_str());
				}
				else {
					lua_getfield(L, -1, var.c_str());
				}

				if (lua_isnil(L, -1)) {
					printError(variableName, var + " is not defined");
					return false;
				}
				else {
					var = "";
					level++;
				}
			}
			else {
				var += variableName.at(i);
			}
		}
		if (level == 0) {
			lua_getglobal(L, var.c_str());
		}
		else {
			lua_getfield(L, -1, var.c_str());
		}
		if (lua_isnil(L, -1)) {
			printError(variableName, var + " is not defined");
			return false;
		}

		return true;
	}

	template <typename T>
	T lua_get(const std::string& variableName) {
		return 0;
	}

	template <>
	inline bool LuaScript::lua_get(const std::string& variableName) {
		return (bool)lua_toboolean(L, -1);
	}

	template <>
	inline float LuaScript::lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			printError(variableName, "Not a number");
		}
		return (float)lua_tonumber(L, -1);
	}

	template <>
	inline int LuaScript::lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			printError(variableName, "Not a number");
		}
		return (int)lua_tonumber(L, -1);
	}

	template <>
	inline std::string LuaScript::lua_get(const std::string& variableName) {
		std::string s = "null";
		if (lua_isstring(L, -1)) {
			s = std::string(lua_tostring(L, -1));
		}
		else {
			printError(variableName, "Not a string");
		}
		return s;
	}

	template <typename T>
	T lua_getdefault() {
		return 0;
	}

	template<>
	inline std::string LuaScript::lua_getdefault() {
		return "null";
	}

	void clean() {
		int n = lua_gettop(L);
		lua_pop(L, n);
	}

	std::vector<int> LuaScript::getIntVector(const std::string& name) {
		std::vector<int> v;
		lua_getglobal(L, name.c_str());
		if (lua_isnil(L, -1)) {
			return std::vector<int>();
		}
		lua_pushnil(L);
		while (lua_next(L, -2)) {
			v.push_back((int)lua_tonumber(L, -1));
			lua_pop(L, 1);
		}
		clean();
		return v;
	}

	std::vector<std::string> LuaScript::getTableKeys(const std::string& name) {
		std::string code =
			"function getKeys(name)"
			"	s = \"\""
			"	for k, v in pairs(_G[name]) do "
			"		s = s..k..\",\" "
			"	end"
			"	return s"
			"end";

		luaL_loadstring(L, code.c_str());
		lua_pcall(L, 0, 0, 0);
		lua_getglobal(L, "getKeys");
		lua_pushstring(L, name.c_str());
		lua_pcall(L, 1, 1, 0);

		std::string test = lua_tostring(L, -1);
		std::vector<std::string> strings;
		std::string temp = "";
		std::cout << "TEMP: " << test << std::endl;
		for (unsigned int i = 0; i < test.size(); i++) {
			if (test.at(i) != ',') {
				temp += test.at(i);
			}
			else {
				strings.push_back(temp);
				temp = "";
			}
		}
		clean();
		return strings;
	}

	void registerCFunction(int(f)(lua_State* L), std::string nameFunction) {
		lua_pushcfunction(L, f);
		lua_setglobal(L, nameFunction.c_str());
		lua_pcall(L, 0, 0, 0);
	}
private:
	lua_State* L;
	int level;
};

/*
void write(const char* str) {
std::cout<<str<<std::endl;
}

static int l_write(lua_State* L) {
	const char* str = lua_tostring(L, 1); // get function argument
	write(str); // calling C++ function with this argument...
	return 0; // nothing to return!
}

lua_State* L = luaL_newstate();
luaL_openlibs(L); // load default Lua libs
if (luaL_loadfile(L, "test.lua")) {
	std::cout<<"Error loading script"<<std::endl;
}
lua_pushcfunction(L, l_write);
lua_setglobal(L, "write"); // this is how function will be named in Lua
lua_pcall(L, 0, 0, 0); // run script



*/
#pragma once
#include <windows.h>
#include <iostream>

class Vector3
{
public:
	float x;
	float z;
	float y;
};

class Player
{
public:
	char pad_0000[48]; //0x0000
	Vector3 pos; //0x0030
	float yaw; //0x003C
	float pitch; //0x0040
	float roll; //0x0044
	char pad_0048[4]; //0x0048
	int32_t health; //0x004C
	int32_t maxHealth; //0x0050
	char pad_0054[480]; //0x0054
}; //Size: 0x0234

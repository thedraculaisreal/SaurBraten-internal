#pragma once
#include <Windows.h>
#include "reclass.h"
#include "constants.h"


static void console()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stderr);

    std::cout << "Console created" << std::endl;

    while (true)
    {

		std::string input;
        std::cin >> input;

        if (input == "up")
            localPlayer->pos.y += 100;
        if (input == "player")
			std::cout << "Player: " << localPlayer << std::endl;
		if (input == "pos")
			std::cout << "Position: " << localPlayer->pos.x << ", " << localPlayer->pos.y << ", " << localPlayer->pos.z << std::endl;
        if (input == "players")
			std::cout << "Number of players:" << numPlayers << std::endl;
        
    }

	FreeConsole();
}



static BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)console, nullptr, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


#include "retroachievements.h"

HWND g_mainWindow = NULL;
unsigned int g_activeGameId = 0;

bool RA_KnownUtility(const char* name, unsigned int size)
{
    if (!name)
        return false;

    const char* ptr = name;
    while (*ptr)
    {
        if (*ptr++ == '\\')
            name = ptr;
    }

    // built in utilities are all 20 bytes
    if (size == 20)
    {
        return (_stricmp(name, "mount.com") == 0 ||
            _stricmp(name, "mem.com") == 0 ||
            _stricmp(name, "loadfix.com") == 0 ||
            _stricmp(name, "rescan.com") == 0 ||
            _stricmp(name, "intro.com") == 0 ||
            _stricmp(name, "boot.com") == 0 ||
            _stricmp(name, "loadrom.com") == 0 ||
            _stricmp(name, "imgmount.com") == 0 ||
            _stricmp(name, "keyb.com") == 0);
    }

    return false;
}

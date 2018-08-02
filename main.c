#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

#include "plugin.h"

typedef plugin_t *(*LOADPLUGINPROC)();

int main() {
    HMODULE pluginHandle = LoadLibrary("test-plugin.dll");
    if(!pluginHandle) {
        fprintf(stderr, "Failed to load plugin.\r\n");
        return EXIT_FAILURE;
    }

    LOADPLUGINPROC get_plugin = (LOADPLUGINPROC)GetProcAddress(pluginHandle, "get_plugin");
    if(!get_plugin) {
        fprintf(stderr, "Failed to acquire get_plugin.\r\n");

        CloseHandle(pluginHandle);
        return EXIT_FAILURE;
    }

    plugin_t* p = get_plugin();
    if(!p) {
        fprintf(stderr, "get_plugin() returned NULL.\r\n");

        CloseHandle(pluginHandle);
        return EXIT_FAILURE;
    }

    fprintf(stdout, "Calling %s:\r\n", p->pluginName);
    p->on_call(p);

    CloseHandle(pluginHandle);
    return EXIT_SUCCESS;
}

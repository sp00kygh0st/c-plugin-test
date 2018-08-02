#include <stdio.h>
#include <string.h>

#include "plugin.h"

void on_load(plugin_t* p) {}
void on_unload(plugin_t* p) {}
void on_call(plugin_t* p) {
    fprintf(stdout, "Hello world!\r\n");
}

plugin_t* get_plugin() {
    plugin_t* p = (plugin_t *) malloc(sizeof(plugin_t));
    
    p->on_load = &on_load;
    p->on_unload = &on_unload;
    p->on_call = &on_call;

    sprintf_s(p->pluginName, 512, "Hello world");
    sprintf_s(p->pluginDescription, 512, "Prints hello world when invoked");

    return p;
}
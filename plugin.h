#ifndef _PLUGIN_H_
#define _PLUGIN_H_

typedef struct _plugin_t {
    void (*on_load)(struct _plugin_t* p);
    void (*on_unload)(struct _plugin_t* p);
    void (*on_call)(struct _plugin_t *p);

    char pluginName[512];
    char pluginDescription[512];
} plugin_t;

#endif /* _PLUGIN_H_ */
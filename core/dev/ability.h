#include "msg.h"

enum ability_type {
    INPUT,
    OUTPUT,
    INPUT_OUTPUT,
    CONTROL
};

enum ability_state {
    ABILITY_STATE_DISABLED,
    ABILITY_STATE_ENABLED,
    ABILITY_STATE_START,
    ABILITY_STATE_STOP,
    ABILITY_STATE_PAUSE,
    ABILITY_STATE_ERROR
};

struct ability_ops {
    int (*init)(int argc, void *argv[]);
    int (*deinit)(void);
    int (*ctrl)(int cmd, void *arg);
    int (*read)(int cmd, void *arg);
    int (*write)(int cmd, void *arg);
};

struct ability {
    unsigned int id;
    unsigned char priority;
    char name[24];
    char *description;
    char *dependency;
    enum ability_state state;
    enum ability_type type;

    struct msg_srv *msg_srv;
    struct ability_ops *ops;
};

struct ability_node {
    struct ability *ability;
    struct ability_node *next;
    struct ability_node *prev;
};

struct ability_mgr {
    struct ability_node *root;
    unsigned int cnt;
    unsigned int cursor;
};

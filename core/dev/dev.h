#include "ability.h"

enum device_per {
    LEVEL0 = 0,
    LEVEL1,
    LEVEL2,
    LEVEL3
};

enum device_link_type {
    LINK_TYPE_NONE,
    LINK_TYPE_UART,
    LINK_TYPE_IIC,
    LINK_TYPE_SPI,
    LINK_TYPE_TCP,
    LINK_TYPE_UDP
};

enum device_link_state {
    LINK_STATE_ONLINE,
    LINK_STATE_OFFLINE,
    LINK_STATE_PENDING
};

struct device_link_srv {
    enum device_link_type type;
    enum device_link_state state;
    void *link;

    struct device_link_srv *next;
    struct device_link_srv *prev;
};


struct device_link_srvs {
    struct device_link_srv *head;
    int count;
};

struct device_ops {
    int (*band)(int argc, void *argv[]);
    int (*unband)(void);
    int (*ctrl)(int cmd, void *arg);
};

struct device {
    int id;
    char name[24];
    char key[128];
    enum device_per per;

    struct device_link_srvs link_srvs;
    struct ability_mgr ability_mgr;

    struct device_ops *ops;
};

struct deivce_node {
    struct device *dev;
    struct deivce_node *next;
    struct deivce_node *prev;
    struct deivce_node *child;
    struct deivce_node *parent;
};

struct device_mgr {
    struct deivce_node *root;
    unsigned int cnt;
    unsigned int cursor;
};

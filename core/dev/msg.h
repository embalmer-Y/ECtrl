enum msg_q_state {
    MSG_Q_EMPTY,
    MSG_Q_FULL,
    MSG_Q_PARTIAL,
};

struct msg_buff {
    unsigned int len;

    struct {
        unsigned char type:4;
        // features...
    };
    
    struct {
        unsigned char head:1;
        unsigned char end:1;
        struct msg_buff *next;
        struct msg_buff *prev;
    };

    unsigned char *header;
    unsigned char *data;
    unsigned char *tail;
};

struct msg_txq {
    int qcnt;
    int cursor;
    enum msg_q_state state;

    struct msg_buff *msgb;
};

struct msg_rxq {
    int qcnt;
    int cursor;
    enum msg_q_state state;

    struct msg_buff *msgb;
};

struct msg_srv {
    struct msg_txq txq;
    struct msg_rxq rxq;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ability.h"

int ability_init(struct ability *ability)
{
    if (ability == NULL)
        return -1;
    // ...

    return 0;
}

void ability_deinit(struct ability *ability)
{
    if (ability == NULL)
        return;

    free(ability);
    return;
}

int ability_bind(struct ability *ability, struct ability_mgr *mgr)
{
    if (ability == NULL || mgr == NULL)
        return -1;
    // ...

    return 0;
}

int ability_mgr_init(struct ability_mgr *mgr)
{
    if (mgr == NULL)
        return -1;
    // ...

    return 0;
}

void ability_mgr_deinit(struct ability_mgr *mgr)
{
    if (mgr == NULL)
        return;

    // ...

    free(mgr);
    return;
}

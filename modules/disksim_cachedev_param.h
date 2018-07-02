#include <libparam/libparam.h>

#ifndef _DISKSIM_CACHEDEV_PARAM_H
#define _DISKSIM_CACHEDEV_PARAM_H  


/* prototype for disksim_cachedev param loader function */
   struct cache_def *disksim_cachedev_loadparams(struct lp_block *b);

typedef enum {
   DISKSIM_CACHEDEV_CACHE_SIZE,
   DISKSIM_CACHEDEV_MAX_REQUEST_SIZE,
   DISKSIM_CACHEDEV_WRITE_SCHEME,
   DISKSIM_CACHEDEV_FLUSH_POLICY,
   DISKSIM_CACHEDEV_FLUSH_PERIOD,
   DISKSIM_CACHEDEV_FLUSH_IDLE_DELAY,
   DISKSIM_CACHEDEV_CACHE_DEVICE,
   DISKSIM_CACHEDEV_CACHED_DEVICE
} disksim_cachedev_param_t;

#define DISKSIM_CACHEDEV_MAX_PARAM		DISKSIM_CACHEDEV_CACHED_DEVICE


static struct lp_varspec disksim_cachedev_params [] = {
   {"Cache size", I, 1 },
   {"Max request size", I, 1 },
   {"Write scheme", I, 1 },
   {"Flush policy", I, 1 },
   {"Flush period", D, 1 },
   {"Flush idle delay", D, 1 },
   {"Cache device", S, 1 },
   {"Cached device", S, 1 },
   {0,0,0}
};
#define DISKSIM_CACHEDEV_MAX 8
static struct lp_mod disksim_cachedev_mod = { "disksim_cachedev", disksim_cachedev_params, DISKSIM_CACHEDEV_MAX, (lp_modloader_t)disksim_cachedev_loadparams,  0,0 };
#endif // _DISKSIM_CACHEDEV_PARAM_H

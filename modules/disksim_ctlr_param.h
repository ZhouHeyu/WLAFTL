#include <libparam/libparam.h>

#ifndef _DISKSIM_CTLR_PARAM_H
#define _DISKSIM_CTLR_PARAM_H  


/* prototype for disksim_ctlr param loader function */
   struct controller *disksim_ctlr_loadparams(struct lp_block *b);

typedef enum {
   DISKSIM_CTLR_TYPE,
   DISKSIM_CTLR_SCALE_FOR_DELAYS,
   DISKSIM_CTLR_BULK_SECTOR_TRANSFER_TIME,
   DISKSIM_CTLR_MAXIMUM_QUEUE_LENGTH,
   DISKSIM_CTLR_PRINT_STATS,
   DISKSIM_CTLR_SCHEDULER,
   DISKSIM_CTLR_CACHE,
   DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT
} disksim_ctlr_param_t;

#define DISKSIM_CTLR_MAX_PARAM		DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT


static struct lp_varspec disksim_ctlr_params [] = {
   {"type", I, 1 },
   {"Scale for delays", D, 1 },
   {"Bulk sector transfer time", D, 1 },
   {"Maximum queue length", I, 1 },
   {"Print stats", I, 1 },
   {"Scheduler", BLOCK, 0 },
   {"Cache", BLOCK, 0 },
   {"Max per-disk pending count", I, 0 },
   {0,0,0}
};
#define DISKSIM_CTLR_MAX 8
static struct lp_mod disksim_ctlr_mod = { "disksim_ctlr", disksim_ctlr_params, DISKSIM_CTLR_MAX, (lp_modloader_t)disksim_ctlr_loadparams,  0,0 };
#endif // _DISKSIM_CTLR_PARAM_H

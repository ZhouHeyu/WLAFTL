#include <libparam/libparam.h>

#ifndef _DISKSIM_BUS_PARAM_H
#define _DISKSIM_BUS_PARAM_H  


/* prototype for disksim_bus param loader function */
   struct bus *disksim_bus_loadparams(struct lp_block *b, int *num);

typedef enum {
   DISKSIM_BUS_TYPE,
   DISKSIM_BUS_ARBITRATION_TYPE,
   DISKSIM_BUS_ARBITRATION_TIME,
   DISKSIM_BUS_READ_BLOCK_TRANSFER_TIME,
   DISKSIM_BUS_WRITE_BLOCK_TRANSFER_TIME,
   DISKSIM_BUS_PRINT_STATS
} disksim_bus_param_t;

#define DISKSIM_BUS_MAX_PARAM		DISKSIM_BUS_PRINT_STATS


static struct lp_varspec disksim_bus_params [] = {
   {"type", I, 1 },
   {"Arbitration type", I, 1 },
   {"Arbitration time", D, 1 },
   {"Read block transfer time", D, 1 },
   {"Write block transfer time", D, 1 },
   {"Print stats", I, 1 },
   {0,0,0}
};
#define DISKSIM_BUS_MAX 6
static struct lp_mod disksim_bus_mod = { "disksim_bus", disksim_bus_params, DISKSIM_BUS_MAX, (lp_modloader_t)disksim_bus_loadparams,  0,0 };
#endif // _DISKSIM_BUS_PARAM_H

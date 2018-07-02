
#define STACK_MAX 32
{
    int c;
    int needed = 0;
    int param_stack[STACK_MAX];
    int stack_ptr = 0;  // index of first free slot
    BITVECTOR(paramvec, DISKSIM_PF_STATS_MAX_PARAM);
    bit_zero(paramvec, DISKSIM_PF_STATS_MAX_PARAM);

    for(c = 0; c < b->params_len; c++) {
	int pnum;
	int i = 0; 
	double d = 0.0; 
	char *s = 0; 
	struct lp_block *blk = 0;
	struct lp_list *l = 0;
	
	if(!b->params[c]) continue;

TOP:
	pnum = lp_param_name(lp_mod_name("disksim_pf_stats"), b->params[c]->name);

        // don't initialize things more than once
	if(BIT_TEST(paramvec, pnum)) continue;


	if(stack_ptr > 0) {
	    for(c = 0; c < b->params_len; c++) {
	        if(lp_param_name(lp_mod_name("disksim_pf_stats"), b->params[c]->name) == needed)
		    goto FOUND;
            }
	    break;
	}
      FOUND:

	switch(PTYPE(b->params[c])) {
	    case I:  i   = IVAL(b->params[c]); break;
	    case D:  d   = DVAL(b->params[c]); break;
	    case S:  s   = SVAL(b->params[c]); break;
	    case LIST: l = LVAL(b->params[c]); break;
	  default: blk = BVAL(b->params[c]); break;
	}


	switch(pnum) {
case DISKSIM_PF_STATS_PRINT_PER_PROCESS_STATS:
{
if(!(RANGE(i,0,1))) { BADVALMSG(b->params[c]->name); return 0; }
else {
 pf_print_perprocessstats = i;
}
} break;
case DISKSIM_PF_STATS_PRINT_PER_CPU_STATS:
{
if(!(RANGE(i,0,1))) { BADVALMSG(b->params[c]->name); return 0; }
else {
 pf_print_percpustats = i;
}
} break;
case DISKSIM_PF_STATS_PRINT_ALL_INTERRUPT_STATS:
{
if(!(RANGE(i,0,1))) { BADVALMSG(b->params[c]->name); return 0; }
else {
 pf_print_intrstats = i;
}
} break;
case DISKSIM_PF_STATS_PRINT_SLEEP_STATS:
{
if(!(RANGE(i,0,1))) { BADVALMSG(b->params[c]->name); return 0; }
else {
 pf_print_sleepstats = i;
}
} break;
    default: assert(0); break; 
    } /* end of switch */ 
    BIT_SET(paramvec, pnum);
    if(stack_ptr > 0) { c = param_stack[--stack_ptr]; goto TOP; }    } /* end of outer for loop */ 

  for(c = 0; c <= DISKSIM_PF_STATS_MAX; c++) {
    if(disksim_pf_stats_params[c].req && !BIT_TEST(paramvec,c)) {
      fprintf(stderr, "*** error: in DISKSIM_PF_STATS spec -- missing required parameter \"%s\"
", disksim_pf_stats_params[c].name);
      return 0;
    }
  }
} /* end of scope */ 

 
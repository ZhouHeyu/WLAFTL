
#define STACK_MAX 32
{
    int c;
    int needed = 0;
    int param_stack[STACK_MAX];
    int stack_ptr = 0;  // index of first free slot
    BITVECTOR(paramvec, DISKSIM_SYNTHIO_MAX_PARAM);
    bit_zero(paramvec, DISKSIM_SYNTHIO_MAX_PARAM);

    for(c = 0; c < b->params_len; c++) {
	int pnum;
	int i = 0; 
	double d = 0.0; 
	char *s = 0; 
	struct lp_block *blk = 0;
	struct lp_list *l = 0;
	
	if(!b->params[c]) continue;

TOP:
	pnum = lp_param_name(lp_mod_name("disksim_synthio"), b->params[c]->name);

        // don't initialize things more than once
	if(BIT_TEST(paramvec, pnum)) continue;


	if(stack_ptr > 0) {
	    for(c = 0; c < b->params_len; c++) {
	        if(lp_param_name(lp_mod_name("disksim_synthio"), b->params[c]->name) == needed)
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
case DISKSIM_SYNTHIO_NUMBER_OF_IO_REQUESTS_TO_GENERATE:
{
if(!(i > 0)) { BADVALMSG(b->params[c]->name); return 0; }
else {
 synthio_endiocnt = i;
}
} break;
case DISKSIM_SYNTHIO_MAXIMUM_TIME_OF_TRACE_GENERATED:
{
if(!(d > 0.0)) { BADVALMSG(b->params[c]->name); return 0; }
else {
 synthio_endtime = d; synthio_endtime *= 1000.0;
}
} break;
case DISKSIM_SYNTHIO_SYSTEM_CALLRETURN_WITH_EACH_REQUEST:
{
if(!(RANGE(i,0,1))) { BADVALMSG(b->params[c]->name); return 0; }
else {
 synthio_syscalls = i;
}
} break;
case DISKSIM_SYNTHIO_THINK_TIME_FROM_CALL_TO_REQUEST:
{
if(!(d >= 0.0)) { BADVALMSG(b->params[c]->name); return 0; }
else {
 synthio_syscall_time = d;
}
} break;
case DISKSIM_SYNTHIO_THINK_TIME_FROM_REQUEST_TO_RETURN:
{
if(!(d >= 0.0)) { BADVALMSG(b->params[c]->name); return 0; }
else {
 synthio_sysret_time = d;
}
} break;
case DISKSIM_SYNTHIO_GENERATORS:
{
if(!(!loadsynthgenerators(0,l))) { BADVALMSG(b->params[c]->name); return 0; }
} break;
    default: assert(0); break; 
    } /* end of switch */ 
    BIT_SET(paramvec, pnum);
    if(stack_ptr > 0) { c = param_stack[--stack_ptr]; goto TOP; }    } /* end of outer for loop */ 

  for(c = 0; c <= DISKSIM_SYNTHIO_MAX; c++) {
    if(disksim_synthio_params[c].req && !BIT_TEST(paramvec,c)) {
      fprintf(stderr, "*** error: in DISKSIM_SYNTHIO spec -- missing required parameter \"%s\"
", disksim_synthio_params[c].name);
      return 0;
    }
  }
} /* end of scope */ 

 
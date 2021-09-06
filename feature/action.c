// action.c
// modified by Olives@SJ 5/14/2001 CST
// totally QC by YUJ@SJ 5/13/2001 EST
// add some functions for lost_attack and add_busy

varargs void interrupt_me(object who, string how);

static mixed busy, interrupt, bqueue;

void add_busy(int new_busy)
{
	if (!intp(new_busy))
		error("action: Invalid busy action type.\n");
	if (intp(busy))
		busy += new_busy;
	else bqueue += new_busy;
	set_heart_beat(1);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if (!new_busy) return;
	if (!intp(new_busy) && !functionp(new_busy))
		error("action: Invalid busy action type.\n");
	if (functionp(busy)) interrupt_me();
	if (intp(new_busy) && new_busy < 0)
		busy = new_busy;
	else if (intp(busy)) {
		if (intp(new_busy))
			busy = new_busy;
		else {
			bqueue = busy;
			busy = new_busy;
		}
		if (!intp(new_interrupt) && !functionp(new_interrupt))
			error("action: Invalid busy action interrupt handler type.\n");
		interrupt = new_interrupt;
	} else if (intp(new_busy))
		bqueue += new_busy;
	set_heart_beat(1);
}

nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy; }

static int exert_time;
static string exert_type = "�ڹ�";

varargs void start_exert(int new_exert, string new_type)
{
	if (!intp(new_exert))
		error("action: Invalid exert time.\n");
	exert_time = new_exert;
	if (!stringp(new_type))
		new_type = "�ڹ�";
	exert_type = new_type;
	set_heart_beat(1);
}

nomask string query_exert() { return exert_type; }
nomask int is_exert() { return exert_time; }

static int perform_time;
static int perform_nohalt_time;
static string perform_type = "�⹦";

varargs void start_perform(int new_perform, string new_type)
{
	if (!intp(new_perform))
		error("action: Invalid perform time.\n");
	perform_time = new_perform;
	perform_nohalt_time = perform_time>3 ? 3 : perform_time;
	if (!stringp(new_type))
		new_type = "�⹦";
	perform_type = new_type;
	set_heart_beat(1);
}

nomask string query_perform() { return perform_type; }
nomask int is_perform() { return perform_time; }
nomask int is_nohalt() { return perform_nohalt_time; }

static int lost_time;

varargs void start_lost(int new_lost)
{
	if (!intp(new_lost))
		error("action: Invalid lost time.\n");
	lost_time = new_lost;
	set_heart_beat(1);
}

nomask int is_lost() { return lost_time; }

// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
private void continue_action()
{
	if (intp(busy) && (busy > 0)) busy--;
	else if (functionp(busy)) {
		if( !evaluate(busy, this_object()) ) {
			busy = 0;
			interrupt = 0;
		}
	} else {
		busy = 0;
		interrupt = 0;
	}

	if (exert_time > 0) exert_time--;
	else exert_time = 0;

	if (perform_time > 0) perform_time--;
	else perform_time = 0;
	
	if (perform_nohalt_time > 0) perform_nohalt_time--;
	else perform_nohalt_time = 0;

	if (lost_time > 0) lost_time--;
	else lost_time = 0;

	if (!busy) {
		busy = bqueue;
		bqueue = 0;
	}
}

static int flag;

varargs void interrupt_me(object who, string how)
{
	if (flag) return;
	if (!busy) return;

	if (intp(busy) && intp(interrupt)) {
		if (busy < interrupt) {
			busy = 0;
			bqueue = 0;
		}
	} else if( functionp(interrupt) ) {
		flag = 1;
		if (evaluate(interrupt, this_object(), who, how)) {
			busy = 0;
			interrupt = 0;
			if(bqueue) {
				busy = bqueue;
				bqueue = 0;
			}
		}
		flag = 0;
	}
}

// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
//
// Because this could cause a serious security problem, so we need highest
// security check here.
int start_call_out(function fun, int delay)
{	
	if( !previous_object()
	||  (geteuid(previous_object()) != ROOT_UID
	     && userp(this_object())
	     && this_player() != this_object()) ) //������ȥ����һ�� 1  ��Ϊ�˷�ֹ�������BUGʹCall_out��Ч By Ciwei@SJ
	     {
		return 0;
	}
	
	call_out("eval_function", delay, fun);
	return 1;
}

private void eval_function(function fun) { evaluate(fun); }

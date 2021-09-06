// condition.c
// From ES2

#include <ansi.h>

#include <condition.h>

mapping conditions;
nosave mapping type_conditions;

// This function is called by heart_beat to update "continously active"
// conditions. These conditions will be saved as well. Because such type
// of conditions costs heart beat evaluation time, don't make player got
// too much this kind of conditions or you might got lots fo "Too long
// evaluation" error message in the log file.

nomask int update_condition()
{
	string *cnd, err;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {
		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		if (!mapp(conditions) || undefinedp(conditions[cnd[i]])) continue;
		err = catch(cnd_d = load_object(CONDITION_D(cnd[i])));
		if( !cnd_d ) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.

			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd[i]), this_object(), err)
			);
			map_delete(conditions, cnd[i]);
			continue;
		}

		// We assume since the condition daemon is loaded successfully, the
		// calling on its update_condition() should success as well. Because
		// catch() is somewhat costly, so we don't attempt to catch possible
		// error from the call_other. It is condition daemon's reponsibility
		// that don't cause error in users's heart beat.
		// If condition daemon returns 0 (or update_condition() not defined),
		// we can just assume the condition expired and remove it.
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( !( flag & CND_CONTINUE ) )
			if (mapp(conditions)) map_delete(conditions, cnd[i]);
		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;

	return update_flag;
}

// apply_condition()
//
// This function applies the specific condition to the character. Note we 
// don't check if the condition already exist before setting condition info.
// It is condition giver's reponsibility to check if the condition should
// override the old one if same condition already exists.(Use query_condition
// to check)

nomask void apply_condition(string cnd, mixed info)
{
    string c_type;
    //�츳��ǧ�����ˡ�Ӱ��Ч����  by lsxk@hsbbs  2008/3/16
    if(this_object()->query("relife/recover/qgqr")){
        c_type = call_other(load_object(CONDITION_D(cnd)), "query_type", this_object());
        if (c_type == "poison"){
            info -= info * (int)this_object()->query("relife/recover/qgqr",1) * 10 / 100;
            message_vision(HIB"���ϵ�$N�������ⶾ��֮�츳����󽵵��˸��඾�صĶ���Ч��!\n"NOR,this_object());
        }
    }

	if( !mapp(conditions) ) conditions = ([ cnd : info ]);
	else conditions[cnd] = info;
}

nomask void add_condition(string cnd, mixed info)
{
	if (!mapp(conditions))
		apply_condition(cnd, info);
	else
		apply_condition(cnd, conditions[cnd] + info);
}

// query_condition()
//
// This function returns info about the specific condition if any.

nomask mixed query_condition(string cnd)
{
	if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
	return conditions[cnd];
}

nomask mapping query_entire_conditions()
{
	return conditions;
}

nomask mapping query_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return 0;
	type_conditions = 0;
	cnd = keys(conditions);
	while(i--) {

		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		err = catch(cnd_d = load_object(CONDITION_D(cnd[i])));
		if (!cnd_d) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.

			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd[i]), this_object(), err)
			);
			map_delete(conditions, cnd[i]);
			continue;
		}

		// We assume since the condition daemon is loaded successfully, the
		// calling on its update_condition() should success as well. Because
		// catch() is somewhat costly, so we don't attempt to catch possible
		// error from the call_other. It is condition daemon's reponsibility
		// that don't cause error in users's heart beat.
		// If condition daemon returns 0 (or update_condition() not defined),
		// we can just assume the condition expired and remove it.
		
		cnd_type = call_other(cnd_d, "query_type", this_object());
		if (cnd_type == required_type) {
			if (!mapp(type_conditions)) type_conditions = ([ cnd[i] : conditions[cnd[i]] ]);
			else type_conditions[cnd[i]] = conditions[cnd[i]];
		}
	}
	return type_conditions;
}

nomask void clear_condition(string cnd)
{
	if (!cnd)
		conditions = 0;
	else if (mapp(conditions)) map_delete(conditions, cnd);
}
 
nomask void clear_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return;
	cnd = keys(conditions);
	while(i--) {
		// In order to not casue player lost heart beat occasionally while
		// calling external condition daemons, we take careful calling
		// convention here.

		err = catch(cnd_d = load_object(CONDITION_D(cnd[i])));
		if (!cnd_d) {
			// If we failed to load the external condition daemon, remove
			// it before we stuff log files with error messages.
			log_file("condition.err",
				sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
					CONDITION_D(cnd[i]), this_object(), err)
			);
			map_delete(conditions, cnd[i]);
			continue;
		}

		// We assume since the condition daemon is loaded successfully, the
		// calling on its update_condition() should success as well. Because
		// catch() is somewhat costly, so we don't attempt to catch possible
		// error from the call_other. It is condition daemon's reponsibility
		// that don't cause error in users's heart beat.
		// If condition daemon returns 0 (or update_condition() not defined),
		// we can just assume the condition expired and remove it.
		
		cnd_type = call_other(cnd_d, "query_type", this_object());
		if (cnd_type == required_type) map_delete(conditions, cnd[i]);
	}
}

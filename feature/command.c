// command.c
// From ES2
// Modified by Xiang@XKX (12/15/95)

#include <command.h>
#include <dbase.h>
#include <origin.h>

// Let command path be nosave, thus we can make sure no one can get command
// path directly from restore_object().
nosave string *path;
nosave int hook_flag = 0;

// Leave this to allow other objects can search your commands such as
// help, which...

string find_command(string verb)
{
	return (string)COMMAND_D->find_command(verb, path);
}

string remove_leading_space(string arg)
{
	int i;
	for (i = 0; i < strlen(arg); i++)
        if (arg[i] != ' ')
			return arg[i..<1];
	return "";
}

// This is the add_action hook handling movement, commands, emotes and
// channels. Optimization is needed.
protected nomask int command_hook(string arg)
{
	string verb, file;
	object me = this_object();
#ifdef PROFILE_COMMANDS
	int mem, utime, stime;
	mapping info;
#endif


	if (!wizardp(me) && !living(me)) return 0;

#ifdef PROFILE_COMMANDS
	mem = memory_info();
	info = rusage();
	utime = info["utime"];
	stime = info["stime"];
#endif

	verb = query_verb();
	if (verb == "") {
		verb = arg = remove_leading_space(arg);
		if (arg) {
			if (sscanf(arg, "%s %s", verb, arg) != 2) arg = 0;
		} else return 0;
	}

	if (!query_notify_fail()) notify_fail(get_config(12)+"\n");
	if( !arg 
	&&	(environment() && stringp(environment()->query("exits/" + verb)))
	&&	stringp(file = find_command("go"))
	&&	call_other(file, "main", me, verb))
		;
	else if( stringp(file = find_command(verb)) 
	&& call_other(file, "main", me, arg))
		;
	else if( EMOTE_D->do_emote( me, verb, arg ) )
		;
	else if( CHANNEL_D->do_channel( me, verb, arg ) )
		;
	else tell_object(me, query_notify_fail());

#ifdef PROFILE_COMMANDS
	info = rusage();
	PROFILE_D->log_command(verb, memory_info() - mem, info["stime"] - stime,
		info["utime"] - utime);
#endif

	return 1;
}

private nomask void set_path(string *p)
{
//	if( origin() != ORIGIN_LOCAL
//	&&	geteuid(previous_object()) != ROOT_UID )
//		return;
	path = p;
}

string *query_path() { return path; }
mixed *query_commands() { return commands(); }

int force_me(string cmd)
{
	int id1, id2;
	object me = this_object();

	if (geteuid(previous_object()) != ROOT_UID) {
		id1 = wiz_level(geteuid(previous_object()));
		id2 = wiz_level(geteuid(me));
		if( id1 < id2 )
			return 0;
	}
	return command( me->process_input(cmd) );
}

nomask void enable_player()
{
	object me = this_object();

	if( stringp(query("id")) ) set_living_name(query("id"));
	else set_living_name(query("name"));

	enable_commands();
	delete("disable_type");

	if (!hook_flag) {
		hook_flag = 1;
		add_action("command_hook", "", 1);
	}

	if( !userp(me) ) set_path(NPC_PATH);
	else switch( wizhood(me) ) {
		case "(admin)":
			set_path(ADM_PATH);
			enable_wizard();
			break;
		case "(assist)":
			set_path(ASS_PATH);
			enable_wizard();
			break;
		case "(arch)":
			set_path(ARC_PATH);
			enable_wizard();
			break;
		case "(wizard)":
			set_path(WIZ_PATH);
			enable_wizard();
			break;
		case "(apprentice)":
			set_path(APR_PATH);
			enable_wizard();
			break;
		case "(immortal)":
			set_path(IMM_PATH);
			enable_wizard();
			break;
		default:
			if ( me->query("registered") < 2) set_path(UNR_PATH);
			else set_path(PLR_PATH);
			disable_wizard();
	}
}

nomask void disable_player(string type)
{
	object me = this_object();

	if( geteuid(previous_object())!=ROOT_UID
	&&	previous_object()!=me) return;

	set("disable_type", type);
	me->interrupt_me();
	me->disable_commands();
}

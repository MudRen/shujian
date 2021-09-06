// zmud.c  ;����/cmds���Ա����ʹ��force_me����
// By Jpei

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit FINGER;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

void create()
{
	seteuid(getuid());

	set("long",@LONG
����һ������ZMUD�ĳ�ʽ��

����<help zmud>�Ի�ø������Ѷ��
LONG
);

	set("unit","��");
	set("no_get", 1);
	set("no_drop", 1);

	set("material", "program");
	set("armor_prop/armor", 100);
	set_weight(1);
	setup();
}

void init()
{
	object me = this_player();

	seteuid(geteuid());
	if (!wizardp(me)) return;
	if (me && present(this_object(), me))
		set_name (me->name(1) + "��ZMUD��ʽ", ({ "zmud program" }));
	else
		set_name ("ZMUD��ʽ", ({ "zmud program" }));

	if (me && present(this_object(), me)) {
		add_action("help", "help");
		add_action("do_loop", ({"loop", "#"}));
		add_action("do_run", ({"run", "~"}));
	}
}

int help(string str)
{

	if (str != "zmud" && str != "zmud program") return 0;

	write(@Help

	�����ʹ�����µļ�������:

	loop��# <����n> <����>		<�ظ�������n��>
	run��~ <��;�������������>	<һ��ִ����;�����Ķ�������>

Help
);
	return 1;
}

int query_autoload()
{
	if (wizardp(this_player())) return 1;
	else return 0;
}

int do_loop(string arg)
{
	int count, i;
        object me = this_player();
        string cmd;

	if (!geteuid()) seteuid(getuid());
        if (!arg || arg == "") return notify_fail ("[ZMUD]: ������ʲôѽ��\n");
        if (sscanf(arg,"%d %s", count, cmd) != 2)
		return notify_fail ("loop��# <count> <cmd>\n");
	for (i = 0; i < count; i++)
		if (objectp(me)) me->force_me(cmd);
	return 1;
}

int do_run(string arg)
{
	int i;
        object me = this_player();
        string *cmds;

	if (!geteuid()) seteuid(getuid());
        if (!arg || arg == "") return notify_fail ("[ZMUD]: ������ʲôѽ��\n");
	cmds = explode(arg, ";") - ({ "" });
	for (i = 0; i < sizeof(cmds); i++)
		if (objectp(me)) me->force_me(cmds[i]);
	return 1;
}


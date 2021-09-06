//  No Copyright Message (6.17.1997)

#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
#include <mudlib.h>

mapping dir_alias = ([
	"n":	"north",
	"e":	"east",
	"w":	"west",
	"s":	"south",
	"nu":	"northup",
	"eu":	"eastup",
	"wu":	"westup",
	"su":	"southup",
	"nd":	"northdown",
	"ed":	"eastdown",
	"wd":	"westdown",
	"sd":	"southdown",
	"ne":	"northeast",
	"se":	"southeast",
	"nw":	"northwest",
	"sw":	"southwest",
	"u":	"up",
	"d":	"down"
]);

mapping dir_desc = ([
	"north":		"����",
	"south":		"����",
	"east":			"����",
	"west":			"����",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":		"����",
	"southdown":		"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":		"����",
	"northwest":		"����",
	"southeast":		"����",
	"southwest":		"����",
	"up":			"����",
	"down":			"����",
	"enter":		"����",
	"out":			"����"
]);

int msgon = 1;

int whereis(string arg);

void create()
{
	seteuid(getuid());

	set("long",@LONG
����һ����ֵ���Ʒ��

����<help myst>�Ի�ø������Ѷ��
LONG
);

	set("unit","��");
	set("no_get", 1);
	set("no_drop", 1);

	set("material", "cloth");
	set("armor_prop/armor", 100);
	set_weight(-100000);
	setup();
}

void init()
{
	object me = this_player();

	seteuid(geteuid());
	if (!me->id("yuj") && !present(this_object(), me)) {
		if (environment(environment(me))) {
			write("�㱻һ���������������ˣ�\n");
			me->move(environment(environment(me)), 1);
		}
		return;
	}
	set_name ("������Ʒ", ({ "mystique" }));
	if (wiz_level(me) < 6) return;
	set_name (me->name(1) + "��������Ʒ", ({ "mystique" }));

	if (me && present(this_object(), me)) {
		add_action("help", "help");
		add_action("full", "full");
		add_action("remove_wield", "xie");
		add_action("clone_money", "yao");
		add_action("steal", "tou");
		add_action("whereis", "whereis");
		add_action("pk_mob", "pk");
		add_action("do_give", "give");
		add_action("do_wakeup", "wakeup");
		add_action("force_quit", "fquit");
		add_action("make_unconcious", "hun");
		add_action("do_say", "ss");
//		add_action("do_gift", ({"gift"}));
		add_action("force_go", ({"forcego", "fgo"}));
		add_action("do_who", ({"userlist", "ul"}));
		add_action("do_look", ({"lookhere", "ll"}));
		add_action("do_fgive", "fgive");
		add_action("do_tie", "tie");
		add_action("message_switch", "msg");
	}
}

int help(string str)
{

	if (str != "myst" && str != "mystique") return 0;

	write(@Help

	�����ʹ�����µļ�������:

	% localcmd, stat, call, data, score, skills, �ȵ�
	���� help wizcmds ȡ�ý�һ������

	yao <number> <type>		<<ȡ������Ǯ�ҵĶ�����Ŀ>
	xie <eqs> from <object>		<��ĳһ object ���װ��>
	tou <object> from <object>	<��ĳ��һ�object������ĳ������>
	pk <����1> with <����2>		<������1 ������2 �� k>
	forcego <����> <����>		<��������ĳ����ȥ>
	whereis <���|����|�ļ�>	<��ʾһ��ҵ����ڵػ�����ļ�������clone���ڵ�>
	forcego <����> <����>		<��������ĳ����ȥ>
	full <���>              	<ȫҽ, ��������������ڶ�Ϊ�Լ�>
	fquit <���>              	<ǿ������˳�>
	hun <���>			<����һ���>
	wakeup <���>			<�ѻ��Բ��ѵ���ҽ���>
	ss <string>			<ֱ����sayƵ����ʾstring>
	userlist �� ul <-i|-l|-w>	<who�Ĺ���>
	lookhere �� ll			<look������>
	fgive <���> <��Ʒ>            	<�������Ʒ�������ʾ����ʵ�ʶ���>
	tie						<�����ﻥ�� follow>
	msg <on|off>			<�򿪻�ر�pk_mob��force_go����ʾ,Ĭ��on>

Help
);
	return 1;
}

int query_autoload()
{
	if (wizardp(environment())) return 1;
	return 0;
}

int remove_wield(string str)
{
	string ob, player;
	object obj, npc, me = this_player();

	if (!geteuid()) seteuid(getuid());
	if (sscanf(str,"%s from %s", ob, player) != 2) return 0;

	if (!(npc = find_player(player)))
		if (!(npc = find_living(player)))
			if (!(npc = present(player, environment(me))))
				return notify_fail ("[MYST]: û�����\n");

	obj = present(ob, npc);

	if(!obj) return notify_fail ("����û�����ֶ���\n");
	else {
		message_vision ("$N��" + npc->name() + "����$n��\n", me, obj);
		obj->move(me);
		obj->move(npc);
		return 1;
	}
}

int make_unconcious(string arg)
{
	object ob;
	object me = this_player();

	if (!geteuid()) seteuid(getuid());
	if (!arg) return notify_fail("[MYST]: ������˭ſ�£�\n");
	ob = present(lower_case(arg), environment(me));
	if (!ob) return notify_fail ("[MYST]: �Ҳ���"+ arg + "\n");
	if (msgon) {
		message_vision(HIR "$N�ӿڴ����ͳ�һ��С���죬��$n����ǰ�������Σ�$n��Ȼ��������һƬ�հס�\n", me, ob);
		message_vision(HIR "$N��ɫ��òҰס�\n" NOR, ob);
	}
	ob->unconcious();
	return 1;
}

int message_switch(string arg)
{
	if (arg == "on" || arg == "ON") msgon = 1;
	else if (arg == "off" || arg == "OFF") msgon = 0;
	else return notify_fail ("[MYST]: msg on|off\n");
	return 1;
}

int steal(string str)
{
	string ob, player;
	object obj, npc, me = this_player();

	if (!geteuid()) seteuid(getuid());
	if (sscanf(str,"%s from %s", ob, player) != 2) return 0;
	if (player == "yuj") return notify_fail("��͵����Ķ������±��Ӱɡ�\n");
	if (player == "jpei") return notify_fail("�������㻹�Ǹ����Լ����Űɡ�\n");
	npc = find_player(player);
/*	if (!(npc = find_player(player)))
		if (!(npc = find_living(player)))
			if ( !(npc = present(player, environment (me))) )
				return notify_fail ("û���"+str+"\n");
	if (wiz_level(npc) > 4) return notify_fail("��͵����Ķ������±��Ӱɡ�\n");*/
	if (!(obj=present(ob, npc))) return notify_fail ("[MYST]: ����û�������("+ str + ")\n");

	obj->move(me);

	write("��͵��" + npc->name(1) + "��" + obj->short() + "��\n");
	CHANNEL_D->do_channel(this_object(), "rumor*", "�������˹������ش�" + npc->name(1)
		+ "����͵����" + obj->name(1) + "��");
	return 1;
}

int where_list(string arg)
{
	object where, npc;
	object *ob;
	string filename;
	int i;

	if (!geteuid()) seteuid(getuid());
	if (!arg) return 0;
//	if (LOGIN_D->find_body(arg)) return whereis(arg);
	if (arg[0..0] != "/") {
		if (!(npc = find_living(arg))) return 0;
		if (!this_player()->visible(npc)) return 0;
		filename = base_name(npc);
	}
	else
		filename = arg;
	printf("Base file: %s\n", filename);
	ob = children(filename);
	for (i = 0; i < sizeof(ob); i++) {
		if (arg[0..0] == "/" || ob[i]->id(arg)) {
			where = environment(ob[i]);
			if (where) {
				if (!userp(where)) printf("%s %O\n", base_name(where), ob[i]);
				else printf("��%s(%s)���� %O\n", where->query("name"), where->query("id"), ob[i]);
			}
		}
	}
	return 1;
}

int whereis(string arg)
{
	object where, target, me = this_player();
	object *ob;
	string msg;
	int i;

	if (!geteuid()) seteuid(getuid());
	if (arg) {
		if ((target = LOGIN_D->find_body(arg)) && me->visible(target)) {
			where = environment(target);
			if (!where) return notify_fail("��������Ʈ��䡣\n");
			"/cmds/std/look"->look_room(me, where);
			return 1;
		}
		else {
			if (where_list(arg)) return 1;
			else return notify_fail("�����������ڡ�\n");
		}
	}
	else {
		ob = users();
		msg = "";
		for (i = 0; i < sizeof(ob); i++) {
			where = environment(ob[i]);
			if (!where)
				msg = sprintf("%s%14s(%-10s) %s\n",
					msg, ob[i]->name(1), ob[i]->query("id"),
					"??????????");
			else
				msg = sprintf("%s%14s(%-10s) %s\n",
					msg, ob[i]->name(1), ob[i]->query("id"),
					file_name(where));
		}
	}
	write (msg);
	return 1;
}

int full(string str)
{
	int max;
	object me;

	if(!str)
		me = this_player();
	else
		me = LOGIN_D->find_body(str);

	if (!me) me = present(str, environment());
	if (!me) return notify_fail ("[MYST]: full error: �Ҳ���"+str+"\n");
	me->set_ghost(0);
	max = me->query("eff_jingli")*2;
	if (max > me->query("jingli")) me->set("jingli",max);
	max = me->query("max_jing");
	if (max > me->query("eff_jing")) me->set("eff_jing",max);
	if (max > me->query("jing")) me->set("jing",max);
	max = me->query("max_qi");
	if (max > me->query("eff_qi")) me->set("eff_qi",max);
	if (max > me->query("qi")) me->set("qi",max);
	max = me->query("max_neili")*2;
	if (max > me->query("neili")) me->set("neili",max);
	max = me->max_food_capacity();
	if (max > me->query("food")) me->set("food",max);
	max = me->max_water_capacity();
	if (max > me->query("water")) me->set("water",max);
	max = me->query("max_pot") / 2;
	if (max > me->query("potential")) me->set("potential",max);
	me->add("combat_exp", random(2));
	if (wizardp(me)) me->clear_condition();

	if (me != this_player())
		if (msgon)
			message_vision( "$N����$n��������ظ�����[32;1m���� ���� ����ķ[37;0m\n",
				this_player(), me);
		else
			write(me->name() + "״̬�ָ���ϣ�\n");
	else
		write("״̬�ָ���ϣ�\n");

	return 1;
}

int clone_money(string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: yao <����Ǯ> <Ǯ������>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        }
	else
                n_money->add_amount(amount);

	message_vision( sprintf("$Nʹ�����Ϳڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
			this_player());
        return 1;
}

int do_tie(string str)
{
        object ob1, ob2;
        string st1, st2;

        if (!str || str=="") return notify_fail ("[MYST]: ������˭ PK ˭����\n");
        if (sscanf(str, "%s with %s", st1, st2) != 2)
		return notify_fail ("tie <ob1> with <ob2>\n");

		if (!ob1 = find_living(st1)) ob1 = LOGIN_D->find_body(st1);
		if (!ob2 = find_living(st2)) ob2 = LOGIN_D->find_body(st2);
        if (!ob1) return notify_fail("�Ҳ��� " + st1 + " ������\n");
        if (!ob2) return notify_fail("�Ҳ��� " + st2 +" ������\n");
		if (ob1 == ob2) return notify_fail("��û����ɣ�\n");

		write("����" + ob1->name(1) +"��" + ob2->name(1) + "������档\n");
		ob1->set_leader(ob2);
		ob2->set_leader(ob1);
		return 1;
}

int pk_mob(string str)
{
        object ob1, ob2, me = this_player();
        string st1, st2;

        if (!str || str=="") return notify_fail ("[MYST]: ������˭ PK ˭����\n");
        if (sscanf(str, "%s with %s", st1, st2) != 2)
		return notify_fail ("pk <ob1> with <ob2>\n");

        if (!ob1 = present(st1, environment(me)) || !ob1->is_living()) return notify_fail("�Ҳ��� " + st1 + " ������\n");
        if (!ob2 = present(st2, environment(me)) || !ob2->is_living()) return notify_fail("�Ҳ��� "+st2+" ������\n");
	if (ob1 == ob2) return notify_fail("��û����ɣ�\n");
	if (st1 == "jpei" || st2 == "jpei") return notify_fail("���������������ط�����������ܣ��±��Ӱɡ�\n");

	if (msgon) {
		message_vision(HIR "$N�ӿڴ����ͳ�һ��С���죬��$n����ǰ�������Σ�$n��Ȼ��������һƬ�հס�\n", me, ob1);
		message_vision(HIR "$N�����Ц����Ц������С����$nһָ��\n", me, ob2);
		message_vision(HIR "$N����ɱ��ص���$nһ�ۣ����С��ɺɡ������س�����ȥ��\n" NOR, ob1, ob2);
	}
	else printf("����" + ob1->name() +"��" + ob2->name() + "����PK��\n");
        ob1->kill_ob(ob2);
        return 1;
}

int force_go(string str)
{
        object ob, obj, env, me = this_player();
        string st1, st2, dir, dest;
	mapping exit;

        if (!str || str=="") return notify_fail ("[MYST]: ������˭ȥ���ﰡ��\n");
        if (sscanf(str,"%s %s", st1, st2) != 2)
		return notify_fail ("fgo <ob> <dir>\n");

        if (!ob = present(st1, environment(me)))
		return notify_fail("�Ҳ��� "+ st1 + " �������.\n");

	if (st1 == "jpei") return notify_fail("���������ֻϲ����������ϲ���Ĵ��Ҵڡ�\n");

	if (st1 == "bbb") return notify_fail("ɱ�������ֻϲ����������ϲ���Ĵ��Ҵڡ�\n");
	if (st1 == "yuj") return notify_fail("���������ֻϲ�����ˣ���ϲ�����˸ϡ�\n");

 	env = environment(me);
	if (!env) return notify_fail("[MYST]: ����Ҳȥ���ˡ�\n");

	if (!undefinedp(dir_alias[st2])) st2 = dir_alias[st2];

	if (!mapp(exit = env->query("exits")) || undefinedp(exit[st2]))
		return notify_fail("[MYST]: �Ǹ�����û�г�·��\n");

	dest = exit[st2];

	if (!(obj = find_object(dest)))
		call_other(dest, "???");
	if (!(obj = find_object(dest)))
		return notify_fail("[MYST]: �޷��ƶ���\n");

	dir = obj->query("short");
	if (!undefinedp(dir_desc[st2]))
		dir = dir_desc[st2] + "��" + dir;

	if (msgon) {
		message_vision(HIR "$N�ӿڴ����ͳ�һ��С���죬��$n����ǰ�������Σ�$n��Ȼ��������һƬ�հס�\n", me, ob);
		message_vision(HIR "$N�����Ц����Ц������С����" + dir + "һָ��\n", me);
		message_vision(HIR "$N�������������˹�ȥ��\n" NOR, ob);
	}
	else printf("����" + ob->name() +"��" + dir + "��ȥ��\n");
	"/cmds/std/go"->main(ob, st2);
        return 1;
}

/*
int do_gift (object me, string arg)
{
int i;
object *users;
        seteuid(getuid());
                users = users();
                 i = sizeof(users);
        while(i--) {
               tell_object(users[i],HIW "���ϴ���һ�󶣶�����������\n\n" + HIY "ͻȻ���������һ�¶���һ��ʲô����,������1000��Ԫ,һ�����˽��齣��������,999������õ�������?��\n\n" NOR);
                }
write("���﷢����ϡ�\n");
return 1;
}
*/

int do_give (string arg)
{
	object ob, who, me = this_player();
	string wiz, obs, whos;

	if (!arg) return 0;
	wiz = wizhood (me);
	if (sscanf(arg, "%s to %s", obs, whos) != 2) return 0;
	if (obs != "myst" && obs != "myst") return 0;

	write ("my level : " + wiz_level(me) + "\n");
	if (wiz_level(me) > 2)
		if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
			write ("��������Ʒ���ܸ�����������ˡ�\n");
			return 1;
		}

	ob = present ("myst", me);
	if (!ob) write ("��û������������\n");
	who = find_player(whos);
	if (!who) write ("û������ˡ�\n");
	if (ob && who) {
		ob->move (who);
		message_vision ("$N��$nһ��������Ʒ��\n", me, who);
	}
	return 1;
}

int do_wakeup (string str)
{
	object who;

	if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

	if (!(who = present(lower_case(str), environment(this_player()))) )
		return notify_fail ("[MYST]: wakeup error, û��" + str + "\n");
	who->remove_call_out("revive");
	who->revive();
	who->reincarnate();
	return 1;
}

int force_quit (string str)
{
	object ob;

	if (!geteuid()) seteuid(getuid());
	if (!str) return notify_fail ("[MYST]: Hey you! ������˭ quit ��\n");


	if (!(ob = find_player(str))) return notify_fail ("[MYST]: û�����(" + str + ")\n");

	if (objectp(ob)) destruct( ob );
	else write ("[MYST]: cannot force quit\n");
	return 1;
}

int do_say(string arg)
{
	object me = this_player();

	tell_room(environment(me), CYN + arg + "\n"NOR);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	string name1, name2;

	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2)
			- wiz_level(ob1);

	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

mixed do_who(string arg)
{
	string str, *option, fname = "";
	object *list, *ob;
	int i, ppl_cnt, cnt, count, wcnt = 0;
	int opt_long, opt_id, opt_wiz, opt_party;
	object me=this_player();

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1; break;
				case "-i": opt_id = 1; break;
				case "-w": opt_wiz = 1; break;
				case "-f":
				case "-p": opt_party = 1; break;
				default:
/*				default:
					if( wizardp(me)
					&&	option[i][0]=='@' ) {
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
							me, opt_long);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
*/
					return notify_fail("ָ���ʽ��who [-l|-i|-w]\n");
			}
	}

	if( opt_long && !wizardp(me)) {
		if( (int)me->query("jing") < 30 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("jing", 30);
	}

    str = "�� " + MUD_NAME + "\n";
	str += "��������������������������������������������������������������������������\n";
	ob = filter_array(objects(), (: userp :));
	if (opt_party)
		ob = filter_array(ob, (: $1->query("family/family_name") ==
			$2->query("family/family_name") :), me);
	list = sort_array(ob, (: sort_user :));
	ppl_cnt = 0;
	cnt = 0;
	if( opt_long || opt_wiz ) {
		i = sizeof(list);
		while( i-- ) {
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
//			if( !me->visible(list[i]) ) continue;
			if( opt_wiz && !wizardp(list[i]) ) continue;
			if (interactive(list[i])) ppl_cnt++;
			else cnt++;
			str = sprintf("%s%12s%s%s\n",
				str,
				RANK_D->query_rank(list[i]),
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+" NOR:(me->visible(list[i])?" ":HIC "&" NOR)):HIG "*" NOR,
				list[i]->short(1)
			);
		}
	} else {
		i = sizeof(list);
		count = 0;
		while( i-- ) {
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
//			if( !me->visible(list[i]) ) continue;
			if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
			    fname = list[i]->query("family/family_name");
			    if (count % 8) str += "\n";
			    str += sprintf(HIY "%-10s" NOR, (fname?fname:"��ͨ����") + "��");
			    count = 1;
			}
			if (!wcnt && wiz_level(list[i])) {
			    if (count % 8) str += "\n";
			    str += sprintf(HIY "%-10s" NOR, "��ʦ��");
			    wcnt = 1;
			    count = 1;
			}
			if (!(count%8)) {
				count++;
				str += "          ";
			}
                        str = sprintf("%s%s%-9s"NOR"%s",
				str,
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "+":(me->visible(list[i])?" ":HIC "&")):HIG "*",
				opt_id?capitalize(list[i]->query("id")): list[i]->name(1),
				++count%8 ? "": "\n"
			);
			if (interactive(list[i])) ppl_cnt++;
			else cnt++;
		}
		if( count%8 ) str += "\n";
	}
	str += "��������������������������������������������������������������������������������\n";
	str = sprintf("%s�� %d λ��������У�%d λ��Ҷ����У�ϵͳ������%s\n* ��ʾ������  + ��ʾ������", str, ppl_cnt,
		cnt, query_load_average());

//	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int do_look(string arg)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;
	object me = this_player();
	object env = environment(me);

	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
		return 1;
	}
	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
		else
			str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
	//	if( inv[i]==me ) continue;
	//	if( !me->visible(inv[i]) ) continue;
	        if (userp(inv[i]) && inv[i]->query_temp("pending/exercise"))
			str += "  " + inv[i]->short() + "  ID:(" + inv[i]->query("id") + ")\n";
		else
			str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}

int false_give(object me, object obj, object who, int amount)
{
	string unit;

	notify_fail("�Է�����������������\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
		return 0;

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		return 1;
	}
	if (amount) unit = chinese_number(amount) + obj->query("base_unit");
	else unit = "һ" + obj->query("unit");
	printf("���װ��%s%s%s��\n", who->name(), unit, obj->name());
	message("vision", sprintf("%s����%s%s��\n", me->name(),	unit, obj->name()), who );
	return 1;
}

int do_fgive(string arg)
{
	string target, item;
	object obj, who, *inv, me = this_player();
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( who == me) return notify_fail("���Լ���\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		return false_give(me, obj, who, amount);
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			false_give(me, inv[i], who, inv[i]->query_amount());
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return false_give(me, obj, who, obj->query_amount());
}

// dig.c
#define	__SJSZ__	"/cmds/leitai/bwdh/"

inherit F_CLEAN_UP;

#include <ansi.h>

void create() { seteuid(getuid()); }

void remove_busy(object me)
{
	if (me) me->delete_temp("dig_busy");
}

int main(object me, string arg)
{
	object env, ob, huwei, weapon, room;
	object *obj = deep_inventory(me);
        object *list;
	int i, sum, chance, j;
	mixed *local;
	string str;

	mapping *item_list = ({
	([
		"object" : "/clone/money/gold",
		"chance" : 1
	]),
	([
		"object" : "/clone/money/silver",
		"chance" : 8
	]),
	([
		"object" : "/clone/medicine/yaocao",
		"chance" : 35
	]),
	([
		"object" : "/clone/money/coin",
		"chance" : 50
	]),
	});

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( me->is_fighting() )
		return notify_fail("�㻹��ר����ս�ɣ�\n");

	if( me->query("jingli") < 10 )
		return notify_fail("�㻹�ǵ���������ʱ����˵�ɣ�\n");

	env = environment(me);
	if (!env->query("outdoors"))
		return notify_fail("��������ѽ��\n");

	if (env->query("no_dig")) {
		if (stringp(env->query("no_dig")))
			return notify_fail(env->query("no_dig"));
		return notify_fail("���ﲻ׼����ھ�\n");
	}

	weapon = me->query_temp("weapon");

	if ( weapon)
	if ( weapon->query("skill_type") == "whip"
	|| weapon->query("skill_type") == "throwing")
		return notify_fail("����"+weapon->name()+"�ڣ�����������ְɣ�\n");

	if ( strsrch(file_name(env), "/cmds/leitai/bwdh") >= 0 ) {
		j = sizeof(obj);
		while (j--)
		if ( obj[j]->query("sjsz_item"))
			return notify_fail("���Ƚ����ڳ����Ķ�����������ټ����ڰɡ�\n");

		list = filter_array(all_inventory(env), (: userp :) );
		list -= ({me, 0});

		if ( sizeof(list))
			return notify_fail("�ھ�����ô���ܵ��£������еڶ����ڳ���\n");

		if ( env->query("dig_times") < 1 )
			return notify_fail("���������Ѿ��ڲ���ʲô�����ˡ�\n");

		if ( me->query_temp("dig_busy") && !wizardp(me))
			return notify_fail("��ո��ھ���ϣ���������Ϣһ��ɡ�\n");

		local = localtime(time());
		if ( ! room = find_object("/cmds/leitai/bwdh/zongtai"))
			room = load_object("/cmds/leitai/bwdh/zongtai");

		if ( ! room->query("time1") && !room->query("time2"))
			return notify_fail("ϵͳ��δ����ʱ�䣬�����Խ�ɽׯ�ڲ����ھ��\n");

		if ( !env->query("have_quest_room"))
		if ( local[2] < room->query("time1")
		|| ( local[2] >= room->query("time1") + 4 && local[2] < room->query("time2") )
		|| ( local[2] >= room->query("time2") + 4 && local[2] < room->query("time3") )
		|| local[2] >= room->query("time3") + 4)
			return notify_fail("���ڵ�ʱ��Σ��Խ�ɽׯ�ڲ����ھ��\n");
/*
		if ( me->query("no_pk"))
			return notify_fail("���Ѿ�����ϴ�֣��Ͳ�Ҫ�ٽ��뽭�������ˡ�\n");
*/
	}

	if ( weapon )
		message_vision(HIY"$N���ڵ��ϣ������е�"+weapon->name()+HIY"�ڵ���һ�����١�\n"NOR, me);
	else 
		message_vision(HIY"$N���ڵ��ϣ������ڵ���һ�����١�\n"NOR, me);

	if ( !wizardp(me))
		me->add_busy(1);

	me->receive_damage("jingli", 5 + random(5));

	if ( strsrch(file_name(env),"/cmds/leitai/bwdh") >= 0 && random(2) && !me->query_condition("job_busy")) {
		switch(random(10)) {
			case 1:	str = "max_neili";	break;
			case 3:	str = "combat_exp";	break;
			case 5:	str = "max_jingli";	break;
			case 7:	str = "potential";	break;
		}
		if ( stringp(str) ) {
			env->add("dig_times", -1);
			ob = new(__SJSZ__"obj/danwan");
			ob->set("bonus", str);
			ob->set("owner", getuid(me));
			ob->set("sjsz_item", 1);
			if ( env->query("have_quest_room") && str == "combat_exp") {
				ob->set("treasure", 10);
				ob->set("secret_obj", 1);
				ob->set("eat_time", uptime());
				ob->delete("no_get");
				env->delete("have_quest_room");
			}
			ob->move(me);
			me->set_temp("dig_busy", 1);
			call_out("remove_busy", 10 +random(5), me);
			message_vision("����һ��ʱ���Ѱ�ң�$N�ڵ���һ" + ob->query("unit") + ob->query("name") + "��\n", me);
			if ( str == "combat_exp") {
				message_vision("$N��Ҫ��ϸ�鿴���е�"+ob->query("name")+"����Ȼһλ�Խ�ɽׯ�Ļ�Ժ���˽�����\n",me);
				huwei= new(__SJSZ__"npc/huwei");
				huwei->set_temp("target", getuid(me));
				huwei->move(environment(me));
			}
		}
		else
			message_vision("$N����һ�󣬽��ʲôҲû���ҵ���\n", me);
	}
	else {
		if (random(80 - 2 * me->query("kar")) == 7 && !env->query("dig_out")) {
			sum = 0;
			for (i = 0; i < sizeof(item_list); i++)
				sum += item_list[i]["chance"];
			chance = random(sum);
			for (i = 0; i < sizeof(item_list); i++) {
				if ((chance -= item_list[i]["chance"]) < 0) {
					ob = new(item_list[i]["object"]);
					message_vision("����һ��ʱ���Ѱ�ң�$N�ڵ���һ" + ob->query("unit") + ob->query("name") + "��\n", me);
					ob->move(me);
					return 1;
				}
			}
		}
		if (env->query("dig_out"))
			if (env->add("dig_out", 1) > 100)
				env->delete("dig_out");
		message_vision("$N����һ��ʲôҲû���ҵ���\n", me);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dig

���ָ����������ڻ����ھ���棬���ܻ��ڵ�һЩ��Ʒ.

HELP
    );
    return 1;
}

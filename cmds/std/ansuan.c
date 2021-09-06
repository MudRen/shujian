// ansuan.c ����
//by Yu Jue 98.09

#include <ansi.h>
#include <pktime.h>

inherit F_CLEAN_UP;

mapping default_where = ([
	"n":    "north",
	"s":    "south",
	"e":    "east",
	"w":    "west",
	"nu":   "northup",
	"su":   "southup",
	"eu":   "eastup",
	"wu":   "westup",
	"nd":   "northdown",
	"sd":   "southdown",
	"ed":   "eastdown",
	"wd":   "westdown",
	"ne":   "northeast",
	"nw":   "northwest",
	"se":   "southeast",
	"sw":   "southwest",
	"u":    "up",
	"d":    "down",
]);

mapping default_dirs = ([
	"north":	"����",
	"south":	"����",
	"east":		"����",
	"west":		"����",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":		"����",
	"down":		"����",
	"enter":	"����",
	"out":		"����",
]);

int main(object me, string arg)
{
	string who, where, dir, undir, where_temp, *name;
	object env, old_env;
	mapping exits;
	object target;
	string gen;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (!arg || sscanf(arg, "%s at %s", who, where_temp)!=2)
		return notify_fail("ָ���ʽ��ansuan <����> at <����>\n");

	env = environment(me);
	if (!env)
		return notify_fail("������Ҳȥ���ˡ�\n");
	old_env = env;

	if (!undefinedp(default_where[where_temp]))
		where = default_where[where_temp];
	else
		where = where_temp;

	if (!mapp(exits = env->query("exits")) || undefinedp(exits[where]))
		return notify_fail("û���������\n");

	if (!objectp(env = load_object(exits[where])))
		return notify_fail("������������⣬�뱨����ʦ��\n");

	if (env == old_env)
		return notify_fail("ֱ���� kill ָ����ˡ�\n");
	if (!old_env->valid_leave(me, where))
		return 0;

	if (env->query("no_fight"))
		return notify_fail("�����ֹս����\n");

	if (!objectp(target = present(who, env)))
		return notify_fail("�������û�д��ˡ�\n");

	if (wiz_level(me) < wiz_level(target))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if (userp(me) && userp(target)
	&& (target->query("age") < 17 || target->query("combat_exp") < 15000))
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

	if (userp(me) && me->query_condition("killer") && userp(target))
		return notify_fail("���뵽�Լ�����ͨ���ţ��ֲ�������������������\n");
	if (!target->is_character() || target->is_corpse())
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if (me->is_fighting())
		return notify_fail("����æ��ս���أ�������˼������ˣ�\n");
		
  if (userp(me) && userp(target)&& me->query("combat_exp")<1200000)
		return notify_fail("�Բ���,ֻ�д���1.2M�ſ��԰�����ˡ�\n");
		
	if (!living(target))
		return notify_fail(target->name() + "���Ѿ������ˣ��㻹�õ��Ű�����\n");

	if (target->query("no_ansuan") || target->query("job_npc"))
		return notify_fail("�㲻�ܰ�������ˣ�\n");

	if (!me->can_kill_ob(me, target))
		return notify_fail("���ɱ������ˣ�\n");

	if (me->query("jingli") < 100)
		return notify_fail("���޷����о��������㲻�˱��ˡ�\n");

	if (userp(me) && userp(target)) {
		if(me->query("no_pk")) return notify_fail("���Ѿ�����ϴ�֣���λ������˵ȹ�����\n");
		if(target->query("no_pk")) return notify_fail("�Է��Ѿ�����ϴ�֣��㻹�ǷŹ����ɡ�\n");
		if(target->query_temp("user_type") == "worker") return notify_fail(target->name(1)+"ֻ�Ǹ�����������ĳ�Ҳ̫���˰ɡ�\n");
	}

// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, target))
		return 0;



if (userp(target) && me->query("combat_exp")<1000000) //��������1M����PK����ֹ���׸����˼�JOB��
                return notify_fail("�Բ���,ֻ�д���1M�ſ���PK��\n");

if (userp(target) && target->query("combat_exp")<1000000) 
                return notify_fail("�Բ����밮��С���ѡ�\n");


if (userp(target) && me->query("combat_exp")<  target->query("combat_exp") * 2 /3 &&  !target->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");
		
if (userp(target) && me->query("combat_exp") > target->query("combat_exp") * 3 / 2 &&  !target->query_condition("killer")) 
                return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");






	dir = env->query("short");
	if (!undefinedp(default_dirs[where]))
		dir = default_dirs[where] + dir;

	undir = old_env->query("short");

	if(me->query("gender") == "Ů��")
		gen = "ٻӰ";
	else
		gen = "��Ӱ";

	write(CYN "����Ϣ���������������" + dir + "��" + target->name() + "��ȥ��\n" NOR);
	tell_room(old_env, CYN "\nһ��" + gen + "��Ȼ��" + dir + "��ȥ��\n" NOR, me);
	message_vision(CYN "\nһ��" + gen + "��Ȼ��" + undir + "��$N������\n\n" NOR, target);

	name = me->query_temp("apply/name");
	me->set_temp("apply/name", ({ gen }));

	me->move(environment(target));
	if (userp(me) && userp(target))
	{
		target->set_temp("other_kill/"+me->query("id"), 1);
 me->apply_condition("no_quit",20);
		log_file("ANSUAN", 
                        sprintf("%-18s ansuan %-18s",                                
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                target->name(1)+"("+capitalize(getuid(target))+")"
                        ),
                        this_object(),
                );
	}

	if (target->query_skill_mapped("force") == "hamagong"
	&& target->query_skill_mapped("parry") == "hamagong"
	&& target->query_skill("hamagong", 1) > 50
	&& target->query("oyf/hamagong") > 1) {
		tell_object(target, RED"��ͻȻ�е��������������������Ǹ�Ӧ����ʲôΣ����\n"NOR);
		message_vision(CYN"����$N������һ�ף����ڸ�󡹦��Ȼ�߶�����$nһ���ӷ����ȥ��\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"), 2);
		me->move(old_env);
		write(
			"����һ��Ѹ���˻أ���Ȼ���޴󰭣���Ҳ�����ˣ�\n"
			"�����������ӵ�и�󡹦������˵����ô�����ã�\n"
		);
		me->set_temp("apply/name", name);
		me->add_busy(2);
		me->receive_damage("jingli", 50);
		return 1;
	}
	
	if(meisdummy(me,target))
	{
		me->set_temp("apply/name", name);
		message_vision("$N��Ȼ�����Լ��������ף���ʱ�����ҡ�\n", me);
		me->set("qi", -1);
		return 1;
	}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);

	if (wizardp(me) || random(me->query("combat_exp")) > target->query("combat_exp")/2 ) {
		message_vision(CYN"$Nһʱû�з�������$n���˸����ֲ�����\n"NOR, target, me);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	} else {
		message_vision(CYN"$N����ḻ������ϸ����������$n������\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"), 1);
	}

	if (!wizardp(me) && random(me->query("combat_exp")) < target->query("combat_exp")/3) {
		me->set_temp("apply/name", name);
		tell_object(target, CYN"��һ����ԭ����" + me->name() + "�ڰ����㣡\n"NOR);
		write(CYN "���ã��㱻" + target->name() + "�����ˣ�\n"NOR);
		message_vision(CYN"$N�ȵ���$n����Ұ����ң��Ҹ���û�꣡\n"NOR, target, me);
		if (!userp(target)) target->kill_ob(me);
		else target->fight_ob(me);
		me->start_busy(4);
	} else {
		tell_room(env, CYN "\n" + gen + "ת˲������\n\n"NOR, me);
		write(CYN"\n�������˻�ԭ����\n\n"NOR);

		me->move(old_env);
		tell_room(old_env, CYN "\nת�ۼ�" + gen + "�ֻص�ԭ����\n\n"NOR, me);

		me->set_temp("apply/name", name);

		tell_object(target, CYN"��һ���񣬿���ʲô��û������\n"NOR);
		tell_room(env, CYN + target->name() + "һ���֣̿���Ȼ��֪������˭�İ��㣡\n"NOR, target);
		write(CYN "������" + target->name() + "��Ȼû��������\n"NOR);
		write(CYN "��ɿ���������һ���޹������ӡ�\n"NOR);
		me->start_busy(3);
		me->receive_damage("jingli", 50);
	}

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ansuan <����> at <����>

���ָ�����㰵��λ��<����>��<����>��
�������ɹ�������˷��ֲ����㡣����...:)
HELP
);
	return 1;
}

// bark.c ����
// Creat By Looklove@SJ at 2000/10/07
// Modify By Looklove@SJ 2001/1/19

#include <ansi.h>
#include <pktime.h>

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
        "north":                "����",
        "south":                "����",
        "east":                 "����",
        "west":                 "����",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":            "����",
        "southdown":            "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":            "����",
        "northwest":            "����",
        "southeast":            "����",
        "southwest":            "����",
        "up":                   "����",
        "down":                 "����",
        "enter":                "����",
        "out":                  "����",
]);

int main(object me, string arg)
{
	int mp,tp;
	string who, where, dir, undir, where_temp, *name;
	object env, old_env;
	mapping exits;
	object target;
	string gen,dir2;

	if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 )
		return notify_fail("ָ���ʽ��bark <����> at <����>\n");

	env = environment(me);

	if(!env) return notify_fail("��Ҫ����˭��\n");
	old_env = env;

	if( !undefinedp(default_where[where_temp]) )
		where = default_where[where_temp];
	else
		where = where_temp;

	if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) )
		return notify_fail("û���������\n");

	if( !objectp(env = find_object(exits[where])) ) {
		call_other(exits[where], "???");
		env = find_object(exits[where]);
	}

	if (env == old_env) return notify_fail("ֱ������ƨ�ɺ��ˡ�\n");
    	if( !old_env->valid_leave(me, where) ) {
        	write(query_notify_fail());
        	return 1;
        }

	if( !objectp(target = present(who, env)) )
		return notify_fail("�������û�д��ˡ�\n");

	if ( me->query("no_pk") )
		return notify_fail("���Ѿ�����ϴ�֣����ǲ�Ҫ���뽭�������ɣ�\n");

	if (wiz_level(me) < wiz_level(target))
		return notify_fail("�㲻�ܽ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if ( userp(me) && me->query("age") < 18 )
		return notify_fail("�����С����ô��ѧ�ã�\n");

	if ( userp(me) && userp(target) && target->query("age") < 16 )
		return notify_fail("�����̫����, С����Ҳ�\n");

	if ( !wizardp(me) && !userp(target))
		return notify_fail("�㲻�ܽ���NPC��\n");

// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, target))
		return 0;

	if(meisdummy(me,target))
	{
		return notify_fail("�����ף�һ������ȥ��\n");
	}

	if ( userp(me) && target->query("combat_exp") < 15000 )
		return notify_fail("�����̫����, ������Ҳ�\n");
		
 if ( userp(me) && me->query("combat_exp") < 2000000 )
                                return notify_fail("�Բ���,ֻ�д���2M�ſ��Խ�����ҡ�\n");

        if( me->query_condition("killer") && userp(target))
                return notify_fail("���뵽�Լ���ͨ�������̲�סѹ����������\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( me->is_busy() )
		return notify_fail("���ȴ������ٿ���ɡ�\n");

	if( me->is_fighting() )
		return notify_fail("����æ��ս���أ�������˼���ˣ�\n");

	if( !living(target))
		return notify_fail(target->name() + "��������ķϻ����㻹��ʡʡ�ɡ�\n");

	if( target->query("no_bark") || target->query("no_pk") || target->query("job_npc") )
		return notify_fail("�㲻�ܽ�������ˣ�\n");

	if( (int)me->query("jingli") < 500 )
		return notify_fail("�����ھ���ͷ���㣬û�˻����㡣\n");

	if(!wizardp(me)){
		if( env->query("no_fight")
			|| old_env->query("no_fight")
			|| !userp(target))
			return notify_fail("�˼��������㣬ʡʡ�ɡ�\n");
		}


if (userp(target) && target->query("combat_exp")<1000000) 
		return notify_fail("�����̫����, ������Ҳ�\n");


if (userp(target) && me->query("combat_exp")<  target->query("combat_exp") * 2 /3 &&  !target->query_condition("killer") ) 
			return notify_fail("�˼��������㣬ʡʡ�ɡ�\n");
		
if (userp(target) && me->query("combat_exp") > target->query("combat_exp") * 3 / 2 &&  !target->query_condition("killer")) 
		return notify_fail("�����̫����, ������Ҳ�\n");






	dir = env->query("short");
	if( !undefinedp(default_dirs[where]) )
		dir = default_dirs[where] + dir;

	undir = old_env->query("short");


	if(me->query("gender") == "Ů��")
		gen = "Ů��";
	else
		gen = "����";
	switch (where_temp) {
		case "north": 	dir2 = "south"; break;
		case "n": 	dir2 = "south"; break;
		case "south": 	dir2 = "north"; break;
		case "s": 	dir2 = "north"; break;
		case "east": 	dir2 = "west"; break;
		case "e": 	dir2 = "west"; break;
		case "west": 	dir2 = "east"; break;
		case "w": 	dir2 = "east"; break;
		case "northup": dir2 = "southdown"; break;
		case "nu": 	dir2 = "southdown"; break;
		case "southup": dir2 = "northdown"; break;
		case "su": 	dir2 = "northdown"; break;
		case "eastup": 	dir2 = "westdown"; break;
		case "eu": 	dir2 = "westdown"; break;
		case "westup": 	dir2 = "eastdown"; break;
		case "wu": 	dir2 = "eastdown"; break;
		case "southdown": dir2 = "northup"; break;
		case "sd": 	dir2 = "northup"; break;
		case "northdown": dir2 = "southup"; break;
		case "nd": 	dir2 = "southup"; break;
		case "eastdown": dir2 = "westup"; break;
		case "ed": 	dir2 = "westup"; break;
		case "westdown": dir2 = "eastup"; break;
		case "wd": 	dir2 = "eastup"; break;
		case "enter": 	dir2 = "out"; break;
		case "out": 	dir2 = "enter"; break;
		case "northeast": dir2 = "southwest"; break;
		case "ne": 	dir2 = "southwest"; break;
		case "northwest": dir2 = "southeast"; break;
		case "nw": 	dir2 = "southeast"; break;
		case "southeast": dir2 = "northwest"; break;
		case "se": 	dir2 = "northwest"; break;
		case "southwest": dir2 = "northeast"; break;
		case "sw": 	dir2 = "northeast"; break;
		case "up": 	dir2 = "down"; break;
		case "u": 	dir2 = "down"; break;
		case "down": 	dir2 = "up"; break;
		case "d": 	dir2 = "up"; break;
		}


	who = RANK_D->query_rude(target);
	write("�����˿�����˦�������ӣ���" + dir + "��" + target->name() + "�����"+who+"�����е��Ӿ͹������ұȻ��Ȼ���\n");
	tell_room(old_env, CYN "\nֻ��" + me->name() + "˦����������" + dir + "����������\n" NOR, ({me}));
	message_vision(CYN "\nһ��" + gen + "վ��" + undir + "��$N�������"+who+"���е��Ӿ͹������ұȻ��Ȼ���\n\n" NOR, target);

	name = me->query_temp("apply/name");

	if(!me->query_temp("apply/name"))
	me->set_temp("apply/name", ({gen}));

	mp = me->query("max_pot");
	tp = target->query("max_pot");

	if (target->query_busy()){
		me->set_temp("apply/name", name);
		message_vision(CYN"$N������ü����װû����������\n"NOR, target,me);
		message_vision(CYN"�Թ۵����˿���$N��������Ц������\n"NOR, target,me);
		me->start_busy(2+random(2));
		me->receive_damage("jingli", 50+random(50));
		return 1;
	}

	if( target->query("family/family_name")=="������"
	||target->query("family/family_name")=="������"
	||target->query("family/family_name")=="������"
	||target->query("family/family_name")=="�䵱��"
	||target->query("family/family_name")=="������"){
		if(random(tp)> random(mp)){
			write(CYN "�Է������ܸߣ������������ƽϡ�\n"NOR);
			me->set_temp("apply/name", name);
			me->receive_damage("jingli", 80+random(50));
			me->start_busy(1+random(2));
			return 1;
		}
		if(random(tp)>random(mp)/2){
		write(CYN "�Է������ܸߣ���һʱ�κβ�������\n"NOR);
		me->receive_damage("jingli", 80+random(50));
		me->set_temp("apply/name", name);
		me->start_busy(1+random(2));
		return 1;
		}
	}

	if( random(me->query_int()) > target->query_int()) {

		me->set_temp("apply/name", name);
		target->force_me("go "+dir2);

		if (!present(target,environment(me))){
			message_vision(CYN"$N���ߺߵغ�����$n����С�ĵ㣡�����Ҵ��ţ�����ÿ���\n"NOR, target, me);
			return 1;
		}

		tell_room(old_env, CYN "ֻ��"+target->query("name")+"ŭ������ش�" + dir + "���˹�����\n" NOR, ({target}));
		tell_room(env, CYN "ֻ��"+target->query("name")+"���಻ס�������ݵ���" + undir + "���˹�ȥ��\n" NOR, ({target}));
		message_vision(CYN"$N���������࣬��е���$n���ߣ�����Ҳ������\n"NOR, target, me);
		write(CYN "���ã��ۿ�" + target->name() + "�������ǰ��\n"NOR);

		target->set_temp("other_kill/"+me->query("id"), 1);
		
		if (userp(me) && userp(target))
		{
			log_file("ANSUAN", 
                        	sprintf("%-18s bark   %-18s",
                                	me->name(1)+"("+capitalize(getuid(me))+")",
                                	target->name(1)+"("+capitalize(getuid(target))+")"
                        	),
                        	this_object(),
                	);
		}
		if (!userp(target)) target->fight_ob(me);
		else target->fight_ob(me);

		me->receive_damage("jingli", 50+random(50));
		me->start_busy(2+random(2));
		return 1;
	}

	if( random(me->query("pur")) < target->query("pur")/2) {

		me->set_temp("apply/name", name);
		target->force_me("go "+dir2);

		if (!present(target,environment(me))){
			message_vision(CYN"$N���ŽŽе����������������㣬���������ƣ�\n"NOR, target, me);
			return 1;
		}

		tell_object(target, CYN"���߹�ȥһ����ԭ����" + me->name() + "�����Ž������أ�\n"NOR);
		tell_room(old_env, CYN "ֻ��"+target->query("name")+"ŭ������ش�" + dir + "���˹�����\n" NOR, ({target}));
		tell_room(env, CYN "ֻ��"+target->query("name")+"���಻ס�������ݵ���" + undir + "���˹�ȥ��\n" NOR, ({target}));
		message_vision(HIR"$N���˹������ȵ���$n��������ң������Ҹ���û�꣡\n"NOR,target,me);
		write(CYN "���ã�" + target->name() + "�������ڵ�������˹�����\n"NOR);

		if (!userp(target)&& random(4)!=1) {
			me->set_temp("kill_other/"+target->query("id"),1);
			target->kill_ob(me);
		}
		target->set_temp("other_kill/"+me->query("id"), 1);
		
		if (userp(me) && userp(target))
		{
			log_file("ANSUAN", 
                        	sprintf("%-18s bark   %-18s",
                                	me->name(1)+"("+capitalize(getuid(me))+")",
                                	target->name(1)+"("+capitalize(getuid(target))+")"
                        	),
                        	this_object(),
                	);
		}		
		target->fight_ob(me);
		me->receive_damage("jingli", 80+random(50));
		me->start_busy(1+random(2));
		return 1;
	}

	me->set_temp("apply/name", name);

	message_vision(CYN"$N������ü����װû����������\n"NOR, target,me);
	message_vision(CYN"�Թ۵����˿���$N��������Ц������\n"NOR, target,me);

	me->start_busy(2+random(2));
	me->receive_damage("jingli", 50+random(50));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : bark <����> at <����>

���ָ���������λ��<����>��<����>��
�������ɹ�����Է������򶷣��Է��п��ܻ��Զ�ɱ�㣬С�ġ�
HELP
);
	return 1;
}

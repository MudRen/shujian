// /u/beyond/mr/npc/obj/paper.c
// this is made by beyond
// update beyond

inherit ITEM;

#include <ansi.h>
string do_look();
void create()
{
	set_name(HIW"��"NOR, ({ "murong paper", "paper" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", (: do_look :));
		set("value", 0);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
		set("material", "paper");
	}
	setup();
}

void init()
{
	object ob = this_object();
	object me = this_player();
	
	ob->set_temp("skill_lvl", me->query_temp("skill_lvl"));	//��Ҫ͵ѧ�ļ��� 
	ob->set_temp("learned_skill",5);			       //�Ѿ�͵ѧ�ļ���
	ob->set_temp("learned_amount",0);
	add_action("do_touxue", "touxue");
}

string do_look()
{
	string msg;
	object me = this_player();

	msg = "����һ�ŷ��Ƶľ�";
	if ( me->query_temp("skill_target"))
		msg += "������д�ţ�͵ѧ"+ HIW+chinese_number(me->query_temp("skill_lvl"))+NOR+"�� "+HIY+me->query_temp("skill_target")+HIR+" ("+me->query_temp("skill_id")+")��\n"NOR;
	else 
		msg += "��\n";
	return msg;
}

int do_touxue(string arg)
{
	object ob, me, obj, weapon;
	string skill, skill_name, teacher;
	string *v_skill;
	int master_skill, gin_cost, lvl;
	mapping prepare;

	me = this_player();
	obj = this_object();
       
	if (me->query_temp("job_done"))
		return notify_fail(HIW"��о��Ѿ�����������"+me->query_temp("skill_target")+"�ľ��裬���Ի�ȥ�����ˡ�\n"NOR);
	       
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if( me->query("family/family_name") != "����Ľ��")
		return notify_fail("�㲻�ǹ���Ľ�ݵ��ӣ������Ͳ���͵ѧ��\n");

	if( me->query_skill("douzhuan-xingyi", 1) < 100 )
		return notify_fail("��Ķ�ת���Ƽ��𲻹����޷�����͵ѧ����߼����ܡ�\n");

	if(me->query_skill_mapped("parry") != "douzhuan-xingyi")
		return notify_fail("������û���ö�ת���ƣ���ô��͵ѧ�����˵��书��\n");

	if(!arg || (sscanf(arg, "%s from %s", skill, teacher)!=2 ))
		return notify_fail("ָ���ʽ��touxue <����> from <ĳ��>\n");

	if (!(ob = present(teacher, environment(me)))
	|| !ob->is_character()
	|| query_ip_number(ob) == query_ip_number(me))
		return notify_fail("��Ҫ��˭͵ѧ��\n");

	if (!ob->is_fighting(me) )
		return notify_fail("����ս������ô��͵ѧ�أ�\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if( skill != me->query_temp("skill_id") )
		return notify_fail("��һ������Ҫ͵ѧ�����书ô��\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("���������±����ұ���͵ѧ�ˡ�\n");

	if( !me->query_condition("mr_job"))
		return notify_fail("�㻹û���������ء�\n");

	if (userp(ob)) {
		if (objectp(weapon = ob->query_temp("weapon"))) {
			skill_name = weapon->query("skill_type");
			v_skill = ({ ob->query_skill_mapped(skill_name) });
		} else {
			prepare = ob->query_skill_prepare();
			if (!prepare) prepare = ([]);
			v_skill = ({});
			switch (sizeof(prepare)) {
				case 2: v_skill += ({ ob->query_skill_mapped(keys(prepare)[1]) });
				case 1: v_skill += ({ ob->query_skill_mapped(keys(prepare)[0]) });
			}
		}
		if (!arrayp(v_skill) || member_array(skill, v_skill) < 0) {
			return notify_fail("�Է����ڲ�û��ʹ�������书��\n");
		}
	}

	me->set_temp("master_exp", ob->query("combat_exp")/(userp(ob)?2:1));
	lvl = obj->query_temp("learned_skill");
	if( lvl >= me->query_temp("skill_lvl"))	{
		write(HIW"��о��Ѿ�����������"+me->query_temp("skill_target")+"�ľ��裬���Ի�ȥ�����ˡ�\n"NOR);
		me->set_temp("job_done", 1);
		return 1;
	}

	gin_cost = 500 / me->query("int");

	if( (ob->query("jing") > gin_cost/5 + 1 )
	&&  (ob->query("jingli") > gin_cost/5 + 1 )) {
		if( userp(ob) )
		 ob->receive_damage("jing", gin_cost/5 + 1);
		 ob->receive_damage("jingli", gin_cost/5 + 1);
	}
	else {
		write("����" + ob->name() + "��Ȼ̫���ˣ����Ѿ�û�а취͵ѧ��ʲô�ˡ�\n");
		return 1;
	}

	if( me->query("jing") > gin_cost && me->query("jingli") > gin_cost ){
	       if(skill_name = SKILL_D(skill)->query_skill_name(master_skill))
			write(sprintf("����ݶ�ת���Ƶľ��裬��ϸ��ĥ��%s��ÿ������������ԡ�%s����һ���ƺ���Щ�ĵá�\n",
				ob->name(), skill_name));
		else
			write("�����͵ѧ��"+to_chinese(skill)+"�ľ��������������С�\n");
		obj->add_skill(skill, me->query("int"));
	}
	else {
		write("��̫���ˣ���������Ϣһ�°ɡ�\n");
		return 1;
	}
	if (random(10) >= 7 && !userp(ob)) {
		message_vision("$NͻȻ������ʲô���鲻����ˣ�˫�۶���ɱ�⡣\n", ob);
		ob->kill_ob(me);
	}

	me->receive_damage("jing", gin_cost);
	me->receive_damage("jingli", gin_cost);
	me->start_busy(2);
	return 1;
}

void add_skill(string skill, int amount)
{
	object ob = this_object();
	int lvl,sum;
	if( !find_object(SKILL_D(skill))
	  && file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	ob->add_temp("learned_amount",amount);
	lvl = (int)ob->query_temp("learned_skill");
	sum = (int)ob->query_temp("learned_amount");
	if(sum>(lvl*lvl)) {
		ob->add_temp("learned_skill",1);
		ob->set_temp("learned_amount",sum-lvl*lvl);
	}
	return;
}

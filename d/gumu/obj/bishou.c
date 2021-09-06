// bishou.c ذ��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name( "ذ��" , ({ "bi shou", "sword", "bishou", "jian" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѱ�Ե������ذ�ף��������ն(zhan)������\n");
		set("value", 0);
		set("material", "iron");
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
	}
	init_sword(35);
	setup();
}

void init()
{
	add_action("mark_success", ({"zhan", "ն"}));
}

int mark_success(string arg)
{
	object me, target, ob,name1;
	me = this_player();
	name1 = me->query("id"); 

	if(!arg) return notify_fail("��Ҫնʲô��\n");  
	target = present(arg, environment(me));  

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("��������æ���ء�\n"); 

	if(!target) 
		return notify_fail("�Ҳ������������\n");

	if(!target->is_corpse()) 
		return notify_fail("������㣬�ǲ���ʬ�塣\n");

	if (target->query("race") != "����")
		return notify_fail("����ɣ���Զ����ʬ��Ҳ����Ȥ��\n");

	if(target->query("no_head")) 
		return notify_fail("�Ǿ�ʬ���Ѿ�û���׼��ˡ�\n");

	if(!target->is_character()) 
		return notify_fail("�Ǿ�ʬ���Ѿ������ˡ�\n");

	if( me->query_conditions_by_type("job") && target->query("kill_by") != me)
		return notify_fail("�㻹�ǰ���������ɣ����б���ɱ���˸��𰡣�\n"); 

	message_vision(HIR"$N����ذ�� ����׼$n�Ĳ��Ӵ��͵�ն����ȥ��\n"NOR, me, target);
	ob=new("/clone/misc/head");
	ob->set_name(target->query("victim_name")+"���׼�",({"head"}));
	ob->set("long", "����һ��"+target->query("victim_name")+"���׼���\n");    

	if(target->query("victim_user")) 
		ob->set("victim_user", 1);  
	if(target->query("kill_by")){ 
		ob->set("kill_by", target->query("kill_by"));
		target->delete("kill_by");
	}

	ob->set("victim_id", target->query("victim_id"));
	ob->set("victim_name", target->query("victim_name"));
	target->delete("victim_id");
	target->delete("victim_id");

	message_vision(HIR"$N��$nն���������������С�\n"NOR, me, ob);
	ob->move(me);
	target->set("name", "��ͷʬ��");
	target->set("no_head", 1);
	target->set("long", "һ����ͷʬ�壬�������磬��״�ɲ���\n");           
	return 1;
} 

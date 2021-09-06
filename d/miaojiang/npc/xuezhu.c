// /d/miaojaing/npc/xuezhu.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(WHT"ѩ��"NOR, ({ "xue zhu", "zhu" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", WHT"һֻͨ��ѩ�׵�С֩�룬������Ϊ���ء�\n"NOR);
        set("attitude", "peaceful");
        set("str", 10);
        set("cor", 30);
        set("limbs", ({ "ͷ��", "����","β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 50000);
        set("qi",-1);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        setup();
   	if (clonep()) call_out("destroying2", 30, this_object());
}

void destroying2(object me)
{
	if(!me) return;
	if((!living(me)))
	{
		call_out("destroying2", 30, this_object());
		return;
	}
	message_vision("$NͻȻ�ڵ����ϲ����ˡ�\n", me);
	destruct(me);
	return;
}

void destroying(object me)
{
	if(!living(me) && environment(me)->query("name") != "��Ͳ"){
		message_vision("$NͻȻ�ڵ����ϲ����ˡ�\n", me);
		destruct(me);
		return;
	}
	call_out("destroying", 3, this_object());
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 50);
	return 0;
}

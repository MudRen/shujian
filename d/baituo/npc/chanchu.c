#include <ansi.h>
inherit NPC;
void create()
{
    	set_name(HIW"�������"NOR, ({ "xuanbing chanchu", "chanchu", "hama", "xuanbing" }) );
    	set("race", "Ұ��");
    	set("age", 40);
    	set("long", "һֻͨ��ѩ�׵���ܣ�ſ����ʯ����һ��������\n");
    	set("attitude", "peaceful");
    	set("limbs", ({ "ͷ��", "����", "��֫", "��Ƥ" }) );
    	set("verbs", ({ "hoof"}) );
    	set("combat_exp", 15000);
    	set("max_qi", 10000);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 700);
	setup();
}

void init()
{
        object ob = this_player();
        ::init();
        if (interactive(ob) && userp(ob) &&
                !ob->query_skill("hamagong", 1)) {
                        this_object()->kill_ob(this_player());
        }
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("cold_poison",
                victim->query_condition("cold_poison") + 100);
        return 0;
}
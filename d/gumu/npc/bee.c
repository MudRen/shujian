// bee.c
// Modify By River 98/09
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���", ({ "yu feng", "bee","feng" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "ֻ������ҳ����С���ȵס����֣�������С����ھ������֣�ÿ����ϸ����\n"+
                    "�������ʻ�����������ü�ϸ����̳ɡ�\n");
        set("attitude", "peaceful");         

        set("str", 20);
        set("con", 30);

        set("limbs", ({  "����",  "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set_temp("apply/attack", 35);
        set_temp("apply/damage", 23);
        set_temp("apply/armor", 24);

        setup();
}


void die()
{
        message_vision("$N����һ�ƻ��䣬������ɢ��ʬ��ȫ�ޡ�\n", this_object());
        destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("bee_poison", victim->query_condition("bee_poison") + 20);
        return 0;
}     

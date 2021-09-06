// bee1.c
// Modify By River 98/09
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("���", ({ "yu feng", "bee" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "����һֻС��Ů��������䡣\n");
        set("attitude", "peaceful");         

        set("str", 20);
        set("con", 30);

        set("limbs", ({  "����",  "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 13);
        set_temp("apply/armor", 14);

        setup();
}

void init()
{
        mapping fam;
        object ob;
        ::init();
        if (interactive(ob = this_player())
         && (fam = ob->query("family"))
         && fam["family_name"] != "��Ĺ��"){
                message_vision(HIR"$N���Դ����Ĺ���ء�\n"NOR,ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
                set_leader(ob);
        }
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

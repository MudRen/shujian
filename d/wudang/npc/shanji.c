// NPC : /d/wudang/npc/shanji.c ɽ��
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"ɽ��"NOR, ({ "shan ji", "ji"}) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��ë�����Ĵ�ɽ����\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
        
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵ������˼�����һͷ�ص��������ˡ�\n", this_object());
        ob = new(FOOD_D("sjitui"));
        ob->move(environment(this_object()));
        destruct(this_object());
}
        

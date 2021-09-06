// NPC : /d/wudang/npc/bird.c С��
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"С��"NOR, ({ "xiao niao", "niao","bird"}) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻʮ�ֿɰ���С��\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "ͷ��", "����", "��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
        
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}


// cow.c ���ţ
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"���ţ"NOR, ({ "da huangniu", "huangniu", "cow" }));
        set("long","һͷ�ݹ���᾵Ĵ��ţ����֪��˭�ҵģ�����ͷ����س��Ųݡ�\n");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("can_ride",1);
        set_temp("no_return",1);
        set("unique", 1);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 700);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        set("chat_chance", 2);
        set("chat_msg", ({
        "���ţ�޹��Ŀ����㣬����������Щʲô��\n",
        "���ţ���д��Ŵ�����\n",
        }) ); 

        setup();
}

//Cracked by Roath
// aijiao-ma.c ������
inherit NPC_TRAINEE;

#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("������", ({ "aijiao ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ���ְ��������ͳ�;��\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 100);
	set("ability", 3);

	set("ridable", 1);
	set("str", 70);
	set("con", 20);
	set("dex", 20);
        set("int", 20);
	set("apply/attack", 50);

	set("max_jingli", 1200);
	set("combat_exp", 1000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
	set_weight(80000);

        setup();
}

int return_home(object home)
{
        return 1;
}

//Cracked by Roath
//huangbiao-ma.c �Ʊ���
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("�Ʊ���", ({ "huangbiao ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ��ɫ�ĸ�ͷ��������ȫ���ɫ����һ����ë��\n");
	set("msg_fail", "$n����$Nŭ˻һ�������ǰ�㣬��������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n�͵ش���һ�������ߵ�$N��ߣ���˳�ص�����ͷ");
        set("attitude", "peaceful");

        set("wildness", 5);
	set("value", 43);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
        set("con", 40);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 450);
	set("combat_exp", 12000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
        set_weight(100000);

        setup();
}

int return_home(object home)
{
        return 1;
}

//Cracked by Roath
// chuan-ma.c ����

inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();

void create()
{
	set_name("����", ({ "chuan ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ���Ͱ�С�� �Ƶ�ɽ�� �ͳ�;������Ĵ���\n");
	set("msg_fail", "$n����$Nһ��β�ͣ�����������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 3);
	set("value", 100);
	set("ability", 5);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
	set("dex", 30);
        set("int", 20);

	set("max_jingli", 670);
	set("combat_exp", 10000);
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


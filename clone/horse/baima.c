//Cracked by Roath
// bai-ma.c ����

inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
        set_name("����", ({ "bai ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ��ɫ�Ĵ�������������ʨ�ף�������࣬�ƺ���ƥ����\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

        set("wildness", 6);
        set("value", 80);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
        set("dex", 40);
        set("int", 20);
	set("apply/attack", 75);

	set("max_jingli", 630);
	set("combat_exp", 10000);
        set_weight(100000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
        setup();
}

int return_home(object home)
{
        return 1;
}

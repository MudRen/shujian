//Cracked by Roath
// hei-ma.c ����
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
	set_name("����", ({ "hei ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ��ɫ����ֻ�ڶ�Ǵ���һ���װߣ�������ƥ����\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 7);
        set("value", 70);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
	set("dex", 35);
        set("int", 20);

	set("max_jingli", 600);
	set("combat_exp", 8000);
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

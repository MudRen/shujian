//Cracked by Roath
// hong-ma.c ����
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
        set_name("����", ({ "hong ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 8);
        set("long", "����һƥ��ɫ���������������쳣����һ��ɽ����\n");
	set("msg_fail", "$n����$Nҡ�����Դ���");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 62);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 25);
	set("dex", 35);
        set("int", 20);

	set("max_jingli", 600);
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

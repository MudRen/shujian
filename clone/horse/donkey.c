//Cracked by Roath
//xiao-ma.c Сë¿
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("Сë¿", ({ "donkey", "xiao maolu", "lu" }) );
        set("race", "����");
	set("age", 4);
	set("long", "����һƥСë¿�������Ѿ��ܽ�׳��\n");
	set("msg_fail", "$n��ͣ�س���$Nҡ�����Դ���");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 3);
	set("value", 10);
	set("ability", 2);

	set("ridable", 1);
	set("str", 40);
	set("con", 40);
	set("dex", 10);
	set("int", 15);
	set("max_qi", 400);
	set("qi", 400);
	set("max_jingli", 400);
	set("combat_exp", 500);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
	set_weight(5000);

        setup();
}

int return_home(object home)
{
        return 1;
}

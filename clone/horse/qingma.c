//Cracked by Roath
// daqing-ma.c ������
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
	set_name("������", ({ "daqing ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 15);
	set("long", "����һƥ��ɫ�Ĵ�����������ʨ�ף�������࣬ȷ��ƥ����\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 50);
	set("ability", 4);

	set("ridable", 1);
        set("str", 90);
	set("con", 35);
	set("dex", 25);
        set("int", 20);
	set("max_qi", 700);
	set("qi", 700);
	set("max_jingli", 550);
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

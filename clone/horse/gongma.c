//Cracked by Roath
// gong-ma.c ����
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);

void create()
{
	set_name("����", ({ "gong ma", "ma", "horse" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ�������ɴ��������� �ߴ��񿥣� ͨ��ѩ�ף�
	 �����ڻ��ң� ֻ������������䡣\n");
	set("msg_fail", "$n����$Nŭ˻һ����ȫ��ë����������ŭ������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߷���������һ��������������ӣ�");
        set("attitude", "peaceful");

	set("wildness", 10);
	set("value", 220);
	set("ability", 6);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 900);
	set("combat_exp", 10000);
        set_weight(100000);

        setup();
}

int return_home(object home)
{
        return 1;
}

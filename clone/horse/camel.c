//Cracked by Roath

inherit NPC_TRAINEE;
int condition_check();
int return_home(object home);
#include "/clone/horse/horse.h"
void create()
{
	set_name("����", ({ "camel", "luo tuo", "luotuo" }) );
        set("race", "����");
        set("age", 10);
	set("long", "����һƥ�ߴ�׳�����ա����Ǵ������ŵĵ����㣬��������ɳ�а�Ȼ���ߣ�\n"
		    "�����������ܽ�ë���۾��������ڷ�ɳ��ʶ;��������ϸ������ë������\n"
		    "��ɳĮ�п������ȡ������ǵ�ɳĮ�����еıر�֮�\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
        set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
        set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
        set("attitude", "peaceful");

	set("wildness", 6);
	set("value", 120);
	set("ability", 8);

	set("ridable", 1);
	set("str", 80);
        set("con", 40);
	set("dex", 50);
        set("int", 20);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jingli", 3000);
	set("combat_exp", 20000);
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

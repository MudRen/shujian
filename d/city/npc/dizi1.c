// dizi1.c

inherit NPC;
#include "/kungfu/class/gaibang/begger.h";

void create()
{
        set_name("С��ؤ",({ "xiao qigai", "qigai", "xiao" }) );
        set("gender", "����" );
        set("age", 10);
        set("long", "����һ������ؤ���С���ӣ����ϻ����������Ц�ݡ�\n");
        set("attitude", "peaceful");

        set("shen", -1000);
        set("shen_type", -1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);

        set("combat_exp", 300);

        set_skill("unarmed", 20);
        set_skill("begging", 20);

        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);

        setup();

	carry_object(ARMOR_D("caoxie"))->wear();
	carry_object(ARMOR_D("bainayi"))->wear();
	carry_object(CLASS_D("gaibang/obj/gb_budai1"))->wear();
}


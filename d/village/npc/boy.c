// /d/village/npc/boy.c

inherit NPC;

void create()
{
	set_name("�к�",({ "nan hai", "boy" }) );
        set("gender", "����" );
        set("age", 5+random(7));
        set("long",
"���Ǹ�ũ�����꣬������С��ũ����Ȼ��Ͳ��󣬿��ѳ��ĺܴ�׳�ˡ�\n");
        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

	carry_object(ARMOR_D("armor/cloth"))->wear();
	add_money("coin",random(30));
}


// /d/village/npc/oldwoman.c

inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "lao daniang", "woman" }) );
        set("gender", "Ů��" );
        set("age", 60+random(20));
        set("long", "һ��������˪֮ɫ�������š�\n");
	set("shen_type", 1);
	set("combat_exp", 1500);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		"�ϴ������ĵ�˵�����Ǹ���ɱ�ģ�͵���ҵ���ĸ����\n",
		"�ϴ���̾�˿�����˵�������Ǹ�ʲ����������\n",
		"�ϴ�����������ż�������������ˡ�\n",
	}));
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", random(100));
}

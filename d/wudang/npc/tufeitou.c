// NPC : /d/wudang/npc/tufeitou.c

inherit NPC;

void create()
{
	set_name("����ͷ", ({ "tufei tou","bandit leader","tou" }) );
	set("gender", "����");
	set("age", 54);
	set("long",
		"��һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
	set("combat_exp", 300000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 80);
	set("apply/defense", 80);

	set("chat_chance", 5);
	set("chat_msg", ({
		"����ͷ�ٺٵ���Ц��: ������ͱ����������ų�ȥ��!\n",
	}) );

	set_skill("sword", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 80);
}

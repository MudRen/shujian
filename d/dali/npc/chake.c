//  chake.c
inherit NPC;

void create()
{
	set_name("���", ({ "cha ke","ke" }) );
	set("gender", "����");
	set("age", 10+random(30));
	set("long",
		"���Ǵ�����ڲ���ڵ�һλ��ͣ�����������ζ��Ʒ�Ų衣\n");
	set("combat_exp", 16000);
	set("shen_type", 1);
	set("attitude", "friendly");
	setup();

	set("apply/attack", 20);
	set("apply/defense", 20);

	set_skill("unarmed", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("dodge", 36);
	setup();

	carry_object("/clone/misc/cloth")->wear();
       add_money("silver", random(10));

}       


// liumangtou.c ��åͷ

inherit NPC;

void create()
{
	set_name("��åͷ", ({ "liumang tou", "liumang", "liu" }));
	set("gender", "����");
	set("age", 25);
	set("long", "�����ü�������ģ�һ���Ͳ����Ǹ����ˡ�\n");
	
	set("combat_exp", 7000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	set("inquiry", ([
		"name" : "�����ү�ҡ���ͷ��������������ʶ�����벻������Э���ˣ���",
		"rumors" : "�鱦��������Щ�����⣬���ǽ�ָ���������ʲô�ģ���˵���б����飬�����ܳ������ϣ������������ȥ��������",
		"here" : "����������ѽ��ȥ����ͼ�ɡ�",
	]));
	setup();
     carry_object("/d/city/npc/cloth")->wear();
	add_money("silver", 18);
}

//  biaotou.c
inherit NPC;

void create()
{
	set_name("������ͷ", ({ "dali biaotou","biaotou" }) );
        set("title","�����ھ�");
	set("gender", "����");
	set("age", 44);
	set("long","����һ����ͷ�����ϴ������ꡣ\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	setup();

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("dodge", 66);
	setup();

	carry_object("/clone/armor/beixin")->wear();
	add_money("silver", 40);
}       


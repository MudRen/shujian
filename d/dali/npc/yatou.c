//  yatou.cѾͷ

inherit NPC;

void create()
{
	set_name("Ѿͷ", ({ "ya tou","ya" }) );
	set("gender", "Ů��");
	set("age", 14);
	set("long",
		"������ڴ��˼ҵ�һ��СѾͷ,�Ͻ�������\n");
	set("combat_exp", 700);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	"name" :"�ߣ����ǲ��Ƕ��Ҳ������Ⱑ��",
	]) );
	setup();

	set("apply/attack", 10);
	set("apply/defense", 10);

	set_skill("unarmed", 20);
	set_skill("claw", 20);
	set_skill("parry", 20);
	set_skill("dodge", 26);
	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 3);
}       


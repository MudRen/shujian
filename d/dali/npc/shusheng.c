//  shusheng.c
inherit NPC;

void create()
{
	set_name("��������", ({ "luopo shusheng","shusheng" }) );
	set("gender", "����");
	set("age", 24);
	set("long",
		"����һ�����������ĺ��Ǽ��ӣ�һ����ü���������ӡ�\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	"name" :"�����������ҵ�������ʲô�ã��ǻ����������и��ϡ���",
	]) );
	setup();

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 40);
	set_skill("strike", 40);
	set_skill("parry", 40);
	set_skill("dodge", 46);
	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 15);
}

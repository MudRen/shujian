// Modify By River 98/12 
inherit NPC;

void create()
{
	set_name("ɨ������", ({ "saodi puren","puren" }) );
	set("gender", "����");
	set("age", 34);
	set("long","����������һ��ɨ�����ˡ�\n");
	set("title", "������������");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	     "name" :"���˶����Ұ�ľ����ͽ��Ұ�ľ���ˡ�",
	]));

	set("apply/attack", 50);
	set("apply/defense", 50);

	set_skill("unarmed", 50);
	set_skill("cuff", 50);
	set_skill("parry", 50);
	set_skill("dodge", 56);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}       


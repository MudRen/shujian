
inherit NPC;

void create()
{
	set_name("�ο�", ({ "you ke",  "ke" }) );

	if(random(10)<6)
		set("gender","����");
	else
		set("gender","Ů��");

	set("age", 20);
	set("str", 16);
	set("con", 24);
	set("dex", 11);
	set("per", ( 10+random(18)) );

	set("attitude", "peaceful");

	set("force", 50);

	set("food",100);
	set("water",100);

	set("long", "���������ƺ�������ˡ�\n");
                                       

	set("combat_exp", 1000);

	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("literate", 60);

	set("chat_chance", 2);
	set("chat_msg",({
		"�οʹ�е�������ù���浹ù����\n",
		"�οͿ������ݺݵ�˵�������㣡С�ĵ㣡����û��ô�����˽ᣡ��\n",
	}) );

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 30);
}

inherit NPC;
void create()
{
	set_name("�ο�", ({ "you ke",  "ke" }) );
	set("long", "����˿������ƺ�������ˡ�\n");
	if(random(10)<6)
		set("gender","����");
	else
		set("gender","Ů��");

	set("age", 20);
	set("str", 16);
	set("cor", 24);
	set("cps", 11);
	set("per", (10 +random(18)));

	set("attitude", "peaceful");

	set("food",100);
	set("water",100);

	set("combat_exp", 5000+random(20000));

	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("literate", 60);

	set("chat_chance",3);
	set("chat_msg",({
		"�οʹ�е�������ù���浹ù����\n",
		"�οͿ������ݺݵ�˵�������㣡С�ĵ㣡����û��ô�����˽ᣡ��\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 30);
}

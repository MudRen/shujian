// Write By Yanyang@SJ 2001.9.26
// NPC: /d/changan/npc/luotiman.c

inherit NPC;
void create()
{
	set_name("��������", ({ "luoti nanzi","nanzi" }) );
	set("gender", "����" );
	set("age", 26);
	set("per",30);
	set("no_quest", 1);
	set("long","����һλ����ϴ����������ˡ�\n");

	setup();
}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me=this_player();
	if ( arg == "luoti nanzi" || arg == "nanzi") {
		command("say ��ʲô����û������");
		message_vision("�������Ӻݺݵ���$Nһ�ۡ�\n\n",me);
	}
	return 0;
}

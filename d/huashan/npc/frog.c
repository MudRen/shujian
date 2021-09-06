// NPC: /d/huashan/npc/frog.c
// Last modify by Yanyang because erroneous word
// Date: Look 99/03/25
// Lklv Modify at 2001.10.18

inherit NPC;

void create()
{
	set_name("����", ({ "qing wa", "qingwa" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "����һ���ʴ�����ܡ�\n");
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
	set("verbs", ({ "hoof", "bite" }) );

	set("combat_exp", 10000);
	set("shen_type", -1);
	set("chat_chance", 10);
	set("chat_msg", ({
		"���ܽе��������ɡ����������ɡ�����\n",
	}) );
	set("str",10);
	set("dex",50);
	set("con",10);
	setup();
}

void die()
{
	object ob;
	message_vision("$N���ˡ�\n", this_object());
	ob = new(__DIR__"obj/frog-meat");
	ob->move(environment(this_object()));
	destruct(this_object());
}

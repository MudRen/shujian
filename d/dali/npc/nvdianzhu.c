#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("Ů����", ({ "nv dianzhu", "dianzhu", "master" }));
	set("shen_type", 1);

	set("str", 20);
	set("gender", "Ů��");
	set("age", 35);
	set("long", "Ů�����þӴ���ǣ�֪�������ֵ��˲����࣬��˵������ʱ���м��ַ��ϡ�\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "С���ӷ�����\n",
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();

}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting() && visible(ob)) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say(CYN"Ů����Ц���е�˵�������������������ҽ���Ư��ô��\n"NOR);
		break;
	case 1 :
		say(CYN"Ů����˵��������ģ���Ҫ��ʲô��\n"NOR);
		break;
	}
}

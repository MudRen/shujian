// little_monkey.c

inherit NPC;

void create()
{
	set_name("С��",({ "xiao hou","xiao" }) );
        set("race", "Ұ��");

        set("age", 4);
        set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
        set("combat_exp", 1000+random(2000));
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
        setup();
}

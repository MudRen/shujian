// monkey.c 

inherit NPC;

void create()
{
	set_name("����", ({ "hou zi","hou" }) );
        set("race", "Ұ��");
	set("age", 8);
	set("long",
		"��ֻ���������������������£�����ʱ�����ζ�ؿм��������ҡ�\n");
	set("combat_exp", 500);
	set("attitude", "peaceful");
	
	set("water", 200);
	set("food", 200);

	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);

        set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	setup();
}

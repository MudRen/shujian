// jian-ke.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "jian ke","ke" }) );
	set("gender", "����");
	set("age", 45);
	set("long",
		"����λ�������ˣ��米�����������Ľ������Ʈ������ƺ������ա�\n");
        set("combat_exp", 25000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

        set_skill("sword", 70);
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}

void init()
{
	object room, ob;
	string mengzhu;
	
	if(!( room = find_object("/d/taishan/fengchan")) )
	room = load_object("/d/taishan/fengchan");

	if( objectp(ob = present("mengzhu", room)) ) 
	mengzhu = ob->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "������$N����Ϊ��˵�������������˼Һã�\n" NOR, 
		this_player());
	}	
}

// dao-ke.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "dao ke","ke"}) );
	set("gender", "����");
	set("age", 20);
	set("long",
		"��һ��������⣬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 13000);
        set("shen_type", -1);
	set("attitude", "heroism");

        set_skill("unarmed", 40);
        set_skill("blade", 40);
        set_skill("parry", 35);
        set_skill("dodge", 35);

	setup();

        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/misc/cloth")->wear();

	add_money("silver", 10);
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

// zhong2.c �Ӱ��� 

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�Ӱ���", ({ "zhong asi", "zhong","asi" }));
	set("long",
		"������������һ�����Ե�վ�š�\n");
	set("gender", "����");
	set("age", 38);

	set("str", 23);
        set("int", 15);
        set("con", 20);
        set("dex", 18);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 2000);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
	

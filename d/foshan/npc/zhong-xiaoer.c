// zhong3.c ��С�� 

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name("��С��", ({ "zhong xiaoer","zhong", "xiaoer" }));
	set("long",
		"������˫�㣬�¿��ѱ��񹷵�צ��˺��ϡ�ã����һ·������Ѫ��\n");
	set("gender", "����");
	set("age", 13);
	set("attitude", "friendly");

	set("str", 15);
        set("int", 15);
        set("con", 25);
        set("dex", 20);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 500);

	set("inquiry", ([
		"��С��"   : (: ask_me :),
	]) );
	set("shen_type", 0);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	if( (random(10) < 5) || is_fighting() )
		return "�ҡ���֪����\n";
	else 
	{
		if( this_player()->query_temp("marks/feng"))
		{
			this_player()->delete_temp("marks/feng");
			this_player()->set_temp("marks/zhong",1);
			return "������ĺ�ԩ��ѽ!";	
		}	
	else return "���費������˵����";
	}
}

// Room: /d/huashan/shiwu1.c
// Date: Look 99/03/25

// Modified by mxzhao 2004/02/20
// By Spiderii@ty �����츳
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
һ�䲻���չ��ʯ�ң�ǽ������Ƕ�ż�֦���ͻ�ѣ�ʹ�������ǻ�ƵĹ�
�Ρ����˵�Ψһ�о���Ҳ����������ڴ˾����������ϵĽ������衣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__ "jiabi",
		]));

	setup();
}

 void init()
{
	add_action("do_lingwu", "comprehend");
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	object me=this_player();
	int sl,dl,lv;

	if (arg != "sword" 
		&& arg != "jiujian" 
		&& arg != "dugu jiujian"
		&& arg != "dugu-jiujian"
		&& arg != "�Ž�"
		&& arg != "���¾Ž�" )
	{
		write("��Ҫ����ʲô��\n");
		return 1;
	}
	
	if(!me->query("fengset"))
	{
		write("��Ƿ���ǰ���ĵ��ӣ������ڴ�����\n");
		return 1;
	}

	if (me->is_busy() || me->is_fighting())
	{
		write("����æ���ء�\n");
		return 1;
	}

	sl = (int)me->query_skill("sword", 1);
	dl = (int)me->query_skill("dugu-jiujian", 1);
	lv =  me->query("max_pot")-100;
	if (!dl)
	{
		write("�������¾Ž����ܾ�ʽ��û��˵����Ϲ����ʲô?\n");
		return 1;
	}
	
	if (sl > me->query("jing") 
		|| me->query("jing")*100/me->query("max_jing") < 50)
	{
		me->receive_damage("jing", sl/2);
		write("��û�취���о���\n");
		return 1;
	}
/*
        if (dl >= 150 && dl < 350 
		&& ((int)me->query("max_pot") - 100 
		< dl + (int)me->query_skill("huashan-jianfa",1)))
	{
		write("ѧϰ���¾Ž�����������"
			"������Ļ�ɽ������ϰ̫��޷��������������Ľ����ˡ�\n");
		return 1;
	}
*/
	if (sl < dl)
	{
		write("��Ļ����������費����"
			"�޷��������һ��Ķ��¾Ž����⡣\n");
		return 1;
	}
	
	if((int)me->query("potential", 1) < 5 )
	{
		write("�����ڵ�Ǳ�ܲ�����������¾Ž���\n");
		return 1;
	}
	
	write(CYN"��ĬĬ���:������������������ͬ�ˣ�ͬ�������С���ת����\n"
		"��ת������ת��ӳ�֮��������֮������δ֮����������һ�䣬\n"
		"ɽ����һ�䣬ˮ����һ�䡣Ǭ���༤������༤�������༤��\n"
		"���������壬�������ɾš�����\n"NOR);
	
	if( me->query_skill("dugu-jiujian",1 ) < 200)
	{
		me->add("potential", -random(5));
	}
	me->start_busy(random(2));
    me->improve_skill("dugu-jiujian", 
               ( random(me->query_int()) + 5)*20 + 1);
	return 1;
}


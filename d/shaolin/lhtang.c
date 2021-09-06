// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"�޺���"NOR);
    set("long", @LONG
����ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д�š��޺��á�
�������֡����������ֵ�����ϰ���Ż����书�����ڡ��кܶ������ɮ�˽���
������Ժ�ڴ����������������������
LONG
);

	set("exits", ([
		"east" : __DIR__"stoneroad4",
		"west" : __DIR__"lwc",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		"/kungfu/class/shaolin/xuan-ku" : 1,
	]));
	set("coor/x",30);
	set("coor/y",280);
	set("coor/z",120);
	setup();
}

void init()
{
	add_action("do_jump", "zong");
}

int do_jump(string arg)
{
	object me=this_player();   

	if (arg!="bian") return 0;
	if (me->is_busy()) return 0;
	if(me->query_skill("dodge",1)<130)  
		return notify_fail("�㹦���������������Ҷ\n");  
	message_vision("$N�������У�ƽ�հ������ɣ����������Ҷ�֮��\n", me);
	me->move(__DIR__"bianhou");
	tell_room(environment(me), me->name()+"����������\n", me);
	me->set_temp("baitie",1);
	return 1; 
}

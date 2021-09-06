// ɽ��
// gaoshan0.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","��ɽ����");
	set("long",
"���������ߵ�ɽ�壬�Ӱ�ɽ������������ƣ���ɽ���������������Ų���
������ݣ����в��ٺ����Ķ����û����ɽ��������ҩ�Ĳ��أ����궼������
�Ĳ�ҩ��æµ��䡣
��̧ͷ��ȥ���ƺ���һ����ɽ·������䣬��֪��ͨ���δ���
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"west"		: "/d/chengdu/road1",
		"northup"	: __DIR__"gaoshan1",
		"southup"	: __DIR__"gaoshan2",
		"eastup"	: __DIR__"gaoshan3",
	]));
	
	set("outdoors", "�ɶ�����");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

// Added by mxzhao 2004/03/06
int valid_leave(object me, string dir)
{
	if (dir != "west")
	{
		return notify_fail("�˵ؽ������޳�û����ֹͨ�С�\n\n\t\t�ɶ�֪����\n");
	}

	return ::valid_leave(me, dir);
}

void init()
{
          add_action("do_push", "climb");
}

int do_push(string arg)
{
         object me = this_player();
          if (arg != "ɽ·")
                  return notify_fail("��Ҫ��ʲô?\n");
          if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ���ء�\n");

if(me->query("family") && me->query("family/family_name")!="��ң��")
                  return notify_fail("��Ҫ��ʲô??\n");
me->add_busy(3);
     message_vision("$N����һԾ����ʧ��һ����С·�в����ˡ�\n", me);
          me->receive_damage("jing", 30);
          me->move("/d/xiaoyao/muwu2");
          return 1;
}


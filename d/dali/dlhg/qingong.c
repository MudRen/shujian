inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "�޹�");
	set("long", @LONG
������Ǳ����۵��޹��ˣ��޹��������ö��ܼ�࣬�����Ǵ��ϱ���Ļ�
������ֻ�е���֮�����е�����ͼ����������Ͳ����뵽������Ǵ���ʵ۶�
�������޹���
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
            __DIR__"npc/queen" : 1
	]) );

	set("coor/x",-310);
  set("coor/y",-380);
   set("coor/z",-20);
   setup();
}



inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǵ���ʹ��ĺ�Ժ���ٽ�ȥ���Ǳ����۵��޹��ˣ����ڱ���������ϲ
��������������������߶�����������һ�־��׵ĸо���
LONG
	);

	set("exits", ([
		"north" : __DIR__"qingong",
		"south" : __DIR__"xiaoqiao",
	]));
	set("outdoors", "����");
	set("coor/x",-310);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}

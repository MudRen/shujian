// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ȣ��������������������������ʾ�����ﲻ��Ѱ���ĵ�
����������һ��С�ӣ���������С�ţ��ƺ�ͨ��󹬡�
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaoqiao",
		"south" : __DIR__"huating",
                "west" : __DIR__"dadian",
                "east" : __DIR__"xiangfang", 
	]));
	set("coor/x",-310);
  set("coor/y",-410);
   set("coor/z",-20);
   setup();
}

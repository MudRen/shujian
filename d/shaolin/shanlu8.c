// Room: /d/shaolin/shanlu8.c
// Date: bren

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢���������������������������һƬ���֣�����
����һ��ľ��(mupai)��
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin1",
		"southwest" : __DIR__"shanlu7",
        ]));
        set("item_desc",([
		"mupai"	:   "�����»������֣�Υ��������ɱ���⣡\n",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",60);
  set("coor/y",520);
   set("coor/z",160);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}

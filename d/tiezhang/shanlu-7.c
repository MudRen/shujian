// Room: /u/zqb/tiezhang/shanlu-7.c
#include <ansi.h>

inherit ROOM;

string look_dazi();

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����С·��
����һ����ǿ��ȥ��ǰ����һƬï�ܵ����֡�·�Ե�ʯ���Ͽ��ż�������(dazi)��
LONG
	);
	set("exits", ([
"north" : __DIR__"sslin-1",
"southdown" : __DIR__"shanlu-6",
]));

    set("item_desc",([
        "dazi"         :       (: look_dazi :),
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-180);
   set("coor/z",50);
   setup();
}

string look_dazi()
{
        return
        "\n"
"    ���ư��ص�    \n"    
        "\n"
 "    ������----    \n"
HIR"              ����    \n"NOR
        "\n";
}

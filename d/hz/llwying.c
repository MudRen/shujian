// /u/beyond/hz/llwying.c ������ݺ
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",MAG"������ݺ"NOR);
	set("long", @LONG
������һ�����ߴ���ϣ������������������������֦���ҡ�ڣ���
���������Ĵ�����ļ��ʱʱ��ֻ���ӽ�ӷɹ���һ�ɽ��Ϸ羰�������
�����������һƬ���̵Ĳ�ƺ��С�ݳ�������ô���̣���ô���ۡ�
LONG
	);
	set("exits", ([
	    "south" : __DIR__"hubian1",
	    "north" : __DIR__"hubian",
]));
	set("coor/x",90);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}

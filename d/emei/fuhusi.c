// Room: /d/emei/fuhusi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "������" NOR);
	set("long", @LONG
����������ɽ��һ��ɲ�������ڸߴ����ľ�ּ䣬�����ľ���죬���
ʮ�����ꡣ����������ׯ�ϣ���ģ��ʢ�����ÿ����ƶ�Ρ�롣��ɲ���ڸ���
����Ũ��֮�У�������ȴ��һƬ��Ҷ���������Ͻ����±��ǹ����á�
LONG
	);
	set("outdoors", "��üɽ");
	set("no_clean_up", 0);
	set("exits", ([ 
	  "westup" : __DIR__"milin2",
	  "east" : __DIR__"milin",
]));
	set("objects",([
		"/d/emei/npc/dizi" : 1,
		"/d/emei/npc/dizi2" : 1,
]));
	set("coor/x",-210);
  set("coor/y",-130);
   set("coor/z",10);
   setup();
}

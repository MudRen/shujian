// Room: /d/shaolin/fxjing.c
// Date: bren

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIY"���ľ�"NOR);
	set("long", @LONG
����һ��ǧ��ž�������������ʯ���ɵľ�̨�����������������͵�һ
����һ�ߵľ�Ե���������ʮ���ף���������������ס����ڴ���һ��ľ��
�����������ˮ���ഫ�������Ǵ�Ħ����ϴˢ�;�֮����
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"shijie9",
	]));

        set("resource/water",1); 
	set("outdoors", "����");
	set("coor/x",70);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}

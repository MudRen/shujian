// guanyinqiao.c
// ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "������" NOR);
	set("long", @LONG
�����ǹ����š���������ǰ����ǡ�ÿ��Կ���һ�����ʯ�����ڿ��ƹ���
���������������ҡ�һ���ٲ����������£��ֺ��Ƶ�ˮ�������컯֮����ʵ��
������̾���ѡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"jietuopo",
		"west" : __DIR__"guanyintang",
	]));

	set("coor/x",-240);
  set("coor/y",-130);
   set("coor/z",30);
   setup();
}


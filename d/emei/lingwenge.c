// Room: /d/emei/lingwenge.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
	set("short",HIW "���ĸ�" NOR);
	set("long", @LONG
�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط�����������С��
�������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�ª����ǽ���ż������Σ�����
���ż������š�������һ������������һ��ի����
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang",
  "west" : __DIR__"fushouanzt",
  "out" : __DIR__"fushouan",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-zhao" : 1,
]));
	setup();
}

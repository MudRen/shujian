// Room: /d/emei/shenshuian.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "��ˮ��" NOR);
	set("long", @LONG
��ˮ��λ�ڱ��Ʒ��£���ǰ�д��ʯ����ҺȪ��Ȫ��ʯ�£��峺�ޱȣ���
�겻�ԡ�һ����������������ٲ��䣬������Χ���ߴ�ʮ���ɡ��Ա��и���
�֣��ɴ������з��£����´����
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
	  "south" : __DIR__"fushouan",
	  "eastdown" : __DIR__"chunyangdian",
	  "westup" : __DIR__"zhongfengsi",
]));
set("objects",([
    __DIR__"npc/xiangke" : 2,
]));

	setup();
}

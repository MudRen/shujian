// by dubei
// Modify By River@sj 99.5.24
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"����"NOR);
	set("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ������ʮ
�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�˿��
Ҳ�ޡ����ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);
	set("exits", ([
		"east" :  __DIR__"linhai"+(random(10)+1),
		"south" : __DIR__"linhai9",
		"west" :  __DIR__"linhai"+(random(10)+1),
		"north" : __DIR__"xiaolu1",
	]));

        set("outdoors", "����");
        setup();
}

void reset()
{
	set("exits", ([
		"south" : __DIR__"linhai9",
		"north" : __DIR__"xiaolu1",
		"west" :  __DIR__"linhai"+(random(10)+1),
		"east" :  __DIR__"linhai"+(random(10)+1),
	]));
}

// Room: d/gb/xinglin9.c
// by pishou
// Modify by Looklove@SJ for update npc

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������"NOR);
	set("long", @LONG
������������м��һƬ�յأ����ܵ������Ͽ����˻���һȺ�۷������
ȥ��æ�ز��ۡ������м�����ؤΧ����һ���Ա�վ������������ؤ��������
ɫ���أ�������������ʲô��
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"xinglin8",
		"west" : __DIR__"kongdi2",
		"north" : __DIR__"pomiao",
	]));

	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
		CLASS_D("gaibang/liang") : 1,
        ]));

	setup();
}
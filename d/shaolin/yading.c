#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�¶�");
        set("long", @LONG
�¶���һƬ���֣�������գ������������㷢����ߵ�ʯ�����ƺ��и�С
С��ɽ�����м����Ϻ����������棬����ʯ�ڣ���Ŀ����������ĵ����ƺ�û
���κη�ӳ��
LONG
        );

	set("outdoors", "������");
	set("exits", ([ 
		"enter" : __DIR__"houshand",
		"down" : __DIR__"duanya",
	]));
        setup();
}

// /d/xiangyang/djie1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ������������Ƕ���һ���ֵ���·������������ʯ��������������
�е������������м��������ڳ�������ʱ���ж�����׵�ʿ���߹�ȥ���򶫳�
�ǿ��Խ��밲�ա����վ��ڡ��ֱ����Ǽҵ��̣��ſ����ż������
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"west" : __DIR__"cross2",
		"east" : __DIR__"djie2",
                "north" : __DIR__"dangpu",
	]));

	set("incity",1);
	setup();
}

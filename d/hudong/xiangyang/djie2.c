// /d/xiangyang/djie2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ������������Ƕ���һ���ֵ���·������������ʯ��������������
�е������������м��������ڳ�������ʱ���ж�����׵�ʿ���߹�ȥ���򶫳�
�ǿ��Խ��밲�ա����վ��ڡ��ֱ����������ӿڣ�������Ҳ��������������
�淽��ͨ�������ġ�
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"west" : __DIR__"djie1",
		"east" : __DIR__"eroad1",
                "north" : __DIR__"dcx5",
	]));

	set("incity",1);
	setup();
}

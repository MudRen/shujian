// Room: /d/putian/road05.c
// Lklv 2001.9.11

inherit ROOM;
#include <wanted.h>
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·�𽥿�ʼ��խ�����ҿ�ʼ������ɽ�ˡ�Զ����ɽ��ȫ������ľ���ǣ��̵�
�������ߡ�ż�����������֦ͷ�����Ľ�����
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"road04",
                "eastup" : __DIR__"road06",
        ]));

	set("objects",([
		NPC_D("tiao-fu") : 1,
	]));

        set("outdoors", "����");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "eastup" && is_wanted(me))
        	return 0;
	return ::valid_leave(me, dir);
}

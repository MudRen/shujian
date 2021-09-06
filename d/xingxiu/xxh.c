// Room: /d/xingxiu/xxh.c
// Modify by Lklv 2001.10.16

#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", "���޺�");
	set("long", @LONG
��������ɽ���µ����޺����ߡ���Ϊ��Բ�����ﶼ��һ���޼ʵĺ�������
�����Ա��������˳�Ϊ��������һ���м�ֻ��Ⱥ������ʧ�ڡ����������
Ҳ�Ҳ����ˡ�������������������̳�����ڱ���ĺ����롣
LONG
        );
	set("outdoors", "����");
        set("exits", ([
             "north" : __DIR__"xxh1",
             "south" : __DIR__"shanjiao",
             "southeast" : __DIR__"yili/yili",
	]));
	set("objects", ([
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
                __DIR__"npc/azi" : 1,
        ]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if (is_wanted(me) && dir == "north")
		return 0;
	return ::valid_leave(me, dir);
}

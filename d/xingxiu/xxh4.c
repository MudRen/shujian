// Room: /d/xingxiu/xxhh4.c ���޺�
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺�����Բ�����ﶼ��һ���޼ʵĺ��������󣬵��������˳�
֮Ϊ��������Ҳ��������ʪ�����深ֳ���������޵��ӳ����˲�׽���棬�Ա�
����֮�á�����ͨ�����޺������
LONG);
	set("outdoors", "����");
        set("objects", ([
                __DIR__"npc/xxdizi"  : 1,
        ]));
        set("exits", ([
		"east" : __DIR__"xxh2",
		"south" : __FILE__,
		"west" : __DIR__"xxh3",
		"north" : __DIR__"xxh1",
        ]));
        set("outdoors", "xingxiuhai");
	setup();
}
#include "/d/xingxiu/xxh.h";

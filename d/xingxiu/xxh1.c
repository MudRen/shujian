// Room: /d/xingxiu/xxhh1.c ���޺�

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺�����Բ�����ﶼ��һ���޼ʵĺ��������󣬱����������˳�
֮Ϊ��������Ҳ��������ʪ�����深ֳ���������޵��ӳ����˲�׽���棬�Ա�
����֮�á�����ͨ�����޺������
LONG
        );
	set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/xxdizi"  : 1,
	]) );
        set("exits", ([
                "east" : __DIR__"xxh2",
                "south" : __FILE__,
                "west" : __DIR__"xxh3",
                "north" : __DIR__"xxh4",
        ]));
	setup();
}
#include "/d/xingxiu/xxh.h";

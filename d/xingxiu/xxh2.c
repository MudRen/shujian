// Room: /d/xingxiu/xxhh2.c ���޺�
// Update by Lklv@SJ 2001.10.16
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
        set("exits", ([
                "east" : __DIR__"xxh4",
                "south" : __FILE__,
                "west" : __DIR__"xxh1",
                "north" : __DIR__"xxh3",
        ]));
	setup();
}

#include "/d/xingxiu/xxh.h";

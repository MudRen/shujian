// Room: /d/xingxiu/ryd1.c
inherit ROOM;
void create()
{
        set("short", "���¶���");
        set("long", @LONG
���������޺��ľ�ͷ����Բ�����ﶼ��һ���޼ʵĺ��������󣬵�����
���˳�֮Ϊ��������������һ��Сʯɽ���������ܶ����¶��������������
����һ��ͭ������(paizi)��
LONG);
        set("exits", ([
             "north" : __DIR__"ryd",
             "southdown" : __DIR__"xx1",
             "west" : __DIR__"xxh4",
             "east" : __DIR__"xxh3",
	]));
	set("item_desc", ([
                "paizi" : "
             ���޺�����
             ���¶����졣\n",
	]));
	set("objects", ([
                __DIR__"npc/anran" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );
        set("outdoors", "����");
	setup();
	"/clone/board/xingxiu_b"->foo();
}

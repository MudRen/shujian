// Room: /d/hengshan/cuipinggu1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ڹ��г�ˢ�����������ʹ���ɽ����Ͽ�����࣬����ǧ�����絶
���������������ƣ������Թž�������ͨ���ڵص��ʺ�Ҫ��������һ�򵱹���
��Ī��֮�ơ�
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
                "northeast"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		__DIR__"npc/wen" : 1,
	]));
        set("outdoors", "��ɽ");
        setup();
}

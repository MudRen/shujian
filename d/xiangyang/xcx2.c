// /d/xiangyang/xcx2.c ������
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������С���������������������������һ���ʯ�ӣ�����
ȥ����ɳɳ��������������һֱ�����ߣ�����ͨ����ȸ���ڽ֡�����ͨ���׻�
�š�����������һ�Ҷ�������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"west"  : __DIR__"doufufang",
		"north"  : __DIR__"xcx1",
		"south" : __DIR__"xcx3",
	]));

	set("incity",1);
	setup();
}

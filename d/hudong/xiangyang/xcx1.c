// /d/xiangyang/xcx1.c ������
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������С���������������������������һ���ʯ�ӣ�����
ȥ����ɳɳ��������������һֱ�����ߣ�����ͨ����ȸ���ڽ֡�����ͨ���׻�
�š�����������һ�ҵ��̣������ų����š�
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"west"  : __DIR__"chayedian",
		"north"  : __DIR__"bhmnj",
		"south" : __DIR__"xcx2",
	]));

	set("incity",1);
	setup();
}

// /d/xiangyang/xcx5.c ������
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������С���������������������������һ���ʯ�ӣ�����
ȥ����ɳɳ��������������һֱ�����ߣ�����ͨ����ȸ���ڽ֡�����ͨ���׻�
�š�����������һ��ҩ���̣�������һ��˽�ӣ�����һ�����������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"west"  : __DIR__"yaopu",
		"north"  : __DIR__"xcx4",
		"south" : __DIR__"sishu",
		"east" : __DIR__"zqmnj",
	]));

	set("incity",1);
	setup();
}

// /d/xiangyang/xcx3.c ������
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������С���������������������������һ���ʯ�ӣ�����
ȥ����ɳɳ��������������һֱ�����ߣ�����ͨ����ȸ���ڽ֡�����ͨ���׻�
�š�����������һ���ձ����ӣ����洫��һ�����ձ�����ζ��
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"west"  : __DIR__"shaobingpu",
		"north"  : __DIR__"xcx2",
		"south" : __DIR__"xcx4",
	]));

	set("incity",1);
	setup();
}

// /d/xiangyang/xcx4.c ������
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������С���������������������������һ���ʯ�ӣ�����
ȥ����ɳɳ��������������һֱ�����ߣ�����ͨ����ȸ���ڽ֡�����ͨ���׻�
�š�����������һ�Ұ����̣��ſ������ϵİ���ð��������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"west"  : __DIR__"baozipu",
		"north"  : __DIR__"xcx3",
		"south" : __DIR__"xcx5",
	]));

	set("incity",1);
	setup();
}

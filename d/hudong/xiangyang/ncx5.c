// /d/xiangyang/ncx5.c �ϳ���
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
����һ��������С�����������������������һֱ�����ߣ�����ͨ��
�������ڽ֡����Ӷ�����һ�Ҵ����̣����ȴ��ų����š����洫������������
��������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"east"  : __DIR__"datiepu",
		"south"  : __DIR__"ncx4",
		"north"  : __DIR__"eroad1",
	]));

	set("incity",1);
	setup();
}

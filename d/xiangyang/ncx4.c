// /d/xiangyang/ncx4.c �ϳ���
// Lklv 2001.9.25

inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
����һ��������С�����������������������һֱ�����ߣ�����ͨ��
�������ڽ֡����Ӷ�����һ��ľ���̣��Ű���ڣ����������Ŵ������������
��Զ�������������ˡ�
LONG
        );
        set("xyjob", 1);
        set("exits", ([
		"east"  : __DIR__"mujiangpu",
		"west"  : __DIR__"ncx3",
                "north"  : __DIR__"ncx5",
                "south"  : __DIR__"bingqipu",
	]));

	set("incity",1);
	setup();
}

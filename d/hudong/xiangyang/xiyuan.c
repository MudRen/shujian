// /d/xiangyang/xiyuan.c ϷԺ
// Lklv 2001.9.26

inherit ROOM;
void create()
{
        set("short", "ϷԺ");
        set("long", @LONG
������һ��ϷԺ����������˺ܶ���ӣ���ǰ���Ŀ�̨����һ��Ϸ������
����ѽѽ�ص�ɤ�ӡ���̨��һ�ǰ���һ���������������һ�����������ڲ�
��Ӫҵʱ�䣬û��������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"dcx4",
        ]));

        set("objects", ([
                __DIR__"npc/xizi" : 1,
        ]));
        set("incity",1);
	setup();
}

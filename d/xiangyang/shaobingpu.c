// Room: /d/xianyang/shaobingp.c �ձ���
// Lklv 2001.9.26

inherit ROOM;
void create()
{
        set("short", "�ձ���");
        set("long", @LONG
����һ���ձ��̣�ǽ�ڵ���ɫ�ܺڣ�������Ļ�¯���пڴ������������
�İ���һȦ�Ӻõ��ձ���ɢ����һ�����е��ձ���ζ��������ӵ��ձ��ڸ���
����������ʱ���˽���������һ�������ձ���
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"xcx3",
        ]));

        set("objects", ([
		__DIR__"npc/shaobingliu" : 1,
        ]));

        set("incity",1);
	setup();
}

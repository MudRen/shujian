// /d/xiangyang/xyudian.c �����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ������������ӣ����ﵽ���ڷ��Ŵ��СС����¨��ˮ���ܵġ���
�ű߷���һ�ڴ�ˮ�ף������кܶ������������㡣һ��������Χȹ������Ů
�ӣ�վ������۹��������⡣
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"bcx3",
        ]));

        set("objects", ([
		__DIR__"npc/liersao" : 1,
        ]));
        set("incity",1);
	setup();
}

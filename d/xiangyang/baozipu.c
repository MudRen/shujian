// Room: /d/xianyang/baozipu.c ������
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ұ����̣����������Ƕ�ϲ��������İ��ӣ��ϰ������������Ҳ
��Զ���������ſ��и���¯���������һ�����룬����ð��һ˿˿��������
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"xcx4",
        ]));

        set("objects", ([
		__DIR__"npc/baoziwang" : 1,
        ]));

        set("incity",1);
	setup();
}

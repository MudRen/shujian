// Room: /d/xianyang/yaopu.c ҩ����
// Lklv 2001.9.26

inherit ROOM;
void create()
{
        set("short", "ҩ����");
        set("long", @LONG
����һ����ʷ�ƾõ�ҩ���̣���ǰ���ϰ���Ϊ��Ӫ���ã���������������
��Ǯ�����������˱��˾�Ӫ������ҩ�̵���˵����Ҳ�Ǻպ������������ǽ���
���˳ơ�ɱ����ҽ����ƽһָ��
LONG
        );
        set("xyjob", 1);
        set("no_fight",1);
        set("exits", ([
                "east" : __DIR__"xcx5",
        ]));

        set("objects", ([
		__DIR__"npc/ping" : 1,
        ]));

        set("incity",1);
	setup();
}

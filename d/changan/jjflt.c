// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjflt.c

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
��ͤ�����Ϊ���£��м�һʯ�������Ͽ��ź�ʮ�ţ���ʮ�ŵ�һ�����̣�
�оֻ�δ��ȥ���峿��������飬Ϧ������ʱƷ��̸�죬��������һ����¡�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "east"  : __DIR__"jjfhhy",
        ]));

        set("incity",1);
	setup();
}


// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/dadian.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������������ڹ�ģ��ΰ�Ĵ���ǰ������ݵ�����������ɣ���
����ǧ������ݡ��������ŵ���Ъɽ������Ͳ���߸��ǣ����ϸ�������������
ǰ���������̡����������н�ɫ�Ŷ�����ǰ��ש���ء��������������¡�
LONG
        );

        set("exits", ([
                "south" : __DIR__"qingzhensi",
                "north" : __DIR__"houdian",
        ]));

        set("incity",1);
	setup();
}
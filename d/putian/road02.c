// Room: /d/putian/road02.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ��ɽ��С·��·��û�����ˣ����ǿ�����ϡ�����г����߹��ĺ�
���������������Ƨ����ɽ������һ�ֺ컨����Զ����ȥ���ܿ���������ɫ��
�����ڰ���з����ţ�����Ѥ����Ŀ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"road01",
//                "south" : "/d/dehua/road1",
                "southeast" : __DIR__"road03",
        ]));

        set("outdoors", "����");
        setup();
}


// Room: /d/putian/road03.c
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
                "northwest" : __DIR__"road02",
                "east" : __DIR__"road04",
        ]));

        set("outdoors", "����");
        setup();
}


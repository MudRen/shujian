// Room: /d/putian/road04.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ��ɽ��С·��·��û�����ˣ����ǿ�����ϡ�����г����߹��ĺ�
���������������Ƨ����ɽ������һ�ֺ컨����Զ����ȥ���ܿ���������ɫ��
�����ڰ���з����ţ�����Ѥ����Ŀ��������ǵ»���������������һ����խ
��ɽ·��
LONG
        );

        set("exits", ([
                "west" : __DIR__"road03",
                "northeast" : __DIR__"road05",
        ]));

        set("outdoors", "����");
        setup();
}


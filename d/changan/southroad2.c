// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/southroad2.c

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south"  : __DIR__"southroad3",
                "north"  : __DIR__"southroad1",
        ]));

        setup();
}

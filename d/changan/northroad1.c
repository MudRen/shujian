// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad1.c

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
�����ѿ����������������ǵı������ˡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south"  : __DIR__"northmen",
                "north"  : __DIR__"northroad2",
        ]));

        setup();
}

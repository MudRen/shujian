// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/southroad1.c

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
�����ѿ����������������ǵ��ϳ����ˡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "south"  : __DIR__"southroad2",
                "north"  : __DIR__"southmen",
        ]));

        setup();
}

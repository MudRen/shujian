// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/eastroad1.c

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ���������������������
�����̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ����
������������߷ɳ۶���������һ·��������·��������������������֡�
�����ѿ����������������ǵĶ������ˡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : __DIR__"eastroad2",
                "west"  : __DIR__"eastmen",
                //"southeast"  : __DIR__"suishi3",
        ]));

        setup();
}

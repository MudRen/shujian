// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/eastroad2.c

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
                "east"  : "/d/group/entry/caeroad3",
                "west"  : __DIR__"eastroad1",
        ]));

        setup();
}

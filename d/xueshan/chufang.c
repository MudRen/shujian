// Room: chufang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ƣ����������Ų��ٲ�ݺ�ţ�࣬ȼ���������һ𣬲����ž
���죬ůů���ˡ�����������ţ��ζ����һ��Ʈ���ڿ����С�����������һ
������Ĵ���������æµ��һ�ɷ�æ����
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhaitang",
        ]));
        set("objects", ([__DIR__"npc/zayilama" : 2]));
        setup();
}


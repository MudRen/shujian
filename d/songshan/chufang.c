// Room: /u/swl/songshan/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ð��������㣬������ɽ����������֮��Ҫ��������Ӹɻ
���ƽʱ��ҵĻ�ʳ����
LONG);
	set("exits", ([
            "east" : __DIR__"lwdting",
        ]));
        set("objects", ([ 
            FOOD_D("fan") : 1+random(2),
            FOOD_D("zongzi") : 1+random(2),
            FOOD_D("zhuhu") : 1,
        ]));
	setup();
}

// Room: /city/duchang.c

inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ����������Ƕġ���
С���ķ��䣬�����Ƕġ��ƾš��ķ��䣬¥�ϵĹ����ƻ�ͨ����
LONG
        );

        set("item_desc", ([
                "paizi" : "��¥�ǹ�����\n",
        ]));
        set("exits", ([
                "east" : __DIR__"nandajie3",
       "west" : __DIR__"dating1",
        "south" : __DIR__"gusaifang",
        "up" : __DIR__"duchang2",
        ]));
        set("objects", ([
                  __DIR__"npc/duke" : 2,
        ]));

        set("coor/x",90);
        set("coor/y",-20);
        set("coor/z",0);
        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
        if( me->query("no_quest") && dir != "east" ){
        	return notify_fail("\n");
        }
        return ::valid_leave(me, dir);
}

// �᷿ xfang1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "�᷿");
        set("long", @LONG
������һ��ܴ���᷿��������Ȼ�Ƚϼ�ª������ʮ�ָɾ����ڷ�ʮ�ֱ�
�£�����ǽ�ߵĵط�����һЩľ���������Ǹ���ҽ�Ĳ���ס���õġ�
LONG
        );

        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([ 
            "north" : __DIR__"yaofang",
            "west" : __DIR__"caojing",
            "east" : __DIR__"huapu2",
        ]));

        setup();
}

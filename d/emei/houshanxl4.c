// houshanty.c
// ��ɽС·
inherit ROOM;
#include <ansi.h>

int do_ban(string arg);

void create()
{
        set("short", HIG "��ɽС·" NOR);
        set("long", @long
������˵��С·������ľ�������������ҵ���ɽ��·�ˡ�ǰ��һ���ʯͷ
(stone)��ס����ɽ��ȥ·��
long);
        set("outdoors", "��üɽ");
        set("item_desc", ([ 
            "stone" : "    ����һ���ʯͷ������ʹ�㾢���԰�(move)����\n",
]));
        set("exits",([
            "southup":__DIR__"houshanxl3",
]));
        setup();
}

void init()
{
    add_action("do_ban", "move");
}

int do_ban(string arg)
{
    object me = this_player();
    if(!arg) return 0;
    if(arg != "��ʯͷ" && arg != "ʯͷ" && arg != "stone" && arg != "shitou" ) return 0;
    if( random((int)me->query_str()) >= 15) {
        message_vision("$N˫��Ͼ����Ὺ�˴�ʯͷ��\n", me);
        set("exits",([
            "southup":__DIR__"houshanxl3",
            "northdown":__DIR__"qingyinge",
]));
        
    }
    else {
        message_vision("$Nʹ���˳��̵�������Ҳû�Ὺ��ʯͷ��\n", me);
    }
    return 1;
}
 // /u/beyond/hz/shanquan.c ɽȪ
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"ɽȪ"NOR);
        set("long", @LONG
��ɽ��һ����Ȫֱ�����£���ɽ�Ż㼯��һ̶��ˮ������ˮȪ����һ��
Сé�ᣬé����������һȦ�����Ȧ�ţ�һ��С���Ű����ţ����治֪ס��
��ʲô�ˡ�
LONG
        );
        set("outdoors", "hz");
        set("resource/water", 1);
        set("exits", ([
        "enter" : __DIR__"maoshe",
        "east" : __DIR__"shanquan",
        "south" : __DIR__"shanlu1",
        ]));
        setup();
}

// Room: /city/wumiao.c
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
ʱ������������Ҳ�����Ա������ع������Ѳ�֪ȥ��


LONG
    );

    set("exits", ([
        "east" : __DIR__"beidajie2",
    ]));
        setup();
}
//�Ǿ���
int is_mirror() { return 1; }
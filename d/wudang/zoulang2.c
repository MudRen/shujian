
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ�
���Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש����������һ������
����������䵱����, �ǳ�������
LONG
        );

        set("exits", ([
                "west" : __DIR__"zoulang1",
                "east" : __DIR__"ldfang",
        ]));

        setup();
} 


#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������һ�������ϣ��ȶ�����Ž��������ķ羰��ÿ��������ɫ�����Ӽ�
���Ҳ�������ߵľ��룬���ɫ�������ߣ��ۻ�ɫ�ĵ�ש����������һ��ҩ����
������䵱����, �ǳ�������
LONG
        );

        set("exits", ([
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"yaofang",
        ]));

        setup();
} 

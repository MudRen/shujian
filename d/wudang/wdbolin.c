// /d/wudang/wdbolin.c �䵱����
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"�䵱����"NOR);
        set("long", @LONG
�㴩����һƬï�ܵİ����У���ɭ���䣬�������⡣�����ʱ������Ұ
�޵ĺ����������������٣���æ�ӿ첽����
LONG
        );
        set("exits", ([
                "southup" : __DIR__"shanlu1",
                "eastdown" :__DIR__"yuzhen",
        ]));
        set("outdoors","�䵱"); 
        setup();
}

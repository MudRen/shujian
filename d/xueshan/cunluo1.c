 //      cunluo1.c ������

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",NOR"������"NOR);
        set("long",@LONG 
����Ƭ���Ĳ�ԭ���м�������ԭ���Ǽ���������Ϊ���Ĳ�������ͨ
���ɼ������ϰٻ����ȣ���ɲ��䣬�ɲ���ͷ�˴��죬��ˮ�ݶ��ӣ����޶�����
�����ķ����Ը�һ��󶼴�����ţ��ǳ��ÿ͡�
LONG);
        set("exits",([
                "north" : __DIR__"cunluo2",  
                "westup" : __DIR__"caishichang",
                "west" :__DIR__"muchang3",
                "east" :__DIR__"muchang7"
        ]));
        set("objects", ([__DIR__"npc/mumin" : 1,]));
        set("coor/x",-200);
  set("coor/y",150);
   set("coor/z",-10);
   setup();
}

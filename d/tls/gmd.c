#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"�������"NOR);
        set("long",@LONG
�����������֧���Բ����ס������һ�����ң����顰������ס��
����������֡����﹩���Ű����ӷ�������ʥ��
LONG);       
        set("exits", ([
                "east" : __DIR__"yz3",
                "south" : __DIR__"sjt",
	]));
        set("coor/x",-360);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"�زص�"NOR);
        set("long",@LONG
��ǰ�յ���һ�������еƻ����������﹩�������޵ز���������
������£�����֮�����㰸�Ϲ��Ÿ����ʻ���ˮ���������Ͷ�������
��Ϊ��ȥ���������㱣�ӡ�
LONG);       
        set("exits", ([
                "east" : __DIR__"baodian",
                "south"  : __DIR__"zhonglou",
                "northwest"  : __DIR__"yz5",
	]));
        set("coor/x",-360);
  set("coor/y",-330);
   set("coor/z",20);
   setup();
}
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"ҩʦ��"NOR);
        set("long",@LONG
��ǰ�յ���һ����������������﹩��������ҩʦ������������
������£�����֮�����㰸�Ϲ��Ÿ����ʻ���ˮ�������͡�������
��Ͷ����ϵĿ�ͷ���㣬�����Լ��������������տ�����
LONG
        );
       
        set("exits", ([
                "west" : __DIR__"baodian",
                "south"  : __DIR__"gulou",
                "northeast"  : __DIR__"yz4",
        ]));


	set("objects",([
                __DIR__"npc/guest" : 2,
        ]));

        set("coor/x",-340);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}
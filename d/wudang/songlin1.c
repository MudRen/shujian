// /d/wudang/songlin1.c ����
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"����"NOR);
        set("long", @LONG
���������ֵı�Ե�ش�����ľ����̫ï�ܣ�����͸����룬����
��ء������Ƿ��ش����·��
LONG
        );
        set("exits", ([
                "east" :__DIR__"songlin2",
                "west" :__DIR__"sldadao",
        ]));

        set("objects",([
                __DIR__"npc/yetu" : 1,

        ]));
        
        set("coor/x",30);
  set("coor/y",0);
   set("coor/z",30);
   setup();

}

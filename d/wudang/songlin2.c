// /d/wudang/songlin2.c ����
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
                "west" :__DIR__"songlin1",
                "east" :__DIR__"sldadao",
        ]));

        set("objects",([
                __DIR__"npc/shanji" : 1,

        ]));
        
        set("coor/x",40);
  set("coor/y",0);
   set("coor/z",30);
   setup();

}

// Room: /fouzhou/bank.c
// Looklove y2k/4/09
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"��ի"NOR);
        set("long", @LONG
���Ǵ�Į���ϵ�һ��СǮׯ����ʩ�ܼ�ª�����������ڸ������ǲ���ģ�
��Ϊ���С�������ٽ���Į�ߵ�һ����ȫ�������Ե���Ǯׯ������ѡ�񽫵���
����������������˽��Լ���Ѫ��ǮС�ĵĴ�����������е���Ʊ����ͨ
��ȫ����
LONG
        );

        set("exits", ([
                "east" : __DIR__"silk8",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
          
        ]));
 
        set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   set("coor/x",-310);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}


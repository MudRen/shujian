// /u/beyond/hz/yaopu.c ҩ��
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"���괺"NOR);
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�
С������ɢ�������ġ�ҩ���������ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);
        set("objects",([
           __DIR__"npc/yplaoban" : 1,
           __DIR__"npc/huoji" : 1,
         ]));
	set("exits", ([
		"west" : __DIR__"qsddao5",
	]));
	set("coor/x",110);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}


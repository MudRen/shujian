// muqi.c  ��ľ��
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"��ľ��"NOR);
       set("long", @LONG
�����Ǿ�ľ������ڵء�������Ÿ��ָ����Ŀ������ߺ�һ�����Ĵ���ľ��
�������м��������ľ��ľ׮����������౻�ƻ����ĺۼ���Ϊ���е���ƽʱ
����֮�á����в��������������ţ�����ָ��֣���������ܹ��ɽ���������
�ĺ��Ľ������ǳ��Ա���֮�֡���Ϊ���������ڸ߳������������ǹ�������
��һ�����ߣ�������һ�򵱹����Ī��֮�ơ�������һƬ��ɭ�Ĵ����֡�
LONG);    
	set("exits", ([
		"west" : __DIR__"didao/shuling1",
		"east" : __DIR__"didao/shuling2",
                "northup" : __DIR__"gmd",
                "south" : __DIR__"tingtang",
	]));             
	set("objects", ([
		__DIR__"npc/dizi1" : 3,
                CLASS_D("mingjiao") + "/wen" : 1,
	]));

        set("coor/x",-290);
  set("coor/y",160);
   set("coor/z",100);
   set("coor/x",-290);
 set("coor/y",160);
   set("coor/z",100);
   setup();
}

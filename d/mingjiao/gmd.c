// gmd.c  ������
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"������"NOR);
       set("long", "
    ����������̹����������ߵ�����Ϳɿ��������ʺ�ɫ���֡����̣����֣�\n"+
"ؤ�������������Ḷ̌��������������ɣ���ؤ�����������ɡ���������\n"+
"��˹�̴ܽ�����ԭ���аٶ������ʷ�ˡ�����ʼ�ն��Է�Ԫ����������ȥ��\n"+
"��������Ϊ���ѵ���ּ������������̫�����½�������ݹݬ���룬��ʹ����\n"+
"�����ɳ�Ϊħ�̡�������һ���ɫ����Ĵ��졣���������䳡���ϱ��Ǿ�ľ��\n"+
"�����ڵء�\n\n"HIR"\t\t\t��    ��    ��\n\n"NOR);
	set("exits", ([
		"northup" : __DIR__"wu3",
		"southdown" : __DIR__"muqi",			
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/yin" : 1,
                CLASS_D("mingjiao") + "/wulu" : 1,
                __DIR__"npc/m-dizi" : 2,
	]));
        set("outdoors", "���̹�����");
        set("valid_startroom", 1);
        set("coor/x",-290);
  set("coor/y",170);
   set("coor/z",110);
   set("coor/x",-290);
 set("coor/y",170);
   set("coor/z",110);
   setup();        
        call_other("/clone/board/mingjiao_b","???");
}

// wu3.c ���䳡
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",CYN"���䳡"NOR);
       set("long", @LONG
���������̵����䳡�������Ǽ�Ӳ��ʵ�Ļ��������аٶ���ļ���ʹ�õ�
��⻬ƽ�������䳡�м������Ų���������������ľ�С��ܶ����̽���������
ϰ���ա���������һ�������ĳ��ȣ������ǹ㳡���ϱ��ǹ�������
LONG);    
	set("exits", ([
           "west"  :  __DIR__"cl1",
           "east"  :  __DIR__"cl2",
           "southdown" : __DIR__"gmd",
           "north" : __DIR__"guangc",
	]));
	set("objects",([
		__DIR__"npc/m-dizi" : 1,
		__DIR__"npc/f-dizi" : 1,
                CLASS_D("mingjiao") + "/wushou" : 1,
	]));             
        set("outdoors", "���̹�����");
        set("coor/x",-290);
  set("coor/y",180);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",180);
   set("coor/z",120);
   setup();
}

int valid_leave(object me, string dir)
{
       mapping myfam;
       object ob;
       myfam = (mapping)me->query("family");
       if ((!myfam || myfam["family_name"] != "����") && dir != "southdown" 
        && objectp(ob=present("yin wushou", environment(me))) && living(ob))
          return notify_fail(YEL"�����ٰ���һ����ס���ȥ·���㲻�����̵��ӣ����ܽ�ȥ��\n"NOR);	
       return ::valid_leave(me, dir);
}

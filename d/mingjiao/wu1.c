// wu1.c ���䳡
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",CYN"���䳡"NOR);
       set("long", @LONG
���������̵����䳡�������Ǽ�Ӳ��ʵ�Ļ��������аٶ���ļ���ʹ�õ�
��⻬ƽ�������䳡�м������Ų���������������ľ�С��ܶ����̽���������
ϰ���ա����������̵�ҩ���������߾�����Ժ�ˡ�
LONG);    
	set("exits", ([
		"east" : __DIR__"yaofang",
                "west" : __DIR__"shuyuan",
                "south" : __DIR__"guangc",
		"north" : __DIR__"xting",
	]));             
	set("objects",([
		__DIR__"npc/f-dizi" : 1,
		__DIR__"npc/m-dizi" : 1,
                CLASS_D("mingjiao") + "/zhang" : 1,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-290);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",200);
   set("coor/z",120);
   setup();
}

int valid_leave(object me, string dir)
{
        
        object ob;        
        /*
        mapping myfam;
        myfam = (mapping)me->query("family");        
       	if ((!myfam || myfam["family_name"] != "����") && dir == "west" 
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n���а���һ����ס���ȥ·���㲻�����̵Ĳ��ܽ�ȥ����\n\n"NOR);
	if ((!myfam || myfam["family_name"] != "����") && dir == "east"
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n���а���һ����ס���ȥ·���㲻�����̵Ĳ��ܽ�ȥ����\n\n"NOR);
          */
	if ( me->query_temp("marks/Ժ1") && dir=="west"
         && objectp(ob=present("zhang zhong", environment(me))) && living(ob))
          return notify_fail(YEL"\n���а���һ����ס���ȥ·�������ù����˻�Ҫ��ѽ����\n\n"NOR);
        return ::valid_leave(me, dir);
}

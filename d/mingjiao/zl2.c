// /d/mingjiao/zhoulong2.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
����һ�����ȡ�һ������שǽ�ڣ���һ���ǹ�ľ��ɵ�Χ��������ͨ������
ȴҲ�����������һ����ƶ��ϡ����������䳡�������ǹ㳡��
LONG);    
	set("exits", ([
          "west" : __DIR__"guangc",
  	  "east" : __DIR__"wu4",
	]));    
        set("outdoors", "���̹�����");         
        set("coor/x",-280);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-280);
 set("coor/y",200);
   set("coor/z",120);
   setup();
}


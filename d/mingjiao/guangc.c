// guangc.c �㳡 
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"�㳡"NOR);
	set("long", @LONG
����һ��ʮ�ִ�Ĺ㳡��������������ǧ�ˣ������ǵ����Ž�����ƴ����
���ɵĵط���ʹ�����̺���������֮��ĳ�޵����ų�������ƽʱ�ɿ����ܶ�
�����̵�������������������ͨ�����䳡�����ȡ�
LONG);
	set("exits", ([
  	  "west" : __DIR__"zl1",
 	  "east" : __DIR__"zl2",
	  "south" : __DIR__"wu3",
	  "north" : __DIR__"wu1",
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/wei" : 1,
                __DIR__"npc/m-dizi" : 1,
                __DIR__"npc/f-dizi" : 1,
	]));
        set("outdoors", "���̹�����");
	set("coor/x",-290);
  set("coor/y",190);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",190);
   set("coor/z",120);
   setup();  
}


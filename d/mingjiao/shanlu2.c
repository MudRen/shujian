// shanlu2.c  ɽ��С·
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","ɽ��С·");
       set("long", @LONG
����һ���������۵�ɽ��С·�����ƽ�Ϊƽ̹������ľ�����Ƽ䣬�ֱ���
һ����ɭ���¡����ߵ���ľ��ֱ�������ţ����й��ɣ����Ҽ����ʮ�ֺ�Ļ�
ѩ���侰ʮ��׳�ۡ�����������������ı�ˮ��̶�ˡ�
LONG);    
	set("exits", ([
		"east" : __DIR__"bishui",	
		"westup" : __DIR__"shanlu1",				
	]));             
	set("objects",([
		__DIR__"npc/dizi4" :  2,
	]));
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",190);
   set("coor/z",100);
   set("coor/x",-250);
 set("coor/y",190);
   set("coor/z",100);
   setup();
}


// shanlu1.c ɽ��С·
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
ѩ���侰ʮ��׳�ۡ�
LONG);    
	set("exits", ([
		"eastdown" : __DIR__"shanlu2",
		"westup" : __DIR__"shuiqi",				
	]));             
        set("outdoors", "���̹�����");
        set("coor/x",-260);
  set("coor/y",190);
   set("coor/z",110);
   set("coor/x",-260);
 set("coor/y",190);
   set("coor/z",110);
   setup();
}

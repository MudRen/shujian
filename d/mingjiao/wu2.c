// wu2.c ���䳡
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
ϰ���ա�������һ�����ȡ�
LONG);    
	set("exits", ([
                "south" : __DIR__"huoqi",
                "north" : __DIR__"zl6",
		"east" : __DIR__"zl1",
	])); 
	set("objects",([
		__DIR__"npc/m-dizi" : 1,
		__DIR__"npc/f-dizi" : 1,
	]));            
        set("outdoors", "���̹�����");
        set("coor/x",-250);
  set("coor/y",240);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",240);
   set("coor/z",120);
   setup();
}

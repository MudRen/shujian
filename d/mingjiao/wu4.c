// wu4.c ���䳡
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
		"west" : __DIR__"zl2",
		"south" : __DIR__"shuiqi",
                "north" : __DIR__"zl7",
	])); 
	set("objects",([
		__DIR__"npc/m-dizi" : 1,
		__DIR__"npc/f-dizi" : 1,
	]));            
        set("outdoors", "���̹�����");
        set("coor/x",-270);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",200);
   set("coor/z",120);
   setup();
}

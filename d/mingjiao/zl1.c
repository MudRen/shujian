// zl1.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
����һ�����ȡ�һ������שǽ�ڣ���һ���ǹ�ľ��ɵ�Χ��������ͨ������
ȴҲ�����������һ����ƶ��ϡ������ǹ㳡�����������䳡��
LONG);    
	set("exits", ([
                "east" : __DIR__"guangc",
		"west" : __DIR__"wu2",
	]));             
        set("outdoors", "���̹�����");     
        set("coor/x",-240);
  set("coor/y",240);
   set("coor/z",120);
   set("coor/x",-240);
 set("coor/y",240);
   set("coor/z",120);
   setup();
}

// cl1.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
����һ�����ȡ�һ������שǽ�ڣ���һ���ǹ�ľ��ɵ�Χ��������ͨ������
ȴҲ�����������һ����ƶ��ϡ��������һ��죬���������䳡��
LONG);    
	set("exits", ([
		"west" : __DIR__"huoqi",
		"east" : __DIR__"wu3",
	]));    
        set("outdoors", "���̹�����");         
        set("coor/x",-240);
  set("coor/y",230);
   set("coor/z",120);
   set("coor/x",-240);
 set("coor/y",230);
   set("coor/z",120);
   setup();
}

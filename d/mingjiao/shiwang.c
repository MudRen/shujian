// shiwang.c ʨ����
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIY"ʨ����"NOR);
       set("long", @LONG
������רΪ����ëʨ����лѷ������е���ڽ�����˼���常����˵�
Ϊ׼��ӭ��ʨ����Ҳ�����޼ɽ���Ϊ�ټ�����������ʾ����ԭ�����ɾ���ǰ��
��Ԫ�����Ľ�ּ֮�����������һ���㰴�����궼������ȼ�š�
LONG);    
	set("exits", ([
		"east" : __DIR__"jinqi",
		"west" : __DIR__"jyt",
	]));    
        set("objects",([
		__DIR__"npc/f-dizi" : 1,
                __DIR__"npc/m-dizi" : 1,
	]));         
        set("coor/x",-280);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-280);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}


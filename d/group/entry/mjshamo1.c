// shamo1.c ��ɳĮ
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"��ɳĮ"NOR);
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����ڡ���һ��������ʧ�˷����ڶ���ʱ��
����һƬƬ�Ļ�ѩ��������һ����Сɳ��
LONG);    
	set("exits", ([
		"west" : "/d/mingjiao/shaqiu1",
		"northeast" : "/d/xingxiu/silk6"
	]));             
	set("group", 1);
        set("outdoors", "˿��֮·");
	setup();
}

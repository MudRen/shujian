// Room: /d/shaolin/houdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡�����������ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ���
����ǰ�и���ʩչ�ڹ���������ӡ�ǣ������Ǻ�
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
		"east" : __DIR__ "houdian",
                "south" : __DIR__ "hguangz1",            
       ]));
		set("coor/x",40);
  set("coor/y",340);
   set("coor/z",120);
   set("coor/x",40);
 set("coor/y",340);
   set("coor/z",120);
   setup();
}




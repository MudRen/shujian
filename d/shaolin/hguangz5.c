// Room: hguangz5.c


inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡�����������ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ���
����ǰ�и���ʩչ�ڹ���������ӡ�ǡ������Ǻ�
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
		"west" : __DIR__ "houdian",
                "south" : __DIR__ "hguangz3",               
       ]));
		set("coor/x",60);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}




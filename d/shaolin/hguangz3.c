// Room: hguangz3.c


inherit ROOM;

void create()
{
	set("short", "���㳡");
	set("long", @LONG
�����Ǻ��㳡�����������ʯ��ƴ�ɵĵ������м�����͹��̤�ۣ���
����ǰ�и���ʩչ�ڹ���������ӡ�ǡ�������һƬ�����֡�
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
		"west" : __DIR__ "hguangz2",
                 "north" : __DIR__ "hguangz5",
                 "southeast" : __DIR__ "songshu1",             
       ]));
		set("coor/x",60);
  set("coor/y",330);
   set("coor/z",120);
   setup();
}




// Room: /d/shaolin/shijie9.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ǰ��Ȼ����һ��Ƭ���֡����ֳ��ü��ܣ�ʯ���������˺�����Ƶ�
���롣���ڽ��£���������������һֻС����֨������ǰ��������ʧ����
���
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"ting",
		"westup" : __DIR__"shijie10",
                "eastup" : __DIR__"fxjing",
	]));

	set("outdoors", "shaolin");
	set("coor/x",60);
  set("coor/y",170);
   set("coor/z",90);
   set("coor/x",60);
 set("coor/y",170);
   set("coor/z",90);
   setup();
}




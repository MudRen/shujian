// Room: /d/shaolin/shijie7.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ�������������죬�ٲ��ڽ���Խ��ԽС��ˮ��Ҳ����Զȥ��λ���Ż�
��ɫɮ�µ�ɮ�˲����������������ɽ��ʱ��Ų����ȣ������Ǹ�����ӡ�
����Զ�����ƺ����Կ���ʯ��һ�ǡ�
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"shijie6",
		"westup" : __DIR__"shijie8",
	]));

	set("outdoors", "shaolin");
	set("coor/x",70);
  set("coor/y",150);
   set("coor/z",60);
   set("coor/x",70);
 set("coor/y",150);
   set("coor/z",60);
   setup();
}




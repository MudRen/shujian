//lwc9.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ���������ɵ���
��ͭ�ˣ�һЩ׳��ɮ�����������������С�
LONG
	);

	set("exits", ([
		"west" : __DIR__"lwc8",
		"north" : __DIR__"lwc",
	]));
         set("objects",([
		__DIR__"obj/tong-ren" : 1,
	]));


	set("outdoors", "shaolin");
	set("coor/x",20);
  set("coor/y",270);
   set("coor/z",120);
   set("coor/x",20);
 set("coor/y",270);
   set("coor/z",120);
   setup();

}


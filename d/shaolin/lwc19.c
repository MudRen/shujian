//lwc19.c

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
		"west" : __DIR__"lwc18",
		"north" : __DIR__"lwc11",
	]));
         set("objects",([
		__DIR__"obj/tong-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",100);
  set("coor/y",260);
   set("coor/z",110);
   setup();

}


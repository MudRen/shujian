//lwc17.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ���������ɵ�ľ
�ˣ�һЩ����ɮ������Χ����������
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc18",
		"north" : __DIR__"lwc16",
	]));
          set("objects",([
		__DIR__"obj/mu-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",260);
   set("coor/z",110);
   setup();

}


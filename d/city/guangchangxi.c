// Room: /d/city/guangchangxi.c

inherit ROOM;

void create()
{
	set("short", "�㳡��");
	set("long", @LONG
���ǹ㳡�����ࡣ�������������ر�Ӫ�����ڣ�������ǰ�䱸ɭ�ϣ�����
����ϡ�٣������ĵغ������塣�ϱ��ǳ���������ϴ�֡�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
	        "east" : __DIR__"guangchang",
	        "west" : __DIR__"bingyingmen",
		"north" : __DIR__"xidajie3",
		"south" : __DIR__"nandajie3",
	]));

	set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",0);
   set("incity",1);
	setup();
}


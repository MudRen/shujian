// Room: shanlu7.c

inherit ROOM;

void create()
{
	set("short", "ѩ���ŵ�");
	set("long", @LONG
  ���·ת��
  Զ��ɽ��������ѩ�ܣ���Լ�����ᡣ
  ���Ȼ�ѩ����ɼ�ϥ���ٲ�Ϊ�衣
  �����Ⱦ��������ű�ѩ���絶���档
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"houzidong",
		"northwest" : __DIR__"shanmen",
                "westdown" : __DIR__"shanlu6",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-270);
  set("coor/y",160);
   set("coor/z",30);
   setup();
}

// Room: shanlu3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ǰ�洫�������е��������쵽�ˣ��㲻�ɵüӿ��˽Ų���ԶԶ��ȥ��
�ƺ����Ǿ���Ӫ�ţ�Χ�Ų����������䡣
LONG
	);

           set("quest",1);
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"north" : __DIR__"yingmen",
	]));
  set("outdoors", "����");
  setup();
}

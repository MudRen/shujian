// Room: kchang.c
// by bren

inherit ROOM;

void create()
{
	set("short", "�ճ�");
	set("long", @LONG
���Ƿ��ú����һƬ�ճ������������µ���󲿷֡���Ϊ����ش�ƫƧ
�����������صأ�����ƽ��������ɮ�������������ǧ�������ǰ���
������ǵزص
LONG
	);

	set("exits", ([
		
                "north" : __DIR__"qfdian",
                "south" : __DIR__"fatang",
                "west" : __DIR__"dzdian",
                "east" : __DIR__"bydian",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}




inherit ROOM;
void create()
{
	set("short", "���ͼ�");
	set("long", @LONG
����һ����������ƽ���Ƶĵ��̣�һ����߸ߵĹ�̨���������ǰ����
̨�ϰ���һ������(sign)����̨������λ�ϰ壬һ˫�������۾��������´�
�����㡣
LONG
	);
	set("no_sleep_room",1);
set("no_fight",1);
	set("item_desc", ([
		"sign" : "��ƽ����\n",
	]));
	set("objects", ([
		__DIR__"npc/laoban1" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie3",
	]));

	set("coor/x",120);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}


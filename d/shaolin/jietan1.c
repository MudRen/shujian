// Room: jietan1.c
// by bren

inherit ROOM;

void create()
{
	set("short", "��̳");
	set("long", @LONG
����һ�������Σ��Ľ��ܼⶥ��̨ͤʽ������������ɮͽ�ܽ�ĵط���
̳�����з��з����������򱳶�����˫��ͭ�������汱����ҩʦ������
��Ϊ�����ӷ�̳�Ͽ���һ�ˣ��ž�������Խ���Եô˴���ׯ�����¡�
LONG
	);

	set("exits", ([
		
                "southeast" : __DIR__"sblu-3",
                "north" : __DIR__"jietan3",
                "east" : __DIR__"jietan2",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",390);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",390);
   set("coor/z",130);
   setup();
}




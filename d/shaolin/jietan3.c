// Room: jietan3.c
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
		
                "northeast" : __DIR__"fatang.c",
                "south" : __DIR__"jietan1",
                "east" : __DIR__"jietan4",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",400);
   set("coor/z",130);
   setup();
}




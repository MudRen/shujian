// Room: jietan4.c
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
		
                "northwest" : __DIR__"fatang.c",
                "south" : __DIR__"jietan2",
                "west" : __DIR__"jietan3",
		]));
         

	set("outdoors", "shaolin");
	set("coor/x",60);
  set("coor/y",400);
   set("coor/z",130);
   set("coor/x",60);
 set("coor/y",400);
   set("coor/z",130);
   setup();
}




// Room: tulu3.c

inherit ROOM;

void create()
{
	set("short", "�ر���·");
	set("long", @LONG
�����Ѿ����������أ�����Խ��Խ�ߣ�����ϡ����������������������
���������ۣ�ɹ����Ƥ���������ڸ����ңң����Զ��һ���ǳأ���
�˲��ɵ���ܾ��񣬼ӿ��˽Ų���
LONG
	);

	set("exits", ([
        "northeast" : __DIR__"tulu1",
        "southwest" : __DIR__"tulu3",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-200);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

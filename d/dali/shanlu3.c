// Room: ɽ· 3
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�����ͷ����һ
Щ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�����ɽ����
������������磬������������������һЩ�����Ļ��㣬�����侳�����ӡ���
��֮����Ȼ������
LONG
	);
        set("outdoors", "����");
	set("exits", ([ 
	    "south" : __DIR__"shanlu4",
            "northeast" : __DIR__"wuliang/xiaoxi",
	    "north" : __DIR__"shanlu2", 
        ]));
	set("no_clean_up", 0);

	set("coor/x",-310);
  set("coor/y",-310);
   set("coor/z",-20);
   set("coor/x",-310);
  set("coor/y",-310);
   set("coor/z",-20);
   setup();
}

// Room: ɽ· 1
// bbb 1997/06/11
// Modify By River 98/12  
inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޺�������ͷ����һ
Щ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�����ɽ����
������������磬������������������һЩ�����Ļ��㣬�����侳�����ӡ���
��֮����Ȼ������
LONG
	);
        set("outdoors", "����");
	set("exits", ([ 
      "southwest" : __DIR__"shanlu2",
      "northeast" : "/d/xiangyang/hunanroad2",
      "south" : "/d/miaojiang/shandao2",
	]));

	set("no_clean_up", 0);

	set("coor/x",-300);
  set("coor/y",-290);
   set("coor/z",-20);
   setup();
}

// Room: ɽ· 1
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
	set("exits", ([ 
          "north" : "/d/dali/nanmen",
          "southup" : __DIR__"xgf",
        ]));
        set("outdoors", "����");

	set("coor/x",-310);
  set("coor/y",-480);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if(dir=="southup" ){
        if(me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("ɽ�Ͼ�����������������ɽ��\n");
        }
        return ::valid_leave(me, dir);
}

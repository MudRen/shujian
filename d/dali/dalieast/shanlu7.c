// Room: ɽ· 7
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
                "northeast" : __DIR__"road1",
                "west" : "/d/dali/dongmen",
                "southeast" : __DIR__"xs1",
        ]));
        set("outdoors", "����");

	set("coor/x",-270);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="west" ){
        if( me->query("can_ride")){
          return 0;
          }       
        if(me->query_temp("ride_horse"))
        return notify_fail("ɽ�Ͼ�����������������ɽ��\n");
        }
        return ::valid_leave(me, dir);
}

// Room: /d/dali/xueshan.c
// bbb 1997/06/10 
//cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����ѩɽ");
	set("long", @LONG
����λ��»Ȱ�ؾ��ڣ��ж���ɽ����ΰ����ɽ��������ɽ���վ�����Ȼ��
��ʮ�ֶ��ء�ɽ����������ĸ�ɽ��������ɽ�ݵ顢�߲��ٲ��ͱ��Ī�����
�㡢ѩ�������⡣��������ʮ�ֶž���ɽ���飬����ͷף���������װ�ع���
���ɡ����������١�ѩԭ�Ⱦ���׳�����档
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "northdown" : __DIR__"nj",
	]));

	set("coor/x",-360);
  set("coor/y",-440);
   set("coor/z",0);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xueshan",1);
      }
}

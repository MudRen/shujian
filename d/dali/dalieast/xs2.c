// Room: /d/dali/xs2.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�����ǹ��ڵ���ճ��ĺõط���������������һ�鹹������ɽ�����޺�
ɽ�����ͱ��ϵĽ���Ⱥ���оŲ�ʮһ������ʯ�񹤳̣�����ʯ�������ҹ�����
�ſߡ��ŷ�ȣ�����ɽʤ���ľ������ڡ��������ţ�ƾ�����ӣ�Ϊ����֮����
�ͱڡ���ĿԶ��������һɫ��������ؾ����۵ס�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "south" : __DIR__"xs1",
	]));

	set("coor/x",-260);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xs2",1);
      }
}

// Room: /d/dali/hg3.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ﱻ������ճ�Ϊ���ݺ�����ˮƽ�羵���������֣��������ۣ�������
�ᣬƻ��έ�ء����ϴ������ƣ�����������������������ɽɫ�����м�Ȥ����
�о͵������ˡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"hg1",
	]));

	set("coor/x",-300);
  set("coor/y",-500);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/hg3",1);
      }
}

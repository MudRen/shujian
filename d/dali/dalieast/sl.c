// Room: /d/dali/sl.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��Ҫ������ʯ�֡��˹�ʯ�֡����ˮ�ٲ���֥�ƶ�����綴���������º�
���߸�������������ʯ�������������֣�ǧ�˰�̬��ʯ�塢ʯ����ʯ��ʯƺ��
ʯ��----����һƬç׳��ڵ�ɭ�֣�����Ϊ�����µ�һ��ۡ���ʯ���������
���������Ժ����ΰ�Ŀ�˹�ص�ò������չ��������صķ�ɡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
          "west" : __DIR__"lunan",
	]));

	set("coor/x",-250);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/sl",1);
      }
}

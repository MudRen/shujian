// Room: /d/dali/hg1.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ԭ��һ���ɶ�������������еĳ��̣�����ӽ�Һ�����������
���죬ֹ�ھ���ɽ��һ����ĵ���С���ˮ����ɽ�����¥����ʤң���Ӧ��
�̳�Լ�Ĺ���룬��������ʮ�����������ٹ��߲��ȣ�����һ��Ư���ں���
������������һ��Ϊ������Ϊ������壬��Ϊֱ�������Ǳߵġ��ݺ�����
LONG
	);
        set("outdoors", "����");

	set("exits", ([
	       "south" : __DIR__"hg2",
	       "north" : __DIR__"hg3",
               "northdown" : __DIR__"dg1",
	]));

	set("coor/x",-300);
  set("coor/y",-510);
   set("coor/z",-20);
   setup();
}

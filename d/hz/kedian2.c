// /u/beyond/hz/kedian2.c �͵�
inherit ROOM;
void create()
{
	set("short","�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�����
һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ��
����˯����
LONG
	);

	set("exits", ([
                "down" : __DIR__"tianxiang",
		"enter" : __DIR__"kedian3",
	]));

	set("coor/x",100);
  set("coor/y",-350);
   set("coor/z",10);
   setup();
}


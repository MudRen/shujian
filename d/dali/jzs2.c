// Room: /d/dali/jzs2.c
// bbb 1997/06/10 
// Modify By River 98/12 
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����滨��ݣ��������ޣ����ٹ�����ӧ����ǧ��Σ��Ƕ�£�Ⱥ��������
����ɽ��´�ı���ɳַ��ɽ��·��Ϫˮ���ȣ����񷺱̣�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "eastup" : __DIR__"jzs1",
            "westdown" : __DIR__"jzs3",
	]));

	set("coor/x",-260);
  set("coor/y",-340);
   set("coor/z",0);
   set("coor/x",-260);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}

// Room: /d/dali/htq.c
// bbb 1997/06/10 
// Modify By River 98/12 
inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
�����ڴ���Ǳ���ʮ����Ĳ�ɽ��Ū���¡�������С������ǰ�У�ֻ����
��������Ũ����죬һ����ȪǶ����䣬������ʯ��Ȫˮ������������������
Ǯ���ڳأ����仺�����䣬���������ɸ�£��ص�������˸������Ȫˮ������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
          "southwest" : __DIR__"dadao3",
          "east" : __DIR__"hth",
	]));

	set("coor/x",-300);
  set("coor/y",-340);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-340);
   set("coor/z",-20);
   setup();
}

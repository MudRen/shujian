inherit ROOM;

void create()
{
       set("short", "ɮ��");
       set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�����
ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�������������
������ķ��ż������ź�ľ�㡣
LONG
       );
       set("sleep_room", "shaolin");
        set("no_fight", 1);
       set("exits", ([
                 "north" : __DIR__"sengshe4",
    	]));
	set("coor/x",30);
  set("coor/y",280);
   set("coor/z",120);
   setup();
     }

// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ǵ�����ڵĶ����������������ĥ�Ķ���Զ�����������ٴ����ʳ��
ר������������������Ʈ�Ŷ������������㣬�ö����ڲ�ͣ��æ�š�
LONG
 );
        set("exits", ([
                "east" : __DIR__"dongjie2",
                "west" : __DIR__"qsjie1",
                "north" : __DIR__"jiulou",
	]));

        set("objects", ([
         __DIR__"npc/xishi" : 1,
	]));

	set("coor/x",-300);
  set("coor/y",-400);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-400);
   set("coor/z",-20);
   setup();
}

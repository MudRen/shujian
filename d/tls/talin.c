inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
�߳���С·����ǰ��Ȼһ��������һƬ���֡�������ȥ����������
�в��°����߰���һ��ʯ������Щ����������ɮԲ�ź�Ϊ�����޵�
�����������������壬��ʱ��������Ұ�޵��ƽУ����������У����
���в�����Щ���¡�
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
		"east" : __DIR__"shanlu-4",
        ]));
//	set("objects",([
//                __DIR__"npc/saodiseng" : 1,
//        ]));
        set("coor/x",-460);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}

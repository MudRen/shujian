// Room: wangdali.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǽ乤���������Ѿ��м�ʮ�����ʷ����ʼ���Ǹ������������ˣ�����
�����ഫ�������������������������ֽ��ˣ��������������ʤ���������ڹ�ģ
��������ļ��Щ�˲ţ�ľ�����߹���������ʯ�ϡ������������С�
LONG
	);

	set("exits", ([
		"west" : __DIR__"jiedao3",
	]));
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wang" : 1,]));
	set("coor/x",-210);
  set("coor/y",130);
   set("coor/z",0);
   setup();

}

// Room: shanlu4.c

inherit ROOM;

void create()
{
	set("short", "���Ŀ�");
	set("long", @LONG
�˴�����Ⱥɽ����֮�У�ɽ·ȥ������Ρ��Ĵ�ѩɽ��̧ͷ�������嶥����
���ƣ������ɾ������ǣ�
    ��ɽ������ã�⣬����ȥ��ɽ������
    ��ɽ���أ�����ǧ�
    �������Ĳ����ҡ� 

LONG
	);

	set("exits", ([
		"westup" : __DIR__"fengjiantai",
		"eastup" : __DIR__"shanlu3",
	]));
        set("outdoors", "ѩɽ");
        set("objects", ([CLASS_D("xueshan") + "/baoxiang" : 1,]));
	set("coor/x",-290);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}

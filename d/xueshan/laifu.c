// Room: laifu.c

inherit MISC_ROOM;

void create()
{
	set("short", "�����ӻ�");
	set("long", @LONG
����ӻ������治�󣬻����ϡ������ϡ����������ﶼ�������ذڷ���
Щ��ʽ�����Ļ���Ե���Щ���ҡ������Ӵ�С���ճ����õ��ŵ����ﶼ��
�򵽣������������벻�����С�ꡣǽ�Ϲ��Ÿ���Ŀ��(sign)��
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao3",
	]));
        set("no_sleep_room",1);
	set("no_fight", 1);
        //set("item_desc",([
		//"sign" : "�����ӻ�����������\n"
	//]));
        set("objects", ([__DIR__"npc/jiang" : 1,]));
	set("coor/x",-230);
	set("coor/y",130);
	set("coor/z",0);
	setup();
}

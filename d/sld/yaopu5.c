// yaopu5.c
// ҩ��
inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@long
��������������ҩ�ԣ����˲�������ҩ�ġ�
long);
	set("exits",([
	    "east" : __DIR__"yaopu2",
            "west" : __DIR__"yaopu8",
	    "north" : __DIR__"yaopu4",
            "south" : __DIR__"yaopu6",
]));
	set("no_clean_up",1);
	set("outdoors", "������");
	setup();
}
	    	

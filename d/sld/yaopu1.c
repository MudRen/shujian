// yaopu1.c
// ҩ��
inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@long
��������������ҩ�ԣ����˲�������ҩ�ġ�
long);
	set("exits",([
	    "south" : __DIR__"zl1",
            "west" : __DIR__"yaopu6",
            "north" : __DIR__"yaopu2",
]));
	set("no_clean_up",1);
	set("can_zhong",1);
	set("8type","Ǭ");
	set("outdoors", "������");
	setup();
}
	    	

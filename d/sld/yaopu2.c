// yaopu2.c
// ҩ��
inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@long
��������������ҩ�ԣ����˲�������ҩ�ġ�
long);
	set("exits",([
	    "west" : __DIR__"yaopu5",
            "north" : __DIR__"yaopu3",
            "south" : __DIR__"yaopu1",
]));
	set("no_clean_up",1);
	set("can_zhong",1);
	set("8type","��");
	set("outdoors", "������");
	setup();
}
	    	

// yaopu3.c
// ҩ��
inherit ROOM;
void create()
{
	set("short","ҩ��");
	set("long",@long
��������������ҩ�ԣ����˲�������ҩ�ġ�
long);
	set("exits",([
            "west" : __DIR__"yaopu4",
            "south" : __DIR__"yaopu2",
]));
	set("no_clean_up",1);
	set("can_zhong",1);
	set("8type","��");
	set("outdoors", "������");
	setup();
}
	    	

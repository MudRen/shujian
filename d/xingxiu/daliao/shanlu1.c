// Room: shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ����ɽ��·��ɽ�䴩�������޽У�·���ƺ��ܾ�û�������ˣ�
�Ե���Щ�ƾɣ����Ǵ������ĺۼ���ϡ���Կ�������ĻԻ͡�
LONG
	);

           set("quest",1);
	set("exits", ([
		"northwest" : __DIR__"shanlu2",
                "south" : __DIR__"shulin",
	]));
 setup();
}

// road1.c 小路

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这条小路是胆大的男人们去密林里打猎时走出来的，再往西走就到草原边
缘而进入森林了。偶尔可以听见远处传来野兽的吼声，你还是快回去吧。
LONG
        );

	set("group", 1);
        set("exits", ([
		"westup" : "/d/hj/shanqiu",
		"east" : "/d/hj/pmchang",            
        ]));

        set("outdoors", "回疆草原");
        
	setup();
}

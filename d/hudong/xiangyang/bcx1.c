// /d/xiangyang/bcx1.c 北城巷
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "北城巷");
        set("long", @LONG
这里是由西门通往北门的一条小巷，因为地处襄阳城北，所以人们把这里
叫做北城巷。走在这条小街上举目望去，巷子两旁是各式各样的店铺，人来人
往，很是热闹。
LONG
        );
        set("outdoors", "襄阳");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"bcx2",
                "east" : __DIR__"bjie1",
        ]));

        set("incity",1);
	setup();
}

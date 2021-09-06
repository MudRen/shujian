//ROOM /d/xiakedao/dating.c

inherit ROOM;

int do_push(string arg);
void create()
{
        set("short", "大厅");
        set("long", @LONG
这是『侠客岛』的大厅，四周点满了牛油蜡烛，南面放着一个
大屏风。洞内摆着一百来张桌子，宾客正络绎进来，数百名黄衣汉
子穿索般来去，引导宾客入座。
LONG );
//        set("valid_startroom",1);
        set("no_fight","1");
        
        set("exits", ([
                "north" : "/d/xiakedao/shanmen",
"east"  : "/d/xiakedao/shibi",
                
        ]));
        set("objects",([
                "/d/xiangyang/npc/lisi" : 1,
        ]));
        setup();

}


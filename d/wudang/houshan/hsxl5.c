// Room: /u/dubei/wudang/hsxl5

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С·");
	set("long", @LONG
����һ���˼������ɽ´�����ܹ�ľïʢ����ʱ��Ұ�޵ĳ�û��ż����һ
Щ��ҩ��������Ѱ��һЩϡ�еĲ�ҩ��
LONG	);

	set("exits", ([ 
             "southup" : __DIR__"hsxl4",
             "northwest" : "/d/wudang/shanlu2",
        ])); 
 
        set("outdoors", "�䵱");
 
        setup();
}

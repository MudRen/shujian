// Room: /u/dubei/wudang/hsxl3
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
ɽ���ϵĹ�ľԽ��Խ�࣬·���ϵľ�����ʱ�İ�����ֽŻ��ƣ�һЩ����
�г���ٿ�Ĵڳ�һ�����ߣ������ľ�������
LONG	);
	set("exits", ([ 
                 "southup" : __DIR__"hsxl3",
                 "northdown" : __DIR__"hsxl5",
        ])); 

        set("outdoors", "�䵱");
        setup();

}


// Room: /u/dubei/wudang/hsxl3
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
������Ӳݽ�Ϊϡ�٣�����ɽ·Խ�����͡�������һЩïʢ������������
����һЩ�����һ������Ծ����һ�����ϡ���ĿԶ���������ܿ���ǰ����һ��
�վ���ɽ�塣
LONG	);
	set("exits", ([ 
                 "southup" : __DIR__"hsxl2",
                 "northdown" : __DIR__"hsxl4",
        ])); 
      
        set("outdoors", "�䵱");
        setup();
}

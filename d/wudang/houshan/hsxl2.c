// Room: /u/dubei/wudang/hsxl2
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
ɽ·���������������ϣ�ɽ·����������Χ��Ļ���������������Ͽ�ȣ�
�����Ƕ��͵�ɽ�ڡ�·���ϵ���ʯ��͹��ƽ��һ��С�ľͿ���Ҫˤ����Ԩ��
һ���˵�������Ͳ�������ǰ�ˡ�
LONG	);
	set("exits", ([ 
                 "southup" : __DIR__"hsxl1",
                 "northdown" : __DIR__"hsxl3",
        ])); 
      
        set("outdoors", "�䵱");
        setup();
}

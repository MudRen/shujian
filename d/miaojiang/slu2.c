// /u/dubei/�置
 

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��һ��ɽ·�쳣���ͣ�������ïʢ�Ĵ��֡�·�����嶾����ֲ�Ļ�ľ��ɢ��
�ų�ǵ�������
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"slu1",
                "eastup" : __DIR__"slu3",
                "northup" : __DIR__"slu4",
	]));
     
        set("objects",([
		__DIR__"npc/dushe" : 1,
	]));
       
	set("outdoors", "�置");
	setup();
}

#include "mjpoison.h"

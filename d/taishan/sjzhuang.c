// Room: /d/taishan/sjzhuang.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"����ׯ"NOR);
        set("long", @LONG
���ߵ�һ����լ��Ժ���ſڣ����ſ��ţ���ǰ����������ʯʨ�ӣ����弶
��ʯ̨���������ȶ���ͭ���Ĵ��š����ó������ǵ��ش����ס�����ſ�����
�������һ��ڵ׽��ֵĴ��ҡ�����ׯ����
LONG
        );
        set("exits", ([
              "south" : __DIR__"shulin1",              
        ]));

        set("objects",([
                __DIR__"npc/shanzheng" : 1,
        ]));
 
	setup();
}

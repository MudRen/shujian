#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��԰"NOR);
	set("long", @LONG
��԰�����ݵ�һ������֮һ�����Խṹ���ֽ��ܡ����û�����֡�װ��
�������Ŷ����С����е�һ��԰��֮����
LONG	);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
        set("exits", ([ 
	"west" : __DIR__"hehuating",
	"east" : __DIR__"nandajie2",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",100);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}
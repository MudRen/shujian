#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"��ľ��ڭ"NOR);
	set("long", @LONG
��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸��©��������
���в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;����С��Ʋ���Ӱ��֮���
�����׿���ң������������ɪ¥������һ�֡�ͥԺ��������Ϳռ䲻��
֮�С�
LONG	);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
        set("exits", ([ 
	"southwest" : __DIR__"chitang",
	"east" : __DIR__"hehuating",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",80);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}
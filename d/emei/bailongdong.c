// Room: /d/emei/bailongdong.c
// made by jackie

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
    ��������˵�ǡ����ߴ����еİ�������������֮���������ľ���죬����
�е���������ͦ���Σ�֦Ҷ����������������ӵ�𣬴�Ϊ��ʱһ��ɮ��������
��������һ�֣�ֲ��һ�꣬��ֲ�����ǧ�߰���ʮ���꣬ʱ�ƹŵ��֡����ﱱ
���������֣�������������
LONG
	);
	set("exits", ([ 
	  "west" : __DIR__"gudelin",
	  "southeast" : __DIR__"qingyinge",
	  "northup" : __DIR__"wannianan",
]));
	set("no_clean_up", 0);

	setup();
}

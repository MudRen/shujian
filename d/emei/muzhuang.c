// muzhuang.c
// ÷��׮

inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "zhuang.h"
void create()
{
	set("short",HIY "÷��׮" NOR);
	set("long",@long
����������ľ׮������������һ����ϰ�Ṧ�ľ��ѳ�����
long);
set("exits",([
"down" :  __DIR__"gudelin3",
]));
	setup();
}

// Room: /u/xdd/gumu/rukou.c
// Modify by river 98/08/29
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIY"��Ĺ"NOR);
	set("long", @LONG
����˶��񣬷����Լ��������֮�У��������ɣ�������ˡ�������Ƭ
��С�Ŀ����أ�һ��һ�˸ߵİ�ɫ����Բڣ�������У�Ĺ������ɭɭ�����ֹ�
ľ����ƽ��ʮ��������į����ɪ֮�⡣Ĺ�Ž����ߣ������ǹ�Ĺ�����ڡ���
Ĺ������������������������ٳ�����Ů��Ľ��������˫���ϱڿ��⽭���ĺ�
�飬����ǧ��ĥ�Ѻ��ճɾ����������顣��Զǧ������Ͷ�ݡ�
LONG        );

	set("outdoors","��Ĺ");

	set("exits", ([
		"enter" : __DIR__"gmqt",
		"south" : __DIR__"xuanya",
                "north" : __DIR__"guoyuan",
                "up" : __DIR__"yinhang",
	]));

	setup();
	"/clone/board/gumu_b"->foo();
} 

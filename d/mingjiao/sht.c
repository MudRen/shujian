// sht.c ʥ����
// Modify By River@SJ 99.06
// Modify by Lklv 2002.1.17
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIR"ʥ����"NOR);
       set("long", @LONG
�����������ʥ�������ڡ���һ�ߵ�����ͻȻ����һ��ǰ��û�е�ׯ����
��֮�⣬���������ô����д������Ѫ����֡�ʥ���á����м���һ�������
��д�ţ������Ҳ���������ʥ������λ�������οࣿΪ�Ƴ���Ω�����ʣ�
ϲ�ֱ���Թ鳾�����������ˣ��ǻ�ʵ�࣡�������ˣ��ǻ�ʵ�ࡱ�������
�ų��겻���ʥ�𣬾�����������ʿ�͹ټ���ʿ�����ݡ��м����һ�Ŵ�ͷ
�Σ���������������֮λ���м���Ѿ�����Ա��̺
LONG);
	set("exits", ([
		"southdown" : __DIR__"jyt",
		"northup" : __DIR__"baota",
	]));
	set("objects",([
		__DIR__"npc/yahuan" :   1,
		__DIR__"npc/f-dizi" :   1,
		CLASS_D("mingjiao") + "/zhangwuji" : 1,
	]));
	setup();
}

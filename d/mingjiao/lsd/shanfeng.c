///u/qingyun/lsd/shanfeng.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"ɽ��"NOR);
	set("long", @LONG
����ɽ�¶��У��򱱶�����һ��ɽ�壬ɽ�����������ߵ��ı�������ɽ��
֮�������Կ���һ��������é�ݡ�
LONG);
	set("exits", ([
	  	"southdown" : __DIR__"sfjiao",
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/huiyue" : 1,
                CLASS_D("mingjiao") + "/liuyun" : 1,
                CLASS_D("mingjiao") + "/miaofeng" : 1,
	]));
	set("outdoors","���ߵ�");
	setup();
}

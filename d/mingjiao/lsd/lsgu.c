// /u/qingyun/lsd/lsgu.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"���߹�"NOR);
	set("long", @LONG
�����ǵ����һ��ɽ�ȡ�ɽ�ȳ�������滨��ݣ������������������
��������Զ�뷲�����㵽�˴˴�������Ϊ�ɾ����˵���Ȼ�����ж��߳�û��Ψ
�д˴���������֮��Ӱ��Ҳ��˼����˳��ڴ˼�����֮����
LONG);
	set("exits", ([ 
  		"southup" : __DIR__"shanguang",
                "north" : __DIR__"sfjiao",
	]));
	set("objects",([
             CLASS_D("mingjiao") + "/dai" : 1,
	]));
	set("outdoors","���ߵ�");
	setup();
}
